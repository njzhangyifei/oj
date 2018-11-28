class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int longest = -1;
        int curr = 0;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 0) {
                ++curr;
                longest = max(longest, (curr + 1) / 2);
            } else {
                curr = 0;
            }
        }

        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                longest = max(longest, i);
                break;
            }
        }

        for (int i = seats.size() -1; i >= 0; -- i) {
            if ( seats[i] == 1 ) {
                longest = max(longest, ((int)seats.size()-1) - i);
                break;
            }
        }
        
        return longest;
    }
};
