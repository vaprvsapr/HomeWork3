#include <iostream>
#include <algorithm>
#include <map>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

#include <ctime>
#include <random>

using namespace std;

void PrintMap(const map<size_t, string>& res) {
    for(auto& element : res) {
        cout << element.second << ": " << element.first << endl;
    }
}

int main() {
    vector<int> data;
    const uint64_t size_of_data = 100000;
    map<size_t, string> results;

    for(int i = 0; i < size_of_data; i ++) {
        data.push_back(rand() % size_of_data);
    }

    vector<int> test_vector = data;
    array<int, size_of_data> test_array{};
    forward_list<int> test_forward_list;
    deque<int> test_deque;
    list<int> test_list;

    for(int i = 0; i < size_of_data; i++) {
        test_array[i] = data[i];
        test_forward_list.push_front(data[i]);
        test_deque.push_back(data[i]);
        test_list.push_back(data[i]);
    }

    auto time = clock();
    sort(test_vector.begin(), test_vector.end());
    results[clock() - time] = "vector";

    time = clock();
    sort(test_array.begin(), test_array.end());
    results[clock() - time] = "array";

    time = clock();
    test_list.sort();
    results[clock() - time] = "list";

    time = clock();
    test_forward_list.sort();
    results[clock() - time] = "forward list";

    time = clock();
    sort(test_deque.begin(), test_deque.end());
    results[clock() - time] = "deque";

    PrintMap(results);
}
