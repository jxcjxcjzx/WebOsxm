#ifndef DICTREE_H
#define DICTREE_H

#define MAX 128
typedef struct Trie
{
Trie* child[MAX];
int time;  // you can make changes to this if you need
}DicTreeNode,*DicTreeNodePtr;
#endif
