#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stackNode{ //스택의 노드 구조 정의
	char data;
	struct stackNode*link;
}stackNode;
stackNode*top;	//포인터top 선언

void push(char item)
{
	stackNode*temp = (stackNode*)malloc(sizeof(stackNode));	//추가할 데이터 노드
	temp->data = item;		//temp의 데이터에 입력받은 item을 삽입한다.
	temp->link = top;		//top에 저장되있는 주소값을 temp의 링크에 넣는다.
	top = temp;				//temp라는 노드가 삽입되면 top이 맨 위의 노드가 아니기 때문에 top을 한칸 올려준다.
}

void printfStack()
{
	stackNode*p = top;
	printf("\n STACK[");
	while (p){	//밑에서 p를 p의 링크값으로 이동시키기 때문에 p가 참이 아닌경우는 마지막 노드일경우다.
		printf("%c", p->data); // p의 데이터 필드에 저장되어있는 데이터를 출력한다.
		p = p->link;	//p를 다음 연결리스트로 이동시킨다.
	}
	printf("]");
}
char pop()
{
	char item;
	stackNode*temp = top;
	if (top == NULL) //스택에 아무것도 지정되어있지 않은경우
	{
		printf("\n\n 스택이 비었습니다.");
		return 0;
	}
	else
	{
		item = temp->data;	//item은 temp의 데이터값이다.
		top = temp->link;	//temp의 다음노드를 탑으로 지정한다.
		free(temp);	//메모리를 return해준다.
		return item; //item값을 초기화한다.
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