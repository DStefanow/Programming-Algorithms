#include<stdio.h>
#include<stdlib.h>

int setPowerOf(int, int);

int main() {
	int num, pow;

	printf("Enter number: ");
	scanf("%d", &num);

	printf("Enter 'power of': ");
	scanf("%d", &pow);

	printf("%d ^ %d = %d\n\n", num, pow, setPowerOf(num, pow));

	return 0;
}

int setPowerOf(int num, int pow) {
	if (pow < 1) {
		return 1;
	}

	return num * setPowerOf(num, pow - 1);
}
