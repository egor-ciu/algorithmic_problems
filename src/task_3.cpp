#include <iostream>
#include <vector>
#include <ctime>
#include <array>
#include "task_3.h"

using namespace std;


int compute_cycle_length(uint64_t x) {
	int result = 1;

	while (x != 1) {
		if (x % 2 == 0) {
			x /= 2;
		} else {
			x = x * 3 + 1;
		}
		++result;
	}

	return result;

}

int16_t compute_cycle_length_with_caching(uint64_t x, array<int16_t, 1000000>& cache) {
	if (x == 1) return 1;
	int16_t result;

	if (x < cache.size() && cache[x] != 0) {
		result = cache[x];
		return result;
	}

	if (x % 2 == 0) {
		result = compute_cycle_length_with_caching(x / 2, cache) + 1;
	} else {
		result = compute_cycle_length_with_caching(x * 3 + 1, cache) + 1;
	}

	if (x < cache.size()) {
		cache[x] = result;
	}

	return result;

}

void run_task_3() {
	uint64_t x, y;

	while(cin >> x >> y) {
		bool less = true;
		if (x > y) {
			uint64_t temp = x;
			x = y;
			y = temp;
			less = false;
		}

		int result = 0;
		auto start = clock();
		for (uint64_t number = x; number <= y; ++number) {
			result = max(result, compute_cycle_length(number));
		}
		auto end = clock();

		cout << end - start << " ms, operations: " << result * y << endl;

		if (less) cout << x << " " << y << " " << result << endl;
		else 	  cout << y << " " << x << " " << result << endl;
	}

}

void run_task_3_with_caching() {
	uint64_t x, y;

	array<int16_t, 1000000> cache = {0};

	while(cin >> x >> y) {
		bool less = true;
		if (x > y) {
			uint64_t temp = x;
			x = y;
			y = temp;
			less = false;
		}

		int16_t result = 0;
		auto start = clock();
		for (uint64_t number = x; number <= y; ++number) {
			int16_t cycle_length = compute_cycle_length_with_caching(number, cache);
			result = max(result, cycle_length);
		}
		auto end = clock();

		cout << end - start << " ms, operations: " << result * y << endl;

		if (less) cout << x << " " << y << " " << result << endl;
		else 	  cout << y << " " << x << " " << result << endl;
	}
}

