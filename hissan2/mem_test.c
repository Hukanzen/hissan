/* メモリ確保,解放に問題はないか */
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int *p;

	p=calloc(50,sizeof(int));
	if(p==NULL){
		printf("ERROR calloc\n");
		return 1;
	}

	free(p);

	printf("特に問題はありません\n");

	return 0;
}
