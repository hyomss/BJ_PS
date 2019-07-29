/*
DP
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
pair <int ,int> A[101];	//	<c.m>
int cost[101] = { 0 };
int mem[101] = { 0 };

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> A[i].second;
	}
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first;
	}

	sort(A, A + N+1);
	for (int i = 1; i <= N; i++) {
		mem[i] = mem[i - 1] + A[i].second;
		cost[i] = cost[i - 1] + A[i].first;
	}

	int ans =0;
	for (int i = 1; i <= N; i++) {
		if (mem[i] >= M) {
			ans = i;
			break;
		}
	}
	cout << cost[ans] << endl;;

	return 0;
}