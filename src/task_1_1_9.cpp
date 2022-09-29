/*
 * 1.1.9. Последовательность Фибоначчи определяется так: a0 = 0,
					a1 = 1, ak = ak-1 + ak-2 при k > 2. Дано n, вычислить an.
 */

#include <iostream>
using namespace std;

int fibonacci_number(int n, int& k) {
	if (n == 0) return 0;

	int number = 1;
	int prev_number = 0;
	for (int i = 1; i < n; ++i) {
		int temp = number;
		number += prev_number;
		++k;
		prev_number = temp;
	}


	return number;
}


int main() {
	int n;
	cin >> n;
	int k = 0;

	cout << n << " число последовательности Фибоначчи: " << fibonacci_number(n, k) << endl;
	cout << "Количество операций: " << k << endl;
	return 0;
}
