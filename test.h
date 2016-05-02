#include<stdio.h>
#include<math.h>

int zero[6][3] = {
    {0,0,0},
    {1,9,1},
    {2,8,1},
    {3,7,1},
    {4,6,1},
    {5,5,1}
};
int one[5][3] = {
    {9,2,1},
    {8,3,1},
    {7,4,1},
    {6,5,1},
    {1,0,0}
};
int two[6][3] = {
    {9,3,1},
    {8,4,1},
    {7,5,1},
    {6,6,1},
    {1,1,0},
    {2,0,0}
};
int three[5][3] = {
    {9,4,1},
    {8,5,1},
    {7,6,1},
    {2,1,0},
    {3,0,0}
};
int four[6][3] = {
    {9,5,1},
    {8,6,1},
    {7,7,1},
    {3,1,0},
    {2,2,0},
    {4,0,0}
};
int five[5][3] = {
    {9,6,1},
    {8,7,1},
    {4,1,0},
    {3,2,0},
    {5,0,0}
};
int six[6][3] = {
    {9,7,1},
    {8,8,1},
    {6,0,0},
    {5,1,0},
    {4,2,0},
    {3,3,0}
};
int seven[5][3] = {
    {9,8,1},
    {7,0,0},
    {6,1,0},
    {5,2,0},
    {4,3,0},
};
int eight[6][3] = {
    {9,9,1},
    {8,0,0},
    {7,1,0},
    {6,2,0},
    {5,3,0},
    {4,4,0}
};
int nine[5][3] = {
    {9,0,0},
    {8,1,0},
    {7,2,0},
    {6,3,0},
    {5,4,0}
};
int *Numbers[]= {zero,one,two,three,four,five,six,seven,eight,nine};
int temp;
int inputs[100000];
int *BitInput;
int newNum[100000];
int *p;
int *pointerToInt;

int SizeOfInt(int);
int ReverseInt(int);
int *DigitsInArray(int);

void FindParentNumbers(int* ,int ,int ,int );
void FindParentNumbers(int *newNum,int size,int start,int end){ //maybe I can make BitInput global and I dont need to pass it as argument
                                                   //another global I need is the newNum, so it is always updated
    if (start > end){
        return; ///TODO, when and how I need this
    }
    //newNum = malloc(10*sizeof(int)) ;
    int new_size;
        printf("digit to test: %d\n",BitInput[end]);
        printf("start: %d\n",start);
        printf("end: %d\n",end);
    printf("%d\n",*(Numbers[BitInput[end]] + 1));
    if(BitInput[start] == BitInput[end]){
        printf("newNum: %d\n", newNum[1]);
        printf("first case \n");
        new_size = size;
        pointerToInt = (Numbers[BitInput[end]]);
        printf("pointerToInt: %d = %d\n",*(pointerToInt + 0),*(pointerToInt + 1));
        if (end == start){
            while((*(pointerToInt + 0 ) != *(pointerToInt + 1)) || (*(pointerToInt + 2) != 0)){
                //printf("Inside: %d = %d\n",*(pointerToInt + 0),*(pointerToInt + 1));
                pointerToInt = pointerToInt + 3;
            }
            temp = *pointerToInt;
            newNum[start] = temp;
            printf("newNumasd, start: %d, %d\n",newNum[start],start);
        } else{
            while(*(pointerToInt + 2) != 0 ){
                //printf("pointer: %d\n",*(pointerToInt + 2));
                pointerToInt = pointerToInt + 3;
            }
            printf("wtf pointer: %d\n",*(pointerToInt));
            temp = *pointerToInt;
            newNum[start] = temp;
            printf("newNumasd, start: %d, %d\n",newNum[start],start);
            temp = *(pointerToInt+1);
            //printf("this should be: %d\n",*(Numbers[BitInput[end]]+1));
            newNum[end] = temp;
            printf("newNumasd, end: %d, %d\n",newNum[end],end);
        }
        start++;
        end--;
        printf("newNum: %d\n", newNum[0]);
        FindParentNumbers(newNum,new_size,start,end);
    }else if(BitInput[start]-1 == BitInput[end]){ //have to add somehow the fact that I w8 for Carry
        printf("2nd case\n");
        new_size = size;
        temp = *(Numbers[BitInput[end]]);
        newNum[start] = temp;
        temp = *(Numbers[BitInput[end]]+1);
        newNum[end] = temp;
        BitInput[start] = BitInput[start] - 1;
        start++;
        end--;
        FindParentNumbers(newNum,new_size,start,end);
    }else if((BitInput[start]*10 + BitInput[start+1]) == (BitInput[end] + 10)){
        printf("3rd case\n");
        new_size = size - 1;
        if (*(Numbers[BitInput[end + 2]]) == 1){ //have to take an option with Carry = 1
            temp = *(Numbers[BitInput[end]]);
            newNum[start] = temp;
            temp = *(Numbers[BitInput[end]+1]);
            newNum[end] = temp;
        }
        //BitInput[start + 1] = BitInput[start + 1] - BitInput[end];
        start++;
        end--;
        //p = newNum;
        FindParentNumbers(newNum,new_size,start,end);
    }
    else{
        printf("4th case\n");
        new_size = size - 1;
        if (*(Numbers[BitInput[end + 2]]) == 1){ //have to take an option with Carry = 1
            temp = *(Numbers[BitInput[end]]);
            newNum[start] = temp;
            temp = *(Numbers[BitInput[end]+1]);
            newNum[end] = temp;
        }
        BitInput[start + 1] = BitInput[start + 1] - BitInput[end];
        if (BitInput[start + 1] == 0){
            start = start + 2;
        }else{
            start++;
        }

        end--;
        FindParentNumbers(newNum,new_size,start,end);
    }
    printf("another test\n");
    printf("newNum: %d\n", newNum[1]);
    //call recursively with the remains of the initial number
    //as every time I take out the digits I checked
    //for(i = 0; i < 3; i++){
    //    printf("final: %d\n",p[i]);
    //}
    return;
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
