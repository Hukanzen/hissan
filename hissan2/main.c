//my フィボ
#include"func.h"

#define DBG 2
/* DBG 1 printf
   DBG 2 fprintf
   other Not Output
*/

int main(void)
{
	FILE *fp;
	fp=fopen("result.txt","w");
//	char *s="2147483647";
//	char *s="4294967294";
	int a;
	int b=INT_MAX;
//	int test=1;
	char *s="1";
	int *x;

	printf("int  max %ld\n",INT_MAX);
	printf("long max %ld\n",LONG_MAX);

	//printf("int %d+%d = %d\n",test,test,test+test);
	x=(int *)array_to_int_from_char(x,s);

//	for(a=0;a<b;a++){
//		printf("%d:\t",a);
//		int i=0;
//		int flag=0;
//	
//		for(i=0;i<(cnt_keta(x));i++){
//			if(x[i]!=0) flag=1;
//			if(flag==1) printf("%d",x[i]);
//		}
//		printf("+");
//	
//		flag=0;
//		for(i=0;i<(cnt_keta(x));i++){
//			if(x[i]!=0) flag=1;
//			if(flag==1) printf("%d",x[i]);
//		}
//		printf("=");
//	
//		flag=0;
//	
//		x=(int *)my_add(x,cnt_keta(x));
//	
//		for(i=0;i<(cnt_keta(x));i++){
//			if(x[i]!=0) flag=1;
//			if(flag==1) printf("%d",x[i]);
//		}
//		printf("\t\t\t\t");
//		printf("\t\t\t\t");
//		printf("\t\t\t\t\t");
//		
//		printf("%d + %d = %d\n",test,test,test+test);
//		test=test+test;
//	//	if(test<0) return 1;
//	}
//
	for(a=0;a<b;a++){
		int i;
		int flag=0;

#if DBG == 1
		printf("%d:\t",a);
#elif DBG == 2
		fprintf(fp,"%d:\t",a);
#endif

		for(i=0;i<(cnt_keta(x));i++){
			if(x[i]!=0) flag=1;
#if DBG == 1
			if(flag==1) printf("%d",x[i]);
#elif DBG == 2
			if(flag==1) fprintf(fp,"%d",x[i]);
#endif
		}
	
#if DBG == 1
		printf("\n");
#elif DBG == 2
		fprintf(fp,"\n");
#endif
		x=(int *)my_add(x,cnt_keta(x));
	}
//
//	int i;
//	int flag=0;
//	for(i=0;i<(cnt_keta(x));i++){
//		if(x[i]!=0) flag=1;
//		if(flag==1) printf("%d",x[i]);
//	}
//	printf("+");
//
//	flag=0;
//	for(i=0;i<(cnt_keta(x));i++){
//		if(x[i]!=0) flag=1;
//		if(flag==1) printf("%d",x[i]);
//	}
//	printf("=");
//
//	flag=0;
//
//
//	for(i=0;i<(cnt_keta(x));i++){
//		if(x[i]!=0) flag=1;
//		if(flag==1) printf("%d",x[i]);
//	}

	return 0;
}
