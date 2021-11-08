class LRUCache {
public:
    //key,val
    list<pair<int,int>> kv;
    map<int,list<pair<int,int>>::iterator> dat;
    int len;
    LRUCache(int capacity) {
        len = capacity;
    }
    
    int get(int key) {
        if (dat.count(key)){
            int ans = (*dat[key]).second;
            kv.erase(dat[key]);
            kv.push_front({key,ans});
            dat[key] = kv.begin();
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (dat.count(key)){
            kv.erase(dat[key]);
            kv.push_front({key,value});
            dat[key] = kv.begin();
        }else{
            kv.push_front({key,value});
            dat[key] = kv.begin();
            
        }
        
        if (dat.size()>len){
            dat.erase(kv.back().first);
            kv.pop_back();
        }
            
    }
};

