/*
	程序：二叉树简单操作
	内容：二叉树创建、先序递归遍历、中序递归遍历、后序遍历递归
*/


#include <stdio.h>
#include <stdlib.h>

#define TElemType char

typedef struct BiTnode {
	TElemType date;
	struct BiTnode *lchild, *rchild;
}BiTnode, *BiTree;

bool CreateBiTree(BiTree &root);
//创建二叉树

void pre_order(BiTree &root);
//先序遍历

void middle_order(BiTree &root);
//中序遍历

void post_order(BiTree &root);
//后序遍历

int main() {

	BiTree root;

	CreateBiTree(root);

	pre_order(root);
	middle_order(root);
	post_order(root);

	system("pause");
	return 0;
}

bool CreateBiTree(BiTree &root) {
	char ch;
	scanf("%c", &ch);
	
	if (ch == '\n')            scanf("%c", &ch);               //排除回车键
	if (ch == '.')     root = NULL;
	else {
		if (!(root = (BiTree)malloc(sizeof(BiTnode))))
			exit(0);
		root->date = ch;
		CreateBiTree(root->lchild);
		CreateBiTree(root->rchild);
	}

	return true;
}

void pre_order(BiTree &root) {
	if (root != NULL) {
		printf("%c ", root->date);
		pre_order(root->lchild);
		pre_order(root->rchild);
	}
}
 
void middle_order(BiTree &root) {
	if (root != NULL) {
		middle_order(root->lchild);
		printf("%c ", root->date);
		middle_order(root->rchild);
	}
}

void post_order(BiTree &root) {
	if (root != NULL) {
		post_order(root->lchild);
		post_order(root->rchild);
		printf("%c ", root->date);
	}
}