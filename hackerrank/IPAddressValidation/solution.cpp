#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;
bool testv6(string ip){
    // (4 + 1) * 7 + 4
    if (ip.length() < 15 || ip.length() > (39)) {
        return false;
    }
    uint64_t ip_v[8] = {0};

    int num = sscanf(ip.c_str(),"%X:%X:%X:%X:%X:%X:%X:%X", 
            &(ip_v[0]),
            &(ip_v[1]),
            &(ip_v[2]),
            &(ip_v[3]),
            &(ip_v[4]),
            &(ip_v[5]),
            &(ip_v[6]),
            &(ip_v[7])
            );
    if (num != 8) {
        return false;
    }

    int i;
    for (i = 0; i < 8; ++i) {
        if (ip_v[i] > 0xFFFF) {
            return false;
        }
    }
    return true;
}

bool testv4(string ip){
    int ip_v[4] = {0};
    char * t = new char[ip.length()];
    if (ip.length() < (4 + 3) || ip.length() > (3+3+3+3+3)) {
        return false;
    }

    int num = sscanf(ip.c_str(),"%d.%d.%d.%d%s", 
            &(ip_v[0]),
            &(ip_v[1]),
            &(ip_v[2]),
            &(ip_v[3]),
            t
            );
    if (num != 4) {
        return false;
    }

    int i;
    for (i = 0; i < 4; ++i) {

        if (ip_v[i] > 255 || ip_v[i] < 0) {
            return false;
        }
    }

    return true;
}
/*
 * Complete the function below.
 */
vector < string > checkIP(vector < string > ip) {
    std::vector<string> v;
    int i= 0;
    for (i = 0; i < ip.size(); i++) {
        bool v4 = testv4(ip[i]);
        bool v6 = testv6(ip[i]);
        if (v4) {
            v.push_back("IPv4");
        } else if (v6) {
            v.push_back("IPv6");
        } else {
            v.push_back("Neither");
        }
    }
    return v;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<string> ips = {
        "123.123.123.123",
        "123.123.123.123",
        "123.123.123.256",
        "2001:0db8:0000:0000:0000:ff00:0042:8329",
        "0:0db8:0000:0000:0000:ff00:0042:8329",
        "FFFFF:0db8:0000:0000:0000:ff00:0042:8329",
        "0:0db8:t0000:0000:0000:ff00:0042:8329",
        "0:0db8:0000:0000:0000:ff00::8329",
        "0:0db8:0000:0000:0000:ff00:0000:8329",
        "0:0:0:0:0:f:0:8",
        // (4 + 1) * 7 + 4
        "test"
    };

    auto v = checkIP(ips);
    for (auto i : v) {
        cout << i<< endl;;
    }

    return 0;
}

