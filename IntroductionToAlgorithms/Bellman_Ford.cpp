/* Author: fenlan
 * function: bellman-ford algorithm
 * date: 2016.12.25
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXNODE 100
#define MAXINT 100000
typedef struct Edge{
	int u, v;                           // 起点，终点
	int weight;                         // 边的权值
}Edge;

Edge edge_array[MAXNODE] = {0};                    // 保存边的值
int dist[MAXNODE] = {0};                          // 结点到源点最小距离
int Nodenum, Edgenum, source;                     // 结点数，边数，源点
int prev_node[MAXNODE] = {0};                     // 某顶点最短路径的前一个顶点

void init();
// 初始化图
void relax(int u, int v, int weight);
//松弛算法， 参数分别是 边起点、终点和权值
bool Bellman_Ford();
//bellman-ford 核心算法

int main()
{
    init();
	if(Bellman_Ford())                        //最短路径有解打印源点到各顶点的最短距离
		for(int i = 1 ;i <= Nodenum; i++){
			printf("Node: %d  the shortest path length: %d ", i, dist[i]);
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

void init(){
	// 输入结点数，边数，源点
	printf("Enter node number:");
    scanf("%d", &Nodenum);
    printf("Enter edge number:");
    scanf("%d", &Edgenum);
    printf("Enter source node:");
    scanf("%d", &source);

    //算法第一步：初始化所有点。每一个点保存一个值，表示从原点到达这个点的距离，将原点的值设为0，其它的点的值设为无穷大（表示不可达）
	for(int i=1; i<=Nodenum; ++i) {                //初始化各节点的路径长度
 		dist[i] = MAXINT;
		prev_node[i] = source;                     //默认将所有顶点的最短路径前一顶点指向源点，（不推荐这样用，这里只是为了方便最后输出）
	}

	dist[source] = 0;                     //将源点的路径长度设为0
	for(int i=1; i<=Edgenum; ++i){
        printf("Enter edge_array[%d].u:", i);
        scanf("%d", &edge_array[i].u);
        printf("Enter edge_array[%d].v:", i);
        scanf("%d", &edge_array[i].v);
        printf("Enter edge_array[%d].weight:", i);
        scanf("%d", &edge_array[i].weight);

		if(edge_array[i].u == source)          //将源点直接指向的顶点进行路径长度赋值
			dist[edge_array[i].v] = edge_array[i].weight;
	}
}

void relax(int u, int v, int weight){
	if(dist[v] > dist[u] + weight){
		dist[v] = dist[u] + weight;
		prev_node[v] = u;
	}

}

bool Bellman_Ford(){
    //算法第二步：通过 n-1 次遍历边，并进行松弛计算，逐渐逼近最短路径
	for(int i=1; i<=Nodenum-1; ++i)
		for(int j=1; j<=Edgenum; ++j)
			relax(edge_array[j].u, edge_array[j].v, edge_array[j].weight);
    //算法第三步：判断是否出现负回路
    bool flag = true;
	for(int i=1; i<=Edgenum; ++i)
		if(dist[edge_array[i].v] > dist[edge_array[i].u] + edge_array[i].weight)
		{
			flag = false;
			break;
		}
	return flag;
}
