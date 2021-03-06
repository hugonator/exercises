#include <stdio.h>
#include <math.h>


signed short signe(float);
float saisieEntier(char);

int main(){
	signed short type, sign;
	float a, b, c, result, discriminant, x1, x2;

	printf("what kind of result do you want to solve?\n1: first order\n2: second order\n");
	fflush(stdin);
	scanf("%hd", &type);

	switch(type){

		case 1:
			printf("you chose the first order solver : ax + b = 0\n");
			a = saisieEntier('a');
			b = saisieEntier('b');
			result = (0 - b)/a;
			printf("the result is: %f\n", result);
			break;

		case 2:
			printf("you chose the second order solver: ax² + bx + c = 0\n");
			a = saisieEntier('a');
			b = saisieEntier('b');
			c = saisieEntier('c');

			discriminant = (b*b) + (4*a*c);
			sign = signe(discriminant);

			if (sign == -1)
			{
				printf("no solution\n");
			}
			else if(sign == 0)
			{
				result = ((-b)/a);
				printf("the result is : x = %f\n", result);
			}
			else
			{
				x1 = (-(b*b)+(sqrt(discriminant)))/2*a;
				x2 = (-(b*b)-(sqrt(discriminant)))/2*a;
				printf("the solutions are x1 = %f and x2 = %f\n", x1, x2);
			}

			break;

		default:
			printf("unknown command\n");
			break;	
	}
	return 0;
}

// FUNC DEF 
float saisieEntier(char c){
	float a;
	
	printf("enter %c\n", c);
	fflush(stdin);
	scanf("%f", &a);
	return a;
}

signed short signe(float nbr){
	signed short sign;

	if (nbr<0){
		sign = -1;
	}
	else{
		if (nbr=0){
			sign = 0;
		}
		else{
			sign = 1;
		}
	}
	return sign;
}
