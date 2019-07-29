/*
DP ¸ô°Ù..
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[501][501];
int mat[501][2];

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &N);

	int r, c;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &mat[i][0], &mat[i][1]);
	}

	for (int i = 0; i < N; i++) {
		dp[i][i + 1] = mat[i][0] * mat[i][1] * mat[i + 1][1];
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = i + 2; j < N; j++) {
			for (int k = i; k < j; k++) {
				int tmp = dp[i][k] + dp[k + 1][j] + mat[i][0] * mat[k][1] * mat[j][1];
				if (dp[i][j] == 0 || dp[i][j] > tmp)
					dp[i][j] = tmp;
			}
		}
	}
	cout << dp[0][N - 1] << endl;


	return 0;
}