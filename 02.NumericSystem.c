#include<stdio.h>

#define LENGTH 20

unsigned char binary[LENGTH];

void decimal_to_binary();
void horner();

void main()
{
	horner();
}

void decimal_to_binary()
{
	char digit, position = 0; // digit for the current and position for the position in the array
	int num;
	scanf("%d", &num);

	while (num > 0)
	{
		digit = num % 2; // get the current digit
		binary[position] = digit;

		position++;
		num /= 2; 
	}

	// print the number
	for (int i = LENGTH - 1; i >= 0; i--)
		printf("%d", binary[i]);
	
	printf("\n");
}
