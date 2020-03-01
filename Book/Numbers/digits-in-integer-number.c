#include<stdio.h>
#include<stdlib.h>

int main()
{
	long number, saveNumber;

	printf("Enter a integer number: ");
	scanf("%ld", &number);

	saveNumber = number;

	// The number that we will divide the number
	int delimiter = 10;

	short digitsCounter = 0;

	while ( 1 )
	{
		number /= delimiter;

		digitsCounter++;

		if ( number == 0 )
		{
			break;
		}
	}

	printf("Digits in given number (%ld): %d\n", saveNumber, digitsCounter);
}
