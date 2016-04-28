#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"test.h"

int SizeOfInt(int);
int ReverseInt(int);
int *DigitsInArray(int);



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
    printf("yolo: %d\n",*(Numbers[5]+5));
    return 0;
}


