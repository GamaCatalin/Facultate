#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool isPrime(int x) {
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool isMagicPair(int a, int b) {
	if (b - a == 2) {
		return true;
	}
	return false;
}

void generateTwinPairs(int n) {
	int a, b;
	int counter=0;
	b = 0;

	while (counter != n) {
		if (isPrime(b)) {
			for (a = b - 1; a >= 2; a--) {
				if (isMagicPair(a, b) && isPrime(a)) {
					printf("(%d, %d)", a, b);
					counter++;
					break;
				}
			}
		}

		b++;
	}
}

int readArray(int vector[]) {

	int i = 0;
	int readNumber;

	printf("Enter an array: ");

	while (i < 20) {
		scanf("%d", &readNumber);

		if (readNumber == 0) {
			return i;
			break;
		}

		vector[i] = readNumber;
		i++;
	}
	return i;
}

bool isDecreasing(int vector[],int a,int b) {
	int lastValue = 999999;
	for (int i = a; i < b; i++) {
		if (lastValue < vector[i]) {
			return false;
		}
		lastValue = vector[i];
	}
	return true;
}

void checkArray(int vector[],int vectorSize,int* a,int* b) {
	int currentA = 0;
	int currentB = 1;

	for (int i = 0; i < vectorSize-1; i++) {
		for (int j = i + 1; j < vectorSize; j++) {
			if (j - i < currentB - currentA) {
				continue;
			}
			if (isDecreasing(vector, i, j)) {
				currentA = i;
				currentB = j;
			}
		}
	}
	*a = currentA;
	*b = currentB;
}

void runA() {
	int n = 1;

	printf("Enter n: ");
	scanf("%d", &n);

	generateTwinPairs(n);
}

void runB() {

	int vector[20];
	int a=0, b=1;
	int vectorSize = readArray(vector);


	checkArray(vector, vectorSize, &a, &b);

	for (int i = a; i <= b; i++) {
		printf("%d ", vector[i]);
	}
}


int main() {

	/*
	11.
		a. Determine the first n pairs of twin numbers, where n is a given natural and non-null number. Two prime numbers p and q are called twin if q – p = 2.
		b. Given a vector of numbers, find the longest decreasing contiguous subsequence.
	*/


	//a)

	//runA();



	//b)

	runB();

	return 0;
}