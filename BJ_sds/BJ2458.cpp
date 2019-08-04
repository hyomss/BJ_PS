/*
DFS
������ ���� �� + ū �� = N - 1 �̸� �� Ű�� ��Ȯ�� �� �� �ִ�.
������ Ű�� ���� �ִ� ���� ������ ����� ���Ѵ�.
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

		if (cnt == N + 1) ans++;	//	�ڱ� �ڽ��� �ι� ��������.
	}

	cout << ans;

	return 0;
}