#include<stdio.h>

int main()
{
	unsigned long n;

	printf("Enter last natural number: ");
	scanf("%ld", &n);

	printf("++ NORMAL ITERATION ++\n\n");
	unsigned long sum = 0;
	for (unsigned long i = 1; i <= n; sum += i, i++);
	printf("Result iteration sum: %ld\n\n", sum);


	printf("++ EVCLID METHOD\n\n++");
	sum = ( n * ( n + 1 ) ) / 2; // Restore the counter


	printf("Result Evclid's method: %ld\n", sum);
}
