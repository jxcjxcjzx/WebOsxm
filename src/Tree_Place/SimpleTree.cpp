#include "SimpleTree.h"


bool IsBalanced(BinaryTreeNode* pRoot,int* pDepth)
{
if(pRoot==NULL)
{
*pDepth=0;
return true;
}

int left,right;
if(IsBalanced(pRoot->m_pLeft,&left)&&IsBalanced(pRoot->m_pRight,&right))
{
int diff = left-right;
if(diff<=1&&diff>=-1)
{
*pDepth = 1+(left>right?left:right);
return true;
}
}
return false;
}

