#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int zero[2][2] = {{0,0},{5,5}};
int one[2][2] = {{1,0},{9,2}};
int two[3][2] = {{2,0},{6,6},{1,1}};
int three[2][2] = {{3,0},{9,4}};
int four[3][2] = {{4,0},{7,7},{2,2}};
int five[2][2] = {{5,0},{9,6}};
int six[3][2] = {{6,0},{8,8},{3,3}};
int seven[2][2] = {{7,0},{9,8}};
int eight[3][2] = {{8,0},{9,9},{4,4}};
int nine[1][2] = {{9,0}};

int **Numbers[]= {(int**)zero,(int**)one,(int**)two,(int**)three,(int**)four,(int**)five,(int**)six,(int**)seven,(int**)eight,(int**)nine};
int SizeOfInt(int);
int ReverseInt(int);
int *DigitsInArray(int);
void FindParentNumbers(int ,int ,int );

int start,end,new_size;
int newNum[100000],inputs[100000];
int **pointerToInt,*bitInput;
int carry = 0;
int flag = 0;

int main(int argc,char* argv[]){
    int input, start, end, size,i,n;

    input = atoi(argv[1]);
    size = SizeOfInt(input);
    start = 0;
    end = size-1;
    bitInput = DigitsInArray(input);
    FindParentNumbers(size,start,end);
    if(new_size <size){
        n = 1;
    }
    else{
        n = 0;
    }
    for(i = n; i < size; i++){
        printf("%d",newNum[i]);
    }
    return 0;
}


void FindParentNumbers(int size,int start,int end){
    pointerToInt = Numbers[bitInput[end]];
    if(start < end){
        flag++; //seperate first and the rest recersive calls of the function
        //pointerToInt = Numbers[bitInput[end]];

        if (flag == 1){ //TODO if I am on either of these cases need to make the [end -1] -1 to keep track of the carry 
            if((bitInput[start]*10 + bitInput[start+1] -1) == bitInput[end]+10){
                new_size = size - 1;
                start++;
                newNum[start] = **(pointerToInt + 2);
                newNum[end] = **(pointerToInt + 3);
                bitInput[end - 1]--;
                carry = 1;
                start++;
                end--;
                FindParentNumbers(new_size,start,end);
                return;
            }
            else if((bitInput[start]*10 + bitInput[start+1]) == bitInput[end]+10){
                new_size = size - 1;
                start++;
                newNum[start] = **(pointerToInt + 2) ;
                newNum[end] = **(pointerToInt + 3);
                bitInput[end-1]--;
                start++;
                end--;
                FindParentNumbers(new_size,start,end);
                return;
            }
            else{
                new_size = size;
            }
        }
        if(bitInput[start]-1 == bitInput[end]){
            if(carry == 1){
                newNum[start] = **(pointerToInt + 2); // if Ihave a carry then i get the second tuple
                newNum[end] = **(pointerToInt + 3); // TODO need to find how to point to the array of arrays
                bitInput[end-1]--;
            }
            if (carry == 0){
                newNum[start] = **pointerToInt;    // if I dont have a carry then i get the first tuple
                newNum[end] = **(pointerToInt + 1); // TODO need to find how to point to the array of arrays
            }
            carry = 1;
            start++;
            end--;
            FindParentNumbers(new_size,start,end);
            return;
        }
        else if(bitInput[start] == bitInput[end]){
            if(carry == 1){
                newNum[start] = **(pointerToInt + 2); // if Ihave a carry then i get the second tuple
                newNum[end] = **(pointerToInt + 3); // TODO need to find how to point to the array of arrays
            }
            if (carry == 0){
                newNum[start] = **pointerToInt;    // if I dont have a carry then i get the first tuple
                newNum[end] = **(pointerToInt + 1); // TODO need to find how to point to the array of arrays
            }
            start++;
            end--;
            FindParentNumbers(new_size,start,end);
            return;
        }
        else{
            return;
        }
    }
    else if(start == end){
        if (bitInput[start] % 2 == 1){
            return;
        }
        if(carry == 0){
            newNum[start] = **(pointerToInt + 4);
            return;
        }
        else{
            newNum[start] = **(pointerToInt + 2);
        }
    }
    else{
        return;
    }
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

