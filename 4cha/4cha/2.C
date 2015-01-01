#include <stdio.h>
#include <math.h>


typedef struct ComplexNum{
	float real;
	float imagine;
}ComplexNum;

ComplexNum Input();
void Output(ComplexNum Num,float NumValue);
float CalculateNum(ComplexNum Num);
void CompareNum(ComplexNum Num[4],float NumValue[4]);
void Swap(ComplexNum *change1,ComplexNum *change2);
void TwoCalculate(ComplexNum One,ComplexNum Two);

void main(){

	ComplexNum Number[4];
	float NumValue[4];
	int i = 0;
	printf("4개의 복소수입력 :\n");
	for(; i < 4 ; i++){
		Number[i] = Input();
		NumValue[i] = CalculateNum(Number[i]);	
	}
	printf("입력된 복소수와 크기: \n");
	for( i = 0 ; i < 4 ; i ++){
		Output(Number[i],NumValue[i]);
	}
	CompareNum(Number,NumValue);

	printf("크기가 큰 상위 두개의 복소수 :\n");
	for(i = 0 ; i < 2 ; i++)
		Output(Number[3-i],0);

	TwoCalculate(Number[3],Number[2]);

}

ComplexNum Input(){
	
	ComplexNum tmp;
	scanf("%f",&tmp.real);
	scanf("%f",&tmp.imagine);
	return tmp;

}
void Output(ComplexNum Num,float NumValue){
	if(NumValue == 0){
		if(Num.imagine > 0)
			printf("%f + %fi\n",Num.real,Num.imagine);
		else
			printf("%f  %fi\n",Num.real,Num.imagine);
	}
	else{
		if(Num.imagine > 0)
			printf("%f + %fi  %.2f\n",Num.real,Num.imagine,NumValue);
		else 
			printf("%f  %fi  %.2f\n",Num.real,Num.imagine,NumValue);
	}
}

float CalculateNum(ComplexNum Num){
	float NumValue;
	NumValue = sqrt(pow(Num.real,2) + pow(Num.imagine,2));
	return NumValue;
}

void CompareNum(ComplexNum Num[4],int NumValue[4]){
	int i,j;
	for(i = 0 ; i < 4 ; i++){
		for(j = i ; j < 3 ; j++){
		if( NumValue[j] > NumValue[j+1] ){
			
			int tmp;
			tmp = NumValue[j];
			NumValue[j] = NumValue[j+1];
			NumValue[j+1] = tmp;
			Swap(Num + j,Num + j+1);

			}
		}
	}
}

void Swap(ComplexNum *change1,ComplexNum *change2){
	ComplexNum tmp = {0};
	tmp = *change1;
	*change1 = *change2;
	*change2 = tmp;
}

void TwoCalculate(ComplexNum One,ComplexNum Two){
	ComplexNum Tmp;
	float NumValue;
	
	Tmp.real = One.real + Two.real;
	Tmp.imagine = One.imagine + Two.imagine;
	NumValue = CalculateNum(Tmp);
	
	printf("합 :\n");
	Output(Tmp,NumValue);

	Tmp.real = One.real * Two.real - One.imagine * Two.imagine;
	Tmp.imagine = One.real * Two.imagine + One.imagine * Two.real;
	NumValue = CalculateNum(Tmp);

	printf("곱 :\n");
	Output(Tmp,NumValue);

}
