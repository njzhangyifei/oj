class Solution {
public:
    vector<string> target = {
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };


    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) {
            return res;
        }

        int i = digits[0] - '1';

        if (i >= 9) {
            return res;
        }

        vector<string> curr_res = letterCombinations(digits.substr(1));
        if (curr_res.size() == 0) {
            curr_res.push_back("");
        }
        for (int j = 0; j < target[i].size(); ++j) {
            for (int k = 0; k < curr_res.size(); ++k) { 
                res.push_back(target[i][j] + curr_res[k]);
            }
        }

        return res;
    }
};
