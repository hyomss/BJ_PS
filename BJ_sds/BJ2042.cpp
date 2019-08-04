/*
����Ʈ�� ���׸�Ʈ Ʈ��

https://www.crocus.co.kr/648
*/

#include <iostream>
#include <vector>
using namespace std;

int arr[1000010];

long init(vector<long> &arr, vector <long> &tree, int node, int s, int e) {
	if (s == e)	// leaf node
		return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = init(arr, tree, node * 2, s, mid) + init(arr, tree, node * 2 + 1, mid + 1, e);
}

void update(vector<long> &tree, int node, int s, int e, int idx, long diff) {
	if (!(s <= idx && idx <= e))	return;	//	ã������ idx�� �����ȿ� ���� ���
	
	tree[node] += diff;	//	�ϳ��� �����ϸ� ��ü���� �׸�ŭ ����

	if (s != e) {
		int mid = (s + e) / 2;
		update(tree, node * 2, s, mid, idx, diff);
		update(tree, node * 2 + 1, mid + 1, e, idx, diff);
	}
}

long sum(vector <long> &tree, int node, int s, int e, int left, int right) {
	if (left > e || right < s) return 0;	//	���þ��� �κ�

	if (left <= s && e <= right)	return tree[node];	//	������ node�� ���� : �ش� �� ��ȯ

	int mid = (s + e) / 2;
	return sum(tree, node * 2, s, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, e, left, right);
}







int main() {
	freopen("input.txt", "r", stdin);
	
	int N, M, K;
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int a, b, c;
	cin >> a >> b >> c;
	
	if (a == 1) {	// �� �ٲٱ�
			
	}
	else {		//	�� ���ϱ�
		
	}



	return 0;
}