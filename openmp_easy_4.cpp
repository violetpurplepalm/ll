//Напишите программу перемножения больших матриц. Сравните врем выполнения последовательной и параллельной программы на 2,4, 8 потоках (процессорах).

#include <cstdlib>
#include <iostream>
using namespace std;
#include <omp.h>

int main(){
int num_threads = 4;
int len1 = 1000;
int len2 = 500;
int** m1 = new int* [len1];
for (int i = 0; i < len1; i++) {
	m1[i] = new int[len2];
	for (int j = 0; j < len2; j++)
		m1[i][j] = rand() % 200 + 1; // Заполняем первую матрицу числами от 1 до 200
}
int** m2 = new int* [len2];
for (int i = 0; i < len2; i++) {
	m2[i] = new int[len1];
	for (int j = 0; j < len1; j++)
		m2[i][j] = rand() % 200 + 1; // Заполняем вторую матрицу числами от 1 до 200
}

int** res = new int* [len1];
for (int i = 0; i < len1; i++) {
	res[i] = new int[len1];
	for (int j = 0; j < len1; j++)
		res[i][j] = 0;
}

double start, end;
start = omp_get_wtime();

#pragma omp parallel shared(m1, m2, res) num_threads(num_threads)
{
#pragma omp for ordered 
	for (int i = 0; i < len1; i++)
	{	for (int j = 0; j < len1; j++)
			for (int k = 0; k < len2; k++)
				res[i][j] += m1[i][k] * m2[k][j];
	}
}
end = omp_get_wtime();

cout << "threads: " << num_threads << " the time: " << end - start << endl;
return 0;
}

//threads: 2 the time : 1.88319
//threads: 4 the time: 1.86573
//threads: 8 the time: 1.87556

