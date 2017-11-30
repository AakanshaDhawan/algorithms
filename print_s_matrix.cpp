#include <stdio.h>
#define L 5
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
   
   printf("The array p:\n\n");
   for (i = 0; i <= n; i++)
      printf("p[%i] =%3i, ", i, p[i]);
   
   printf("\n\nThe array m:\n\n       ");
   for (i = 1; i <= n; i++)
      printf(" i=%2i  ", i);
   printf("\n");
   for (j = n; j >= 1; j--) {
      printf("j=%2i:", j);
      for (i = 1; i <= j; i++)
         printf("%7i", m[i][j]);
      printf("\n");
   }

   printf("\nThe array s:\n\n       ");
   for (i = 1; i < n; i++)
      printf(" i=%2i  ", i);
   printf("\n");
   for (j = n; j >= 2; j--) {
      printf("j=%2i:", j);
      for (i = 1; i < j; i++)
         printf("%7i", s[i][j]);
      printf("\n");
   }
   printf("\n");
   
   return 0;
}

