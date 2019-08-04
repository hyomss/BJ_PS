/*
그냥 하면 4000^4 로 범위 초과
4000^2단위로 줄여야 한다. -> N^2
이 경우 조금 남으므로 (N*N)lgN을 쓰면 꽉 찬다. 현재 숫자가 아주 랜덤하므로 꽉찬 복잡도를 활용할 것이라고 유추 가능

A+B+C+D = 0 
A+B = -(C+D)
A+B 경우의 수는 4000*4000

(C+D) 모든 경우 배열 구한 다음 A+B 배열에서 그 음수를 찾는다. upper 과 lower을 찾아서 그 개수를 찾는다.
NlgN으로 소팅하고 lgN안에 binary로 찾을 수 있다

2143과 비슷
*/
#include<iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[4000][4] = { 0 };
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	int A[4000];
	int B[4000];
	int C[4000];
	int D[4000];
	for (int i = 0; i < N; i++) {
		A[i] = arr[i][0];
		B[i] = arr[i][1];
		C[i] = arr[i][2];
		D[i] = arr[i][3];
	}

	int list1[16000000] = { 0 };
	int list2[16000000] = { 0 };
	int p = 0, q = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			list1[p++] = A[i] + B[j];
			list2[q++] = C[i] + D[j];
		}
	}
	sort(list1, list1 + N*N);
	sort(list2, list2 + N*N);
	for (int i = 0; i < N*N; i++) {
		int a = -list2[i];
		
		int s = 0, e = N*N, mid;
		while (e - s > 0) {
			mid = (s + e) / 2;
			if (list1[mid] < a) s = mid + 1;
			else e = mid;
		}
		int lower_bound = e + 1;
		while (e - s > 0) {
			mid = (s + e) / 2;
			if (list1[mid] <= a) s = mid + 1;
			else e = mid;
		}
		int upper_bound = e + 1;
	}


	return 0;
}