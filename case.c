#include<stdio.h>

int * fillArray(int);
int arr[11];
int *p;
int main(){
    int i;
    int size = 10;
    p = fillArray(size);
    
    for(i = 0;i < size; i++){
        printf("%d\n",p[i]);
    }
    return 0;
}



int *fillArray(int size_){
    int i;
    for(i = 0;i < size_; i++){
        scanf("%d",&arr[i]);
    }
    return arr;
}