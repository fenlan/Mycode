/*�� �� ���� ����ͨѶ¼
 *ʱ    �䣺 2016��6��28��
 *��    �ߣ� fenlan
 *����ȱ�㣺 ����ʱ��ԭ��û��ʵ�����ݳ־û����Ժ���ʱ��ȥʵ��
 *���������� �����ļ�����������������ݴ������ļ������棬���ú���fread,fwrite�ȿ���ʵ�ָù���
 */

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

int number = 0;   //���ڵ�����ϵ�˵������

typedef struct              //����ṹ��������ÿ����ϵ�˵�ͨѶ��Ϣ
{
	int number;    //ÿ����ϵ�˵������
	char Name[10];
	char Phone_number[15];
	char Email[30];
	char Address[50];
}People;

void Add(People *);
/*�������ã������ϵ��
*���������������ϵ�˵Ľṹ������
*/

void Change(People *);
/*�������ã��޸���ϵ��
*���������������ϵ�˵Ľṹ������
*/

void Delete(People *);
/*�������ã�ɾ����ϵ��
*���������������ϵ�˵Ľṹ������
*/

void Find(People *);
/*�������ã�������ϵ��
*���������������ϵ�˵Ľṹ������
*/

void Display_All_People(People *);
/*�������ã���ʾ������ϵ��
*���������������ϵ�˵Ľṹ������
*/

int main ()
{
	int i;
	People people[100];       //������ϵ�˵����飬��ഢ��100��

	//�˵���
	printf("-------------------------\n");
	printf("           ͨѶ¼         \n");
	printf("-------------------------\n");
	printf("\n");
	printf("-------------------------\n");
	printf("0.Add  1.Change  2.Delete \n");
	printf("3.Find  4.Display 5.Exit  \n");
	printf("-------------------------\n");
	printf("\n");


	for (i=0; i<100; i++)           //��ʼ�������е���ϵ������������������ж����鴢����ϵ����
	{
		people[i].number = 0;
	}

	while (1)
	{
		int number;                  //�û���Ҫ���еĲ���ѡ��
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

void Add(People * people)                   //�����ϵ�˺���
{
	while (people->number != 0)              //��֮ǰ��ӵ���ϵ�˺����������ϵ��
		people++;

	printf("�����������ϵ�˵���Ϣ\n");
	printf("���֣�");
	scanf("%s", &people->Name);
	printf("�绰��");
	scanf("%s", &people->Phone_number);
	printf("���䣺");
	scanf("%s", &people->Email);
	printf("��ַ��");
	scanf("%s", &people->Address);
	people->number = ++number;
	printf("it's ok!\n\n");
}

void Change(People * people)                     //�޸���ϵ����Ϣ����û��ʱ�������ȷ�ԣ�
{
	char name[10];
	printf("��������Ҫ������ϵ�˵�����\n");
	printf("������");
	scanf("%s", &name);

	while (people->number != 0)
	{
		if (people->Name == name)
		{
			printf("���޸������ϵ����Ϣ\n");
			printf("�绰��");
			scanf("%s", &people->Phone_number);
			printf("���䣺");
			scanf("%s", &people->Email);
			printf("��ַ��");
			scanf("%s", &people->Address);
			break;
		}
		people++;
	}
	printf("it's ok!\n\n");
}

void Delete(People * people)                      //ɾ����ϵ��
{
	int i = 0;
	int size1 = 0;
	int size2 = 0;
	char name[10];

	printf("��������Ҫɾ����ϵ�˵�����\n");
	printf("���֣�");
	scanf("%s", &name);
	size1 = _mbstrlen(name);

	while (people->number != 0)
	{
		size2 = _mbstrlen(people->Name);                 //��麯���Ƚ���������ֺ���ϵ��������������Ƿ���ͬ
		if (size1 == size2)                              //��Ҫע�͵��ǲ��ܼ򵥵Ľ�name��people->name���бȽ�
		{                                                //�����name�ַ������磺 ����-------
			for (i=0;i<size1;i++)                        //����û����Ŀռ�������������ֵ�����Բ��ܽ�name��people->name��������Ƚ�
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
					* people = * (people+1);              //������ǰ�������Ƿ���ɾ���������ʲô�㷨��֪��
					people->number--;
					people++;
				}
			}
			number--;                                     //ɾ��һ���ˣ�������������һ
			break;
		}
		people++;
	}
	printf("it's ok!\n\n");
}

void Find(People * people)                               //Ѱ����ϵ��
{
	int i = 0;
	int judge = 0;
	int size = 0;
	int size2 = 0;
	char Name[10];

	printf("��������Ҫ������ϵ�˵�����\n");
	printf("������");
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
			printf("��ţ�%d\n������%s\n�绰��%s\n���䣺%s\n��ַ��%s\n", people->number, people->Name, people->Phone_number, people->Email, people->Address);
			break;
		}
		people++;
	}
	printf("it's ok!\n\n");
}

void Display_All_People(People * people)                            //��ʾ������ϵ��
{
	while (people->number != 0)
	{
		printf("��ţ�%d\n������%s\n�绰��%s\n���䣺%s\n��ַ��%s\n", people->number, people->Name, people->Phone_number, people->Email, people->Address);
		people++;
	}
	printf("it's ok!\n\n");
}