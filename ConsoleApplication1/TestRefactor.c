#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	double* pd = NULL;
	size_t no = 0;
	double sum = 0;
	for (;;) {
		printf("���l����͂��Ă��������B(E�ŏI��)");
		char szDATA[32];
		if (gets_s(szDATA, sizeof szDATA)) {
			//���͐���
			if (strcmp(szDATA, "E") == 0 || strcmp(szDATA, "e") == 0) {
				printf("���͂��I�����܂�\n");
				break;
			}
			else {
				double* const pd2 = realloc(pd, (no + 1) * sizeof *pd);
				if (pd2) {
					(pd = pd2)[no] = atof(szDATA);
					sum += pd[no];
					++no;
				}
				else {
					if (no == 0)
						perror("�̈�m�ۂɎ��s\n");
					else
						perror("�̈�̃T�C�Y�ύX�Ɏ��s���܂���\n");
					break;
				}
			}
		}
		else {
			//���͎��s
			break;
		}
	}
	if (no) {
		assert(pd);
		for (int i = 0; i < no; i++)
			printf("[No.%d]%f\n", i + 1, pd[i]);
		printf("���v\t%f\n", sum);
		printf("����\t%f\n", sum / no);
	}
	free(pd);
	return 0;
}
