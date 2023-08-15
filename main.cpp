#include <stdio.h>
#include <math.h>

typedef long double ld_t;

int main(){
	ld_t a;
	ld_t b;
	ld_t c;
	printf("enter coefficients of\nquadratic equation\n");
	printf("a: ");
	scanf("%Lf", &a);
	printf("b: ");
	scanf("%Lf", &b);
	printf("c: ");
	scanf("%Lf", &c);

	ld_t d = b*b - 4.0*a*c;
	if(d > 0.0){
		printf("first root: %.3Lf\n", (-b + sqrt(d))/(2.0 * a));
		printf("second root: %.3Lf\n", (-b - sqrt(d))/(2.0 * a));
	} else if(d < 0.0){
		printf("no roots\n");
	} else {
		printf("root: %.3Lf\n", (-b)/(2.0*a));
	}

	return 0;
}