#include<stdio.h>


int main(int argc, char** argv){
    int i;
    for(i = 0; i < 15; i++){
        printf("%d\n",argv[1][i] -'0');
    }
    return 0;
}