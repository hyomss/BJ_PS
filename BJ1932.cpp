/*
DP
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N; //~500
int tri[501][501];
int tmp[501][501];

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	tmp[0][0] = tri[0][0];
	for (int i = 0; i < N-1;i++) {
		for (int j = 0; j <= i+1;j++) {
			//cout << endl<<  "i j" << i << j << endl;
		/*	if (j == 0 || j == i) {
				tmp[i + 1][0] = tri[i + 1][0] + tmp[i][0]; cout << tmp[i + 1][0] << "/";
				if (j == i) {
					tmp[i + 1][i + 1] = tri[i + 1][i + 1] + tmp[i][i]; cout << tmp[i + 1][i + 1] << "|";
				}
			}*/
				tmp[i + 1][j] = tri[i + 1][j] + max(tmp[i][j - 1], tmp[i][j]); //cout << tmp[i + 1][j] << "-";
			
		}
		//cout << endl;
	}
	int ans =0;
	for (int j = 0; j < N; j++) {
		if (tmp[N - 1][j] > ans) ans = tmp[N - 1][j];
	}
	cout << ans;

	return 0;
}