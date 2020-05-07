#include <stdio.h>
#define colone 5
float* perceptron(float w[colone], float (*d)[colone], int l);
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
					  
	
	float* p = perceptron(W, dataset, 10);
	perceptron_test(p, test_data, 4);
}
/////// perceptron \\\\\\\/

float* perceptron(float w[colone], float (*d)[colone], int l){
	float s = 0;
	for(int i = 0 ; i < l ; i++ ){
		for(int j = 0; j < colone-1; j++){
			s = s + d[i][j]*w[j];
		}
		if(sign(s) != d[i][colone-1]){
			for(int k = 0; k < colone-1; k++){
				w[k] = w[k] + d[i][k]*d[i][colone-1];
			}
		s = 0;
		}
		 
	}
	return 	w;
}
/////// perceptron_test \\\\\\\/

void perceptron_test(float w[colone], float (*d)[colone], int l){
	float s ;
	for(int i = 0 ; i < l ; i++ ){
		for(int j = 0; j < colone-1; j++){
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
