//6. Разработайте программу решения задачи поиска минимального значения среди максимальных элементов строк матрицы
#include <cstdlib>
#include <iostream>
using namespace std;
#include <omp.h>

int main() {
	const int row = 500, col = 400;
	int m[row][col];
	int max_row[row];
	int max_int = 0;
	int min_int = RAND_MAX;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			m[i][j] = rand();
			//cout << m[i][j] << " ";
		}
		//cout << endl;
	}

	auto start = omp_get_wtime();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (m[i][j] > max_int) max_int = m[i][j];
		}
		max_row[i] = max_int;
		if (max_int < min_int) {
			min_int = max_int;
		}
		max_int = 0;
	}
	auto end = omp_get_wtime();
	cout << min_int << "\n";
	std::cout << "The time: " << start-end << "\n";
	return 0;
}
