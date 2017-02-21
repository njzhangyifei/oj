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
        Dictionary<int, int> d = BuildDictionary();

        int _n = Int32.Parse(Console.ReadLine());

        int [] _ar = new int[_n];
        for(int _ar_i=0; _ar_i < _n; _ar_i++) {
            String elements = Console.ReadLine();
            String[] split_elements = elements.Split(' ');
             _ar[_ar_i] = Convert.ToInt32(split_elements[0]); 
        }

        Count(d, _ar);

        int cumulativeCount = 0;
        for (int i = 0; i < 100; i++)
        {
            // if (d[i] > 0)
            // {
                // for (int j = 0; j < d[i]; j++)
                // {
                    // Console.Write(i + " ");
                // }
            // }
            cumulativeCount += d[i];
            Console.Write(cumulativeCount + " ");
        }
    }

    static void Count(Dictionary<int,int> d, int[] ar) {
        for (int i = 0; i < ar.Length; i++)
        {
            d[ ar[i] ] ++;
        }
    }

    static Dictionary<int, int> BuildDictionary() {
        Dictionary<int, int> dic = new Dictionary<int, int>();
        for (int i = 0; i < 100; i++)
        {
            dic[i] = 0;
        }
        return dic;
    }
}
