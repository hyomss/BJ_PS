/*
최소 신장 트리
https://www.crocus.co.kr/733
*/
#include <iostream>
using namespace std;

typedef struct _line {
	int s;
	int e;
	int w;
}line;
line edge[100010];
int ed;

const int MAX_N = 1005;
int N, parent[MAX_N];


void init() {
	for (int i = 1; i <= N; ++i) {
		parent[i] = i;	// 초기에 나의 부모는 나.
	}
}

bool merge(int n1, int n2) { // retturn을 해주면 merge여부 확인할 수 있다.
							 // 각각 루트를 찾고 같은지 먼저 확인
	int r1 = find(n1);
	int r2 = find(n2);
	if (r1 == r2) {
		return 0;	//	merge 안했음
	}
	parent[r2] = r1;
	
	return 1;	//	merge 했음
}

int find(int n) {
	// 어떤 노드의 부모 찾아오기. 재귀 이용
	if (n == parent[n])	return n;
	return parent[n] = find(parent[n]);	//	아래로 쭉 안내려가고 parent에 바로 연결되게 변경. 이러면 skewed 방지가능
}

int main() {
	int N, M;
	scanf("%d %d", &N,&M);
	int a, b, w;
	ed = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &edge[i].sa, &edge[i].b, &edge[i].w);
		edge
		merge(a, b);
	}
}
