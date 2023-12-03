/*
 * Nathan Whitney
 *
 * Advent of Code 2023 Day 2
 * Parts 1 & 2
 */

#include <stdio.h>

const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;

const int BUFFER_SIZE = 256;

int main(int argc, char* argv[]){
    FILE* fptr = fopen(argv[1], "r");

    char buffer[BUFFER_SIZE];

    //Final data to keep track of
    int sumOfGameID = 0;
    long totalPowerSet = 0;

    //The IDs start at 1.
    int gameID = 1;

    while(fgets(buffer, BUFFER_SIZE, fptr)){
        int largestRed, largestGreen, largestBlue;
        largestRed = largestGreen = largestBlue = 0;

        int bufferIndex = 0;

        //Start by assuming a game is possible
        int possibleGame = 1;

        //Skip the game ID, because they are being kept track by the gameID var
        while(buffer[bufferIndex] != ':')
            bufferIndex++;
        
        //Keeps track of location in string
        bufferIndex++;

        int tempNum = -1;

        //Loop through each line
        while(buffer[bufferIndex] != '\n'){
            //Get the number
            if(buffer[bufferIndex] >= '0' && buffer[bufferIndex] <= '9'){
                if(buffer[bufferIndex + 1] >= '0' && buffer[bufferIndex + 1] <= '9'){
                    tempNum = ((buffer[bufferIndex] - 48) * 10) + (buffer[bufferIndex + 1] - 48);
                }
                else{
                    tempNum = buffer[bufferIndex] - 48;
                }
                bufferIndex += 2;
            }

            //If a tempNm exists check the characters.
            if(tempNum != -1){
                //Need to check for all of red, as the first re could be apart of green
                if(buffer[bufferIndex] == 'r' && buffer[bufferIndex + 1] == 'e' && buffer[bufferIndex + 2] == 'd'){
                    if(tempNum > MAX_RED)
                        possibleGame = 0;

                    if(tempNum > largestRed)
                        largestRed = tempNum;

                    tempNum = -1;
                }
                //Check for green
                else if(buffer[bufferIndex] == 'g'){
                    if(tempNum > MAX_GREEN)
                        possibleGame = 0;

                    if(tempNum > largestGreen)
                        largestGreen = tempNum;

                    tempNum = -1;
                }
                //Check for blue
                else if(buffer[bufferIndex] == 'b'){
                    if(tempNum > MAX_BLUE)
                        possibleGame = 0;

                    if(tempNum > largestBlue)
                        largestBlue = tempNum;

                    tempNum = -1;
                }
            }

            bufferIndex++;
        }

        //If the game is possible, add its ID to a sum.
        if(possibleGame)
            sumOfGameID += gameID;
        
        //Create the power out of each set.
        totalPowerSet += largestRed * largestGreen * largestBlue;

        //increment the gameID tracker
        gameID++;
    }

    printf("The sum of possible Game IDs is: %d\n", sumOfGameID);
    printf("The sum of all powers of sets is: %d\n", totalPowerSet);
}