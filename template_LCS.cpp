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


	/*연속 안해도 될 때 */
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
	cout << ans << endl;	// 공통 문자열 길이


	/*연속해야 될 때*/
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (B[i - 1] == A[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				ans = arr[i][j] > ans ? arr[i][j] : ans;
			}
		}
	}



	string lcs = "";	//	공통 문자열
	int j_tmp = c;
	for (int i = r; i >= 1; i--) {
		for (int j = j_tmp; j >= 1; j--) {
			if (arr[i][j] == ans && arr[i][j - 1] == ans - 1 && arr[i - 1][j] == ans - 1) {
				lcs = A[j - 1] + lcs;
				ans--;
				j_tmp = j;
				break;
			}
		}
	}

	cout << lcs << endl;

	return 0;
}