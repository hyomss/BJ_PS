/*
시간복잡도에 영향을 주는 요소 : N, L
N: 500만이므로 NlgN이하여야한다.

deQue에 idx를 넣으면서 진행. 앞에 range 벗어난거 앞에서 한번 팝 / 들어오는 에보다 큰애는 뒤에서 while로 팝. 맨앞에 있는 애가 제일 작은 애.

시간복잡도 : 하나씩 진행하는 도중에 중간에 while문 있으니까 N + 최대 N = 2N
*/
#include <iostream>
#include <deque>
using namespace std;

deque <int> q;
int arr[50000000] = { 0 };
int min_arr[50000000];


int main() {
	int N, L;
	int s = 0, e = 2;
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {

	}


	return 0;
}