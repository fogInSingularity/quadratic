#include <stdio.h>
#include <math.h>

#define SMALL_NUMBER 0.00000001

void input ( double*, double*, double* );
int is_zero ( double );

int main () {
	double a = SNAN;
	double b = SNAN;
	double c = SNAN;

	input ( &a, &b, &c );

	if ( is_zero(a) ) { // линейное bx + c = 0
		printf ( "bro thats not even quadratic\n" );
		if ( is_zero(b) ) { // b == 0
			if ( is_zero(c) ) { // все вещ числа корни
				printf ( "root: any real number\n" );
			} else { // нет корней
				printf ( "no roots\n" );
			}
		} else { // один корень
			printf ( "root: %.5lf\n", (-c)/b );
		}
	} else { // квадратное ax^2 + bx + c = 0
		double d = b*b - 4.0*a*c;
		if ( is_zero(d) ) { // один корень 
			printf ( "root: %.5lf\n", (-b)/(2.0*a) );
		} else if ( d > 0.0 ) { // два корня
			printf ( "first root: %.5lf\n", ( -b + sqrt(d) )/( 2.0 * a ) );
			printf ( "second root: %.5lf\n", ( -b - sqrt(d) )/( 2.0 * a ) );
		} else if ( d < 0.0 ) { // нет корней
			printf ( "no roots\n" );
		}
	}

	return 0;
}

void input ( double* a_p, double* b_p, double* c_p ) {
	printf ( "enter coefficients of\nquadratic equation\n" );
	printf ( "a: " );
	char ch = '\0';
	while ( !scanf ( "%lf", a_p ) ) {
		scanf ( "%c", &ch );
	}
	printf ( "b: " );
	while ( !scanf ( "%lf", b_p) ) {
		scanf ( "%c", &ch );
	}
	printf ( "c: " );
	while ( !scanf ( "%lf", c_p ) ) {
		scanf ( "%c", &ch );
	}
}

int is_zero ( double n ) {
	if ( abs(n) < SMALL_NUMBER ) {
		return 1;
	} else {
		return 0;
	}
}