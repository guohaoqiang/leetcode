class LFUCache {
public:
    int size;
    // frequency, key-list
    map<int,list<int>> f_k;
    // key, {val,frequency}
    unordered_map<int,pair<int,int>> kvf;
    // key, aand its iterator in f_k
    unordered_map<int,list<int>::iterator> k_it;
    LFUCache(int capacity) {
        size = capacity;
    }
    int get(int key) {
        if (kvf.count(key)){
            update(key);
            return kvf[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (size==0)    return;
        if (kvf.count(key)){
            update(key);
            kvf[key].first = value;
        }else{
            if (kvf.size()==size){
                int evict_key = (*f_k.begin()).second.back();
                (*f_k.begin()).second.pop_back();
                if ((*f_k.begin()).second.empty()){
                    f_k.erase(f_k.begin());
                }
                kvf.erase(evict_key);
                k_it.erase(evict_key);
            }
            kvf[key] = pair<int,int>(value,1);
            //kvf[key] = {value,1};
            f_k[1].push_front(key);
            k_it[key] = f_k[1].begin();
        }
    }
    void update(int key){
        auto it = k_it[key];
        int freq = kvf[key].second++;
        
        f_k[freq].erase(it);
        if (f_k[freq].empty()){
            f_k.erase(freq);
        }
        f_k[freq+1].push_front(key);
        
        k_it[key] = f_k[freq+1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
