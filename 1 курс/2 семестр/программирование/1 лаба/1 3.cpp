#include <stdio.h>
#include <math.h>

double cosinus(double x) {
	
    double result = 1.0;
    double factarial = 1.0;
    double power = 1.0;
    double eps = 0.0001;

    for (int n = 1; fabs(factarial) > eps; n++) {
    	
        power *= -1.0 * x * x / ((2 * n - 1) * (2 * n));
        factarial = power;
        result += factarial;
    }
    return result;
}

int main() {
	
    double x, epsilon;
    scanf("%lf", &x);

    double tcos = cosinus(x);
    double fcos = cos(x);

    printf("%lf\n", tcos);
    printf("%lf\n", fcos);

    return 0;
}
