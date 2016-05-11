#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int zero[3][2] = {{0,0},{5,5},{0,0}};
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
void FindParentNumbers(int ,int ,int );

int start,end,new_size;
int newNum[100000],inputs[100000];
int *pointerToInt,bitInput[100000];
int carry = 0;
int flag = 0;
void FindParentNumbers(int size,int start,int end){
    pointerToInt = Numbers[bitInput[end]];
    printf("here\n");
    printf("first num to compare: %d\n",bitInput[start]);
    printf("[first + 1] num to compare: %d\n",bitInput[start + 1]);
    printf("second num to compare: %d \n",*(Numbers[bitInput[end]]));
    printf("is there a carry? %d\n",(bitInput[start]*10 + bitInput[start+1]));
    printf("fresh: start: %d, end: %d\n",start, end);

    if(start < end){
        flag++; //seperate first and the rest recersive calls of the function
        //pointerToInt = Numbers[bitInput[end]];
        printf("flag: %d\n",flag);
        if (flag == 1){ //TODO if I am on either of these cases need to make the [end -1] -1 to keep track of the carry 
            if((bitInput[start]*10 + bitInput[start+1] -1) == bitInput[end]+10){
                printf("4th case\n");
                new_size = size - 1;
                start++;
                printf("start: %d, end: %d\n",start, end);
                newNum[start] = *(pointerToInt + 2);
                printf("first: %d\n",*(pointerToInt + 2));
                newNum[end] = *(pointerToInt + 3);
                printf("second: %d\n",*(pointerToInt + 3));
                bitInput[end - 1]--;
                carry = 1;
                start++;
                end--;
                printf("cannl from 4 \n");
                FindParentNumbers(new_size,start,end);
                return;
            }else if((bitInput[start]*10 + bitInput[start+1]) == bitInput[end]+10){
                printf("3rd case\n");
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
                printf("call from 3\n");
                printf("start: %d, end: %d\n",start, end);
                FindParentNumbers(new_size,start,end);
                return;
            }else if(((bitInput[start]*10 - 1) + bitInput[start+1]) == bitInput[end]){
                printf("compare 10 with 9\n");
                new_size = size - 1;
                start++;
                newNum[start] = *(pointerToInt + 0) ;
                newNum[end] = *(pointerToInt + 1);
                carry = 0;
                start++;
                end--;
                printf("call from 10-9 case\n");
                printf("start: %d, end: %d\n",start, end);
                FindParentNumbers(new_size,start,end);
                return;
            }else{
                new_size = size;
                printf("doesn't have carry\n");
            }
        }
        printf("carry = %d\n",carry);
        if((bitInput[start]-1 == bitInput[end]) || (bitInput[start] == 0)){
            printf("2nd case\n");
            //bitInput[start]%2 == 1;
            if(carry == 1){
                if(bitInput[end] == 9){
                    newNum[start] = *(pointerToInt + 0); // if Ihave a carry then i get the second tuple
                    printf("first: %d\n",*(pointerToInt + 0));
                    newNum[end] = *(pointerToInt + 1); // TODO need to find how to point to the array of arrays
                    printf("second: %d\n",*(pointerToInt + 1));
                    if(bitInput[end-1] == 0){
                        bitInput[end-1] = 9;
                    }else{
                        bitInput[end-1]--;
                    };
                }else{
                    newNum[start] = *(pointerToInt + 2); // if Ihave a carry then i get the second tuple
                    printf("first: %d\n",*(pointerToInt + 2));
                    newNum[end] = *(pointerToInt + 3); // TODO need to find how to point to the array of arrays
                    printf("second: %d\n",*(pointerToInt + 3));
                    if(bitInput[end-1] == 0){
                        bitInput[end-1] = 9;
                    }else{
                        bitInput[end-1]--;
                    };
                }
            }
            if (carry == 0){
                printf("pointer: %d \n",*pointerToInt);
                newNum[start] = *pointerToInt;    // if I dont have a carry then i get the first tuple
                printf("first: %d\n",*(pointerToInt + 0));
                newNum[end] = *(pointerToInt + 1); // TODO need to find how to point to the array of arrays
                printf("second: %d\n",*(pointerToInt + 1));
            }
            //bitInput[end-1]--;
            carry = 1;
            start++;
            end--;
            printf("call from 2\n");
            FindParentNumbers(new_size,start,end);
            return;
        }
        else if(bitInput[start] == bitInput[end]){
            printf("1st case\n");
            if (carry == 0){
                printf("pointer: %d \n",*pointerToInt);
                newNum[start] = *pointerToInt;    // if I dont have a carry then i get the first tuple
                printf("firstt: %d\n",*(pointerToInt + 0));
                newNum[end] = *(pointerToInt + 1); // TODO need to find how to point to the array of arrays
                printf("second: %d\n",*(pointerToInt + 1));
                carry = 0;//////
            }
            if(carry == 1){
                if(bitInput[end] == 9){
                    newNum[start] = *(pointerToInt + 0); // if Ihave a carry then i get the second tuple
                    printf("first: %d\n",*(pointerToInt + 0));
                    newNum[end] = *(pointerToInt + 1); // TODO need to find how to point to the array of arrays
                    printf("second: %d\n",*(pointerToInt + 1));
                    carry = 1;
                    //bitInput[end-1]--;
                }else{
                    newNum[start] = *(pointerToInt + 2); // if Ihave a carry then i get the second tuple
                    printf("first: %d\n",*(pointerToInt + 2));
                    newNum[end] = *(pointerToInt + 3); // TODO need to find how to point to the array of arrays
                    printf("second: %d\n",*(pointerToInt + 3));
                                    carry =0;//////
                }
                if(bitInput[end-1] == 0){
                    bitInput[end-1] = 9;
                    printf("changed from 0 to 9\n");
                    carry = 1;
                }else{
                    printf("bitInput[end-1] %d\n",bitInput[end-1]);
                    bitInput[end-1]--;
                                    carry =0;//////
                };
            }

            //carry = 0;
            start++;
            end--;
            printf("call\n");
            FindParentNumbers(new_size,start,end);
            return;
        }
        else{
            printf("doesn't have parent numbers\n");
            return;
        }
    }
    else if(start == end){
        printf("start = end\n");
        if (bitInput[start] % 2 == 1){
            printf("0");
            exit(0);
        }
        if(carry == 0){
            printf("start: %d\n",start);
            printf("pointer: %d \n",*(pointerToInt + 4));
            newNum[start] = *(pointerToInt + 4);
            return;
        }
        else{
            printf("start: %d\n",start);
            printf("pointer: %d \n",*(pointerToInt + 2));
            newNum[start] = *(pointerToInt + 2);
            return;
        }
    }
    else{
        printf("the end\n");
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
int SizeOfInt(int n){
  int count=0;
  while(n!=0){
      n/=10;             /* n=n/10 */
      ++count;
  }
  return count;
}