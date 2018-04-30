#include "DicTree.h"
#include <stdio,h>
#include <string.h>

// here we provide all the tree operations 
// in the seperated form , and later you must
// implement the manage class to have this
// all wrapped by yourself
static DicTreeNodePtr g_root = NULL;

void insert(const char* str)
{
int i=0;
int len = strlen(str);
DicTreeNodePtr prePtr = NULL:
DicTreeNodePtr nxtPtr = NULL:

if(!g_root)
{
g_root = (DicTreeNodePtr)malloc(sizeof(DicTreeNode));
memset(g_root,0,sizeof(DicTreeNode));
}
prePtr = g_root;

for(i=0;i<len;i++)
{
nxtPtr = prePtr->child[str[i]];
if(!nxtPtr)
{
nxtPtr = (DicTreeNodePtr)malloc(DicTreeNode);
memset(nxtPtr,0,sizeof(DicTreeNode));
}
prePtr->child[str[i]] = nxtPtr;
prePtr = nxtPtr;
if(i==len-1){
	++(prePtr->times);
}

}

}

int search(const char* str)
{
int i=0;
int len = strlen(str);
DicTreeNodePtr prePtr = NULL:
DicTreeNodePtr nxtPtr = NULL:

if(!g_root){
	return 0;
}
prePtr = g_root;

for(i=0;i<len;i++)
{
nxtPtr = prePtr->child[str[i]];
if(!nxtPtr)
{
return 0;
}
prePtr = nxtPtr;
}
return prePtr->times;
}

// here we just need the main function for testing purpose
int main()
{


return 0;
}
