#include <stdio.h>
#define L 3
int r(int i, int j, int s[L][L]);  
void putpre(int x);                
void putdig(int x);                
int newtemp(void);                 
void r2(int i, int j, int s[L][L]);
void r3(int i, int j, int s[L][L]);

int main() {
   int p[L];     
   int m[L][L];  
   int s[L][L];  
   int n = 0, i, ll, j, k, q;
   int res; 
   for (i = 0; i < L; i++) {
      scanf("%i", &p[i]); 
	  if (p[i] <= 0) break;
   }
   n = i - 1;  
   for (i = 1 ; i <= n; i++)
      m[i][i] = 0;
   for (ll = 2; ll <= n; ll++)
      for (i = 1; i <= n - ll + 1; i++) {
         j = i + ll - 1;
         m[i][j] = 444444444; 
         for (k = i; k <= j - 1; k++) {
            q = m[i][k] + m[k+1][j] +
               p[i-1]*p[k]*p[j];
            if (q < m[i][j]) {
               m[i][j] = q;
               s[i][j] = k;
            }
         }
      }
    
   printf("\n");
   res = r(1, n, s);
   printf("Final result is in T");
   putdig(res); printf("\n\n");
   r2(1, n, s); printf("\n\n");
   r3(1, n, s); printf("\n");
   return 0;
}

int r(int i, int j, int s[L][L]) {
   int k, arg1, arg2, res;
   if (i == j) return i;
   k = s[i][j];         
   arg1 = r(i, k, s);  
   arg2 = r(k+1, j, s); 
   res = -newtemp();   
   putpre(res); putdig(res); putchar('=');
   putpre(arg1);putdig(arg1);putchar('*');
   putpre(arg2);putdig(arg2);putchar('\n');
   return res;
}
void putpre(int x) {
   if (x < 0) putchar('T');
   else putchar('A');
}
void putdig(int x) {
   if (x < 0) x = -x;
   printf("%i", x);
}
int newtemp() {
   int i = 1;
   return i++;
}
void r2(int i, int j, int s[L][L]) {
   int k;
   if (i == j) {
      printf("A%i", i);
      return;
   }
   k = s[i][j];
   printf("(");
   r2(i, k, s);
   printf(")*(");
   r2(k+1, j, s);
   printf(")");
}
void r3(int i, int j, int s[L][L]) {
   int k;
   if (i == j) {
      printf("A%i", i);
      return;
   }
   printf("(");
   k = s[i][j];
   r3(i, k, s);
   printf("*");
   r3(k+1, j, s);
   printf(")");
}
