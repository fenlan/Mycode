#include <iostream>
using namespace std;

int n;      int capacity;       int value[100];
int weight[100];                int currentWeight = 0;
int currentValue = 0;           int bestp = 0;
double perp[100];//单位物品价值排序后
int order[100];//物品编号
int put[100];//设置是否装入

//按单位价值排序
void knapsack()
{
    int i,j;
    int temporder = 0;
    double temp = 0.0;

    for(i = 1; i <= n; i++)
        perp[i] = value[i] / weight[i];
    for(i = 1; i <= n-1; i++)
    {
        for(j = i+1; j<=n; j++)
            if(perp[i] < perp[j])//冒泡排序perp[],order[],sortv[],sortw[]
        {
            temp = perp[i];
            perp[i] = perp[i];
            perp[j] = temp;

            temporder = order[i];
            order[i] = order[j];
            order[j] = temporder;
            temp = value[i];
            value[i] = value[j];
            value[j] = temp;

            temp = weight[i];
            weight[i] = weight[j];
            weight[j] = temp;
        }
    }
}

//计算上界函数
double bound(int i)
{
    double leftw = capacity - currentWeight;
    double b = currentValue;
    while(i <= n && weight[i] <= leftw)
    {
        leftw -= weight[i];
        b += value[i];
        i++;
    }
    if(i <= n)
        b += value[i] / weight[i] * leftw;
    return b;

}

//回溯函数
void backtrack(int i)
{
    if(i > n)
    {
        bestp = currentValue;
        return;
    }
    if(currentWeight + weight[i] <= capacity)
    {
        currentWeight += weight[i];
        currentValue += value[i];
        put[i] = 1;
        backtrack(i+1);
        currentWeight -= weight[i];
        currentValue -= value[i];
    }
    if(bound(i+1) > bestp)//符合条件搜索右子数
        backtrack(i+1);
}


int main()
{
    int i;
    capacity = 100;     n = 5;
    weight[1] = 10; weight[2] = 20; weight[3] = 30; weight[4] = 40; weight[5] = 50;
    value[1] = 20; value[2] = 30; value[3] = 65; value[4] = 40; value[5] =60;
    order[1] = 1; order[2] =2; order[3] = 3; order[4] = 4; order[5] = 5;

    knapsack();
    backtrack(1);
    cout << "最有价值为： " << bestp << endl;
    cout << "需要装入的物品编号是：";
    for(i = 1;i <= n; i++)
    {
        if(put[i]==1)
            cout << order[i] << " ";
    }
    cout << endl;
    return 0;
}