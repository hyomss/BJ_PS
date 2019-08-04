#include <iostream>
using namespace std;

int N;
void div(int divN) {
	for (int i = 2; i*i <= divN; ++i) {
		if (divN%i == 0) {
			cout << i << endl;
			divN /= i;
			--i;
		}
	}
	if(divN>1)
		cout << divN << endl;
}

int main() {
	cin >> N;
	div(N);

	return 0;
}