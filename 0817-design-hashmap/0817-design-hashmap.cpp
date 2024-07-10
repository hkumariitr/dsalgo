class MyHashMap {
public:
    vector<list<pair<int,int>>> buckets;
    int size = 1000;
    MyHashMap() {
        buckets.resize(size);
    }
    
    void put(int key, int value) {
       int b_no = key%size;
       auto &chain = buckets[b_no];
        for(auto &it:chain){
            if(it.first == key){
                it.second = value;
                return;
            }
        }
        chain.push_back({key,value});

    }
    
    int get(int key) {
        int b_no = key%size;
        auto &chain = buckets[b_no];

        if(chain.empty()) return -1;
        
        for(auto &it :chain){
            if(it.first == key){
                return it.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int b_no = key%size;
        auto &chain = buckets[b_no];   

        for(auto it = chain.begin(); it!= chain.end();it++){
            if(it->first == key){
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */