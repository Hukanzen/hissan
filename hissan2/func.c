#include"func.h"

int *array_to_int_from_char(int *x,char *s)
{
	int i=0;
	int n=strlen(s);
	
	x=(int *)calloc(n+1,sizeof(int));
//	int *y=(int *)calloc(n+1,sizeof(int));

	//for(i=0;i<n;i++){
	//	x[i]=s[n-i-2]-'0';
//	//	printf("i=%d\n",i);
//	//	printf("x[i]=%d\n",x[i]);
	//}

	for(i=0;s[i]!='\0';i++){
		x[n-i-1]=s[i]-'0';
	}

	x[n]=-1;
	//y[n]=-1;
	//for(i=0;y[i]!=-1;i++){
	//for(i=0;i<=n;i++){
	//	printf("%d",x[i]);
	//}
	//printf("%d",y[n]);

	return x;
}

int cnt_keta(int *x)
{
	int i;
	int n=0;

	for(i=0;;i++){
		if(x[i]==-1) break;
		n++;
	}
//	printf("\nn=%d\n",n);
	return n;
}

void reset(int *X,int keta)
{
	int i;
	for(i=0;i<keta;i++){
		X[i]=0;
	}
}

int *my_add(int *x,int keta/* 使える数字のみが入っている桁数.-1の分は入っていない*/)
{
	int i;
	int *A;
//	int *B;
	int *C;
//	int kuri;
//	int c_yoso; /* int型配列Cの要素数 */
//	int c_keta; /* int型配列Cの使える桁数 */

	A=x;

	C=(int *)calloc(keta+2,sizeof(int));
	reset(C,keta+2);
	C[keta+1]=-1;
////	if(A[0]==0){
////		c_yoso=keta+1; /*keta + "-1" */
////		c_keta=keta;
////	}else{
////		c_yoso=keta+2; /*keta + "-1" + 繰り上がり */
////		c_keta=keta+1;
////	}
////
////	printf("c_keta=%d\n",c_keta);
////	printf("c_yoso=%d\n",c_yoso);
////
////	C=(int *)calloc(c_yoso+1,sizeof(int));
////	reset(C,c_yoso);
////
////	C[c_yoso]=-1;
//
//	for(i=keta-1;i>=0;i--){
//		C[i+1]+=(A[i]+A[i])%10;
//		kuri=(A[i]+A[i])/10;
//		C[i+1-1]+=kuri;
//	}
//
	for(i=0;A[i]!=-1;i++){
		C[i]+=(A[i]+A[i])%10;
		C[i+1]+=(A[i]+A[i])/10;
	}
////	for(i=0;i<keta;i++){
////		C[c_keta-i]+=(A[keta-i]+A[keta-i])%10;
////		kuri=(A[keta-i]+A[keta-i])/10;
////		C[c_keta-i-1]+=kuri;
////	}

	free(A);

	//printf("C=");
	//for(i=0;i<c_keta;i++) printf("%d",C[i]);

	return C;

}
