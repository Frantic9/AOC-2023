/*
 * Nathan Whitney
 *
 * Advent of Code 2023 Day 1
 * Part 1
 */

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
    FILE* fptr = fopen(argv[1], "r");

    char curChar;

    int totalSum = 0;

    int firstNumber;
    int secondNumber;

    bool foundFirst = false;

    do {
        curChar = fgetc(fptr); 
        
        if(feof(fptr)){
            break;
        }
        if(curChar == '\n'){
            totalSum += ((firstNumber - 48) * 10 + (secondNumber - 48));
            foundFirst = false;
            
        } 
        else if(curChar >= '0' && curChar <= '9'){
            if(!foundFirst){
                firstNumber = curChar;
                secondNumber = curChar;
                foundFirst = true;
            } else {
                secondNumber = curChar;
            }
        }
    } while(true);

    fclose(fptr);

    printf("Sum of all numbers in the file: %d\n", totalSum);
}