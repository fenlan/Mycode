/*Author:fenlan
 *function:
 *date:2016-12-25
 */
 #include <stdio.h>
 #include <stdlib.h>

 #define MAXNODE  100
 #define MAXINT  100000

 // 各数组都从下标1开始
 int dist[MAXNODE];                                 // 表示当前点到源点的最短路径长度
 int prev_node[MAXNODE];                                 // 某顶点最短路径的前一个顶点
 int c[MAXNODE][MAXNODE];                           // 图的邻接矩阵
 int Nodenum, Edgenum;                              // 图的结点数和边数
 int source = 0;                                    // 源点

void Dijkstra(int Nodenum, int source, int *dist, int *prev_node, int c[MAXNODE][MAXNODE]);
//Dijkstra 核心算法， 参数： 顶点数， 源点， 顶点到源点最短路径长度， 顶点最短路径上的前一顶点， 邻接矩阵

int main()
{
   int p = 0, q = 0, weight = 0;

   printf("Enter node number:");
   scanf("%d", &Nodenum);

   printf("Enter edge number:");
   scanf("%d", &Edgenum);

   printf("Enter source node:");
   scanf("%d", &source);

   // 初始化c[][]为maxint
   for(int i=1; i<=Nodenum; ++i)
       for(int j=1; j<=Nodenum; ++j)
           c[i][j] = MAXINT;

   for(int i=1; i<=Edgenum; ++i)
   {
       printf("Enter edge[%d].p:", i);
       scanf("%d", &p);
       printf("Enter edge[%d].q:", i);
       scanf("%d", &q);
       printf("Enter edge[%d].weight:", i);
       scanf("%d", &weight);

       c[p][q] = weight;
       //c[q][p] = weight;      // 当图为无向图时取消注释
   }

   for(int i=1; i<=Nodenum; ++i)
       dist[i] = MAXINT;
   for(int i=1; i<=Nodenum; ++i)              //debug
   {
       for(int j=1; j<=Nodenum; ++j)
           printf("%6d ", c[i][j]);
       printf("\n");
   }

   Dijkstra(Nodenum, 1, dist, prev_node, c);

   for(int i = 1 ;i <= Nodenum; i++){
       printf("Node: %d  the shortest path length: %d  ", i, dist[i]);
       //以下代码单纯为了输出规范结果，不是核心算法
       int prev = prev_node[i];
       int j = 1;
       printf("shortest path:%d->", i);
       while (i != source && prev != source){
           printf("%d->", prev);
           prev = prev_node[prev];
           if (++j > Nodenum)     break;
       }
       printf("%d", source);
       printf("\n");
   }

printf("\n");

   return 0;
}

void Dijkstra(int Nodenum, int source, int *dist, int *prev_node, int c[MAXNODE][MAXNODE])
{
    bool s[MAXNODE];                                        // 判断是否已存入该点到S集合中
 	for(int i=1; i<=Nodenum; ++i)                           //初始化
 	{
 		dist[i] = c[source][i];
 		s[i] = false;                                           // 初始都未用过该点
 		if(dist[i] == MAXINT)
 			prev_node[i] = 0;
 		else
 			prev_node[i] = source;
 	}
 	dist[source] = 0;
 	s[source] = 1;

 	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
 	// 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
 	for(int i=1; i<=Nodenum-1; ++i)
 	{
 		int tmp = MAXINT;
 		int u = source;
 		// 找出当前未使用的点j的dist[j]最小值
 		for(int j=1; j<=Nodenum; ++j)                // 获取当前邻接点中距离最小的顶点
 			if((!s[j]) && dist[j]<tmp)
 			{
 				u = j;
 				tmp = dist[j];
 			}
 		s[u] = 1;                                    //u 已存入S 集合中

 		// 更新dist
 		for(int j=1; j<=Nodenum; ++j)
 			if((!s[j]) && c[u][j]<MAXINT)
 			{
 				int newdist = dist[u] + c[u][j];
 				if(newdist < dist[j])
 				{
 					dist[j] = newdist;
 					prev_node[j] = u;
 				}
 			}
 	}
 }
