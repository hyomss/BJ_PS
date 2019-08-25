#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int t=1;t<=10;t++){
		string s1, s2;
		cin >> t;
		cin >> s1;
		cin >> s2;

			int start = 0;
			int Total = 0;

			while (start < s2.length()) {
				int find = s2.find(s1, start);
				if (find != -1) {
					Total++;
					start = find + 1;
				}
				else break;
			}
			printf("#%d %d\n", t, Total);
		
	}
	   
	return 0;
}