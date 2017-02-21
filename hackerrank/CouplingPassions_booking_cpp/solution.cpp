#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

struct person {
    int key;
    std::set<string> * set_passion = new std::set<string>;

    person(int key, std::set<string> * group_passion) {
        this->key = key;
        int num_passion;
        cin >> num_passion;
        int i;
        for (i = 0; i < num_passion; ++i) {
            string passion;
            cin >> passion;
            set_passion->insert(passion);
            group_passion->insert(passion);
        }
    }
};

struct city {
    int key;
    string name;
    float latitude;
    float longitude;
    std::set<string> * set_passion = new std::set<string>;

    city(int key) {
        this->key = key;
        int num_passion;
        cin >> name >> latitude >> longitude >> num_passion;
        int i;
        for (i = 0; i < num_passion; ++i) {
            string passion;
            cin >> passion;
            set_passion->insert(passion);
        }
    }
};

int passion_score(city * c1, city * c2, set<string> * passion_required) {
    set<string> city_union = *(c1->set_passion);
    city_union.insert(c2->set_passion->begin(), c2->set_passion->end());
    set<string> intersect;
    set_intersection(
            city_union.begin(),city_union.end(),
            passion_required->begin(),passion_required->end(), 
            std::inserter(intersect,intersect.begin())
            );
    return intersect.size();
}
#define degree2radian(a) (a * 0.017453292519)

float distance(city * c1, city * c2) {
    auto EARTH_RADIUS = 6371;//in km
    auto point1_lat_in_radians  = degree2radian( c1->latitude );
    auto point2_lat_in_radians  = degree2radian( c2->latitude );
    auto point1_long_in_radians  = degree2radian( c1->longitude );
    auto point2_long_in_radians  = degree2radian( c2->longitude );

    return acos( sin( point1_lat_in_radians ) * sin( point2_lat_in_radians ) +
                 cos( point1_lat_in_radians ) * cos( point2_lat_in_radians ) *
                 cos( point2_long_in_radians - point1_long_in_radians) ) * EARTH_RADIUS;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N_person, N_city;
    int i, j;
    std::set<string> * group_passion = new std::set<string>;
    std::vector<person *> * v_person = new std::vector<person *>;
    std::vector<city *> * v_city = new std::vector<city *>;
    cin >> N_person;
    for (i = 0; i < N_person; ++i) {
        v_person->push_back(new person(i, group_passion));
    }
    cin >> N_city;
    for (i = 0; i < N_city; ++i) {
        v_city->push_back(new city(i));
    }

    #ifdef DEBUG
    cerr << "person:" << endl;
    for (auto i : (*v_person)) {
        cerr << i->key << " - ";
        std::set<string>::iterator iter;
        for (iter = i->set_passion->begin(); iter != i->set_passion->end(); ++iter) {
            cerr << (*iter) << " ";
        }
        cerr << endl;
    }
    cerr << endl;

    cerr << "group_passion:" << endl;
    std::set<string>::iterator iter;
    for (iter = group_passion->begin(); iter != group_passion->end(); ++iter) {
        cerr << (*iter) << " ";
    }
    cerr << endl;
    #endif

    // std::map<pair<int, int>, int> city_score;
    pair<int, int> best_pair = pair<int, int>(0, 1);
    int best_score = INT_MIN;
    for (i = 0; i < (N_city-1); ++i) {
        for (j = i+1; j < N_city; ++j) {
            auto c1_ptr = v_city->at(i);
            auto c2_ptr = v_city->at(j);
            int score = passion_score(c1_ptr, c2_ptr, group_passion);
            #ifdef DEBUG
            cerr << "matching " << c1_ptr->name 
                << ", " << c2_ptr->name
                << " score " << score << endl;
            #endif 
            if (score > best_score) {
                best_pair = pair<int, int> (i, j);
                best_score = score;
            } else if (score == best_score) {
                auto b1_ptr = v_city->at(best_pair.first);
                auto b2_ptr = v_city->at(best_pair.second);
                float best_distance = abs(distance(b1_ptr, b2_ptr));
                float current_distance = abs(distance(c1_ptr, c2_ptr));
                if (current_distance < best_distance) {
                    best_pair = pair<int, int>(i,j);
                    best_score = score;
                }
            }
        }
    }

    auto best_c1_ptr = v_city->at(best_pair.first);
    auto best_c2_ptr = v_city->at(best_pair.second);
    string best_c1_name = best_c1_ptr->name;
    string best_c2_name = best_c2_ptr->name;
    cout << min(best_c1_name, best_c2_name) << " " 
        << max(best_c1_name, best_c2_name) << endl;

    return 0;
}

