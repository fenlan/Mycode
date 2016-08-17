#ifndef CMAP_H
#define CMAP_H

#include <vector>
using namespace std;
#include "Node.h"

class CMap
{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);      //向图中加入顶点（结点）
	void resetNode();               //重置顶点
	bool setValueToMatrixForDirectedGraph(int row,int col,int val = 1);      //为有向图设置邻接矩阵
	bool setValueToMatrixForUndirectedGraph(int row,int col,int val = 1);    //为无向图设置邻接矩阵

	void printMatrix();            //打印邻接矩阵

	void depthFirstTraverse(int nodeIndex);          //深度优先遍历
	void breadthFirstTraverse(int nodeIndex);        //广度优先遍历

private:
	bool getValueFromMatrix(int row,int col,int &val);   //从矩阵中获取权值
	void breadthFirstTraverseImpl(vector<int> preVec);    //广度优先遍历实现函数

private:
	int m_iCapacity;         //图中最多可以容纳的顶点数
	int m_iNodeCount;        //已经添加的顶点（结点）个数
	Node *m_pNodeArray;      //用来存放顶点数组
	int *m_pMatrix;          //用来存放邻接矩阵
};

#endif