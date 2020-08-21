#ifndef _HashSep_H
#define _HashSep_H
#include <stdio.h>
#include <stdlib.h>

#define Error(Str) FatalError(Str)
#define FatalError(Str) fprintf(stderr, "%s\n", Str), exit(1)
/* Interface for separate chaining hash table */
typedef int ElementType;

typedef unsigned int Index;

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);
/* Routines such as Delete are MakeEmpty are omitted */

#endif /* _HashSep_H */
