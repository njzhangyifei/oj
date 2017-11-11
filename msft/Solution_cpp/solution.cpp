//
// .___  ___.  _______   ________   ________  
// |   \/   | |       \ |       /  |       /  
// |  \  /  | |  .--.  |`---/  /   `---/  /   
// |  |\/|  | |  |  |  |   /  /       /  /    
// |  |  |  | |  '--'  |  /  /----.  /  /----.
// |__|  |__| |_______/  /________| /________|
//
//
                                           
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
#include <sstream>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

std::vector<string> * split(string s, char delim){
    std::stringstream ss(s);
    auto v = new std::vector<string>();
    string e;
    while (getline(ss, e, delim)) {
        v->push_back(e);
    }
    return v;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    return 0;
}

