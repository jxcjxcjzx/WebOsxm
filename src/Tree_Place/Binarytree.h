#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

// the capsule of btree implementation
// realization of the following functions:
// search, insert,remove,create,destory,print

#define BTREE_D 2
#define ORDER (BTREE_D*2)  // defines to 4 level , 2-3-4 tree though

typedef int KeyType;
typedef struct BTNode{
  int keynum;  // number of key words
  KeyType key[ORDER-1];   // key word vector
  struct BTNode *child[ORDER];  // child pointer vector
  bool isLeaf;  // whether is the leaf node
}BTNode;

typedef BTNode *BTree;  // defines a btree

// given the data collection, create a btree
void BTree_create(Btree *tree,const KeyType *data,int length);

// in verse of above, destory a btree
void BTree_destory(BTree *tree);

// insert one key word into the btree
void Btree_insert(BTree *tree,KeyType key);

// remove one key word in btree
void BTree_remove(BTree *tree,KeyType key);

// print all the nodes in the tree
void BTree_print(const BTree tree,int layer = 1);

// find one key word in btree
// return value : *pos if successfully find it,
// null if encounters failure
BTNode* BTree_search(const BTree tree,int key, int *pos);

#endif
