#include"func.h"

int *array_to_int_from_char(int *x,char *s)
{
	int i=0;
	int n=strlen(s);

	x=(int *)calloc(n+1,sizeof(int));
//	reset(x,n);
	for(i=n-1;i>=0;i--){
		x[i]=s[i]-'0';
//		printf("x%d\n",x[i]);
	}
	x[n]=-1;


	return x;
}

int cnt_keta(int *X)
{
	int i=0;
	int n=0;

	for(i=0;;i++){
		if(X[i]==-1) break;
		n++;
	}

//	printf("n=%d\n",n);

	return n;
}

void reset(int *X,int keta)
{
	int i;
	for(i=0;i<keta;i++){
		X[i]=0;
	}
}

int *my_add(int *x,int keta)
{
	int i;
	int *A;
	int *B;
	int *C;
	int kuri;
	int ans;

	//A=(int *)calloc(keta,sizeof(int));
	A=x;
	//B=(int *)calloc(keta,sizeof(int));
	C=(int *)calloc(keta+1+1,sizeof(int));
	C[keta+1]=-1;

//	reset(A,keta);
//	
	for(i=0;i<keta;i++){
	//	printf("A%d\n",x[i]);
	}

	reset(C,keta+1);

	for(i=keta-1;i>=0;i--){
		C[i+1]+=(A[i]+A[i])%10;
		kuri=(A[i]+A[i])/10;
		C[i-1+1]+=kuri;
	}

//	for(i=0;i<keta+1;i++){
//		printf("%d",C[i]);
//	}
//	printf("\n");

	free(A);


	return C;

}
