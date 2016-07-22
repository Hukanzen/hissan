//my フィボ

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int cnt_keta(long x)
{
	int n;
	n=(int)log10(x)+1;

	return n;
}

void reset(int *X,int keta)
{
	int i;
	for(i=0;i<keta;i++){
		X[i]=0;
	}
}

//int my_array_to_int(int *X,int keta)
//{
//	int i;
//	int ans=0;
//
//	//printf("%dke",keta);
//	for(i=0;i<keta;i++){
//		//printf("kkk%d\n",keta-i-1);
//		//printf("aaa%d\n",X[i]);
//		//printf("ii%d\n",X[i]*pow(10,keta-i-1));
//		ans+=X[i]*pow(10,keta-i-1);
//		printf("ans%d\n",ans);
//	}
//
//	return ans;
//}

void my_add(long x,int keta)
{
	int i;
	int *A;
	int *B;
	int *C;
	int kuri;
	int ans;

	A=(int *)calloc(keta,sizeof(int));
	//B=(int *)calloc(keta,sizeof(int));
	C=(int *)calloc(keta+1,sizeof(int));

	reset(A,keta);
	
	for(i=0;i<keta;i++){
		A[i]=x/pow(10,(keta-i-1));
		x-=A[i]*pow(10,keta-i-1);
	//	printf("A%d\n",A[i]);
	}

	reset(C,keta+1);

	for(i=keta-1;i>=0;i--){
		C[i+1]+=(A[i]+A[i])%10;
		kuri=(A[i]+A[i])/10;
		C[i-1+1]+=kuri;
	}

	for(i=0;i<keta+1;i++){
		printf("%d",C[i]);
	}
	printf("\n");

//	ans=my_array_to_int(C,keta+1);
	//printf("ans%d\n",ans);

//	return ans;
	
}

int main(void)
{
	
	/*=== 成功 ===*/
	printf("int  max %ld\n",INT_MAX);
	printf("long max %ld\n",LONG_MAX);
	int test=(int)INT_MAX;
	long x=(long)INT_MAX;

	printf("int %d+%d = %d\n",test,test,test+test);
	
	printf("my  %ld+%ld = ",x,x);
	my_add(x,cnt_keta(x));
	/*=== 成功 ===*/

	////printf("int max %d\n",INT_MAX);
	//int x=(int)1;

	//printf("%d+%d = ",x,x);
	//my_add(x,cnt_keta(x));

	return 0;
}
