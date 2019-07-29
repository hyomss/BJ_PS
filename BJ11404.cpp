/*
플로이드 워셜
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 100001;
const int MAX_N = 105;

int N, M;
int d[MAX_N][MAX_N];
void floyd() {
	for (int i = 1; i <= N; ++i) {  // 경유점
		for (int j = 1; j <= N; ++j) {  // 시작점
			for (int k = 1; k <= N; ++k) {  // 종료점
				// 시작점~경유점 + 경유점~종료점 < 시작점~종료점
				if (d[j][i] + d[i][k] < d[j][k]) {
					d[j][k] = d[j][i] + d[i][k];
				}
			}
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}

	int a, b, we;
	for (int i = 1; i <= M; ++i) {
		scanf("%d %d %d", &a, &b, &we);
		d[a][b] = min(d[a][b],we);
	}

	floyd();

	for (int i =1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (d[i][j] == INF) cout << 0 << " ";
			else cout << d[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}