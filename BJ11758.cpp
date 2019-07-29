#include <iostream>
#include <vector>
using namespace std;

int x1, x2, x3, y1, y2, y3;
int ccw() {
	int result = x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2;
	if (result > 0) return 1;
	else if (result == 0) return 0;
	else return -1;
}

int main() {
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	cout << ccw();
	
	return 0;
}