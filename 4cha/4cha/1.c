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
	printf("성 : ");
	scanf("%s",tmp.name.firstname);
	printf("이름 : ");
	scanf("%s",tmp.name.lastname);
	printf("나이 : ");
	scanf("%d",&tmp.age);
	printf("키 : ");
	scanf("%f",&tmp.height);
	printf("몸무게 : ");
	scanf("%f",&tmp.weight);
	printf("혈액형 : ");
	scanf("%s",tmp.blood);

	return tmp;
}
void Output(Person Human){
	printf("%s%s의 나이는 %d세, 키는 %.1fcm, 몸무게는 %.1fkg, 혈액형은 %s형입니다.\n",Human.name.firstname,Human.name.lastname,Human.age,Human.height,Human.weight,Human.blood);
}
