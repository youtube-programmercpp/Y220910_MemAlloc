#include <stdlib.h> //malloc 用
#include <stdio.h> //scanf_s 用
int main()
{
	//キャスト演算子    
#define	N 100
	char* p = (char*)malloc(N);
	if (p) {
		//メモリ割り付け成功
		if (scanf_s("%s", p, N) == 1) {
			//入力成功
			printf("入力された文字列は「%s」です。\n", p);
		}
		else {
			//入力失敗
		}
		free(p);
	}
	else {
		//メモリ割り付け失敗
	}
#undef	N
}
