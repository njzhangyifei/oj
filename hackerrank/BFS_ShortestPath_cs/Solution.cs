using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Solve(){
        string input;
        int numNode, numEdge;
        input = Console.ReadLine();
        string[] s = input.Split();
        numNode = Int32.Parse(s[0]);
        numEdge = Int32.Parse(s[1]);
        bool[,] graph = new bool[numNode,numNode];
        for (int i = 0; i < numEdge; i++)
        {
            input = Console.ReadLine();
            string[] s_edge = input.Split();
            int from = Int32.Parse(s_edge[0]);
            int to = Int32.Parse(s_edge[1]);
            graph[from-1, to-1] = true;
            graph[to-1, from-1] = true;
        }

        input = Console.ReadLine();
        int start = Int32.Parse(input);
        start --;

        int[] path = new int[numNode];
        for (int i = 0; i < numNode; i++)
        {
            path[i] = -1;
        }
        path[start] = 0;
        Queue<int> q = new Queue<int>();
        q.Enqueue(start);

        while (q.Count > 0) {
            int currentNode = q.Dequeue();
            int currentPath = path[currentNode];
            for (int i = 0; i < numNode; i++)
            {
                if (graph[currentNode, i] && path[i] == -1)
                {
                    // not visited and exists an edge
                    path[i] = currentPath + 6;
                    q.Enqueue(i);
                }
            }
        }

        for (int i = 0; i < numNode; i++)
        {
            if (i == start)
            {
                continue;
            }
            Console.Write(path[i]);
            Console.Write(" ");
        }
        Console.WriteLine();
    }

    static void Main(String[] args) {
        /* 
         * Enter your code here. Read input from STDIN. 
         * Print output to STDOUT. Your class should be named Solution
         *
         */
        string input;
        int t;
        input = Console.ReadLine();

        t = Int32.Parse(input);
        for (int i = 0; i < t; i++)
        {
            Solve();
        }
    }
}
