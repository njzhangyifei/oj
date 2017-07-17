#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        static bool isPalindromic(string s){
            int str_len = s.length();
            for (int i = 0; i < str_len / 2; ++i) {
                if (s[i] != s[str_len - i - 1]) {
                    return false;
                }
            }
            return true;
        }

        string longestPalindrome(string s) {
            int str_len = s.length();
            bool map[str_len][str_len];
            int i, j;
            for (i = 0; i < str_len; ++i) {
                for (j = 0; j < str_len; ++j) {
                    map[i][j] = false;
                }
            }

            for (i = 0; i < str_len; ++i) {
                map[i][i] = true;
            }
            for (i = 0; i < str_len-1; ++i) {
                if (s[i] == s[i+1]) {
                    map[i][i+1] = true;
                }
            }

            // p[i][j] = p[i+1][j-1] && s[i] == s[j]
            for (i = str_len-2; i >= 0; --i) {
                for (j = 1; j < str_len; ++j) {
                    if (i == j || i == j-1) {
                        continue;
                    }
                    map[i][j] = map[i+1][j-1] && (s[i] == s[j]);
                }
            }
            
            // for (i = 0; i < str_len; ++i) {
                // for (j = 0; j < str_len; ++j) {
                    // cout << (map[i][j] ? '1' : '0') << ' ';
                // }
                // cout << endl;
            // }
            // cout << endl;

            int max_len = 1;
            string result = string({s[0]});
            for (i = 0; i < str_len-1; ++i) {
                for (j = max_len; j < str_len - i; ++j) {
                    if (map[i][i+j]) {
                        if ((j+1) > max_len) {
                            max_len = j + 1;
                            result = s.substr(i, max_len);
                        }
                    }
                }
            }


            return result;
        }
        string longestPalindrome_bf(string s) {
            int str_len = s.length();
            string longest = s.substr(0,1);
            int max_len = 1;
            for (int i = 0; i < str_len; ++i) {
                for (int len = max_len+1; len < str_len - i; ++len) {
                    auto sub = s.substr(i, len);
                    if (isPalindromic(sub)) {
                        if (max_len < len) {
                            max_len = len;
                            longest = sub;
                        }
                    }
                }
            }
            return longest;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    Solution s;

    // string test = "flsuqzhtcahnyickkgtfnlyzwjuiwqiexthpzvcweqzeqpmqwkydhsfipcdrsjkefehhesubkirhalgnevjugfohwnlhbjfewiunlgmomxkafuuokesvfmcnvseixkkzekuinmcbmttzgsqeqbrtlwyqgiquyylaswlgfflrezaxtjobltcnpjsaslyviviosxorjsfncqirsjpkgajkfpoxxmvsyynbbovieoothpjgncfwcvpkvjcmrcuoronrfjcppbisqbzkgpnycqljpjlgeciaqrnqyxzedzkqpqsszovkgtcgxqgkflpmrikksaupukdvkzbltvefitdegnlmzeirotrfeaueqpzppnsjpspgomyezrlxsqlfcjrkglyvzvqakhtvfmeootbtbwfhqucbnuwznigoyatvkocqmbtqghybwrhmyvvuchjpvjckiryvjfxabezchynfxnpqaeampvaapgmvoylyutymdhvhqfmrlmzkhuhupizqiujpwzarnszrexpvgdmtoxvjygjpmiadzdcxtggwamkbwrkeplesupagievwsaaletcuxtpsxmbmeztcylsjxvhzrqizdmgjfyftpzpgxateopwvynljzffszkzzqgofdlwyknqfruhdkvmvrrjpijcjomnrjjubfccaypkpfokohvkqndptciqqiscvmpozlyyrwobeuazsawtimnawquogrohcrnmexiwvjxgwhmtpykqlcfacuadyhaotmmxevqwarppknoxthsmrrknu";

    auto sss = s.longestPalindrome("cbbd");
    // auto sss = s.longestPalindrome(test);

    // cout << (Solution::isPalindromic("sbbs")  ? "TRUE" : "FALSE")<< endl;
    cout << sss << endl;

    return 0;
}

