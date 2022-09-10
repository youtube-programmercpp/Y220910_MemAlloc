#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
int main()
{
	int* p = NULL;
	size_t n = 0;//データの個数
	for (;;) {
		int* const p2 = realloc(p, (n + 1) * sizeof * p);
		if (p2) {
			//メモリ割り付け成功
			p = p2;
			if (scanf_s("%d", &p[n]) == 1) {
				//入力成功
				++n;
				continue;
			}
			else {
				//入力失敗
				int* const p3 = realloc(p2, n * sizeof * p);
				assert(p3 != NULL);
				p = p3;
				break;
			}
		}
		else {
			//メモリ割り付け失敗
			break;
		}
		printf("～入力内容～\n");
	}
	assert(n == 0 || p != NULL);
	for (size_t i = 0; i < n; ++i) {
		printf("p[%zd] = %d\n", i, p[i]);
	}
	free(p);
}
