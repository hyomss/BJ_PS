#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N = 102;
int arr[MAX_N][MAX_N];

void pascal(int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (j == 0 || j == i) {
				arr[i][j] = 1;
				continue;
			}
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
		}
	}
}

int main() {
	int A, Z, k;
	cin >> A >>Z >> k;

	vector <char> s;

	for (int i = 0; i < A; ++i) {
		s.push_back('a');
	}
	for (int j = A; j < A + Z; ++j) {
		s.push_back('z');
	}
	sort(s.begin(), s.end());

	
	return 0;
}