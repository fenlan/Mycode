#include <stdio.h>
# include <stdlib.h>

void main()
{
	int i,j,k,year,week;
	int day[]={31,28,31,30,31,30,31,31,30,31,30,31};
	char month[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};

	printf("Input year you want to print:");
	scanf("%d",&year);

	if((year%4==0&&year%100!=0)||(year%400==0)) day[1]++; //�ж��Ƿ�����
	week=(35+year+year/4-year/100+year/400)%7; //���㵱����1��1�����ܼ��Ĺ�ʽ 

	for(i=0;i<12;i++)
	{
		printf("\n%s\n",month[i]); //�����·ݵ�Ӣ��
		printf("Sun Mon Tue Wed Thu Fri Sat\n"); //������ͷ
	for(k=0;k<week;k++) printf(" "); //ÿ��һ�Ŷ�������������
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
