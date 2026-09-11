#include <iostream>
#include <unordered_map>

using namespace std;


struct Node{
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

// time: O(1), space: O(1)
class LRUCache {
int cap;
unordered_map<int, Node*> cache;
Node left, right;

public:
    LRUCache(int capacity) : left(0, 0), right(0, 0){
        cap = capacity;
        left.next = &right;
        right.prev = &left;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }  
    
    void insert(Node* node){
        right.prev->next = node;
        node->prev = right.prev;
        node->next = &right;
        right.prev = node;
    }      
    
    int get(int key) {
        if(cache.count(key)){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            Node* node = cache[key];
            remove(node);

            node->value = value;
            
            insert(node);
            return;
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode); 
        
        if(cache.size() > cap){
            Node* lru = left.next;
            
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};