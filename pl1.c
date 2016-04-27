#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int SizeOfInt(int);
int ReverseInt(int);

int main(int argc,char* argv[]){
    int input, mod_, div_, newNum, i, temp, start, end, j, size, mid_, iSize,test ;
    input = atoi(argv[1]);
    size = SizeOfInt(input);
    start = 10* (size - 2);
    end = input;
    
    for(i = 0; i < input; i++){
        
        newNum = ReverseInt(i);
        if (i + newNum == input){
            printf(" Fuck yeah, %d\n",i);
            break;
        }
    }
}



int ReverseInt(int i){
    int iSize = SizeOfInt(i);
    int reverseNum = 0;
    int temp = i;
    int j;
    for(j = 0; j < iSize; j++){
        int div_ = temp / 10;
        int mod_ = temp % 10;
        int test = pow(10,(iSize - 1 - j));
        reverseNum = reverseNum + (mod_ * (test));
        temp = div_;
    }
    return reverseNum;
}

int SizeOfInt(int n)
{
  int count=0;
  while(n!=0)
  {
      n/=10;             /* n=n/10 */
      ++count;
  }
  return count;
}