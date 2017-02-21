using System;
using System.Linq;
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
            int _len = Int32.Parse(Console.ReadLine());
            int [] _ar = new int[_len];
            String elements = Console.ReadLine();
            String[] split_elements = elements.Split(' ');
            for(int _ar_i=0; _ar_i < _len; _ar_i++) {
                  _ar[_ar_i] = Convert.ToInt32(split_elements[_ar_i]); 
            }           
            Console.WriteLine(FindPairs(_ar));
        }
    }

    static long FindPairs(int [] ar) {
        Dictionary<int,long> d = new Dictionary<int, long> ();
        long pairs = 0;
        for (int i = 0; i < ar.Length; i++)
        {
            if (d.Keys.Contains(ar[i]))
            {
                d[ar[i]]++;
            } else {
                d[ar[i]] = 1;
            }
        }

        pairs = d.Values.Select(x => ((x-1) * (x))).Aggregate((x,y) => (x+y));

        return (pairs);
    }
}
