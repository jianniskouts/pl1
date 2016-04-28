#include<stdio.h>
int temp;
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
int *Numbers[10] = {zero,one,two,three,four,five,six,seven,eight,nine};
int main(int argc, char* argv[]){

    int input = 0;
    scanf("%d", &input);
   //Get Input and put each bit in an array
   //int inputs[size];
    input = input % 10;
    if (input == 3){
        int temp = *(Numbers[3] + 2);
        printf("temp = %d\n",temp);
    }
    return 0;
}
int FindParentNumbers(input, size){
    for(int i = 0 ; i< size/2 + 1,i++){
        if(BitNum[j] == BitNum[size-j-1]){
            new_size = size;
            temp = *(Numbers[BitNum[size-j-1]]);
            newNum[j] = temp;
            temp = *(Numbers[BitNum[size-j-1]]+1);
            newNum[size-j-1] = temp;
        }else if(BitNum[j]-1 == BitNum[size-j-1]){ //have to add somehow the fact that I w8 for Carry
            new_size = size;
            temp = *(Numbers[BitNum[size-j-1]]);
            newNum[j] = temp;
            temp = *(Numbers[BitNum[size-j-1]]+1);
            newNum[size-j-1] = temp;
        }else if((BitNum[j]*10 + BitNum[j+1]) == (BitNum[size-j-1] + 10)){
            new_size = size - 1;
            temp = *(Numbers[BitNum[size-j-1]]); //have to take an option with Carry = 1
            newNum[j] = temp;
            temp = *(Numbers[BitNum[size-j-1]]+1);
            newNum[size-j-1] = temp;
        }
        else{
            new_size = size - 1;
            temp = *(Numbers[BitNum[size-j-1]]); //have to take an option with Carry = 1
            newNum[j] = temp;
            temp = *(Numbers[BitNum[size-j-1]]+1);
            newNum[size-j-1] = temp;
        }
        //call recursively with the remains of the initial number
        //as every time I take out the digits I checked
        temp = *(Numbers[input]);
    }
}   
int findNum(inputs[tade],temp){
    //if even 6 else if odd 5 loops
    for(int i = 0; i < 6; i++){
        temp = *(Numbers[inputs[size-1]]);
        //temp a global variable, which will be added to te number we build in each case ,, HOW????
        //maybe pass temp to the next function call
        if (*(Numbers[inputs[]+2]) > 0){
            findNum(*(Numbers[inputs[size-2]]));
        }
    }
    
    return 0;
}