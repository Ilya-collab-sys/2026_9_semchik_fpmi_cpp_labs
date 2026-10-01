
// solve task with usage of
// dymanic arrays
void Delete(int* arr, int size, int m) {
    int k = 0;
    for (int i = 0; i < size; i++) {

        if (arr[i] == m) {
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
    int n;
    int a[5] = { 4, 5, 6, 7, 8 };
    std::cin >> n;
   
    Delete(a, 5, n);
    
    delete[] a;
    return 0;
}
