#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int* sieve(int n){
  int* prims = (int*) calloc(n,sizeof(int));
  
  for(int i = 0; i < n; ++i){
    prims[i] = 1;
  }
  

  double root = sqrt(n);

  for(int i = 2; i <= root; ++i){
    if(prims[i] == 1){
      prims[i*i] = 0;
      for(int k = 0; (i*i + k*i) < n; ++k){
        prims[i*i + k*i] = 0;
      }
    }
  }
  return prims;
}

int main(void){

  int n = 0;
  printf("How many primes?");
  printf("\n");
  printf("-> ");
  scanf("%d",&n);

  int* primes = sieve(n);

  printf("\n");
  printf("[");
  
  int numberOfPrimes = 0;

  for(int i = 2; i < n; ++i){
    if(primes[i] == 1){
      printf("%i, ",i);
      ++numberOfPrimes;
    }
  }

  printf("]");
  printf("\n");
  
  printf("Found %i primes",numberOfPrimes );
  printf("\n");

  free(primes);
  scanf("%d",n);
  return 0;
}
