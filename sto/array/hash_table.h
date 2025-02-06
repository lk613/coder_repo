#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>

#define HASH_TABLE_SIZE 1000

/**
 * @brief hash table node struct
 * 
 */
typedef struct Node
{
    int key;                    // save array element
    int value;                  // save array index
    struct Node *next;
}Node;

/**
 * @brief hash table struct
 * 
 */
typedef struct HashTable
{
    Node *hash_table[HASH_TABLE_SIZE];
}HashTable;

extern int hash(int key);
extern void init(HashTable *hash_table);
extern void insert(HashTable *hash_table, int key, int value);
extern int search(HashTable *hash_table, int key);
extern void freeHashTable(HashTable *hash_table);
#endif // HASH_TABLE_H
