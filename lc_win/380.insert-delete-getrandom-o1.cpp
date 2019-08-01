class RandomizedSet {
public:
    unordered_set<int> s;

    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (s.find(val) == s.end()) {
            s.insert(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (s.find(val) != s.end()) {
            s.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int k = 1;
        int val = 0;
        for (auto it = s.begin(); it != s.end(); ++it) {
            bool selected = ((rand() % k) == 0);
            if (selected) {
                val = *it;
            }
            k += 1;
        }
        return val;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
