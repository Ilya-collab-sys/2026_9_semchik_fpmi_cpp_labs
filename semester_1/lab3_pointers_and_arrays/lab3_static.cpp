
// solve task with usage of
// static arrays

#include <iostream>

int main()
{
	int arr[20], n, k, m = 0;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::cout << "arr[] = { ";
	for (int i = 0; i < n; i++) {
		if (abs(arr[i]) == abs(k)) {
			m += 1;
		}else
	
		std::cout << arr[i] << ' ';
	}
	if (m > 0) {
		for (int d=1; d<=m; d++){
		std::cout << "0 ";}
	}
	std::cout << "}";
	return 0;
}
