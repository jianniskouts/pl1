#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"test.h"

/*int SizeOfInt(int);
int ReverseInt(int);
int *DigitsInArray(int);

int *FindParentNumbers(int ,int ,int ,int );*/


int main(int argc,char* argv[]){
    int input, start, end, size,i;
    //int *newNum = malloc(1000000*sizeof(int));//array with 100.000 memory sets
    int *final = malloc(10*sizeof(int));
    input = atoi(argv[1]);
    size = SizeOfInt(input);
    start = 0;
    end = size-1;
    BitInput = DigitsInArray(input);
    for(i = 0;i< size;i++){
        printf("BitInput: %d\n",BitInput[i]);
    }
    p = FindParentNumbers(final,size,start,end);
    printf("final: ");
    for(i = 0;i< size;i++){
        printf("%d",p[i]);
    }
    printf("\n");
    /*for(i = 0; i < input; i++){
        BitInput = DigitsInArray(input);
        newNum = ReverseInt(i);
        if (i + newNum == input){
            printf(" Fuck yeah, %d\n",i);
            break;
        }
    }*/
    return 0;
}


