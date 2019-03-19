#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <math.h>
#include <algorithm>
#include "numbers.dat"
using namespace std;

bool prostoNumer(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	if (n == 1) return false;
	return true;
}

int main(int argc, char* argv[])
{
	if ((argc % 2) == 0 || argc == 1) {
		return -1;
	}
	vector<int> numbers;
	int i;
	for (i = 1; i < argc; i++)
	{
		int v = atoi(argv[i]);
		numbers.push_back(v);
		int z;
		if ((i % 2) != 1 && i > 2) {
			int b = numbers[i - 2];
			bool indicator2 = false;
			for (z = 0; z < (numbers.size() - 2); z++) {
				if (v >= numbers[z] && b <= numbers[z + 1]) {
					numbers[z] = max(numbers[z], b);
					numbers[z + 1] = min(numbers[z + 1], v);
					indicator2 = true;
				}
				z++;
			}
			if (indicator2) {
				numbers.pop_back();
				numbers.pop_back();
			}
		}
	}
	int kol = 0;
	int x;
	for (x = 0; x < numbers.size(); x++) {
		int i, j, k;
		bool indicator = false;
		bool indicator1 = false;
		for (i = 0; i < Size; i++) {
			if (numbers[x] == Data[i]) {
				indicator = true;
				break;
			}
			if (numbers[x] < Data[i]) {
				break;
			}
		}

		for (j = i; j < Size; j++) {
			if (numbers[x+1] == Data[j]) {
				indicator1 = true;
			}
			if (numbers[x+1] < Data[j]) {
				break;
			}
		}

		if (indicator == false || indicator1 == false) {
			cout << 0 << endl;
			return 0;
		}

		bool indicator2;

		for (k = i; k < j; k++) {
			indicator2 = prostoNumer(Data[k]);
			if (indicator2)
				kol++;
		}
		x++;
	}

	cout << kol << endl;
	return 0;
}
