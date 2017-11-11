#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

#define DEBUG
using namespace std;

class BadNeighbors
{
public:
    int maxDonations(vector<int> donations) {
        int i;
        int N = donations.size();

        // either contains the first or the last => two seq
        std::vector<int> seq_1(N-1);
        for (i = 0; i < N-1; ++i) {
            seq_1[i] = donations[i];
        }

        std::vector<int> seq_2(N-1);
        for (i = 1; i < N; ++i) {
            seq_2[i-1] = donations[i];
        }

        // dp[i] = max(dp[i-1] + dp[i-3], dp[i-2] + seq[i])
        std::vector<int> dp_1(N-1);
        std::vector<int> dp_2(N-1);
        dp_1[0] = seq_1[0];
        dp_2[0] = seq_2[0];
        dp_1[1] = max(seq_1[1], seq_1[0]);
        dp_2[1] = max(seq_2[1], seq_2[0]);
        dp_1[2] = max(seq_1[2] + dp_1[0], seq_1[1]);
        dp_2[2] = max(seq_2[2] + dp_2[0], seq_2[1]);
        for (i = 3; i < N-1; ++i) {
            // two possibility for the max donation ending at i
            // 1. dp = seq[current] + dp[current - 2]
            // 2. dp = seq[current-1] + dp[current - 3]
            dp_1[i] = max(seq_1[i-1] + dp_1[i-3], seq_1[i] + dp_1[i-2]);
            dp_2[i] = max(seq_2[i-1] + dp_2[i-3], seq_2[i] + dp_2[i-2]);
        }

#ifdef DEBUG
        cout << "dp_1:" << endl;
        for (i = 0; i < N-1; ++i) {
            cout << dp_1[i] << " ";
        }
        cout << endl;
        cout << "dp_2:" << endl;
        for (i = 0; i < N-1; ++i) {
            cout << dp_2[i] << " ";
        }
        cout << endl;
#endif

        int max = 0;
        for (i = 0; i < N-1; ++i) {
            if (dp_1[i] > max) {
                max = dp_1[i];
            }
            if (dp_2[i] > max) {
                max = dp_2[i];
            }
        }

        return max;
    }
private:
    /* data */
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i, T;
    string arr;
    getline(cin, arr);
    stringstream ss(arr);
    ss >> T;

    for (i = 0; i < T; ++i) {
        string arr;
        getline(cin, arr);
        stringstream ss(arr);
        std::vector<int> v;
        int x;
        while (ss >> x) {
            v.push_back(x);
        }

        int ans;
        getline(cin, arr);
        ss.str(arr);
        ss.clear();
        ss >> ans;
        cout << "-----------------------------------------------" << endl;
        cout << " * input: ";
        for (auto element : v) {
            cout << element << " ";
        }
        cout << endl;

        BadNeighbors * b = new BadNeighbors();
        delete b;
        int user_ans = b->maxDonations(v);

        cout << " * answer: " << ans << endl;
        cout << " * user ans: " << user_ans << endl;
        cout << ((ans==user_ans) ? "PASSED" : "FAILED") << endl;
    }

    return 0;
}

