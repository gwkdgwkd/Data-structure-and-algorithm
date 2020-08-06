#ifndef _Splay_H
#define _Splay_H
#include <stdio.h>
#include <stdlib.h>

#define Error(Str) FatalError(Str)
#define FatalError(Str) fprintf(stderr, "%s\n", Str), exit(1)

typedef int ElementType;
#define Infinity 30000
#define NegInfinity (-30000)

struct SplayNode;
typedef struct SplayNode *SplayTree;

SplayTree MakeEmpty(SplayTree T);
SplayTree Find(ElementType X, SplayTree T);
SplayTree FindMin(SplayTree T);
SplayTree FindMax(SplayTree T);
SplayTree Initialize(void);
SplayTree Insert(ElementType X, SplayTree T);
SplayTree Remove(ElementType X, SplayTree T);
ElementType Retrieve(SplayTree T); /* Gets root item */

#endif /* _Splay_H */
