class Solution {
public:
    bool isNumber(string s) {
        int begin = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                begin = i;
                break;
            }
        }
        int end = 0;
        for (int i = s.size()-1; i>=0 ; --i) {
            if (s[i] != ' ') {
                end = i;
                break;
            }
        }
        s = s.substr(begin, end - begin + 1);
        


        bool eSeen = false;
        bool numberAfterE = false;
        bool numberBeforeE = false;

        bool pointSeen = false;


        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                if (eSeen) numberAfterE = true;
                if (!eSeen) numberBeforeE = true;
            } else if (s[i] == '.') {
                if (pointSeen || eSeen) {
                    return false;
                }
                pointSeen = true;
            } else if (s[i] == 'e') {
                if (eSeen) {
                    return false;
                }
                eSeen = true;
            } else if (s[i] == '-' || s[i] == '+') {
                // signs
                if (!(i == 0 || s[i-1] == 'e')) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return eSeen ? (numberAfterE && numberBeforeE) : numberBeforeE ;
    }
};
