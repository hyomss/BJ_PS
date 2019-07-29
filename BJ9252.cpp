/*
LCS 최장 공통 부분문자열 
DP
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string A, B;
int arr[1001][1001] = { 0 };

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> A;
	cin >> B;
	int c = A.length();	//	6 0~5
	int r = B.length();	//	6

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (A[j - 1] == B[i - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}
	int ans = arr[r][c];
	cout << ans << endl;

	string lcs = "";
	int j_tmp = c;
	for (int i = r; i >= 1; i--) {
		for (int j = j_tmp; j >=1; j--) {
			if (arr[i][j] == ans && arr[i][j-1] == ans-1 && arr[i-1][j] == ans-1	 ) {
				lcs = A[j-1] + lcs;
				ans--;
				j_tmp = j;
				break;
			}
		}
	}

	cout << lcs << endl;

	return 0;
}