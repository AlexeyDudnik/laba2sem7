#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
void Sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void Print(const string& threadName, vector<int>& arr, int start, int end) {
    cout << threadName << endl;
    Sort(arr);
    for (int i = start; i < end; i++) {
        cout << arr[i] << " ";
        this_thread::sleep_for(chrono::milliseconds(10));
    }
    cout << endl;
}
void random(vector<int>& arr) {
    srand(time(nullptr));
    for (int& el : arr) {
        el = rand() % 100 + 1;
    }
}
int main() {
    int size = 6;
    vector<int> arr(size);
    random(arr);
    thread thread1(Print, "thread1 ", ref(arr), 0, size / 2);
    thread1.join();
    thread thread2(Print, "thread2 ", ref(arr), size / 2, size);
    thread2.join();
    thread thread3(Print, "thread3 ", ref(arr), 0, size);
    thread3.join();
    cout << "All threads finished" << endl;
    return 0;
}
