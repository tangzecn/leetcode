#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class CacheNode {
public:
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {} 
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        if (indexMap.find(key) == indexMap.end()) return -1;
        list<CacheNode>::iterator nodePosition = indexMap[key];
        CacheNode cacheNode = *nodePosition;
        cacheList.erase(nodePosition);
        cacheList.push_front(cacheNode);
        indexMap[key] = cacheList.begin();
        return cacheNode.value;
    }
    
    void set(int key, int value) {
        if (get(key) != -1) {
            indexMap[key]->value = value;    
        } else {
            if (cacheList.size() >= capacity) {
                indexMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            CacheNode cacheNode(key, value);
            cacheList.push_front(cacheNode);
            indexMap[key] = cacheList.begin();
        } 
    }

private:
    int capacity;
    unordered_map<int, list<CacheNode>::iterator> indexMap;
    list<CacheNode> cacheList;
};

int main() {
	return 0;
}