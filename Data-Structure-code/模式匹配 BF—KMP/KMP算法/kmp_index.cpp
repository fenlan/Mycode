#include<iostream>
#include<string>
using namespace std;
int kmp_index(const string &,const string &,int);
void get_next(const string &,int *,int);
void get_nextval(const string &,int *,int);

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
	
		int result = kmp_index(Tag,Ptn,pos);
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
����KMP�㷨�������λ��ȫ���Դ�0��ʼ����Ϊ׼������T�ǿգ�0<=pos<=Tlen
*/
int kmp_index(const string &Tag,const string &Ptn,int pos)
{
	int i = pos;  //������ǰ�����Ƚϵ�λ�ã���ʼΪpos
	int j = 0;   //�Ӵ���ǰ�����Ƚϵ�λ�ã���ʼΪ0
	int Tlen = Tag.size();  //��������
	int Plen = Ptn.size();  //�Ӵ�����

	//��next�����ֵ����������
	int *next = (int *)malloc(Plen*sizeof(int));
	get_next(Ptn,next,Plen);
//	get_nextval(Ptn,next,Pln);
	int t;
	cout<<"�Ӵ���next�����еĸ�Ԫ��Ϊ��";
	for(t=0;t<Plen;t++)
		cout<<next[t]<<" ";
	cout<<endl;

	while(i<Tlen && j<Plen)
	{
		if(j==-1 || Tag[i] == Ptn[j])   
		{   //�����ǰ�ַ���ͬ���������Ӵ��ĵ�һ���ַ���ʧ�䣬��������±Ƚ�
			i++;
			j++;
		}
		else   //�����ǰ�ַ���ͬ����i���ֲ��䣬j��Ϊ��һ����ʼ�Ƚϵ�λ��
		{   
			//next����ʱKMP�㷨�Ĺؼ���i�����ˣ�
			//���Ǽ������Ӵ��е�nex[j]λ�õ��ַ����бȽ�
			j = next[j];
		}
	}

	if(j >= Plen)
		return i - Plen;
	else
		return -1;
}

/*
��next�����и�Ԫ�ص�ֵ�������ڳ�Ϊlen��next������
*/
void get_next(const string &Ptn,int *next,int len)
{
	int j = 0;
	int k = -1;
	next[0] = -1;

	while(j<len-1)
	{
		if(k == -1 || Ptn[j] == Ptn[k])
		{   //����������������Pk = Pj�������������Ƚ���һ���ַ���
			//����next[j+1]=next[j]+1
			j++;
			k++;
			next[j] = k;
		}
		else
		{   //���������������ĵ�2�������������next[k]����Ѱ����һ���Ƚϵ�λ��
			k = next[k];
		}
	}
}


/*
��next����ĸĽ������и�Ԫ�ص�ֵ�������ڳ�Ϊlen��nextval������
*/
void get_nextval(const string &Ptn,int *nextval,int len)
{
	int j = 0;
	int k = -1;
	nextval[0] = -1;

	while(j<len-1)
	{
		if(k == -1 || Ptn[j] == Ptn[k])
		{   //����������������Pk = Pj�������������Ƚ���һ���ַ���
			//����next[j+1]=next[j]+1
			j++;
			k++;
			if(Ptn[j] != Ptn[k])
				nextval[j] = k;
			else  //Ptn[j]��Ptn[k]���ʱ��ֱ������netval[k]
				nextval[j] = nextval[k];
		}
		else
		{   //���������������ĵ�2�������������next[k]����Ѱ����һ���Ƚϵ�λ��
			k = nextval[k];
		}
	}
}