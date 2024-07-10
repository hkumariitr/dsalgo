// class Node{
// public:
//     int data;
//     Node* next;
//     Node(int data1,Node* next1){
//         data = data1;
//         next = next1;
//     }
//     Node(int data1){
//         data = data1;
//         next = nullptr;
//     }
//     Node(){
//         data = NULL;
//         next = nullptr;
//     }
// };

class MyHashSet {
public:
    vector<int> m;
    int size;
    MyHashSet() {
        size = 1e6+1;
        m.resize(size);
    }
    
    void add(int key) {
        m[key] = 1;
    }
    
    void remove(int key) {
        m[key]=0;
    }
    
    bool contains(int key) {
        return m[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */