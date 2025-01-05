// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#define ROW 3
const int COL=4;

//PROTOTYPES
void fillData(float[][COL]);
void showData(float[][COL]);
float average(float[][COL],float[]);
float bestGrade(float[]);

//MAIN
int main(){
	//VARIABLES
	float data[ROW][COL], aver[ROW], averGroup=0, best=0;

	fillData(data);
	showData(data);
	averGroup = average(data,aver);
	printf("Group average: %.1f\n",averGroup);
	best = bestGrade(aver);
	printf("\n The best average is: %.1f\n",best);	

	return 0;
}

//IMPLEMENTATIONS
void fillData(float data[][COL]){
	printf("Grade[0]-P1 | Grade[1]-P2 | Grade[2]-F | Grade[3]-P\n");
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			printf("Grade[%d][%d]: ",i,j);
			scanf("%f",&data[i][j]);
		}//j  Grades
		printf("\n");
	}//i students
}

void showData(float data[][COL]){
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			printf("%.1f\t",data[i][j]);
		}//j  Grades
		printf("\n");
	}//i students
}

float average(float data[][COL], float aver[]){
	float addition=0, aux[]={0.20,0.25,0.30,0.25};
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			aver[i] += (data[i][j]*aux[j]);
		}//j
		addition += aver[i];
	}//i
	return addition/ROW;   //group average
}

float bestGrade(float aver[]){
	float max=0;
	for(int i=0; i<ROW; i++){
		printf("%.1f \t",aver[i]);
		if (aver[i]>max){
			max = aver[i];
		}//if
	}//i
	return max;	
}











