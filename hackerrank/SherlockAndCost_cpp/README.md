### Problem Statement
    Given an array B, we want to find an array A for which A_i < B_i for all i. The
    array A also need to maximize the cost, S = sum(abs(A_i, A_{i-1}))

### Optimal Structure

See Editorial.

A[i] has to be either 1 or B[i] to make S the largest
