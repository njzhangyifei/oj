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
        int _n = Int32.Parse(Console.ReadLine());
        for (int i = 0; i < _n; i++)
        {
            Console.WriteLine(FindDigit(Console.ReadLine()));
        }
    }

    static int FindDigit(string str) {
        int num = Int32.Parse(str);
        int t = num;
        int count = 0;
        while (t != 0)
        {
            if (t % 10 != 0)
            {
                if ((num % (t % 10)) == 0)
                {
                    count ++;
                }               
            }
            t = t / 10;
        }
        return count;
    }
}
