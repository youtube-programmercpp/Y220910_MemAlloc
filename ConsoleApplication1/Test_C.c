#include <stdlib.h>
#include <stdio.h>
int main()
{
	int n = 100;
	char* p = malloc(n);
	if (p) {
		if (scanf_s("%s", p, n) == 1) {
			printf("�u%s�v\n", p);
		}
	}
	free(p);
}
