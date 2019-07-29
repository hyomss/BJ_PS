/*
z + r(나머지) = y/x * 100
여기서 z = 99였으면 승률이 100이 될수는 없다. 이미 진게 있으므로. 이때가 답이 -1인 경우

k번 경기를 하고 모두 이긴다 : y+k/x+k *100 = z'
결정문제로 생각가능
k
0 1 2 3 4 5 6 7 8 . . .10000000
x x x x x x x o o . . .    o -> z가 증가한 시점?
mid를 포함하는 lowerbound 구하면 된다

k=0~충분히 크게. 어차피 log이다
*/
#include <iostream>
using namespace std;

int main() {
	int x, y, z;
	int k = 10000000;
	
	cin >> x >> y;
	

	if (y >= 99) {
		cout << -1;
		return 0;
	}

	return 0;
}
