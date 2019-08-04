/*
DP
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[201]; // K<=20;
int dp[201][201];// = { 98765432 };

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	
	
   for (int l = 1; l <= N; l++) {
		for (int i = 1; i <= N-l; i++) {
			dp[i][i + l] = 98765432;
			for (int k = i; k < i + l; k++) {
				dp[i][i + l] = min(dp[i][i + l], dp[i][k] + dp[k + 1][i + l] + (arr[i] != arr[k + 1]));
			}
		}
	}

	cout << dp[1][N] << endl;

	return 0;
}