class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    void remove(Node* node){
        Node* nxt = node->next;
        Node* prv = node->prev;
        nxt->prev = prv;
        prv->next = nxt;
    }
    void insert(Node* node){
        Node* prv = right->prev;
        prv->next = node;
        node->prev = prv;
        node->next = right;
        right->prev = node;
    }

    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }

        Node* nw = new Node(key,value);
        cache[key] = nw;
        insert(nw);
        if(cache.size() > cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */