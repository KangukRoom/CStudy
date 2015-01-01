#include <stdio.h>

typedef struct Name{
	char lastname[20];
	char firstname[20];
}Name;

typedef struct Person{
	Name name;
	short age;
	float height,weight;
	char blood[5];
}Person;

Person Input();
void Output(Person Human);

void main(){
	Person Human;
	Human = Input();
	Output(Human);
}

Person Input(){
	
	Person tmp;
	printf("�� : ");
	scanf("%s",tmp.name.firstname);
	printf("�̸� : ");
	scanf("%s",tmp.name.lastname);
	printf("���� : ");
	scanf("%d",&tmp.age);
	printf("Ű : ");
	scanf("%f",&tmp.height);
	printf("������ : ");
	scanf("%f",&tmp.weight);
	printf("������ : ");
	scanf("%s",tmp.blood);

	return tmp;
}
void Output(Person Human){
	printf("%s%s�� ���̴� %d��, Ű�� %.1fcm, �����Դ� %.1fkg, �������� %s���Դϴ�.\n",Human.name.firstname,Human.name.lastname,Human.age,Human.height,Human.weight,Human.blood);
}
