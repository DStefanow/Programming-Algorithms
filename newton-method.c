#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
	The following program calculate the square root of a given number.
	The idea is to get the number from stdin and start with an applicant.
	We better have a near applicant in a given range, but we accept that
	we need to start from 10.

	After that we perform the following calculation:

	1) x1 = x0 - f(x0)/f'(x0) = applicant - (( applicant ^ 2 - given_number )) / ( 2 * applicant )
	2) then we check if ( x1 * x1 ) < 0.000..1
		2.1) If the above is true - WE FOUND the square number
		2.2) If not - then x0 = x1 and perform 1) again until we get true for 2)

	Example:
	given_number = 612
	application = 10

	Calculation:
		1) First we get = 35.6
		2) Then 26.3955..
		After some more calculation we get the final result: 24.7386338
*/

int main()
{
	// The number that we are going to find the square root
	int number;

	// Variables used in calculation
	// Start with 10
	double applicant = 10.0;
	double tmpValue;

	// Read the number from stdin
	printf("Enter a number: ");
	scanf("%d", &number);

	// Start calculation
	while (1) {

		tmpValue = applicant - (( pow(applicant, 2) - number ) / ( 2 * applicant ));

		printf("Current one: %.6f\n", tmpValue);
		if ( (pow(tmpValue, 2) - number) < 0.000000001f ) {
			printf("We found the square root: %.9f\n", tmpValue);
			break;
		}

		applicant = tmpValue;

		sleep(1);
	}

	return 0;
}
