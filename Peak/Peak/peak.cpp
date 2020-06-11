#include <iostream>
#include <fstream>
#include <math.h>

void DAC(int[],int);

int main(void) {
	int theArray[32];
	int n = 0;
	std::ifstream theFile;

	theFile.open("peak.txt");

	if (theFile.is_open()) {
		while (!theFile.eof()) {
			theFile >> theArray[n];
			n++;
		}
	}

	theFile.close();

	DAC(theArray, n);

	return 0;
}

void DAC(int arr[], int n) {
	int L = 0;
	int R = n-1;
	int m;
	while (L < R) {
		m = std::floor((L + R) / 2);
		if (arr[m] <= arr[m + 1]) {
			L = m + 1;
		}
		if (arr[m] > arr[m + 1]) {
			R = m;
		}
	}
	std::cout << "The highest value is: " << arr[L] << " and the index is: " << L << std::endl;
	system("pause");
}