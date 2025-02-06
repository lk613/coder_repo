#include "hash_table.h"

/**
 * @brief hash function : key mod HASH_TABLE_SIZE
 * 
 * @param key 
 * @return int 
 */
int hash(int key)
{
    return abs(key) % HASH_TABLE_SIZE;
}

/**
 * @brief initailize hash table
 * 
 * @param hash_table 
 */
void init(HashTable *hash_table)
{
    int i;
    for (i = 0; i < HASH_TABLE_SIZE; i++)
    {
        hash_table->hash_table[i] = NULL;
    }
}

/**
 * @brief insert key-value pair into hash table
 * 
 * @param hash_table 
 * @param key 
 * @param value 
 */
void insert(HashTable *hash_table, int key, int value)
{
    int idx = hash(key);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = hash_table->hash_table[idx];
    hash_table->hash_table[idx] = new_node;         // insert at head , link address method
}

/**
 * @brief search key in hash table
 * 
 * @param hash_table 
 * @param keyt 
 * @return int 
 */
int search(HashTable *hash_table, int key)
{
    int idx = hash(key);
    Node *cur_node = hash_table->hash_table[idx];
    
    while (NULL != cur_node)
    {
        if (cur_node->key == key)
        {
            return cur_node->value;
        }
        cur_node = cur_node->next;
    }

    return -1;      // not found
}

/**
 * @brief free hash table address
 * 
 * @param hash_table 
 */
void freeHashTable(HashTable *hash_table)
{
    int i;

    for (i = 0; i < HASH_TABLE_SIZE; i++)
    {
        Node *cur_node = hash_table->hash_table[i];
        while (NULL != cur_node)
        {
            Node *temp = cur_node;
            cur_node = cur_node->next;
            free(temp);
        }
        hash_table->hash_table[i] = NULL;
    }
}
