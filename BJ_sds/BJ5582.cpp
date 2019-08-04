/*
LCS 최장 공통 부분문자열 (연속)
DP
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string A, B;
int arr[4001][4001] = { 0 };

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> A;
	cin >> B;
	int c = A.length();	//	6 0~5
	int r = B.length();	//	6

	int ans = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (B[i-1] == A[j-1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				ans = arr[i][j] > ans ? arr[i][j] : ans;
			}
		}
	}
	cout << ans << endl;

	return 0;
}