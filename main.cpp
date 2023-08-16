#include <stdio.h>
#include <math.h>

#define SMALL_NUMBER 0.00000001

int main(){
	double a = SNAN;
	double b = SNAN;
	double c = SNAN;
	printf("enter coefficients of\nquadratic equation\n");
	printf("a: ");
	scanf("%lf", &a);
	printf("b: ");
	scanf("%lf", &b);
	printf("c: ");
	scanf("%lf", &c);


	double d = b*b - 4.0*a*c;
	if(isnan(a) || isnan(b) || isnan(c)){ // ошибка
		printf("incorrect input!!!\n");
	}else if(abs(a) < SMALL_NUMBER){ // линейное bx + c = 0
		printf("bro thats not even quadratic\n");
		if(abs(b) < SMALL_NUMBER){ // b == 0
			if(abs(c) < SMALL_NUMBER){ // все вещ числа корни
				printf("root: any real number\n");
			}else{ // нет корней
				printf("no roots\n");
			}
		}else{ // один корень
			printf("root: %.3lf\n", (-c)/b);
		}
	}else{ // квадратное ax^2 + bx + c = 0
		if(abs(d) < SMALL_NUMBER){ // один корень 
			printf("root: %.3lf\n", (-b)/(2.0*a));
		}else if(d > 0){ // два корня
			printf("first root: %.3lf\n", (-b + sqrt(d))/(2.0 * a));
			printf("second root: %.3lf\n", (-b - sqrt(d))/(2.0 * a));
		}else if(d < 0){ // нет корней
			printf("no roots\n");
		}
	}

	return 0;
}