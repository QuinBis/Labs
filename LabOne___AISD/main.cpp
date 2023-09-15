#include <iostream>
#include <time.h>
#include <math.h>

#include "Header.h"

// ����� ������������ ������������� ������ ��� ���������� = (n-1)! (��� ������ �������� ����� ���������� - ��������� ����)
// ������� ������ �������� �� ��������� ��������.


int main(int) {

	/*========================������������� ����������========================*/

	int numberCities, startCity, waylength = 0, minlength = 0;

	std::cout << "Enter the number of cities : "; std::cin >> numberCities;
	std::cout << "Enter the starting city : "; std::cin >> startCity; std::cout << "\n";

	int **MatricWays = CreatingMatric(numberCities);
	//InputMatric(MatricWays, numberCities);
	RundNumMatric(MatricWays, numberCities);
	OutputMatric(MatricWays, numberCities, numberCities);

	// ������ Ways ��� ��������� �����, ��� ������ ������ ���� numberCities+1 (��������� �������� ������� 1-2-3-1).
	// ������ minimumWay ��� ������ �������� � ����������� ����������.
	int *Ways = CreatingArray(numberCities + 1), *minimumWay = CreatingArray(numberCities + 1);




	/* ===================== ��������� ������� ���� � ���������� ��������� �������� ========================= */

	for (int i = 0, countCities = 1, previndex = 0; i < numberCities;) {
		if (i == 0) { // ������ �������� 1 � ��������� ��������� �� �������� ���������� ������.
			Ways[i] = startCity;
			Ways[numberCities] = startCity;
			minimumWay[numberCities] = startCity;
			minimumWay[i] = startCity;
			i++;
		}

		else if (countCities == startCity) { countCities++; } // ���� ������� ����� = ����������, ��������� ������� ����� �� 1.

		else { // �� ���� ���� �������, ������ ���������� ������, ������ �� �����.
			Ways[i] = countCities;
			countCities++;
			i++;
		}
	}

	std::cout << "\nThe first way looks like this : ";
	OutputArray(Ways, numberCities + 1);
	waylength = CostOfTheWay(Ways, MatricWays, numberCities);
	std::cout << "\nThe cost of the way : : " << waylength << std::endl;

	minlength = waylength; // ����� ����� ��������� ������� �������� �� �����������, � ����������� ����� ����������.
	CopyArray(Ways, minimumWay, numberCities); // ���������� � ��� �������.

	// ���������� ��������� ��������.

	int numberofcycles = Factorial(numberCities-1); // ����� ��������� ���� (n-1)! ���, ������ �� ����� ������. (n-1)! - ���������� ������������ ���������� ������.

	int countCycles = 1;

	while (countCycles != numberofcycles) {
		/* ============= �������� ���������� ������ �������� ============ */
		for (int i = numberCities-2; i >= 1; i--) {
			int next_index = i + 1;
			// ���� ������ ������� , ������� �� ������� �� ����� ������, ���� ����� ������ ���� ������ ����������.
			if ( (i < numberCities-1) && (Ways[i] < Ways[next_index]) ) { 
				// ��� ������ ����� ����� �����, �������� ������ ������.
				for (int j = numberCities - 1; j > i;j--) {
					// ��������� ����� ���� � �����, ���� ����� ������ ���� ������ �� �������� ��� ������.
					if ( ( j <= numberCities-1) && ( Ways[i] < Ways[j] )) {

						// ������ ������ ������� ������
						// � ������� ����� ������ ��������, � ������ ���� ���� ������� �������� �������, ���������� ���.
						
						SwapElementInArray(Ways[i], Ways[j]);
						for (int invert_i = i + 1, invert_j = numberCities - 1; invert_i <= invert_j;invert_i++,invert_j--) {
								SwapElementInArray(Ways[invert_i], Ways[invert_j]);
							}

						waylength = CostOfTheWay(Ways, MatricWays, numberCities);

						if (minlength > waylength) {
							minlength = waylength;
							CopyArray(Ways, minimumWay, numberCities);
						}

						std::cout << "\nCompleted permutation : ";
						OutputArray(Ways, numberCities+1);
						std::cout << "\nThe cost of the way : " << waylength << std::endl;
						i = numberCities - 1;
						countCycles++; // ���������� ��� �� ������� 1 ������������
						std::cout << "There are permutations left : " << countCycles << std::endl;
					}
				}
			}



			
		}
	}
	


	std::cout << "\nThe minimum cost way is : "; OutputArray(minimumWay, numberCities+1);
	std::cout << "\nIts cost will be as follows : " << minlength << std::endl;



	// ������������ ������ �� ������������ �������.
	RemovingArray(Ways, numberCities + 1);
	RemovingArray(minimumWay, numberCities + 1);
	RemovingMatric(MatricWays, numberCities);


	return 0;
}