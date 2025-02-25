#include <stdio.h>
#include <stdlib.h> 

int Easter (int year) {
	int a = year%19;
	int b = year%4;
	int c = year%7;
	int d = (19*a+15)%30;
	int e = (2*b+4*c+6*d+6)%7;
	int f = d+e;
	
	if (f<=26) {
		return (4+f); 
		printf (" april");
	}
	else {
		return (f-26);
		printf(" may");
	}
}

int main() {
	
	int yearEaster;
	scanf("%d", &yearEaster);
	int dateEaster = Easter (yearEaster);
	printf("%d", dateEaster);
}
