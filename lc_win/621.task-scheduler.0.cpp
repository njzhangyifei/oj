class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (int i = 0; i < tasks.size(); ++i) {
            freq[tasks[i] - 'A'] += 1;
        }

        sort (freq.rbegin(), freq.rend());

        int max_val = freq[0]-1;
        int total = max_val * n;

        for (int i = 1; i < freq.size(); ++i) {
            total -= min(freq[i], max_val);
        }

        if (total < 0) {
            return tasks.size();
        } else {
            return tasks.size() + total;
        }

    }
};
