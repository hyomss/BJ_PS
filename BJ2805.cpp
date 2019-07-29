/*
N = 100��. M�� int ����
time = 1sec
�׷��Ƿ� NlgN �� ������ �̿��ؾ� �Ѵ�.
����ȭ -> ��������. �̺�Ž�� �̿�
*/

/*
1 1 1 2 3 3 3 5 6 7 8 9
x x x x o o o o o o o o  -> o�� ù��°�� ã�� ��������
3 �̻��� õ��° �ε���. �̷������� ã���� �ִ� �̺� Ž����
while(s,e){
mid = (s+e)/2;
if(arr[mid] > target){	//	>=���� =�� ����
e = mid-1;
} else{  // mid �� ���� �Ʒ��� ���ʿ� ���� �ؾߵȴ�.
s = mid;
}
}
return e;

�̺�Ž�� ���� ����!
upper/lower bound ��� �����ִ� �żҵ嵵 �� �� �ִ�.
*/
#include <iostream>
using namespace std;

int tree[1000100];

int main() {
	int N, M;
	int max = -1;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		if (tree[i] > max)	max = tree[i];
	}
	int s = 0, e = max;
	while (s <= e) {
		long long sum = 0;
		int mid = (s + e +1 ) / 2;
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid)	sum += (tree[i] - mid);
		}
		if (s == e) {
			cout << mid; break;
		}
		if (sum > M) {
			s = mid; 
		}
		else if (sum == M) {
			cout << mid; break;
		}
		else {
			e = mid - 1; 
		}
	}

	return 0;
}
