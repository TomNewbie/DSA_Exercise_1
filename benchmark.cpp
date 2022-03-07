#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void generateRand(int arr[], int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = rand();
    }
}
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int pIndex = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[r]);
    return pIndex;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r) {
        int q = partition(arr, l, r);
        quickSort(arr, l, q - 1);
        quickSort(arr, q + 1, r);
    }
}

void array_merge(int arr[], int l, int m, int h)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = h - m;
    int L[n1], H[n2];
    for (i = l; i <= m; i++) {
        L[i - l] = arr[i];
    }
    for (j = m + 1; j <= h; j++) {
        H[j - m - 1] = arr[j];
    }
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] > H[j]) {
            arr[k] = H[j];
            k++, j++;
        }
        else {
            arr[k] = L[i];
            k++, i++;
        }
    }
    for (i; i < n1; i++) {
        arr[k] = L[i];
        k++;
    }
    for (j; j < n2; j++) {
        arr[k] = H[j];
        k++;
    }
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h) {
        int m = l + (h - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        array_merge(arr, l, m, h);
    }
}
void insertion_sort(int arr[], int length)
{
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void merge_sort(int arr[], int length)
{
    mergeSort(arr, 0, length - 1);
}

void quick_sort(int arr[], int length)
{
    quickSort(arr, 0, length - 1);
}
void copyArray(int arr_source[], int arr_dest[], int length)
{
    for (int i = 0; i < length; i++) {
        arr_dest[i] = arr_source[i];
    }
}

auto executionTime(int length, int arr[], void (*func)(int[], int))
{
    double sum = 0;
    int quicksort[length];
    copyArray(arr, quicksort, length);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    func(quicksort, length - 1);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(t2 - t1);
    return duration.count();
    // cout << "Time run: " << sum / 1000 << endl;
    // cout << "-----------" << endl;
}

void benchmark(int length, int numGenerate = 10)
{
    cout << "Number element: " << length << endl;
    double sum_qs = 0, sum_merge = 0, sum_insert = 0;
    for (int i = 0; i < numGenerate; i++) {
        int arr[length];
        generateRand(arr, length);
        sum_qs += executionTime(length, arr, quick_sort);
        sum_insert += executionTime(length, arr, insertion_sort);
        sum_merge += executionTime(length, arr, merge_sort);
    }
    cout << "Time run Quicksort " << sum_qs / (1000000 * numGenerate) << endl;
    cout << "Time run Merge " << sum_merge / (1000000 * numGenerate) << endl;
    cout << "Time run Insertion " << sum_insert / (1000000 * numGenerate) << endl;

    cout << "-----------" << endl;
}

int main()
{
    benchmark(10);
    benchmark(50);
    benchmark(100);
    benchmark(200);
    benchmark(500);
    benchmark(1000);
    benchmark(2000);
    benchmark(5000);
    benchmark(10000);
    benchmark(20000);
    benchmark(50000);
    benchmark(100000);
    return 0;
}