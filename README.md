1. Seperate the input number into digits and place them into an array
2. Find the size of the input number
3. Check individualy each digit and compare the first with the last each time.
    3.1. if first == last digit => I am looking for numbers with the same size as the input
        3.1.1 Pick any combination of numbers that can create the last digit (with no carry??)
    3.2. if first-1 == last digit() ,I just have a carry from the second MSB => I am looking for numbers with the same size as the input
        3.2.1 Pick any combination of numbers that can create the last digit (with no carry??)
    3.3. if inputs[first]*10 + inputs[second]  = inputs[last] + 10 => I am looking for numbers with the size one less than the input.
    3.4.if inputs[first]*10 - 1 + inputs[second]  = inputs[last] + 10, I hace another carry of the second MSB =>
    
    //in cases 3 and 4 if I have carries need to make -1 the remaining number
    //also in cases 3 and 4 , need to make: first two digits - the last number
    //we need to check if it is (1 or 2) or (3 or 4) to search for a n-digit or (n-1)-digit number
4. After we take a decision about the number we exclude the checked digits and go on with the rest recursively.



//keep in mind the possibiity to go through the array, while it is non zero the digits instead of changing the start and the end of the recirsive call
//need to pick the correct add if there is only one spot left() eg: 181, when we check 8, need to take ONLY 4+4




if start < end
    if[start] = [end]
    elseif [start] + 1 = [end]
    elseif [start]*10 + [start+1] == [end] + 10
        GOTO [start + 1] and find something with Carry to create the num
        Carry = 1
        [end-1] - 1 to check afterwards
    elseif [start]*10 + 1 == [end] + 10
        GOTO [start + 1] and find something with Carry to create the num
        Carry = 1
        [end-1] - 1 to check afterwards
        [start+2] should ne with Carry
else if start == end
    only on e digit and either you have a Carry from the rest of the number or not
    if it is an odd number, no solution, elseif even we have solution
else start > end
    return