class LRUCache {
public:
    std::list<int> l; // lr keys
    std::unordered_map<int, pair<int, std::list<int>::iterator>> m;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }

    void touch(int key, int val) {
        if (m.find(key) != m.end()) {
            l.erase(m[key].second);
        }
        l.push_front(key);
        m[key] = make_pair(val,l.begin());
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            // does not exists
            return -1;
        }
        int val = m[key].first;
        touch(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if (m.size() == cap && m.find(key) == m.end()) {
            int key = l.back();
            m.erase(key);
            l.pop_back();
        }
        touch(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */