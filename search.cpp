#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Data{
    ElemType elem;
    int length = 0;
}*DATA;

bool GetData(DATA &data, char *FileName);
//从FileName 中获取数据,将数据地址指针传给data
bool Shun_Xu_search(DATA &data, ElemType, int &address);
//在data 中顺序查找elem 元素，找到返回true ,并返回地址
bool Di_Gui_Search(DATA &data, ElemType elem, int &address);
//递归方法将已经排序好的data 进行折半查找
bool No_Di_Gui_Search(DATA &data, ElemType elem, int &address);
//非递归方法将已经排序好的data 进行非排序查找
void Bubble_Sort(DATA &data, int length);
//运用冒泡法进行排序

int main (){
    DATA data;
    int i = 0, address = 0;
    ElemType elem = 0;

    if (GetData(data, "datafile.txt") == false)
        printf("fail to get the data!\n");
    //for (i = 0; i < data->length; i++)
        //printf("%d ", data[i].elem);

    Bubble_Sort(data, data->length);
    for (i = 0; i < data->length; i++)
        printf("%d ", data[i].elem);

    printf("\n");

    if (No_Di_Gui_Search(data, 64, address) == false)
        printf("fail to search the elem!\n");
    else
        printf("The address is %d\n", address);

    return 0;
}

bool GetData(DATA &data, char *FileName){
    FILE *file;
    file = fopen(FileName, "r");
    int i = 0, j = 0;

    if (file == NULL)           return false;
    else{
        for (i = 0;;i++){
            if (fscanf(file,"%d", &data[i].elem) != 1) break; //读取int 类型数据
            //printf("%d ", data[i]);
        }
        data->length = i;
        return true;
    }
}

bool Shun_Xu_search(DATA &data, ElemType elem, int &address){
    int i = 0;

    for (i = 0; i < data->length; i++)
        if (data[i].elem == elem){
            address = i;
            break;
        }
    //printf("%d\n", address);
    if (i == data->length){
        address = 0;
        return false;
    }
    else     return true;
}

bool Di_Gui_Search(DATA &data, ElemType elem, int &address){

}

bool No_Di_Gui_Search(DATA &data, ElemType elem, int &address){
    int low = 0, high = data->length;
    int now = 0;

    now = (low + high) / 2;
    for (; high >= low;){
        if (elem == data[now].elem){
            address = now;
            break;
        }
        else if (elem < data[now].elem)         high = now - 1;
        else           low = now + 1;
        now = (low + high) /2;
    }

    if (high < low)        return false;
    else                   return true;
}

void Bubble_Sort(DATA &data, int length){
    int i = 0, j = 0, exchange = 0;
	bool flag = true;

	for(i=0; i<length-1 && flag; i++)
	{
		flag = false;
		for(j=0; j<length-i-1; j++)
			if(data[j].elem > data[j+1].elem)
			{
				exchange = data[j].elem;
				data[j].elem = data[j+1].elem;
				data[j+1].elem = exchange;
				flag = true;
			}
	}
}
