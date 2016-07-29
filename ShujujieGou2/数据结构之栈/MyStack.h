# ifndef MYSTACK_H
# define MYSTACK_H

class MyStack
{
public:
	MyStack(int size);                       //�����ڴ��ʼ��ջ�ռ䣬�趨ջ������ջ��
	~MyStack();                              //����ջ�ռ��ڴ�
	bool stackEmpty();                       //�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���true,�ǿշ���false
	bool stackFull();                        //�ж�ջ�Ƿ�Ϊ����Ϊ������true����������false
	void clearStack();                       //���ջ
	int stackLength();                       //����Ԫ�ظ���
	bool push(char elem);                    //Ԫ����ջ��ջ������
	bool pop(char &elem);                    //Ԫ�س�ջ��ջ���½�
	void stackTraverse(bool isFromButtorm);  //����ջ������Ԫ��

private:
	char *m_pBuffer;              //ջ�ռ�ָ��
	int m_iSize;                  //ջ����
	int m_iTop;                   //ջ����ջ��Ԫ�ظ���
};

# endif 