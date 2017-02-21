using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        /* 
         * Enter your code here. Read input from STDIN. 
         * Print output to STDOUT. Your class should be named Solution
         *
         */
        string s = Console.ReadLine();
        string[] s_array = s.Split();
        int M = Int32.Parse(s_array[0]);
        int R = Int32.Parse(s_array[1]);
        int S = Int32.Parse(s_array[2]);
        s = Console.ReadLine();
        s_array = s.Split();
        int[] arr = new int[M];
        for (int i = 0; i < M; i++)
        {
            arr[i] = Int32.Parse(s_array[i]);
        }
        Int64 res = Solve(M, R, S, arr);
        Console.WriteLine(res);
    }

    static Int64 Solve(int M, int R, int S, int[] arr) {

        int a_sum = (R+S)/2;
        int b_sum = (R-S)/2;
        if (Math.Min(a_sum, b_sum) < 0)
        {
            return 0;
        }
        int max_sum = Math.Max(a_sum, b_sum);

        Int64[,] res = new Int64[M+1,max_sum+1];
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < max_sum; j++)
            {
                res[i,j] = 0;
            }
            
        }

        res[0,0] = 1;
        for (int i = M-1; i >= 0; i--)
        {
            // starting from element m-1 -> element 0
            // which means the max length goes from (M-M+1) to M-0
            for (int j = (M-i); j > 0; j--)
            {
                for (int k = max_sum; k >= 0; k--)
                {
                    int element = arr[i];
                    if (element <= k)
                    {
                        int remaining = k - element;
                        res[j,k] = (res[j,k] + res[j-1,remaining]) % 1000000007;
                    }
                }
            }
        }

        Int64 total = 0;
        // length 1 -> length M
        for (int i = 1; i < M+1; i++)
        {
            total  = (total + (res[i,a_sum] * res[i,b_sum]) % 1000000007) % 1000000007;
        }

        return total;
    }
}
