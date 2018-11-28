// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return binsearch(1, n);
    }

    int binsearch(int start, int end) {
        if (end == start) {
            return start;
        }

        int mid = (end - start) / 2 + start;

        if (isBadVersion(mid)) {
            return binsearch(start, mid);
        } else {
            return binsearch(mid+1, end);
        }
    }
};
