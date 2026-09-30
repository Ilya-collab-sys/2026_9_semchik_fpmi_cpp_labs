
// solve task with usage of
// static arrays
int main() {
	int i, n, m=0;
	int a[5] = { 6, 5, 8, 9, 3 };
	int* p = &a[0];
	std :: cin >> n;
	for (i=0; i<5; i++){
		if (abs(p[i]) == abs(n)) {
			m = m + 1;
		}
		else
			std::cout << p[i]<<' ';	    
  }
	if (m > 0) {
		for (int k = 1; k <= m; k++) {
			std::cout << '0' << ' ';
		}
	}
    return 0;
}
