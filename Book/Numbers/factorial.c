#include<stdio.h>


unsigned long factorial(unsigned short num)
{
	if (num == 0) {
		return 1;
	}

	return num * factorial(num - 1);
}

int main()
{
	unsigned short num;

	printf("Enter number: ");
	scanf("%hu", &num);

	unsigned long facNumber = factorial(num);

	printf("The factorial of %hu is: %lu\n\n", num, facNumber);

	return 0;
}
