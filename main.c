#include <stdio.h>

int main() {
	int n;

	while (1) {
		printf("Enter your student ID: ");
		while (scanf("%d", &n) == 1) {
			if (n == 2025046025) printf("Your name is Kim Hunhui\n");
			else printf("There are no saved IDs");
		}
		break;
	}
	return 0;
}
