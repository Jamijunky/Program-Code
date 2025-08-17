#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int fact = 1;
	vector<int> digits;
	for (int i = 0; i < 10; ++i) {
		fact *= i + 1;
		digits.push_back(i);
	}
	int pos = 1000000 - 1;
	for (int i = 10; i > 0; --i) {
		fact /= i;
		printf("%d", digits[pos / fact]);
		digits.erase(digits.begin() + pos / fact);
		pos -= fact * (pos / fact);
	}
	puts("");
}