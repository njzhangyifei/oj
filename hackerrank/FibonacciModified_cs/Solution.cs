using System;
using System.Numerics;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        /* 
         * Enter your code here. Read input from STDIN. 
         * Print output to STDOUT. Your class should be named Solution
         *
         */
        string input = Console.ReadLine();
        string[] s = input.Split();
        
        int a = Int32.Parse(s[0]);
        int b = Int32.Parse(s[1]);
        int n = Int32.Parse(s[2]);
        
        List<BigInteger> l = new List<BigInteger>();

        l.Add(new BigInteger(a));
        l.Add(new BigInteger(b));

        for (int i = 0; i < n-2; i++)
        {
            BigInteger t_n = l[i];
            BigInteger t_n1 = l[i+1];
            BigInteger t_n2 =  t_n1 * t_n1 + t_n;
            l.Add(t_n2);
        }

        Console.WriteLine(l[l.Count -1]);
    }
}
