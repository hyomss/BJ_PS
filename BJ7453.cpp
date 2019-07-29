/*
�׳� �ϸ� 4000^4 �� ���� �ʰ�
4000^2������ �ٿ��� �Ѵ�. -> N^2
�� ��� ���� �����Ƿ� (N*N)lgN�� ���� �� ����. ���� ���ڰ� ���� �����ϹǷ� ���� ���⵵�� Ȱ���� ���̶�� ���� ����

A+B+C+D = 0 
A+B = -(C+D)
A+B ����� ���� 4000*4000

(C+D) ��� ��� �迭 ���� ���� A+B �迭���� �� ������ ã�´�. upper �� lower�� ã�Ƽ� �� ������ ã�´�.
NlgN���� �����ϰ� lgN�ȿ� binary�� ã�� �� �ִ�

2143�� ���
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