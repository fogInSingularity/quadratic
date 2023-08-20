#include <stdio.h>
#include <math.h>

#define SMALL_NUMBER 0.00000001

void read_lf(double* n);
void input_of_coeff(double* a, double* b, double* c);
int is_zero(double n);
void linr(double b, double c);
void quad(double a, double b, double c);

int main(){
	double a = NAN;
	double b = NAN;
	double c = NAN;

	input_of_coeff(&a, &b, &c);

	if ( is_zero(a) ) { // линейное bx + c = 0
		linr(b, c);
	} else { // квадратное ax^2 + bx + c = 0
		quad(a, b, c);
	}

	return 0;
}

void read_lf(double* n) {
	char ch = '\0';
	while ( !scanf("%lf", n) ) {
		scanf("%c", &ch);
	}
}

void input_of_coeff(double* a, double* b, double* c) {
	printf("enter coefficients of\nquadratic equation\n");
	printf("a: ");
	read_lf(a);
	printf("b: ");
	read_lf(b);
	printf("c: ");
	read_lf(c);
}

int is_zero(double n) {
	return abs(n) < SMALL_NUMBER;
}

void linr(double b, double c) {
	printf("bro thats not even quadratic\n");
	if ( is_zero(b) ) { // b == 0
		if ( is_zero(c) ) { // все вещ числа корни
			printf("root: any real number\n");
		} else { // нет корней
			printf("no roots\n");
		}
	} else { // один корень
		printf("root: %.5lf\n", (-c)/b);
	}
}

void quad(double a, double b, double c){
	double d = b*b - 4.0*a*c;
	double d_sqrt = sqrt(d);
	if ( is_zero(d) ) { // один корень 
		printf("root: %.5lf\n", (-b)/(2.0*a));
	} else if ( d > 0.0 ) { // два корня
		printf("first root: %.5lf\n", ( -b + d_sqrt ) / ( 2.0 * a ) );
		printf("second root: %.5lf\n", ( -b - d_sqrt ) / ( 2.0 * a ) );
	} else if ( d < 0.0 ) { // нет корней
		printf ("no roots\n");
	}
}