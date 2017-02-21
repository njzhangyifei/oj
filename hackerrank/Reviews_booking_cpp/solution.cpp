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

const int64_t RANGE_BEGIN = 1465948800;
const int64_t RANGE_END = 1468540800;


struct review {
    int key;
    int user_id;
    int score;
    int64_t timestamp;
    string body;

    review(int key, istream & in){
        this->key = key;
        in >> user_id >> timestamp;
        cin.get();
        std::getline(cin, body);
        std::transform(body.begin(), body.end(), body.begin(), ::tolower);
        this->score = 20;
        if (body.length() >= 100) {
            this->score += 10;
        }
        if (timestamp <= RANGE_END && timestamp >= RANGE_BEGIN) {
            this->score += 10;
        }
    };

    bool contains(string passion) {
        std::size_t found = body.find(passion);
        if (found != std::string::npos) {
            return true;
        }
        return false;
    }
};

struct reviewer {
    int id;
    std::map<string, int64_t> score;
    
    reviewer(int id){
        this->id = id;
    }

    void update_score(review * r, string passion){
        if (r->contains(passion)) {
            this->score[passion] += r->score;
        }
    }
};

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N_passion, N_review;
    cin >> N_passion >> N_review;

    int i, j;
    std::vector<string> * v_passion = new std::vector<string>();
    std::map<int, reviewer *> * reviewer_map = new std::map<int, reviewer *>();
    for (i = 0; i < N_passion; ++i) {
        string temp;
        cin >> temp;
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        v_passion->push_back(temp);
        #ifdef DEBUG
        cerr << temp << endl;
        #endif
    }

    std::vector<review *> * v_review = new std::vector<review *>();
    for (i = 0; i < N_review; ++i) {
        v_review->push_back(new review(i, cin));
        #ifdef DEBUG
        cerr << "score " << v_review->at(i)->score << endl;
        #endif
    }

    for (i = 0; i < (int)v_passion->size(); i++) {
        // go through all passion
        string passion = v_passion->at(i);
        for (j = 0; j < (int)v_review->size(); ++j) {
            review * current_review = v_review->at(j);
            int current_reviewer = current_review->user_id;
            if (reviewer_map->find(current_reviewer) == reviewer_map->end()) {
                // doesn't exist
                reviewer_map->insert(
                        pair<int, reviewer *>
                        (current_reviewer,new reviewer(current_reviewer))
                        );
            }
            reviewer_map->at(current_reviewer)->update_score(current_review, passion);
            #ifdef DEBUG
            cerr << "passion " << passion << " updated for " << current_review->key << endl;
            #endif
        }
        int best_reviwer = -1;
        int best_score = 0;
        std::map<int, reviewer *>::iterator reviewer_map_iter;
        for (reviewer_map_iter = reviewer_map->begin(); 
                reviewer_map_iter != reviewer_map->end(); 
                ++reviewer_map_iter) {
            auto reviewer_ptr = reviewer_map_iter->second;
            if (reviewer_ptr->score.find(passion) != reviewer_ptr->score.end()) {
                int64_t current_reviewer_score = reviewer_ptr->score.at(passion);
                #ifdef DEBUG
                cerr << "reviewer " << reviewer_ptr->id 
                    << " score " << current_reviewer_score << endl;
                #endif
                if (current_reviewer_score > best_score) {
                    best_reviwer = reviewer_ptr->id;
                    best_score = current_reviewer_score;
                } else if (current_reviewer_score == best_score) {
                    best_reviwer = min(best_reviwer, reviewer_ptr->id);
                    best_score = current_reviewer_score;
                }
            }
        }
        cout << best_reviwer << endl;
    }


    return 0;
}

