#include<stdio.h>
#include<stdlib.h>

int iterativeEvclidGcd(int, int);
int recursiveEvclidGcd(int, int);

int main() {
	int num1, num2;

	printf("Enter first number: ");
	scanf("%d", &num1);

	printf("Enter second number: ");
	scanf("%d", &num2);

	int divisible, divider;
	int gcd;

	// First of all - the divisible must be the bigger number of num1 and num2
	if (num1 > num2) {
		divisible = num1;
		divider = num2;
	} else {
		divisible = num2;
		divider = num1;
	}

	// If the divider is zero, we return the divisible
	if (divider == 0) {
		gcd = divisible;
	} else {
		gcd = recursiveEvclidGcd(num1, num2);
	}

	printf("The greatest common divide of %d and %d is %d\n", num1, num2, gcd);

	return 0;
}

int recursiveEvclidGcd(int divisible, int divider) {
	int quotinent, remainder;

	quotinent = divisible / divider;
	remainder = divisible % divider;

	if (remainder == 0) {
		return divider;
	}

	return recursiveEvclidGcd(divider, remainder);
}

int iterativeEvclidGcd(int divisible, int divider) {
	int quotinent, remainder;

	while (1) {
		quotinent = divisible / divider;
		remainder = divisible % divider;

		if (remainder == 0) {
			break;
		}

		divisible = divider;
		divider = remainder;
	}

	return divider;
}
