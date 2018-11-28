class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        if (s.size() == 0) {
            res.push_back("");
            return res;
        }
        unordered_set<string> visited;
        queue<string> q;

        visited.insert(s);
        q.push(s);

        bool found = false;
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            if (isvalid(curr)) {
                res.push_back(curr);
                found = true;
            }
            
            if (found) {
                continue;
            }

            for (int i = 0; i < curr.size(); ++i) {
                if (curr[i] != '(' && curr[i] != ')') {
                    continue;
                }
                string next = curr.substr(0,i) + curr.substr(i+1);
                if (visited.find(next) == visited.end()) {
                    // not found
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return res;
    }

    bool isvalid(const string & s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') ++count;
            if (s[i] == ')') --count;
            if (count < 0) {
                return false;
            }
        }
        return count == 0;
    }

};
