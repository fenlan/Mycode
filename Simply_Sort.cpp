/*Author:fenlan
 *function:Simply sorting
 *date:2016.12.9
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int KeyType;
typedef struct sqlist {
    KeyType key;
    int length = 0;
}List, *Sqlist;

void Bubble_Sort(Sqlist &list, int length);
//运用冒泡法进行排序
void Straight_Insertion_Sort(Sqlist &list, int length);
//直接插入排序
void Simple_Selection_Sort(Sqlist &list, int length);
//简单选择排序
int min(Sqlist &list, int start, int length);
//从指定位置开始取序列最小值,返回最小值下标
void Get_Rand_data(KeyType *key, int length);
//产生长度为length 的随机数组key
//void Get_Rand_data(KeyType *key, int range, int length);
//在range 内产生长度为length 的随机数组key
void enter_data_into_file(char *FileName, KeyType *key, int start, int end);
//将数组key 中长度的数据存入文件file
void Get_data_from_file(char *FileName, Sqlist &list);
//从file 文件中读取数据到list 中

int main() {
    KeyType *key;
    Sqlist list;
    key = (KeyType *)malloc(10000 * sizeof(KeyType));
    list = (Sqlist)malloc(10001 * sizeof(List));

    if (key == NULL)          exit(0);

    Get_Rand_data(key, 10000);
    enter_data_into_file("intfile.dat", key, 0, 9999);
    free(key);

    Get_data_from_file("intfile.dat", list);
    Bubble_Sort(list, 10000);
    for (int i = 1;i<=10000;i++)
        printf("%d-%d ", list[i].key, i);

    free(list);
    return 0;
}

void Bubble_Sort(Sqlist &list, int length){
    int i = 0, j = 0, exchange = 0;
	bool flag = true;

	for(i=1; i<length-1 && flag; i++)
	{
		flag = false;
		for(j=1; j<length-i; j++)
			if(list[j].key > list[j+1].key)
			{
				exchange = list[j].key;
				list[j].key = list[j+1].key;
				list[j+1].key = exchange;
				flag = true;
			}
	}
}

void Straight_Insertion_Sort(Sqlist &list, int length){
    int i = 0, j = 0;

    for (i = 2;i <= length;i++){
        if (list[i].key < list[i-1].key){
            list[0].key = list[i].key;              //将lsit[0] 设置为哨兵
            list[i].key = list[i-1].key;
            for (j = i-2; list[0].key < list[j].key; j--)
                list[j+1].key = list[j].key;        //后移操作
            list[j+1].key = list[0].key;            //插入到序列正确位置
        }
    }
}//Straight_Insertion_Sort

void Simple_Selection_Sort(Sqlist &list, int length){
    int i = 0, j = 0;

    for (i = 1; i <list->length; i++){
        j = min(list, i, list->length);
        if (i != j){
            int t = list[i].key;
            list[i].key = list[j].key;
            list[j].key = t;
        }
    }
}//Simple_Selection_Sort

int min(Sqlist &list, int start, int length){
    int min = start;
    int i = 0, j = 0;

    for (i = start+1; i <= length; i++)
        if (list[min].key > list[i].key)      min = i;

    return min;
}//min

void Get_Rand_data(KeyType *key, int length){
    int i = 0;

    srand((int)time(0));
    for (i = 0; i < length; i++){
        key[i] = (KeyType)rand();
        //printf("%d ", key[i]);            //debug
    }
}

void enter_data_into_file(char *FileName, KeyType *key, int start, int end){
    int i = 0;
    FILE *file;
    file = fopen(FileName, "w+");

    for (i = start; i <= end; i++){
        fprintf(file, "%d ", key[i]);
    }

    fclose(file);
}

void Get_data_from_file(char *FileName, Sqlist &list){
    int i = 0;
    FILE *file;
    file = fopen(FileName, "r");

    for (i = 1;;i++){
        if (fscanf(file,"%d", &list[i].key) != 1) break; //读取int 类型数据
        //printf("%d ", list[i].key);        //debug
    }
    list->length = i-1;
    fclose(file);
}
