#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	double* pd = NULL;
	size_t no = 0;
	double sum = 0;
	for (;;) {
		printf("数値を入力してください。(Eで終了)");
		char szDATA[32];
		if (gets_s(szDATA, sizeof szDATA)) {
			//入力成功
			if (strcmp(szDATA, "E") == 0 || strcmp(szDATA, "e") == 0) {
				printf("入力を終了します\n");
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
						perror("領域確保に失敗\n");
					else
						perror("領域のサイズ変更に失敗しました\n");
					break;
				}
			}
		}
		else {
			//入力失敗
			break;
		}
	}
	if (no) {
		assert(pd);
		for (int i = 0; i < no; i++)
			printf("[No.%d]%f\n", i + 1, pd[i]);
		printf("合計\t%f\n", sum);
		printf("平均\t%f\n", sum / no);
	}
	free(pd);
	return 0;
}
