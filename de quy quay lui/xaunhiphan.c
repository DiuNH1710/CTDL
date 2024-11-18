#include <stdio.h>
   int n;
   int x[100];

void Try(int k ){
      for( int v=0; v <=1; v++){
            x[k] =v ; 

            if (k == n-1 ) {
                  for (int i =0; i < n; i++){
                        printf("%d", x[i]);
                    
                  }
                  printf("\n");
            }
            else{
                  Try(k+1);
            }
      }
}

int main(){
   
      printf("nhap do dai xau nhi phan n = ");
      scanf("%d", &n );
      Try(0);
     return 0;
}