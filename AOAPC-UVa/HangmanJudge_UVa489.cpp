#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int c[127];
int cc[127];

int main() {
	
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

	int times;
	while (scanf("%d", &times) && times != -1) {
		getchar();
		memset(c, 0, sizeof(c));
		memset(cc, 0, sizeof(cc));
		printf("Round %d\n", times);
		char i;
		int zh=0;
		while ((i = getchar()) != '\n') {
			if (c[i] == 0) zh++;
			c[i] = 1;
			cc[i] = 1;
		}

		int count = 0;
		while (count < 7 && zh && (i = getchar()) != '\n') {
			if (cc[i]==1 && c[i] == 1) {
				zh--;
				cc[i] = 0;
			}
			else if (c[i] == 0) {
				count++;
			}
		}
		if (zh == 0) {
			while (getchar() != '\n');
			cout << "You win.\n";
		}
		else if (count == 7) {
			while (getchar() != '\n');
			cout << "You lose.\n";
		}
		else
			cout << "You chickened out.\n";
	}
	return 0;
}