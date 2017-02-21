using System;
using System.Text;
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
        string [] _s = new string [_n];
        for (int i = 0; i < _n; i++)
        {
            _s[i] = Console.ReadLine();
        }

        for (int i = 0; i < _n; i++)
        {
            Console.WriteLine( NextPermutation(_s[i]) );
        }
    }
    
    static string NextPermutation(string s) {
        char [] charArray = s.ToCharArray();
        List<char> l = new List<char>(charArray); 
        if (l.Count == 1)
        {
            return "no answer";
        }

        for (int i = 2; i < (l.Count+1); i++)
        {
            // at least 2 elements got changed
            int posToCheck = (l.Count - i);
            char charToCheck = l[posToCheck];

            char [] remaining = new char[l.Count - posToCheck];
            Array.Copy(charArray, posToCheck, remaining, 0, l.Count-posToCheck);
            Array.Sort(remaining);

            List<char> sorted = new List<char>(remaining); 
            List<char> uniq = new List<char>(); 
            char lastChar = sorted[0];
            for (int j = 1; j < sorted.Count; j++)
            {
                if (sorted[j] != lastChar)
                {
                    lastChar = sorted[j];
                    uniq.Add(lastChar);
                }
            }

            int firstOccr = uniq.IndexOf(charToCheck);
            if (firstOccr != (uniq.Count-1))
            {
                // not the biggest
                return buildString(l, sorted, posToCheck, uniq[firstOccr+1]);
            }
        }

        return "no answer";
    }

    static string buildString(
            List<char> original,
            List<char> sorted,
            int posToChange,
            char c) {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < posToChange; i++)
        {
            builder.Append(original[i]);
        }
        builder.Append(c);
        sorted.Remove(c);
        while (sorted.Count > 0)
        {
            builder.Append(sorted[0]);
            sorted.RemoveAt(0);
        }
        return builder.ToString();
    }

}
