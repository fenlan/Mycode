/*Author:fenlan
  function:use Binary Sort Tree to search
  date:2016.11.27
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node{
    ElemType key;
    Node *Lchild, *Rchild;
}BST_node, *BST;

bool Insert_node(BST &root, ElemType key);
//插入elem 到二叉排序树中
bool Delect(BST &root, ElemType key);
//从二叉排序树中删除存在的元素，若返回false ,表示没有关键字
bool Delect_node(BST &node);
//在二叉排序树中删除指定结点
bool Search(BST &root, ElemType key, BST &address);
//查找key ，没有找到返回false,找到返回所在结点指针

int main ()
{
    BST root = NULL;
    BST address;

    Insert_node(root, 45);
    if (Search(root, 45, address))     printf("the key exists! The address: %d, the root :%d\n", address, root);
    else                               printf("the key doesn't exist!\n");

    if (Delect(root, 45)){
        if (Search(root, 45, address))     printf("the key exists! The address: %d, the root :%d\n", address, root);
        else                               printf("the key doesn't exist!\n");
    }
    return 0;
}

bool Insert_node(BST &root, ElemType key){
    if (root == NULL){
        BST_node *new_node;
        new_node = (BST_node *)malloc(sizeof(BST_node));
        if (!new_node)           exit(0);
        else {
            new_node->key = key;
            new_node->Lchild = NULL;
            new_node->Rchild = NULL;
            root = new_node;
        }
        return true;
    }
    else if (key == root->key){
        printf("the key aleady exists!\n");
        return false;
    }
    else if (key < root->key){
        if (Insert_node(root->Lchild, key))        return true;
        else                                       return false;
    }
    else {
        if (Insert_node(root->Rchild, key))        return true;
        else                                       return false;
    }
}//Insert_node

bool Delect(BST &root, ElemType key){
    if (!root)       return false;
    else {
        if (key == root->key)       return  Delect_node(root);
        else if (key < root->key)  return Delect(root->Lchild, key);
        else                        return Delect(root->Rchild, key);
    }
}//Delect

bool Delect_node(BST &node){
    if (!node->Rchild){                  //右子树为空，接左子树
        BST q = node;
        node = node->Lchild;
        free(q);
    }
    else if (!node->Lchild){             //左孩子为空，接右子树
        BST q = node;
        node = node->Rchild;
        free(q);
    }
    else {                                //左右子树均不为空，取左子树中最大值赋值给结点
        BST q = node, s = node->Lchild;
        while (s->Rchild) {               //从左子树往下一直取右子树到最下角，该值为左子树中最大的子树
            q = s;
            s = s->Rchild;
        }
        node->key = s->key;
        if (q != node)    q->Rchild = s->Lchild;
        else              q->Lchild = s->Lchild;
        free(s);
    }
    return true;
}//Delect_node

bool Search(BST &root, ElemType key, BST &address){
    if (root == NULL)                                 return false;
    else if (key == root->key){
        address = root;
        return true;
    }
    else if (key < root->key){
        if(Search(root->Lchild, key, address))        return true;
        else                                          return false;
    }
    else{
        if (Search(root->Rchild, key, address))       return true;
        else                                          return true;
    }
}//Search
