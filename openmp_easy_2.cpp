
//Написать программу, в которой объявлен массив из 16000 элементов и инициализирован так,
//что значение элемента массива равно его порядковому номеру. Затем создайте результирующий массив,
//в котором (за исключением крайних элементов) будут средние значения исходного массива:
//b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0
//Запустите программу с 8 - ю процессами при различных типах распределения работ.

#include <iostream>
#include <omp.h>

using namespace std;
int main()
{
    const int n = 16;
    int a[n], b[n], c[n];
    #pragma omp parallel num_threads(8) 
    //#pragma omp parallel for num_threads(8) - способ 2
    #pragma omp for
    for (int i = 0; i < n; i++) {
        a[i] = i;
        //cout << omp_get_wtime()<<"\n";
    }
    //#pragma omp parallel for num_threads(8) - способ 2 
    #pragma omp for
    for (int i = 0; i < n; i++) {
        if ((i == 0) or (i == n - 1)) {
            b[i] = a[i];
        }
        else b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
        cout << b[i] << " ";
        //cout << omp_get_wtime() << "\n";
    }
}
