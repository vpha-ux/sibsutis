#include <stdio.h>
#include <stdlib.h>

float power (float x, int n) {
	
	float result = 1;
	
	if (n>=0) {
		
		for (int i = 0; i<n; i++) {
		
		result = result * x;
		
		}
		
	}
	else {
		
		for(int i = 0; i>n; i-- ) {
			
			result = result / x;
		}
	}
	
	return result;
	
}

int main() {
	
	float x; 
	scanf ("%f", &x);
	int n;
	scanf ("%d", &n);
	
	float result = power(x,n);
	printf ("результат: %f", result);	
	
}
