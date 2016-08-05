/* my フィボ */
#include"func.h"

int main(void)
{
	clock_t start=clock(); /* プログラム開始時の時刻 */
	clock_t end;   /* プログラム終了時の時刻 */
#if RFILE == 1
	FILE *rfp;
#endif
#if WFILE == 1
	FILE *fp;
	fp=fopen("result.txt","w");
#endif
	char *s;       /* 初期値 */
	char c;	       /* 予約 */
	int n;         /* 予約 */
	int i;         /* 予約 */
	int a;         /* 回数カウント*/
//	int b=INT_MAX; /* 最大値 */
	int b=B_MAX;
	int *x;        /* 演算用ポインタ */
	int flag;      /* 0消し用flag */
	int st;
	int err=0;

#if RFILE == 0
	a=0;
	s="1";
#elif RFILE == 1
	if((rfp=fopen("start.txt","r"))==NULL){
		printf("FILE NOT FOUND");
		return 1;
	}else{
		n=0;
		fscanf(rfp,"%d\n",&a);
		while(fscanf(rfp,"%c",&c)!=EOF){
			n++;
		}
		s=(char *)calloc(n,sizeof(char));

		fseek(rfp,0,SEEK_SET);
	
		i=0;
		fscanf(rfp,"%d\n",&a);
		while(fscanf(rfp,"%c",&c)!=EOF){
			s[i]=c;
			i++;
		}
		
		fclose(rfp);
	}
#endif

	printf("int  max %d\n",INT_MAX);
	printf("long max %ld\n",LONG_MAX);

	x=(int *)array_to_int_from_char(x,s);

//	free(s);

	for(;a<b;a++){
		if(!fork()){
			flag=0;

#if WFILE == 0
			printf("%d:\t",a);
#elif WFILE == 1
			fprintf(fp,"%d:\t",a);
#endif

#if DBG == 0
			//for(i=0;i<(cnt_keta(x));i++){
			for(i=(cnt_keta(x)-1);i>=0;i--){
				if(x[i]!=0) flag=1;
#elif DBG == 1
			//for(i=0;i<(cnt_keta(x))+1;i++){
			for(i=(cnt_keta(x));i>=0;i--){
				printf("%d",x[i]);
#endif
#if WFILE == 0
				if(flag==1) printf("%d",x[i]);
#elif WFILE == 1
				if(flag==1) fprintf(fp,"%d",x[i]);
#endif
				if(x[i]<0){
					err=1;
					return err;
				}

			}
	
#if WFILE == 0
			printf("\n");
#elif WFILE == 1
			fprintf(fp,"\n");
#endif
			exit(0);

		}else{
			x=(int *)my_add(x,cnt_keta(x));
			wait(&st);
			if(err!=0) return err;
		}
	}

	end=clock();
	printf("計算終了 所要時間:%lf[s]\n",(double)end-start/1000);

#if WFILE == 1
	fprintf(fp,"計算終了 所要時間:%lf[s]\n",(double)end-start/1000);
	fclose(fp);
#endif
	

	return 0;
}
