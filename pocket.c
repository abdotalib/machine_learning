#include <stdio.h>
#include <math.h>
#define colone 5
float* perceptron_pocket(float w[colone], float (*d)[colone], int l);
float sign(float s);
void perceptron_test(float w[colone], float (*d)[colone], int l);

int main(void){
	float W[colone-1] = {-0.1, 0.206, -0.23, 1};	
	float dataset[10][colone] = {{0.0, 0.0, 0.0, 0.0, 1.0},
			             {0.0, 0.0, 0.0, 1.0, -1.0},
			             {0.0, 0.0, 1.0, 0.0, 1.0},
			             {0.0, 0.0, 1.0, 1.0, -1.0},
			             {0.0, 1.0, 0.0, 0.0, 1.0},
			             {0.0, 1.0, 0.0, 1.0, -1.0},
			             {0.0, 1.0, 1.0, 0.0, 1.0},
			             {0.0, 1.0, 1.0, 1.0, -1.0},
			             {1.0, 0.0, 0.0, 0.0, 1.0},
			             {0.0, 0.0, 1.0, 0.0, -1.0}};
	//test data
	float test_data[4][colone] = {{1.0, 1.0, 0.0, 0.0, 1.0},
					 {1.0, 1.0, 0.0, 1.0, -1.0},
					 {1.0, 1.0, 1.0, 0.0, 1.0},
					 {1.0, 1.0, 1.0, 1.0, -1.0}};
					  
	
	float* p = perceptron_pocket(W, dataset, 10);
	perceptron_test(p, test_data, 4);
}
/////// perceptron \\\\\\\/

float* perceptron_pocket(float w[colone], float (*d)[colone], int l){
	float s = 0; //somme pondere
	float e = 0; //erreur
	float e_p = 0; //erreur pocket
	float* w_pocket = &w[0];
	int i = 0, j=0, x = 0, k = 0;
	for(i = 0 ; i < l ; i++ ){
		for(j = 0; j < colone-1; j++){
			s = s + d[i][j]*w[j];
		}
		if(sign(s) != d[i][colone-1]){
			for(k = 0; k < colone-1; k++){
				w[k] = w[k] + d[i][k]*d[i][colone-1];
			}
		s = 0;
		}
		for(x = 0 ; x < i ; x++ ){//on calcule les erreur
			for(j = 0; j < colone-1; j++){
				e = e + pow(d[i][colone-1] - d[x][j]*w[j], 2);
				e_p = e_p + pow(d[i][colone-1] - d[x][j]*w_pocket[j], 2);
				}
			}
		if(e/i < e_p/i){
			for( k = 0; k < colone-1; k++){
				w_pocket[k] = w_pocket[k] + d[i][k]*d[i][colone-1];
			}
		}
		e = 0 ; e_p = 0; 
	}
	return 	w_pocket;
}
/////// perceptron_test \\\\\\\/

void perceptron_test(float w[colone], float (*d)[colone], int l){
	float s ;
	int i = 0 , j = 0;
	for( i = 0 ; i < l ; i++ ){
		for( j = 0;j < colone-1; j++){
			s = s + d[i][j]*w[j];
		}
		printf("Expected = %f, Predicted = %f \n",d[i][colone-1], sign(s));
		s = 0;
	}

}
/////// perceptron_test \\\\\\\/
float sign(float s){
	int i=-1.0;
	if(s>= 0.0){
		i = 1;
	}
	return i;
}


