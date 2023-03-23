
///Написать программу где каждый поток печатает свой идентификатор,
///количество потоков всего и строчку «Hello World».
/// Запустить программу с 8 потоками. Всегда ли вывод идентичен ? Почему ?
#include <iostream>
#include <omp.h>

using namespace std;
int main(){
    int id, thr;
 //omp_set_num_threads(8);
    #pragma omp parallel num_threads(8)
    {
        cout << " ID: " << omp_get_thread_num() << " Threads: " << omp_get_num_threads() << " Hello world\n";
    }
}
//Вывод неидентичен. Порядок нитей на каждом запуске разный, какая нить быстрее успела выполнить - та и по порядку раньше написана  
