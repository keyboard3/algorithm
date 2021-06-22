#include "unordered_map"
using namespace std;

struct Node
{
    int key;
    int value;
    Node *prev, *next;
};
class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node> keyMap;
    Node head, tail;
    void remove(int key)
    {
        keyMap[key].next->prev = keyMap[key].prev;
        keyMap[key].prev->next = keyMap[key].next;
        keyMap.erase(key);
    }
    void appendHead(int key, int value)
    {
        keyMap[key].key = key, keyMap[key].value = value;
        keyMap[key].next = head.next;
        head.next->prev = &keyMap[key];
        head.next = &keyMap[key];
        keyMap[key].prev = &head;
    }

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        head.next = &tail;
        tail.prev = &head;
    }
    int get(int key)
    {
        if (keyMap.find(key) == keyMap.end())
            return -1;
        int val = keyMap[key].value;
        remove(key);
        appendHead(key, val);
        return val;
    }

    void put(int key, int value)
    {
        if (keyMap.find(key) != keyMap.end())
            remove(key);
        else if (keyMap.size() >= capacity)
            remove(tail.prev->key);
        appendHead(key, value);
    }
};