/*
DP안쓰고 풀 수 있다. 피보나치 수열로 탑다운 하거나 바텀업 해서 풀 수 있다.
NlgN 이하로 풀어야 한다.
*/
#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int main() {
	int N, M;
	int arr[MAX][3];
	int max_arr[MAX][3];
	int min_arr[MAX][3];
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int a = max_arr[i][j - 1], b = max_arr[i][j], c = max_arr[i][j + 1];
			max_arr[i][j] = max(a, b, c) + arr[i][j];
		}
	}
	int max_ans = max(max_arr[N - 1][0], max_arr[N - 1][1], max_arr[N - 1][2]);
	int min_ans = min(min_arr[N - 1][0], min_arr[N - 1][1], min_arr[N - 1][2]);
	return 0;
}