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

const int LGN = 13;
const int MAX_N = 10000;
vector<int> adj[MAX_N];	// ���� ����Ʈ
int lv[MAX_N], parent[MAX_N][LGN],v[MAX_N];

// ��ó�� ����
void dfs(int here){
	v[here] = 1;
	int next;	// �̰� ������ϰ� �׳� adj�� �ڵ徲�� �޸� ���� �Ƴ� �� �ִ�.
	for (int i = 0; i < (int)adj[here].size(); ++i) {
		next = adj[here][i];
		if (v[next]) continue;

		lv[next] = lv[here] + 1;

		parent[next][0] = here;
		for (int j = 1; j < LGN; ++j) { // dfs ���� ���߿� �θ� ������ ���� ����

			parent[next][j] = parent[parent[next][j - 1]][j - 1];
		}

		dfs(next);
	}
}

int lca(int a, int b) {
	int tmp;
	if (lv[a] > lv[b]) {	// �Ʒ� ������ ���� �� a<b�� ����
		swap(a, b);
	}

	for (int i = LGN; i >= 0; i--) {
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
}

int main() {
	freopen("Input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	lv[1] = 0;	// root node
	dfs(1); // �ƹ����̳� root�� �׳� ����



	return 0;
}