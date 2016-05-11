#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long long x;
long long y;
long long z;

int SizeOfInt(long long);
long long ReverseInt(long long);

int main() {
    scanf("%lld",&x);
    y = ReverseInt(x);    
    z = x + y;
    printf("%lld\n",z);    
    return 0;
}

int SizeOfInt(long long n){
  int count=0;
  while(n!=0){
      n/=10;             /* n=n/10 */
      ++count;
  }
  return count;
}

long long ReverseInt(long long i){
    int iSize = SizeOfInt(i);
    long long reverseNum = 0;
    long long temp = i;
    int j;
    for(j = 0; j < iSize; j++){
        long long div_ = temp / 10;
        long long mod_ = temp % 10;
        long long test = pow(10,(iSize - 1 - j));
        reverseNum = reverseNum + (mod_ * (test));
        temp = div_;
    }
    return reverseNum;
}