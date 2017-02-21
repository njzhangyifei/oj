#!/bin/python3

import sys

Q = int(input().strip())
for a0 in range(Q):
    n = int(input().strip())
    b = input().strip()
    char_map = {}
    for ch in b:
        if ch in char_map:
            char_map[ch] += 1
        else:
            char_map[ch] = 1

    print(char_map)




