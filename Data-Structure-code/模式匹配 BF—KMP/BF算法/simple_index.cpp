#include<iostream>
#include<string>
using namespace std;
int index(const string &,const string &,int);

int main()
{
	char ch;
	do{
		string Tag,Ptn;  
		int pos;
		cout<<"����������";
		cin>>Tag;
		cout<<"�����Ӵ���";
		cin>>Ptn;
		cout<<"���������п�ʼ����ƥ���λ�ã����ַ�λ��Ϊ0����";
		cin>>pos;

		int result = index(Tag,Ptn,pos);
		if(result != -1)
			cout<<"�������Ӵ��������ĵ�"<<result<<"���ַ������ַ���λ��Ϊ0�����״�ƥ��"<<endl;
		else
			cout<<"��ƥ���Ӵ�"<<endl;

		cout<<"�Ƿ�������ԣ�����y��Y������������������������";
		cin>>ch;
	}while(ch == 'y' || ch == 'Y');
	return 0;
}

/*
�����Ӵ�Ptn������Tag�ĵ�pos���ַ���(����pos��λ��)��һ�γ��ֵ�λ�ã��������ڣ��򷵻�-1
����BF�㷨�������λ��ȫ���Դ�0��ʼ����Ϊ׼������T�ǿգ�0<=pos<=Tlen
*/
int index(const string &Tag,const string &Ptn,int pos)
{
	int i = pos;  //������ǰ�����Ƚϵ�λ�ã���ʼΪpos
	int j = 0;   //�Ӵ���ǰ�����Ƚϵ�λ�ã���ʼΪ0
	int Tlen = Tag.size();  //��������
	int Plen = Ptn.size();  //�Ӵ�����
	
	while(i<Tlen && j<Plen)
	{
		if(Tag[i] == Ptn[j])   //�����ǰ�ַ���ͬ����������±Ƚ�
		{   
			i++;
			j++;
		}
		else   //�����ǰ�ַ���ͬ����i��j���ˣ����½���ƥ��
		{   
			//��now_pos��ʾÿ�����½���ƥ��ʱ��ʼ�Ƚϵ�λ�ã���
			//i=now_pos+��������j=0+������
			//��i-j+1=now_pos+1,��ΪTag����һ�ֿ�ʼ�Ƚϵ�λ��
			i = i-j+1;
			//Ptn�˻ص��Ӵ���ʼ��
			j = 0;
		}
	}

	if(j >= Plen)
		return i - Plen;
	else
		return -1;
}