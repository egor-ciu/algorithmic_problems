/*
 * 1.1.9. ������������������ ��������� ������������ ���: a0 = 0,
					a1 = 1, ak = ak-1 + ak-2 ��� k > 2. ���� n, ��������� an.
 */

#include <iostream>
using namespace std;

uint64_t fibonacci_number(uint64_t n, int& k) {
	if (n == 0) return 0;

	uint64_t number = 1;
	uint64_t prev_number = 0;
	for (uint64_t i = 1; i < n; ++i) {
		uint64_t temp = number;
		number += prev_number;
		++k;
		prev_number = temp;
	}


	return number;
}

void run_task_1_1_9() {
	uint64_t n;
	cin >> n;
	int k = 0;

	cout << n << " ����� ������������������ ���������: " << fibonacci_number(n, k) << endl;
	cout << "���������� ��������: " << k << endl;
}
