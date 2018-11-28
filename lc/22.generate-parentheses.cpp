#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<string> v;
        bt(v, "", 0, 0, n);
        return v;
    }

    void bt(vector<string> & v, string curr, int left, int right, int n) {
        if (curr.size() == n * 2) {
            v.push_back(curr);
        }
        if (left < n) {
            bt(v, curr + "(", left+1, right, n);
        }
        if (right < left) {
            bt(v, curr + ")", left, right+1, n);
        }
    }
};
