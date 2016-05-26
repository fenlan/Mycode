#include <stdio.h> 
# include <stdlib.h>

void main() 
{ 
	int i,j,k,year,week; 
	int day[]={31,28,31,30,31,30,31,31,30,31,30,31}; 
	char month[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"}; 

	printf("Input year you want to print:"); 
	scanf("%d",&year); 

	if((year%4==0&&year%100!=0)||(year%400==0)) day[1]++; //判断是否闰年
	week=(35+year+year/4-year/100+year/400)%7; //计算当年的1月1日是周几的公式 

	for(i=0;i<12;i++) 
	{ 
		printf("\n%s\n",month[i]); //输出月份的英文
		printf("Sun Mon Tue Wed Thu Fri Sat\n"); //输出表头
	for(k=0;k<week;k++) printf(" "); //每月一号对齐它的星期数
	for(j=1;j<=day[i];j++) 
	{ 
		printf("%3d ",j); 
	if(++week>=7) 
	{ 
		printf("\n"); 
		week=week%7; 
	} 
} 
printf("\n"); 
} 
	system("pause");
}