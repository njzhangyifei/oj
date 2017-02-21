#include <cinttypes>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    uint64_t i;
    uint64_t factorial[19];

    factorial[0] = 1;
    factorial[1] = 1;
    factorial[2] = 2;

    for (i = 3; i < 19; ++i) {
        factorial[i] = factorial[i-1] * i;
    }

    for (i = 0; i < 19; ++i) {
        cout << (uint64_t)factorial[i] << endl;
    }
    return 0;
}
