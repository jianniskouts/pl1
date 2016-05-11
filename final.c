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

int *Numbers[]= {(int*)zero,(int*)one,(int*)two,(int*)three,(int*)four,(int*)five,(int*)six,(int*)seven,(int*)eight,(int*)nine};
int SizeOfInt(int);
int ReverseInt(int);
int *DigitsInArray(int);
void FindParentNumbers(int ,int ,int);

int start,end,new_size;
int newNum[100001],inputs[100000];
int *pointerToInt,bitInput[100000];
int carry = 0;
int flag = 0;

int main(int argc,char* argv[]){
    newNum[100000] = 0;
    int start = 0;
    int end = 0;
    int size = 0;
    int i = 0;
    int n;
    int c;
    FILE *fd;
    fd = fopen(argv[1], "r");
    if(fd == NULL){
        printf("didn't open the file\n");
        exit(1);
    }
    while ((c = fgetc(fd)) != EOF){
        bitInput[i] = 0;
        newNum[i] = 0;
        bitInput[i] = c - '0';
        i++;
    }

    size = i-1;
    start = 0;
    end = size-1;
    flag = 2;
    FindParentNumbers(size,start,end);
    if(newNum[100000] == -1){
        flag = 0;
        FindParentNumbers(size,start,end);
    }
    if(new_size < size){
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
    new_size = size;
    if(start < end){
        flag++;
        if (flag == 1){
            if((bitInput[start]*10 + bitInput[start+1] -1) == bitInput[end]+10){
                new_size = size - 1;
                start++;
                newNum[start] = *(pointerToInt + 2);
                newNum[end] = *(pointerToInt + 3);
                bitInput[end - 1]--;
                carry = 1;
                start++;
                end--;
                FindParentNumbers(new_size,start,end);
                return;
            }else if((bitInput[start]*10 + bitInput[start+1]) == bitInput[end]+10){
                new_size = size - 1;
                start++;
                newNum[start] = *(pointerToInt + 2) ;
                newNum[end] = *(pointerToInt + 3);
                carry = 0;
                if(bitInput[end-1] == 0){
                    bitInput[end-1] = 9;
                }else{
                    bitInput[end-1]--;
                };
                start++;
                end--;
                FindParentNumbers(new_size,start,end);
                return;
            }else if(((bitInput[start]*10 - 1) + bitInput[start+1]) == bitInput[end]){
                new_size = size - 1;
                start++;
                newNum[start] = *(pointerToInt + 0) ;
                newNum[end] = *(pointerToInt + 1);
                carry = 0;
                start++;
                end--;
                FindParentNumbers(new_size,start,end);
                return;
            }else{
                new_size = size;
            }
        }
        if((bitInput[start]-1 == bitInput[end]) || (bitInput[start] == 0)){
            if(carry == 1){
                if(bitInput[end] == 9){
                    newNum[start] = *(pointerToInt + 0); // if Ihave a carry then i get the second tuple
                    newNum[end] = *(pointerToInt + 1); // TODO need to find how to point to the array of arrays
                    if(bitInput[end-1] == 0){
                        bitInput[end-1] = 9;
                    }else{
                        bitInput[end-1]--;
                    };
                }else{
                    newNum[start] = *(pointerToInt + 2); // if Ihave a carry then i get the second tuple
                    newNum[end] = *(pointerToInt + 3); // TODO need to find how to point to the array of arrays
                    if(bitInput[end-1] == 0){
                        bitInput[end-1] = 9;
                    }else{
                        bitInput[end-1]--;
                    };
                }
            }
            if (carry == 0){
                newNum[start] = *pointerToInt;    // if I dont have a carry then i get the first tuple
                newNum[end] = *(pointerToInt + 1); // TODO need to find how to point to the array of arrays
            }
            carry = 1;
            start++;
            end--;
            FindParentNumbers(new_size,start,end);
            return;
        }
        else if(bitInput[start] == bitInput[end]){
            if (carry == 0){
                newNum[start] = *pointerToInt;    // if I dont have a carry then i get the first tuple
                newNum[end] = *(pointerToInt + 1); // TODO need to find how to point to the array of arrays
                carry =0;
            }
            if(carry == 1){
                if(bitInput[end] == 9){
                    newNum[start] = *(pointerToInt + 0); // if Ihave a carry then i get the second tuple
                    newNum[end] = *(pointerToInt + 1); // TODO need to find how to point to the array of arrays
                    carry = 1;
                }else{
                    newNum[start] = *(pointerToInt + 2); // if Ihave a carry then i get the second tuple
                    newNum[end] = *(pointerToInt + 3); // TODO need to find how to point to the array of arrays
                    carry =0;
                }
                if(bitInput[end-1] == 0){
                    bitInput[end-1] = 9;
                    carry = 1;
                }else{
                    bitInput[end-1]--;
                    carry =0;
                };
            }
            start++;
            end--;
            FindParentNumbers(new_size,start,end);
            return;
        }
        else{
            newNum[100000] = -1;
            return;
        }
    }
    else if(start == end){
        if (bitInput[start] % 2 == 1){
            printf("0");
            exit(0);
        }
        if(carry == 0){
            newNum[start] = *(pointerToInt + 4);
            return;
        }
        else{
            newNum[start] = *(pointerToInt + 2);
            return;
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

