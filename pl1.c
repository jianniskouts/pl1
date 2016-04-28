#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int SizeOfInt(int);
int ReverseInt(int);
int *DigitsInArray(int);
int inputs[100000];


int main(int argc,char* argv[]){
    int input, mod_, div_, newNum, i, temp, start, end, j, size, mid_, iSize,test;
    int *BitInput;
    input = atoi(argv[1]);
    size = SizeOfInt(input);
    start = 10* (size - 2);
    end = input;

    for(i = 0; i < input; i++){
        BitInput = DigitsInArray(input);
        newNum = ReverseInt(i);
        if (i + newNum == input){
            printf(" Fuck yeah, %d\n",i);
            break;
        }
    }
    for(i = 0; i < 15; i++){
        printf("%d digit of input = %d\n",i,BitInput[i]);
    }
    return 0;
}


//reverse an int
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

//put the digits of an int to an array
int *DigitsInArray(int i){
    int iSize = SizeOfInt(i);
    int div_,mod_;
    int temp = i;
    int j = 0;
    do{
        div_ = temp / 10;
        mod_ = temp % 10;
        inputs[iSize-j-1] = mod_;
        temp = div_;
        j++;
    }while(div_ != 0);
    return inputs;
}

//return the size of an int
int SizeOfInt(int n)
{
  int count=0;
  while(n!=0){
      n/=10;             /* n=n/10 */
      ++count;
  }
  return count;
}