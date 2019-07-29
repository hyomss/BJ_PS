/*
�ּ� ���� Ʈ��
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
		parent[i] = i;	// �ʱ⿡ ���� �θ�� ��.
	}
}

bool merge(int n1, int n2) { // retturn�� ���ָ� merge���� Ȯ���� �� �ִ�.
							 // ���� ��Ʈ�� ã�� ������ ���� Ȯ��
	int r1 = find(n1);
	int r2 = find(n2);
	if (r1 == r2) {
		return 0;	//	merge ������
	}
	parent[r2] = r1;
	
	return 1;	//	merge ����
}

int find(int n) {
	// � ����� �θ� ã�ƿ���. ��� �̿�
	if (n == parent[n])	return n;
	return parent[n] = find(parent[n]);	//	�Ʒ��� �� �ȳ������� parent�� �ٷ� ����ǰ� ����. �̷��� skewed ��������
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
