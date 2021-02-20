// Исследование системы выделения памяти в векторе
#include <vector>
#include <iostream>

using namespace std;

void Analysis(const vector<int>& v) {
    cout << "capacity: " << v.capacity() << "; size: " << v.size() << endl;
}

int main() {
    vector<int> vector_of_integers;
    Analysis(vector_of_integers); // Вектор пустой. Ёмкость вектора 0, Количество элементов 0;
    vector_of_integers.push_back(0); // Добавили элемент.
    Analysis(vector_of_integers);
    vector_of_integers.push_back(1); // Добавили элемент.
    Analysis(vector_of_integers);
    vector_of_integers.push_back(2); // Добавили элемент.
    Analysis(vector_of_integers);
    // Интересный результат. Добавили 1 элемент.
    // Размер стал равен 3. Ёмкость - 4.
    // Наталкивает на мысли... Продолжим исследование.

    vector_of_integers.push_back(3);
    vector_of_integers.push_back(4);
    vector_of_integers.push_back(5);
    vector_of_integers.push_back(6);
    vector_of_integers.push_back(7);
    Analysis(vector_of_integers);
    vector_of_integers.push_back(8);
    Analysis(vector_of_integers); // Размер вектора снова увеличился вдвое.
    vector_of_integers.push_back(9);
    Analysis(vector_of_integers);
    // Делаем вывод: при переполнении вектора его размер увеличивается вдвое.
    cout << "===========================" << endl;
    // reserve
    vector<int> vector_with_reserved_memory;
    vector_with_reserved_memory.reserve(4);
    Analysis(vector_with_reserved_memory); // При отсутствии элементов в векторе, ёмкость уже равна 4.
    vector_with_reserved_memory.push_back(0);
    vector_with_reserved_memory.push_back(0);
    vector_with_reserved_memory.push_back(0);
    vector_with_reserved_memory.push_back(0);
    Analysis(vector_with_reserved_memory);
    vector_with_reserved_memory.push_back(0);
    Analysis(vector_with_reserved_memory);
    /* В ходе испытаний выяснилось, что разные среды разработки по разному изменяют capacity.
     * Пример: CLion стабильно увеличивает capacity в два раза.
     * Среда VS может увеличить capacity на 4 (line 33), или на 2 (line 46)*/

    cout << "===========================" << endl;
    vector<int> really_big_vector;
    //    for(int i = 0; i < 1000000; i++) {
    //        really_big_vector.push_back(0);
    //    }
    //    Analysis(really_big_vector);
    //
    //    for(int i = 0; i < 10000000; i++) {
    //        really_big_vector.push_back(0);
    //    }
    //    Analysis(really_big_vector);
    //
    //    for(int i = 0; i < 100000000; i++) {
    //        really_big_vector.push_back(0);
    //    }
    //    Analysis(really_big_vector);
    //
    //    for(int i = 0; i < 1000000000; i++) {
    //        really_big_vector.push_back(0);
    //    }
    //    Analysis(really_big_vector); // push_back миллиарда эллементов занимает около 10 секунд. Память не кончается. Пока.

    // reserve большого вектора.

    really_big_vector.reserve(1000'000'000); // Памяти хватает.
    Analysis(really_big_vector);
    really_big_vector.reserve(10'000'000'000); // Памяти хватает.
    Analysis(really_big_vector);
//    really_big_vector.reserve(100'000'000'000); // Памяти не хватает.
//    Analysis(really_big_vector);
    // Выброшено исключение: terminate called after throwing an instance of 'std::bad_alloc'
    // Вывод: порядок максимального размера вектора: 10^11.
}
