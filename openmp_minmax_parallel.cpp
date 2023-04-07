//6. Разработайте программу решения задачи поиска минимального значения среди максимальных элементов строк матрицы
#include <cstdlib>
#include <iostream>
using namespace std;
#include <omp.h>

int main() {
	const int row = 500, col = 400;
	int** m = new int* [row];
	int max_row[row];
	int max_int = 0;
	int min_int = RAND_MAX;

	cout << "matrix:\n";
	for (int i = 0; i < row; i++) {
		m[i] = new int[col];
		for (int j = 0; j < col; j++) {
			m[i][j] = rand();
			//cout << m[i][j] << " ";
		}
		//cout << endl;
	}

	auto start = omp_get_wtime();
	#pragma omp parallel shared(m, min_int) num_threads(16)
	#pragma omp for ordered
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
	cout <<"MINMAX: " << min_int << "\n";
	std::cout << "The time: " << end - start  << "\n";
	return 0;
}
