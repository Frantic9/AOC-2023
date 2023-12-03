/*
 * Nathan Whitney
 *
 * Advent of Code 2023 Day 2
 * Part 2
 */

#include <stdio.h>
#include <string.h>

int getNumber(char* str);

int main(int argc, char *argv[]){
    FILE* fptr = fopen(argv[1], "r");

    char inputString[64];

    int totalSum = 0;

    while(fgets(inputString, 64, fptr)){
        int firstNumber = -1;
        int secondNumber = -1;

        //Find the first numbers
        for(int i = 0; firstNumber == -1; i++){
            firstNumber = getNumber(inputString + i);
        }

        //Find the second number
        for(int i = 0; inputString[i] != '\n'; i++){
            int temp = getNumber(inputString + i);
            if(temp != -1)
                secondNumber = temp;
        }

        //Create the two digit number and add to sum
        totalSum += (firstNumber * 10) + secondNumber;
    }

    printf("Sum of the numbers in the file: %d\n", totalSum);
}

//Check if current char or next chars create a number
int getNumber(char* str){
    //if the char is a digit then just return the digit
    if(*str >= '0' && *str <= '9')
        return *str - 48;

    //build strings for each length of word
    char threeLetter[4] = {*str, *(str+1), *(str+2), '\0'};
    char fourLetter[5] = {*str, *(str+1), *(str+2), *(str+3), '\0'};
    char fiveLetter[6] = {*str, *(str+1), *(str+2), *(str+3), *(str+4), '\0'};

    //Compare the strings
    if(strcmp(fourLetter, "zero") == 0)
        return 0;
    else if(strcmp(threeLetter, "one") == 0)
        return 1;
    else if(strcmp(threeLetter, "two") == 0)
        return 2;
    else if(strcmp(fiveLetter, "three") == 0)
        return 3;
    else if(strcmp(fourLetter, "four") == 0)
        return 4;
    else if(strcmp(fourLetter, "five") == 0)
        return 5;
    else if(strcmp(threeLetter, "six") == 0)
        return 6;
    else if(strcmp(fiveLetter, "seven") == 0)
        return 7;
    else if(strcmp(fiveLetter, "eight") == 0)
        return 8;
    else if(strcmp(fourLetter, "nine") == 0)
        return 9;
    return -1;
}