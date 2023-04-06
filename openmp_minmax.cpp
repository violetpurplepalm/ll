//6. Разработайте программу решения задачи поиска минимального значения среди максимальных элементов строк матрицы
#include <cstdlib>
#include <iostream>
using namespace std;
#include <chrono>

int main() {
	const int row=500, col=400;
	int m[row][col];
	int max_row[row];
	int max_int = 0;
	int min_int = RAND_MAX;
	auto begin = std::chrono::steady_clock::now();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			m[i][j] = rand();
			//cout << m[i][j] << " ";
		}
		//cout << endl;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (m[i][j] > max_int) max_int = m[i][j];
		}
		max_row[i] = max_int;
		//cout << max_int << " ";
		max_int = 0;
	}
	for (int i = 0; i < row; i++) {
		if (max_row[i] < min_int) {
			min_int = max_row[i];
		}
	}
	cout << min_int << "\n";
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n";
	return 0;
}
