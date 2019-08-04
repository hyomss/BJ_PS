#include <iostream>
using namespace std;

const int MAX_N = 1000010;
int N, parent[MAX_N];
int lv[MAX_N]; // 더 튜닝하려면 깊이를 확인해서 더 적어지게 merge

void init() {
	for (int i = 0; i <= N; ++i) {
		parent[i] = i;	// 초기에 나의 부모는 나.
		lv[i] = 1;
	}
}

int find(int n) {
	// 어떤 노드의 부모 찾아오기. 재귀 이용
	if (n == parent[n])	return n;
	return parent[n] = find(parent[n]);	//	아래로 쭉 안내려가고 parent에 바로 연결되게 변경. 이러면 skewed 방지가능
}

bool merge(int n1, int n2) { // retturn을 해주면 merge여부 확인할 수 있다.
							 // 각각 루트를 찾고 같은지 먼저 확인
	int r1 = find(n1);
	int r2 = find(n2);
	if (r1 == r2) {
		return 0;	//	merge 안했음
	}

	//	n1의 루트를 n2에 붙인다. 반대도 가능
	//	여기서 lv는 그냥 다 빼도 성능차이 크게 없다
	if (lv[r1] > lv[r2]) {
		parent[r2] = r1;
	}
	else {
		parent[r1] = r2;
		if (lv[r1] == lv[r2]) {
			lv[r2] += 1;
		}
	}
	return 1;	//	merge 했음
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
