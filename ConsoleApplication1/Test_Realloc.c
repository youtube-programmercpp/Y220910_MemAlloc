#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
int main()
{
	int* p = NULL;
	size_t n = 0;//�f�[�^�̌�
	for (;;) {
		int* const p2 = realloc(p, (n + 1) * sizeof * p);
		if (p2) {
			//����������t������
			p = p2;
			if (scanf_s("%d", &p[n]) == 1) {
				//���͐���
				++n;
				continue;
			}
			else {
				//���͎��s
				int* const p3 = realloc(p2, n * sizeof * p);
				assert(p3 != NULL);
				p = p3;
				break;
			}
		}
		else {
			//����������t�����s
			break;
		}
		printf("�`���͓��e�`\n");
	}
	assert(n == 0 || p != NULL);
	for (size_t i = 0; i < n; ++i) {
		printf("p[%zd] = %d\n", i, p[i]);
	}
	free(p);
}
