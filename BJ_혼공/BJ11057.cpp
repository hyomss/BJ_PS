#include <iostream>
using namespace std;

int N;
int dp[1010][11];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> N;


	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		cnt += dp[N][i];
	}

	cout << cnt%10007;



	return 0;
}