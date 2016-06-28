/*程 序 名： 简易通讯录
 *时    间： 2016年6月28日
 *作    者： fenlan
 *程序缺点： 由于时间原因，没有实现数据持久化，以后有时间去实现
 *后续工作： 利用文件操作将程序里的数据储存在文件夹里面，利用函数fread,fwrite等可以实现该功能
 */

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

int number = 0;   //用于迭代联系人的序号数

typedef struct              //定义结构体来储存每个联系人的通讯信息
{
	int number;    //每个联系人的序号数
	char Name[10];
	char Phone_number[15];
	char Email[30];
	char Address[50];
}People;

void Add(People *);
/*函数作用：添加联系人
*传入参数：储存联系人的结构体数组
*/

void Change(People *);
/*函数作用：修改联系人
*传入参数：储存联系人的结构体数组
*/

void Delete(People *);
/*函数作用：删除联系人
*传入参数：储存联系人的结构体数组
*/

void Find(People *);
/*函数作用：查找联系人
*传入参数：储存联系人的结构体数组
*/

void Display_All_People(People *);
/*函数作用：显示所有联系人
*传入参数：储存联系人的结构体数组
*/

int main ()
{
	int i;
	People people[100];       //储存联系人的数组，最多储存100个

	//菜单栏
	printf("-------------------------\n");
	printf("           通讯录         \n");
	printf("-------------------------\n");
	printf("\n");
	printf("-------------------------\n");
	printf("0.Add  1.Change  2.Delete \n");
	printf("3.Find  4.Display 5.Exit  \n");
	printf("-------------------------\n");
	printf("\n");


	for (i=0; i<100; i++)           //初始化数组中的联系人序号数，后面用来判断数组储存联系人数
	{
		people[i].number = 0;
	}

	while (1)
	{
		int number;                  //用户想要进行的操作选项
		scanf("%d", &number);

		switch (number)
		{
		case 0:      Add(people);                    break;
		case 1:      Change(people);                 break;
		case 2:      Delete(people);                 break;
		case 3:      Find(people);                   break;
		case 4:      Display_All_People(people);     break;
		case 5:      exit(0);                         break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

void Add(People * people)                   //添加联系人函数
{
	while (people->number != 0)              //从之前添加的联系人后面添加新联系人
		people++;

	printf("请输入添加联系人的信息\n");
	printf("名字：");
	scanf("%s", &people->Name);
	printf("电话：");
	scanf("%s", &people->Phone_number);
	printf("邮箱：");
	scanf("%s", &people->Email);
	printf("地址：");
	scanf("%s", &people->Address);
	people->number = ++number;
	printf("it's ok!\n\n");
}

void Change(People * people)                     //修改联系人信息（还没有时间调试真确性）
{
	char name[10];
	printf("请输入需要更改联系人的姓名\n");
	printf("姓名：");
	scanf("%s", &name);

	while (people->number != 0)
	{
		if (people->Name == name)
		{
			printf("请修改你的联系人信息\n");
			printf("电话：");
			scanf("%s", &people->Phone_number);
			printf("邮箱：");
			scanf("%s", &people->Email);
			printf("地址：");
			scanf("%s", &people->Address);
			break;
		}
		people++;
	}
	printf("it's ok!\n\n");
}

void Delete(People * people)                      //删除联系人
{
	int i = 0;
	int size1 = 0;
	int size2 = 0;
	char name[10];

	printf("请输入你要删除联系人的姓名\n");
	printf("名字：");
	scanf("%s", &name);
	size1 = _mbstrlen(name);

	while (people->number != 0)
	{
		size2 = _mbstrlen(people->Name);                 //这块函数比较输入的名字和联系人数组里的名字是否相同
		if (size1 == size2)                              //需要注释的是不能简单的将name与people->name进行比较
		{                                                //输入的name字符数组如： 芬兰-------
			for (i=0;i<size1;i++)                        //数组没用完的空间会随机产生垃圾值，所以不能将name与people->name进行整体比较
				if (people->Name[i]!=name[i])   break;
		}

		if (i==size1)
		{
			while (people->number!=0)
			{
				if ((people+1)->number == 0)       
				{
					people->number = 0;
				}
				else
				{
					* people = * (people+1);              //利用向前迭代覆盖方法删除，具体叫什么算法不知道
					people->number--;
					people++;
				}
			}
			number--;                                     //删除一个人，数组中人数减一
			break;
		}
		people++;
	}
	printf("it's ok!\n\n");
}

void Find(People * people)                               //寻找联系人
{
	int i = 0;
	int judge = 0;
	int size = 0;
	int size2 = 0;
	char Name[10];

	printf("请输入你要查找联系人的姓名\n");
	printf("姓名：");
	scanf("%s", &Name);

	size = _mbstrlen(Name);

	while (people->number != 0)
	{
		size2 = _mbstrlen(people->Name);
		if (size == size2)
		{
			for (i = 0; i < size; i++)
				if(people->Name[i]!=Name[i])   break;
		}
		if (i == size)
		{
			printf("序号：%d\n姓名：%s\n电话：%s\n邮箱：%s\n地址：%s\n", people->number, people->Name, people->Phone_number, people->Email, people->Address);
			break;
		}
		people++;
	}
	printf("it's ok!\n\n");
}

void Display_All_People(People * people)                            //显示所有联系人
{
	while (people->number != 0)
	{
		printf("序号：%d\n姓名：%s\n电话：%s\n邮箱：%s\n地址：%s\n", people->number, people->Name, people->Phone_number, people->Email, people->Address);
		people++;
	}
	printf("it's ok!\n\n");
}