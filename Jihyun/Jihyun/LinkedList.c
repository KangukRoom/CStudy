#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Infor{
	char *Name;
	int age;
}Infor;

typedef struct Node{
	Infor Human;
	struct Node *Next;
}Node;

void InsertNode(Node **Head);
void ViewNode(Node *Head);
Infor InputInfor();			  // 정보 입력 공간
void Output(Infor test);				  // 출력 테스트 공간
void NameAlloc(char **name,char *buffer); // 이름 크기 할당

void main(){
	int i = 0;
	Node *Head = NULL;
	for(;i<3;i++)
		InsertNode(&Head);
	ViewNode(Head);
}

Infor InputInfor(){
	char Name[50];
	Infor One;
	printf("이름 입력: ");
	fgets(Name,50,stdin);
	Name[strlen(Name) - 1] = '\0';
	NameAlloc(&One.Name,Name);
	printf("나이 입력: ");
	scanf("%d",&One.age);
	getchar();
	return One;
}

void NameAlloc(char **name,char *buffer){
	*name = (char *)malloc(strlen(buffer) + 1);
	strcpy(*name,buffer);
}

void Output(Infor test){
	printf("%s \n%d\n",test.Name,test.age);
}

void InsertNode(Node **Head){
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->Human = InputInfor();
	if(*Head == NULL){
		*Head = tmp;
		(*Head)->Next = NULL;
	}
	else{
		tmp->Next = *Head;
		*Head = tmp;
	}
};

void ViewNode(Node *Head){
	for(;Head != NULL;Head = Head->Next) 
		Output(Head->Human);
}