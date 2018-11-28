class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> v;
        if (num.size() == 0) return v;
        string p("");
        dfs(v, num, target, p, 0, 0, 0);
        return v;
    }

    void dfs(vector<string> & res, const string & num, const int & target, 
    string path, int pos, long path_res, long delta) {
        if (pos == num.size()) {
            if (target == path_res) {
                res.push_back(path);
            }
            return;
        }

        for (int i = pos; i < num.size(); ++i ) {
            // num = pos..i
            if (i != pos && num[pos] == '0') {
                // 0xxxx
                break;
            }

            string cur_str = num.substr(pos, i-pos+1);
            long cur = stol(cur_str);

            if (pos == 0) {
                dfs(res, num, target, cur_str, i + 1, cur,  cur);
            } else {
                dfs(res, num, target, path + "+" + cur_str, i + 1, path_res + cur,  cur);
                dfs(res, num, target, path + "-" + cur_str, i + 1, path_res - cur, -cur);
                dfs(res, num, target, path + "*" + cur_str, i + 1, path_res - delta + cur * delta, cur * delta);
            }
        }
    }


};
