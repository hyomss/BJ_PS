#include <iostream>
using namespace std;

const int MAX_N = 1000010;
int N, parent[MAX_N];
int lv[MAX_N]; // �� Ʃ���Ϸ��� ���̸� Ȯ���ؼ� �� �������� merge

void init() {
	for (int i = 0; i <= N; ++i) {
		parent[i] = i;	// �ʱ⿡ ���� �θ�� ��.
		lv[i] = 1;
	}
}

int find(int n) {
	// � ����� �θ� ã�ƿ���. ��� �̿�
	if (n == parent[n])	return n;
	return parent[n] = find(parent[n]);	//	�Ʒ��� �� �ȳ������� parent�� �ٷ� ����ǰ� ����. �̷��� skewed ��������
}

bool merge(int n1, int n2) { // retturn�� ���ָ� merge���� Ȯ���� �� �ִ�.
							 // ���� ��Ʈ�� ã�� ������ ���� Ȯ��
	int r1 = find(n1);
	int r2 = find(n2);
	if (r1 == r2) {
		return 0;	//	merge ������
	}

	//	n1�� ��Ʈ�� n2�� ���δ�. �ݴ뵵 ����
	//	���⼭ lv�� �׳� �� ���� �������� ũ�� ����
	if (lv[r1] > lv[r2]) {
		parent[r2] = r1;
	}
	else {
		parent[r1] = r2;
		if (lv[r1] == lv[r2]) {
			lv[r2] += 1;
		}
	}
	return 1;	//	merge ����
}


int main() {
	//freopen("Input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int M;
	int p, n1, n2;
	scanf("%d %d", &N, &M);
	init();
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &p, &n1, &n2);
		if (p == 0) {
			merge(n1, n2);
		}
		else {
			if (find(n1) == find(n2)) printf("YES\n");
			else printf("NO\n");
		}
	}
	


	return 0;
}
