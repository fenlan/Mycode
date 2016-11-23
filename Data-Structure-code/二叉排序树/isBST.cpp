/*
author:fenlan
function:判断一个二叉树是否为二叉排序树
date:2016年11月23日
*/
bool isBSTInOrder(BinaryTree *root)
{
    int prev = INT_MIN;
    return isBSTInOrderHelper(root, prev);
}
//该函数判断二叉树是否为二叉排序树，且其结点都大于prev
//思路：二叉排序树的中序遍历结果从小到大排列
bool isBSTInOrderHelper(BinaryTree *p, int &prev)
{
    if (!p)   return true;
    if (isBSTInOrderHelper(p->left, prev)) //判断左子树的值是否大于prev,此处开始递归
    {
        if (p->data > prev)    //判断当前值是否大于prev
        {
            prev = p->data;       //从中序遍历的第一个值开始逐个更新prev的值
            return isBSTInOrderHelper(p->right, prev); //判断右子树的值是否大于prev
        }
        else
            return false;
    }
    else
        return false;
}
