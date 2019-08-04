/*
이진트리 세그멘트 트리

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
	if (!(s <= idx && idx <= e))	return;	//	찾으려는 idx가 범위안에 없는 경우
	
	tree[node] += diff;	//	하나가 증가하면 전체값을 그만큼 증가

	if (s != e) {
		int mid = (s + e) / 2;
		update(tree, node * 2, s, mid, idx, diff);
		update(tree, node * 2 + 1, mid + 1, e, idx, diff);
	}
}

long sum(vector <long> &tree, int node, int s, int e, int left, int right) {
	if (left > e || right < s) return 0;	//	관련없는 부분

	if (left <= s && e <= right)	return tree[node];	//	구간에 node가 포함 : 해당 값 반환

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
	
	if (a == 1) {	// 수 바꾸기
			
	}
	else {		//	합 구하기
		
	}



	return 0;
}