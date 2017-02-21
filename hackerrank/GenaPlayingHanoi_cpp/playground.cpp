#include <iostream>
#include <cinttypes>

using namespace std;

uint32_t division_table[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
};

unsigned int get_digit(uint32_t original, unsigned int digit) {
    digit ++;
    uint32_t larger = original % division_table[digit];
    uint32_t right = original % division_table[digit-1];
    return ((larger - right) / division_table[digit-1]);
}

uint32_t change_digit(uint32_t original, unsigned int digit, unsigned int num){
    digit ++;
    uint32_t left = original / division_table[digit];
    uint32_t right = original % division_table[digit-1];
    return left * division_table[digit] + num * division_table[digit-1] + right;
}

int main(int argc, char *argv[])
{
    // uint64_t i = 10;
    // while (i < UINT_MAX) {
    // cout << i << endl;
    // i *= 10;
    // }

    uint32_t o;
    cin >> o;

    unsigned int digit;
    cout << "digit to get:" << endl;
    cin >> digit;

    auto v = get_digit(o, digit);

    cout << v << endl; 


    return 0;
}
