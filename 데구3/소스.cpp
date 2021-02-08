#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stackNode{ //������ ��� ���� ����
	char data;
	struct stackNode*link;
}stackNode;
stackNode*top;	//������top ����

void push(char item)
{
	stackNode*temp = (stackNode*)malloc(sizeof(stackNode));	//�߰��� ������ ���
	temp->data = item;		//temp�� �����Ϳ� �Է¹��� item�� �����Ѵ�.
	temp->link = top;		//top�� ������ִ� �ּҰ��� temp�� ��ũ�� �ִ´�.
	top = temp;				//temp��� ��尡 ���ԵǸ� top�� �� ���� ��尡 �ƴϱ� ������ top�� ��ĭ �÷��ش�.
}

void printfStack()
{
	stackNode*p = top;
	printf("\n STACK[");
	while (p){	//�ؿ��� p�� p�� ��ũ������ �̵���Ű�� ������ p�� ���� �ƴѰ��� ������ ����ϰ���.
		printf("%c", p->data); // p�� ������ �ʵ忡 ����Ǿ��ִ� �����͸� ����Ѵ�.
		p = p->link;	//p�� ���� ���Ḯ��Ʈ�� �̵���Ų��.
	}
	printf("]");
}
char pop()
{
	char item;
	stackNode*temp = top;
	if (top == NULL) //���ÿ� �ƹ��͵� �����Ǿ����� �������
	{
		printf("\n\n ������ ������ϴ�.");
		return 0;
	}
	else
	{
		item = temp->data;	//item�� temp�� �����Ͱ��̴�.
		top = temp->link;	//temp�� ������带 ž���� �����Ѵ�.
		free(temp);	//�޸𸮸� return���ش�.
		return item; //item���� �ʱ�ȭ�Ѵ�.
	}
}
void main()
{
	top = NULL;
	printfStack();
	push('X');
	printfStack();
	push('Y');
	printfStack();
	push('Z');
	printfStack();

	pop();
	printfStack();
	pop();
	printfStack();
	pop();
	printfStack();
	pop();
	getchar();
}