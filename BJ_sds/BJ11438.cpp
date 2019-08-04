/*
lca���� �� parents�� [�ڽ�][2^n]�θ� 2���� �迭�� �����ؼ� ���� �ö󰡸� ������ ���ϵ��� �Ѵ�
p[7][6] = [p[7][5]][5] -> �� 64ĭ �ö� �θ�� 32ĭ �ö� �θ��� 32ĭ �ö� �θ�. �̷������� memoization
100ĭ ���� ���ؾ��Ѵٸ� 64+32+. . �ϸ� lgN�ȿ� ���� ����
�̶� root���� �� ���� �ö󰡰� �Ǹ� �ʱⰪ�� 0�̱� ������ ������ �ȿö󰣴�.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int LGN = 21;
const int MAX_N = 100010;
vector<int> adj[MAX_N];	// ���� ����Ʈ
int lv[MAX_N], parent[MAX_N][LGN+1], v[MAX_N];

// ��ó�� ����
void dfs(int here) {
	v[here] = 1;
	int next;	// �̰� ������ϰ� �׳� adj�� �ڵ徲�� �޸� ���� �Ƴ� �� �ִ�.
	for (int i = 0; i < (int)adj[here].size(); ++i) {
		next = adj[here][i];
		if (v[next]) continue;

		lv[next] = lv[here] + 1;

		parent[next][0] = here;
		for (int j = 1; j <= LGN; ++j) { // dfs ���� ���߿� �θ� ������ ���� ����
			parent[next][j] = parent[parent[next][j - 1]][j - 1];
		}

		dfs(next);
	}
}

int lca(int a, int b) {
	if (lv[a] > lv[b]) {	// �Ʒ� ������ ���� �� a<b�� ����
		swap(a, b);
	}

	for (int i = LGN; i >= 0; --i) {
		if (lv[b] - lv[a] >= (1 << i)) {
			b = parent[b][i]; // b���� 2^i��ŭ ���� �ִ� �θ�� �ѹ��� ����
		}
	}

	if (a == b) return a;	//	�������� return

	for (int i = LGN; i >= 0; --i) {
		if (parent[a][i] != parent[b][i]) {	//	�θ� �ٸ��� ���� ����������. �ö󰡵� �ȴ�
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int main() {
	//freopen("Input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int N; 
	int root;
	scanf("%d", &N);
	int a,b;
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	lv[1] = 0;	// root node
	dfs(1); // �ƹ����̳� root�� �׳� ����

	int M, r, s;
	scanf("%d", &M);
	while(M--) {
		scanf("%d %d", &r, &s);
		printf("%d\n", lca(r, s));
	}


	return 0;
}