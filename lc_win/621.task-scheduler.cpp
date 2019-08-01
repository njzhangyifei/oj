class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        priority_queue<int, vector<int>, std::less<int>> freq;

        for (int i = 0; i < tasks.size(); ++i) {
            map[tasks[i]] += 1;
        }

        for (auto p : map) {
            freq.push(p.second);
        }

        int cycle = n+1;

        int t = 0;
        while (!freq.empty()) {
            int i = 0;
            vector<int> next_freq;
            while (i < cycle) {
                if (!freq.empty()) {
                    int f = freq.top();
                    if (f > 1) {
                        next_freq.push_back(f-1);
                    }
                    freq.pop();
                }
                ++t;
                if (next_freq.empty() && freq.empty()) {
                    break;
                }
                ++i;
            }
            for (int i = 0; i < next_freq.size(); ++i) { 
                freq.push(next_freq[i]);
            }
        }

        return t;
    }
};
