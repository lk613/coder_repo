#include "LRUCache.h"

// 双向链表
struct DLinkedNode
{
    int key;
    int value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int capacity;
    int size;
    DLinkedNode *head;
    DLinkedNode *tail;
    std::unordered_map<int, DLinkedNode *> cache;

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }

        DLinkedNode *node = cache[key];
        // 访问后，最近被使用的节点，需要将其移动到表头
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            DLinkedNode *new_node = new DLinkedNode(key, value);
            cache[key] = new_node;
            addToHead(new_node);
            ++size;
            if (size > capacity)
            {
                // 超出容量，删除双向链表的尾部节点，最久未被访问
                DLinkedNode *tail_node = deleteTail();
                cache.erase(tail_node->key);    
                delete tail_node;
                --size;
            }
        }else
        {
            DLinkedNode *node = cache[key];
            node->value = value;
            // 最新访问，需要移动到表头
            moveToHead(node);
        }
    }

    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    DLinkedNode *deleteTail()
    {
        DLinkedNode *tail_node = tail->prev;
        removeNode(tail_node);
        return tail_node;
    }
};