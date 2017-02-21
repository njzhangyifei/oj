### Problem Statement
[Problem](https://www.hackerrank.com/challenges/task-scheduling)

### INPUT

```                
5
2 2
1 1
4 3
10 1
2 1
```

---------------------
| Task |  D   |  M  |
---------------------
|  2   |  1   |  1  |
---------------------
|  1   |  2   |  2  |
---------------------
|  5   |  2   |  1  |
---------------------
|  3   |  4   |  3  |
---------------------
|  4   |  10  |  1  |
---------------------



### Schedule
 - first two task

```
time 1: task 2             t = 1, priority => D-t-R   t1.p = 2-1-2=-1  t2.p = 1-1-1=-1
time 2: task 1             t = 2                      t1.p = 2-2-2=-2  t2.p = 1-2-0=-1
time 3: task 1             t = 3                      t1.p = 2-3-1=-2  t2.p = 1-3-0=-2                       

We've overshot task 1 by 1 minute, hence returning 1. 
```

 - first three task

```
time 1 : task 2 
time 2 : task 1 
time 3 : task 3 
time 4 : task 1 
time 5 : task 3 
time 6 : task 3

=> 2
```


