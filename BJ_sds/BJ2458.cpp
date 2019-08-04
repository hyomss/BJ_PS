/*
DFS
나보다 작은 애 + 큰 애 = N - 1 이면 내 키를 정확히 알 수 있다.
나보다 키가 작은 애는 간선 반향을 뒤집어서 구한다.
*/

#include <iostream>
using namespace std;
#define MAX_N 510

int edge[MAX_N*(MAX_N - 1) / 2];
bool chk[MAX_N*(MAX_N - 1) / 2];

int cnt;
void DFS(int i) {
	chk[i] == 1;
	int next = edge[i];
	if (chk[next] == '0') {
		DFS(next);
		cnt++;
		cout << i;
	}
}

void iDFS(int i) {

}

int main() {
	freopen("Input.txt", "r", stdin); freopen("output.txt", "w", stdout);


	int N, M;
	int ans = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		edge[s] = e;
	}
	memset(chk, '0', sizeof(chk));
	for (int i = 0; i < N; i++) {
		cnt = 0;
		DFS(i);
		iDFS(i);

		if (cnt == N + 1) ans++;	//	자기 자신이 두번 세어진다.
	}

	cout << ans;

	return 0;
}