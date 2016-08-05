/* 標準ヘッダーファイル. */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<math.h>
#include<limits.h>
#include<time.h>
#include<unistd.h>
#include<sys/wait.h>


#define DBG 0
/* DBG 0 : Normal mode
   DBG 1 : debug mode
*/

#define RFILE 0
/* RFILE 0 start initial is 1
   RFILE 1 load start.txt
*/

#define WFILE 1
/* WFILE 0 printf
   WFILE 1 fprintf
*/

#define B_MAX (10*10000)
/* 多重インクルード防止 */
#ifdef _FUNC_H_
#define _FUNC_H_


/* char型の配列から,int型の配列に挿入する*/
int *array_to_int_from_char(int *,char *);

/* int型の配列の要素に-1が入ってるところまで,カウントする */
int cnt_keta(int *x);

/* int型の配列の中身をすべて0にする */
void reset(int *X,int keta);

/* さあ,本番だ */
int *my_add(int *x,int keta);

#endif
