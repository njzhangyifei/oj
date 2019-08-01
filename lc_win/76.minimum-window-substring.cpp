class Solution
{
  public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> m;

        for (int i = 0; i < t.size(); ++i)
        {
            m[t[i]] += 1;
        }

        int d = INT_MAX;
        int counter = t.size();
        int head = 0;
        int begin = 0;
        int end = 0;

        while (end < s.size())
        {
            char ch = s[end];
            if (m.find(ch) != m.end())
            {
                if (m[ch] > 0)
                {
                    counter -= 1;
                }
                m[ch] -= 1;
            }
            end += 1;

            while (counter == 0)
            {
                // valid
                int len = end - begin;
                if (len < d)
                {
                    d = len;
                    head = begin;
                }

                char ch_b = s[begin];
                if (m.find(ch_b) != m.end())
                {
                    if (m[ch_b] == 0)
                    {
                        counter += 1;
                    }
                    m[ch_b] += 1;
                }
                begin += 1;
            }
        }
        if (d == INT_MAX)
        {
            return "";
        }
        return s.substr(head, d);
    }
};
