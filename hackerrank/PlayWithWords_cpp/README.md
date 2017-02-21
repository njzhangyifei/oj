### Problem Statement
https://www.hackerrank.com/challenges/strplay

### Thoughts
This is pretty much the longest parlindrome subsequence problem.

- Build a N * N size array, `A[i][j]` will represent the length of LPS 
from index i to j (use standard lps memorization algo)
- Because the problem stated that two subsequences do not cross each other, we
will just go through all the indexes where a seperation is possible.
