#include "unordered_map"
#include "iostream"
using namespace std;
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
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
    unordered_map<int, Node *> keyMap;
    Node *head, *tail;
    void remove(int key, bool earse)
    {
        Node *node = keyMap[key];
        node->next->prev = node->prev;
        node->prev->next = node->next;
        if (earse)
        {
            keyMap.erase(key);
            delete node;
        }
    }
    void appendHead(int key, int value)
    {
        Node *node = new Node();
        node->key = key, node->value = value;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        keyMap[key] = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        head = new Node(), tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        if (keyMap.find(key) == keyMap.end())
            return -1;
        int val = keyMap[key]->value;
        remove(key, false);
        appendHead(key, val);
        return val;
    }

    void put(int key, int value)
    {
        if (keyMap.find(key) != keyMap.end())
            remove(key, false);
        else if (keyMap.size() >= capacity)
            remove(tail->prev->key, true);
        appendHead(key, value);
    }
};
// @lc code=end
