#include <bits/stdc++.h>
using namespace std;
struct LListNode
{
    int key;
    int value;
    LListNode *pre;
    LListNode *next;
    LListNode() : key(0), value(0), pre(nullptr), next(nullptr) {}
    LListNode(int _key, int _value) : key(_key), value(_value), pre(nullptr), next(nullptr) {}
};
class LRUCache
{
private:
    unordered_map<int, LListNode *> cache;
    LListNode *head;
    LListNode *tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity) : size(0), capacity(_capacity)
    {
        head = new LListNode();
        tail = new LListNode();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
        {
            //if cache don't have the node
            return -1;
        }
        else
        {
            //if cache has the node
            LListNode *t = cache[key];
            moveToHead(t);
            return t->value;
        }
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            //if don't have
            LListNode *t = new LListNode(key, value);
            cache[key] = t;
            addToHead(t);
            ++size;
            if (size > capacity)
            {
                LListNode *temp = deleteTail();
                cache.erase(temp->key);
                delete temp;
                --size;
            }
        }
        else
        { //if have
            LListNode *t = cache[key];
            t->value = value;
            moveToHead(t);
        }
    }

    void addToHead(LListNode *node)
    {
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }

    void deleteNode(LListNode *node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void moveToHead(LListNode *node)
    {
        deleteNode(node);
        addToHead(node);
    }

    //return ListNode* because We will delete it and remove it on cache
    LListNode *deleteTail()
    {
        LListNode *t = tail->pre;
        deleteNode(t);
        return t;
    }
};
int main()
{
    //test data
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << " ";
    obj->put(3, 3);
    cout << obj->get(2) << " ";
    obj->put(4, 4);
    cout << obj->get(1) << " ";
    cout << obj->get(3) << " ";
    cout << obj->get(4) << " ";
}
