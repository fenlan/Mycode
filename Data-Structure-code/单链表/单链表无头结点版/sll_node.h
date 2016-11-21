#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int value;
	struct NODE *next;
};
typedef struct NODE Node;

extern Node *root;               //�����root����link_main�ļ��еĶ����,ͬʱӦ����input.cpp�ļ������ļ���û�ж���ָ��root��
					            //�������ڵ��ù�input����֮��rootֵ�ı䣬����ΪNULL��

bool sell_insert(Node **,int );  //����ڵ㺯��

void show(Node *);				//��ʾ�������ݺ���

void input_data(Node **);		//�����������ݺ���

void free_list(Node **);		//�ͷ������ڴ溯��

unsigned int count(Node *);     //����ڵ��������

bool check(Node *,int);			//�������������Ƿ����ı����Ѿ����ڵĺ���

void sort(Node *);			//��������������ð�ݷ�

void delete_data(Node **,int); //ɾ���ڵ㺯��
