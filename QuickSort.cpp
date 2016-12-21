/*Author:fenlan
 *function: Quick Sort
 *data:2016-12-21
 */
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef char * InfoType;
typedef struct {
    KeyType key;           //关键字项
    InfoType otherinfo;    //其他数据项
}RedType;
typedef struct {
    RedType r[1001];     //r[0]作为闲置或哨兵单元
    int length;          //顺序表长度
}Sqlist;

void QSort(Sqlist &List, int low, int high);
//对顺序表List 中的子序列List.r[low..high] 做快速排序
int Partition(Sqlist &List, int low, int high);
//交换顺序表List 中的子表r[low..high] 的记录，柜轴记录到位，病返回其所在位置，
//此时在它之前（后）的记录均不大（小）于它
void Get_data_from_file(char *FileName, Sqlist &list);
//从file 文件中读取数据到list 中

int main()
{
    int i = 0;
    Sqlist List;

    Get_data_from_file("datafile.txt", List);
    QSort(List, 1, List.length);

    for (i = 1;i <= List.length; i++)
        printf("%d ", List.r[i].key);

    printf("\n");

    return 0;
}

void QSort(Sqlist &List, int low, int high){
    if (low < high) {                                 //长度大于1
        int pivotloc = Partition(List, low, high);    //将List.r[low..high] 一分为二
        QSort(List, low, pivotloc-1);                 //对低字表递归排序，pivotloc 是柜轴位置
        QSort(List, pivotloc+1, high);                //对高字表递归排序，pivotloc 是柜轴位置
    }
}//QSort

int Partition(Sqlist &List, int low, int high){
    int pivotloc = 0;

    List.r[0] = List.r[low];                    //用子表的第一个记录作为柜轴记录
    pivotloc = List.r[low].key;                 //柜轴记录关键字
    while (low < high) {
        while (low < high && List.r[high].key >= pivotloc)   --high;
        List.r[low] = List.r[high];             //将比柜轴小的记录移到低端
        while (low < high && List.r[low].key <= pivotloc)    ++low;
        List.r[high] = List.r[low];             //将比柜轴大的记录移到高端
    }
    List.r[low] = List.r[0];                   //柜轴记录到位
    return low;                                //返回柜轴位置
}

void Get_data_from_file(char *FileName, Sqlist &list){
    int i = 0;
    FILE *file;
    file = fopen(FileName, "r");

    for (i = 1;;i++){
        if (fscanf(file,"%d", &list.r[i].key) != 1) break; //读取int 类型数据
        //printf("%d ", list[i].key);        //debug
    }
    list.length = i-1;
    fclose(file);
}
