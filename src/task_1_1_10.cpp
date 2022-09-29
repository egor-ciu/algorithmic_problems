/*
 * 1.1.10. Та же задача, если требуется, чтобы число операций было
					 пропорционально log n. (Переменные должны быть целочисленными.)
					 [Указание. Пара соседних чисел Фибоначчи получается из предыдущей умножением на матрицу
					 1 1
					 1 0
					 — так что задача сводится к возведению матрицы в степень n. Это можно сделать за C log n действий тем же способом, что и для чисел.]
 */

#include <iostream>
#include <ctime>
using namespace std;

void pow_matrix(uint64_t* matrix, uint64_t n) {
	if (n == 1) return;

	uint64_t k = n / 2;

	uint64_t matrix_2[4];

	matrix_2[0] = matrix[0] * matrix[0] + matrix[1] * matrix[2];
	matrix_2[1] = matrix[0] * matrix[1] + matrix[1] * matrix[3];
	matrix_2[2] = matrix[2] * matrix[0] + matrix[3] * matrix[2];
	matrix_2[3] = matrix[2] * matrix[1] + matrix[3] * matrix[3];

	pow_matrix(matrix_2, k);

	if (n % 2 == 0) {
		matrix[0] = matrix_2[0];
		matrix[1] = matrix_2[1];
		matrix[2] = matrix_2[2];
		matrix[3] = matrix_2[3];
	} else {
		uint64_t matrix_3[4];
		matrix_3[0] = matrix_2[0] * matrix[0] + matrix_2[1] * matrix[2];
		matrix_3[1] = matrix_2[0] * matrix[1] + matrix_2[1] * matrix[3];
		matrix_3[2] = matrix_2[2] * matrix[0] + matrix_2[3] * matrix[2];
		matrix_3[3] = matrix_2[2] * matrix[1] + matrix_2[3] * matrix[3];

		matrix[0] = matrix_3[0];
		matrix[1] = matrix_3[1];
		matrix[2] = matrix_3[2];
		matrix[3] = matrix_3[3];
	}


}

int fast_fibonacci_number(uint64_t n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	uint64_t matrix[4] = {2, 1, 1, 1};

	uint64_t k = n / 2;

	pow_matrix(matrix, k);

	if (n % 2 == 0) {
		return matrix[2];
	} else {
		return matrix[0];
	}

}


int fibonacci_number(uint64_t n, uint64_t& k) {
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


int main() {
	uint64_t n;
	cin >> n;
	uint64_t k = 0;

	unsigned int start_2 = clock();
	uint64_t result_2 = fast_fibonacci_number(n);
	unsigned int end_2 = clock();
	cout << n << " число последовательности Фибоначчи (быстро): " << result_2 << endl;
	cout << "Время: " << end_2 - start_2 << endl;

	unsigned int start_1 = clock();
	uint64_t result_1 = fibonacci_number(n, k);
	unsigned int end_1 = clock();
	cout << n << " число последовательности Фибоначчи (медленно): " << result_1 << endl;
	cout << "Время: " << end_1 - start_1 << endl;


	return 0;
}
