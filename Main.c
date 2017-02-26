#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAXN 10000
#define MN 11

unsigned int mPrimes[MN] = { 2, 3, 5, 7, 13, 17, 19, 31, 61, 89 };
unsigned int k, p = 0, number[200];
unsigned long pN, primes[MAXN], counts[MAXN];

void last_zeroes();
void decomposition();
void first_task();
void create_matrix(int matrix[5][5]);
void print_matrix(int matrix[5][5]);
void eratosten(unsigned int num, char sieve[MAXN]);
void findPrimes(unsigned int num, unsigned int primes[MAXN]);
bool is_prime(unsigned int num, unsigned int primes[MAXN]);
void print_number();
void doubleN();
void perfectNumber(unsigned int s, unsigned int m);
void pascalTriangle();
void factorization();
void modify(unsigned long x, unsigned int how);
void solve(unsigned long start, unsigned long end, unsigned long inc);
unsigned long calc();

void main()
{
	factorization();
}

void factorization()
{
	unsigned int n, k;
	pN = 0;
	unsigned long pN, primes[MAXN], counts[MAXN];

	scanf("%u", &n);
	scanf("%u", &k);

	printf("C(%lu, %lu) = ", n, k);

	if (n - k < k)
		k = n - k;

	solve(n - k + 1, n, 1); // factorize the numerator 
	solve(1, k, -1); // factorize the denominator	

	printf("%lu\n", calc());
}

unsigned long calc()
{
	unsigned long result = 1;
	for (int i = 0; i < pN; i++)
		for (int j = 0; j < counts[i]; j++)
			result *= primes[i];

	return result;
}

void modify(unsigned long x, unsigned int how)
{
	for (int i = 0; i < pN; i++)
	{
		if (x == primes[i])
		{
			counts[i] += how;
			return;
		}
	}

	// this fragment maybe must been in the for statement
	counts[pN] = how;
	primes[pN++] = x;
}

void solve(unsigned long start, unsigned long end, unsigned long inc)
{
	unsigned long mul, prime, how;

	for (int i = start; i <= end; i++)
	{
		mul = i;
		prime = 2;
		while (mul != 1)
		{
			for (how = 0; mul % prime == 0; mul /= prime, how++);
			if (how > 0)
				modify(prime, inc * how);
			prime++;
		}
	}
}

void pascalTriangle()
{
	const unsigned int n = 7;
	const unsigned int k = 3;
	unsigned long lastLine[MAXN + 1];

	lastLine[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		lastLine[0] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			lastLine[j] += lastLine[j - 1];
		}
	}

	printf("C(%u,%u) = %lu\n", n, k, lastLine[k]);
}

void perfectNumber(unsigned int s, unsigned int m)
{
	k = 1;
	number[0] = 1;

	for (int i = 0; i < m; i++)
		doubleN();

	number[0]--;
	
	for (int i = 0; i < m - 1; i++)
		doubleN();
	
	printf("%2u perfect number is: ", s);
	print_number();
}

void doubleN()
{
	unsigned int carry = 0, temp;

	for (int i = 0; i < k; i++)
	{
		temp = number[i] * 2 + carry;
		number[i] = temp % 10;
		carry = temp / 10;
	}

	if (carry > 0)
		number[k++] = carry;
}

void print_number()
{
	for (int i = k - 1; i >= 0; i--)
		printf("%u", number[i]);
	printf("\n");
}

void last_zeroes_factorial()
{
	unsigned int num;
	scanf("%d", &num);

	unsigned int zeroes = 0, delimiter = 5;

	while (num >= delimiter)
	{
		zeroes += num / 5;
		delimiter *= 5;
	}

	printf("The number of zeroes are: %d\n", zeroes);
}

void last_zeroes()
{

	int matrix[] = { 100, 20, 88, 34, 91, 22 };

	int twoPower = 0, fivePower = 0;

	for (int i = 0; i < sizeof(matrix) / 4; i++)
	{
		int current = matrix[i]; // the current num

		while (current % 2 == 0 || current % 5 == 0)
		{
			if (current % 2 == 0)
			{
				current /= 2;
				twoPower++;
			}

			else if (current % 5 == 0)
			{
				current /= 5;
				fivePower++;
			}
		}
	}

	printf("The number of zeroes are: %d\n", fivePower > twoPower ? twoPower : fivePower);
}

void decomposition()
{
	// declare and read the number
	int num;
	scanf("%d", &num);

	int i = 2, k; // 'i' is for the number, 'k' is for the power

	printf("The number %d = ", num);
	while (num > 1)
	{
		k = 0;

		while (num % i == 0)
		{
			num /= i;
			k++;
		}

		if (k > 0)
		{
			printf("%d ^ %d . ", i, k);
		}

		i++;
	}
}

void findPrimes(unsigned int num, unsigned int primes[MAXN])
{
	for (int i = 2; i < num; i++)
	{
		if (is_prime(i, primes))
		{
			primes[p] = i;
			p++;
			printf("%5u", i);
		}
	}

	printf("\n");
}

bool is_prime(unsigned int num, unsigned int primes[MAXN])
{
	unsigned int i = 0;
	while (i < p && primes[i] * primes[i] <= num)
	{
		if (num % primes[i] == 0)
			return false;
		
		i++;
	}

	return true;
}

void eratosten(unsigned int num, char sieve[MAXN])
{
	unsigned int j, i = 2;
	
	while (i <= num)
	{
		if (sieve[i] == 0)
		{
			printf("%5u", i);

			j = i * i; // get the next num
			while(j <= num)
			{
				sieve[j] = 1;
				j += i;
			}
		}

		i++;
	}
	printf("\n");
}

void first_task()
{
	int count = 1;
	int matrix[5][5];
	create_matrix(matrix);

	// add under the main diagonal
	for (int col = 0; col < 4; col++)
	{
		for (int row = col + 1; row < 5; row++)
		{
			matrix[row][col] = count++;
		}
	}

	// add before the main diagonal
	for (int col = 4; col > 0; col--)
	{
		for (int row = col - 1; row >= 0; row--)
		{
			matrix[row][col] = count++;
		}
	}

	print_matrix(matrix);
}

void create_matrix(int matrix[5][5])
{
	// all members all zeroes
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void print_matrix(int matrix[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
} // method for printing the matrix