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
            string s = Console.ReadLine();
            Console.WriteLine(isFunny(s) ? "Funny" : "Not Funny");
        }
    }

    static bool isFunny(string s) {
        char[] ch = s.ToCharArray();
        for (int i = 0; i < (ch.Length/2); i ++) {
            if ( Math.Abs(ch[i+1] - ch[i]) != 
                    Math.Abs(ch[ch.Length - i -1] - ch[ch.Length - i - 2]))
            {
                return false;
            }
        }
        return true;
    }
}
