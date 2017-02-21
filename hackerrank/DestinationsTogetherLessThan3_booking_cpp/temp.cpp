#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int64_t res = 1;
    int64_t i;
    for (i = 1; i < 21; ++i) {
        res *= i;
        cout << res << "," << endl;;
    }
    return 0;
}
