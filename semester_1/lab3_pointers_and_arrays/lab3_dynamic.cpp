
// solve task with usage of
// dymanic arrays
#include <iostream>

void Delete(int* arr, int size, int m) {
    int k = 0;
    for (int i = 0; i < size; i++) {

        if (abs(arr[i]) == abs(m)) {
            arr[size] = 0;
            k = k + 1;
        }
        else
            std::cout << arr[i]<<' ';
      }
    if (k > 0) {
        for (int d = 1; d <= k; d++) {
            std::cout << '0' << ' ';
        }
      }
    }

    int main (){
    
    int arr[20], n, k;
    int *array = new int[20];
    std::cin >> n>>k;
    for (int i=0; i<n; i++){
        std::cin >> array[i];
    }
    std::cout << "arr[] = { ";
    Delete(array, n, k);
    std::cout << "}";
    delete[] array;
    return 0;
}
