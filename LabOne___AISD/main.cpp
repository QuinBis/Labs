#include <iostream>
#include <time.h>
#include <chrono>

#include "Header.h"

int main() {

	int quantityCities, startCity, currentLength;

	std::cout << "Enter the quantity of cities : ";
	std::cin >> quantityCities;
	std::cout << "Enter the starting city : ";
	std::cin >> startCity;

	if ( startCity >= quantityCities || startCity <= 0) {

		completionProgramm();

	}

	auto begin = std::chrono::steady_clock::now();

	int** matrixWays = createMatrix(quantityCities);
	inputMatrix(matrixWays, quantityCities);
	outputMatrix(matrixWays, quantityCities, quantityCities);

	int* currentWay = createArray(quantityCities + 1),
	   * minimumWay = createArray(quantityCities + 1);

	for (int i = 0, k = 1; i < quantityCities; ) {

		if (i == 0) {
			currentWay[i] = startCity;
			currentWay[quantityCities] = startCity;

			i++;
		}

		else if (k == startCity) {
			k++;
		}

		else {
			currentWay[i] = k;
			k++;
			i++;
		}

	}

	int countCycles = 1;

	std::cout << "\nPossible ways for this solution : \n";
	outputArray(currentWay, quantityCities + 1);

	currentLength = computeCostWay(currentWay, matrixWays, quantityCities);


	copyArray(currentWay, minimumWay, quantityCities + 1);


	// The number of correct cycles = (n-1)!.
	int numberofCycles = computeFactorial(quantityCities - 1), nextIndex,
		minimumLength = currentLength;



	while (countCycles != numberofCycles) {

		for (int i = quantityCities - 2; i >= 1; i--) {

			nextIndex = i + 1;

			if ( (i < quantityCities - 1) && (currentWay[i] < currentWay[nextIndex]) ) { 

				for (int j = quantityCities - 1; j > i; j--) {

					if ( (j <= quantityCities - 1) && (currentWay[i] < currentWay[j]) ) {

						swapValues(currentWay[i], currentWay[j]);

						for (int k = i + 1, l = quantityCities - 1; k <= l; k++, l--) {
								swapValues(currentWay[k], currentWay[l]);
						}


						currentLength = computeCostWay(currentWay, matrixWays, quantityCities);


						if (minimumLength > currentLength) {

							copyArray(currentWay, minimumWay, quantityCities + 1);

							minimumLength = currentLength;

						}


						outputArray(currentWay, quantityCities + 1);
						countCycles++;

						// We returned the index to the end so as not to miss the solution.
						i = quantityCities - 1;
					}
				}
			}
		}
	}
	
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	std::cout << "\nThe minimum cost way is : "; outputArray(minimumWay, quantityCities + 1);
	std::cout << "The cost of this path : " << minimumLength << std::endl;
	std::cout << "The time: " << elapsed_ms.count() << " ms\n";


	// Freeing up memory from arrays and matrix.
	destroyArray(currentWay, quantityCities + 1);
	destroyArray(minimumWay, quantityCities + 1);
	destroyMatrix(matrixWays, quantityCities);

	return 0;
}