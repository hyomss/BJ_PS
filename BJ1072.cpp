/*
z + r(������) = y/x * 100
���⼭ z = 99������ �·��� 100�� �ɼ��� ����. �̹� ���� �����Ƿ�. �̶��� ���� -1�� ���

k�� ��⸦ �ϰ� ��� �̱�� : y+k/x+k *100 = z'
���������� ��������
k
0 1 2 3 4 5 6 7 8 . . .10000000
x x x x x x x o o . . .    o -> z�� ������ ����?
mid�� �����ϴ� lowerbound ���ϸ� �ȴ�

k=0~����� ũ��. ������ log�̴�
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
