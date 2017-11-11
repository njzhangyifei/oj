### Problem Statement

Given an array of flower heights, bloom time and wilt time.
Find an arrangement so that the tallest flowers as forward as possible without
blocking sunlight.

### Draft Space

Total amount of Arrangement = ?
 - N!

Approach:
 - Preprocess the block/no block for each N^2 pair

Say the type of flower we plant is a function of position
`f(p) = {t_0, t_1, ..., t_(p-1)}`. Given that we've found a method for p = n,
so that we have an possible order `{t_0, t_1, ..., t_(n-1)}`, we know that
`{t_0, t_1, ..., t_(n-k)}` is also a possible plant order given any k < n.

 - Therefore, the subproblem is to generate plant order for k, k < n.
 - How do we put together these subproblems ?
    - `{t_0, t_1, ..., t_(n-k)}` is a possible arrangement, we check for the
        next to-be-planted flower.

Reverse Order?
O(n^2)?
 - First try the smallest one, push into vec
 - Check if the second smallest one would block it, if blocking, put behind it,
    otherwise, put in front of it.
 - Check if the third smallest one would block the second one, if blocking the
    second one, check with the first, eventually we will find a place for the plant
