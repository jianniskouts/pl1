#include<stdio.h>


int main(int argc, char** argv){
    int i;
    for(i = 0; i < 15; i++){
        printf("%d\n",argv[1][i] -'0');
    }
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

int ReverseInt(long long i){
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