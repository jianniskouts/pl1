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
/*struct sum {
    int a;
    int b;
    struct sum *next;
};
struct sum zero0;
zero0->a = 0;
zero0->b = 0;
zero0->next = zero1;
struct sum zero1;

struct sum one0;

struct sum one1;

struct sum two0;

struct sum two1;

struct sum two2;

struct sum three0;

struct sum three1;

struct sum four0;

struct sum four1;

struct sum four2;

struct sum five0;

struct sum five1;
five1.a = 9;
five1.b = 6;
five1.next = NULL;
struct sum six0;
six0.a = 6;
six0.b = 0;
six0.next = six1;
struct sum six1;
six1.a = 8;
six1.b = 8;
six1.next = six2;
struct sum six2;
six2.a = 3;
six2.b = 3;
six2.next = NULL;
struct sum seven0;
seven0.a = 7;
seven0.b = 0;
seven0.next = seven1;
struct sum seven1;
seven1.a = 9;
seven1.b = 8;
seven1.next = NULL;
struct sum eight0;
eight0.a = 8;
eight0.b = 0;
eight0.next = eight1;
struct sum eight1;
eight1.a = 9;
eight1.b = 9;
eight1.next = eight2;
struct sum eight2;
eight2.a = 4;
eight2.b = 4;
eight2.next = NULL;
struct sum nine0;
nine0.a = 9;
nine0.b = 0;
nine0.next = NULL;

struct sum Numbers[10];
    Numbers[0] = &zero0;
    //Numbers[1] = &zero1;
    Numbers[1] = &one0;
    //Numbers[3] = &one1;
    Numbers[2] = &two0;
    //Numbers[5] = &two1;
    //Numbers[6] = &two2;
    Numbers[3] = &three0;
    //Numbers[8] = &three1;
    Numbers[4] = &four0;
    //Numbers[10] = &four1;
    //Numbers[11] = &four2;
    Numbers[5] = &five0;
    //Numbers[13] = &five1;
    Numbers[6] = &six0;
    //Numbers[15] = &six1;
    //Numbers[16] = &six2;
    Numbers[7] = &seven0;
    //Numbers[18] = &seven1;
    Numbers[8] = &eight0;
    //Numbers[20] = &eight1;
    //Numbers[21] = &eight2;
    Numbers[9] = &nine0;
    //Numbers[23] = &nine1;


*/
int **Numbers[]= {(int**)zero,(int**)one,(int**)two,(int**)three,(int**)four,(int**)five,(int**)six,(int**)seven,(int**)eight,(int**)nine};
int SizeOfInt(int);
int ReverseInt(int);
int *DigitsInArray(int);
void FindParentNumbers(int ,int ,int );

int start,end,new_size;
int newNum[100000],inputs[100000];
int *pointerToInt,*bitInput;
int carry = 0;
int flag = 0;
void FindParentNumbers(int size,int start,int end){
    pointerToInt = Numbers[bitInput[end]];
    printf("here\n");
    printf("pointerToInt: %d \n",*(pointerToInt + 0));
    printf("fresh: start: %d, end: %d\n",start, end);
    if(start < end){
        flag++; //seperate first and the rest recersive calls of the function
        //pointerToInt = Numbers[bitInput[end]];

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
                FindParentNumbers(new_size,start,end);
                return;
            }
            else if((bitInput[start]*10 + bitInput[start+1]) == bitInput[end]+10){
                printf("3rd case\n");
                new_size = size - 1;
                start++;
                newNum[start] = *(pointerToInt + 2) ;
                newNum[end] = *(pointerToInt + 3);
                carry = 0;
                bitInput[end-1]--;
                start++;
                end--;
                printf("call from 3\n");
                printf("start: %d, end: %d\n",start, end);
                FindParentNumbers(new_size,start,end);
                return;
            }
            else{
                new_size = size;
                printf("doesn't have carry\n");
            }
        }
        if(bitInput[start]-1 == bitInput[end]){
            printf("2nd case\n");
            //bitInput[start]%2 == 1;
            if(carry == 1){
                newNum[start] = *(pointerToInt + 2); // if Ihave a carry then i get the second tuple
                printf("first: %d\n",*(pointerToInt + 2));
                newNum[end] = *(pointerToInt + 3); // TODO need to find how to point to the array of arrays
                printf("second: %d\n",*(pointerToInt + 3));
                bitInput[end-1]--;
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
            printf("call\n");
            FindParentNumbers(new_size,start,end);
            return;
        }
        else if(bitInput[start] == bitInput[end]){
            printf("1st case\n");
            if(carry == 1){
                newNum[start] = *(pointerToInt + 2); // if Ihave a carry then i get the second tuple
                printf("first: %d\n",*(pointerToInt + 2));
                newNum[end] = *(pointerToInt + 3); // TODO need to find how to point to the array of arrays
                printf("second: %d\n",*(pointerToInt + 3));
                bitInput[end-1]--;
            }
            if (carry == 0){
                printf("pointer: %d \n",*pointerToInt);
                newNum[start] = *pointerToInt;    // if I dont have a carry then i get the first tuple
                printf("first: %d\n",*(pointerToInt + 0));
                newNum[end] = *(pointerToInt + 1); // TODO need to find how to point to the array of arrays
                printf("second: %d\n",*(pointerToInt + 1));
            }
            carry = 0;
            start++;
            end--;
            printf("call\n");
            FindParentNumbers(new_size,start,end);
            return;
        }
        else{
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