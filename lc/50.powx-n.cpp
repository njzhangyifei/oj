class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1.0 / x;
            n = -n;
        }
        return halfPow(x, n);
    }

    double halfPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        bool odd = n % 2;
        double halfres = halfPow(x, n/2);
        if (odd) {
            // (n / 2) * x
            return halfres * halfres * x;
        } else {
            return halfres * halfres;
        }
    }
};
