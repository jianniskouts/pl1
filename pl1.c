#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"reverse.h"

/*int SizeOfInt(int);
int ReverseInt(int);
int *DigitsInArray(int);

int *FindParentNumbers(int ,int ,int ,int );*/


int main(int argc,char* argv[]){
    int start, end, size,i,n;
    char c;
    //int input;
    printf("yolo\n");
    for(i = 0; i < 100000; i++){
        printf("%d\n",argv[1][i]-'0');
    }
    size = i;
    //size = SizeOfInt(input);
    start = 0;
    end = size-1;
    //bitInput = DigitsInArray(input);
    for(i = 0; i < size; i++){
        printf("BitInput: %d\n",bitInput[i]);
    }
    FindParentNumbers(size,start,end);
    if(new_size < size){
        n = 1;
    }
    else{
        n = 0;
    }
    printf("final: ");
    for(i = n; i < size; i++){
        //SUM[i] = newNum[i] + newNum[size-i-1];
        printf("%d",newNum[i]);
    }
    printf("\n");
    /*printf("SUM:");
    for(i = n; i < size; i++){
        //SUM[i] = newNum[i] + newNum[size-i-1];
        printf("%d",SUM[i]);
    }
        printf("\n");*/
    return 0;
}


