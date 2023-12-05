#include <stdio.h>
#include <stdlib.h>

void getSize(int* vertical, int* horizontal, char* fileName);

void fillSchematic(char** schematic, char* fileName);

int checkChar(char** schematic, int row, int col);

int main(int argc, char* argv[]){
    int horizontalSize, verticalSize;


    getSize(&verticalSize, &horizontalSize, argv[1]);

    printf("Lines: %d Columns: %d\n", verticalSize, horizontalSize);
    
    //Allocating dynamic 2d array
    char** schematic = malloc(sizeof(char *) * horizontalSize);
    for(int i = 0; i < horizontalSize; i++)
        schematic[i] = malloc(sizeof(char) * verticalSize);

    fillSchematic(schematic, argv[1]);

    //Printing out the schematic for testing
    /*
    for(int i = 0; i < horizontalSize; i++){
        for(int j = 0; j < verticalSize; j++){
            printf("%c", schematic[i][j]);
        }
        printf("\n");
    }*/

    for(int i = 0; i < horizontalSize; i++){
        for(int j = 0; j < verticalSize; j++){
            
        }
    }
} 

void getSize(int* vertical, int* horizontal, char* fileName){
    *vertical = 0;
    *horizontal = 0;

    FILE* fptr = fopen(fileName, "r");

    char curChar;

    int newHorizontal = 0;

    while(!feof(fptr)){
        curChar = fgetc(fptr);

        if(curChar == '\n'){
            (*vertical)++;
            *horizontal = newHorizontal;
            newHorizontal = 0;
        }
        else
            newHorizontal++;
    }

    fclose(fptr);
}

void fillSchematic(char** schematic, char* fileName){
    FILE* fptr = fopen(fileName, "r");

    char curChar = fgetc(fptr);

    int row = 0;
    int col = 0;

    while(!feof(fptr)){
        if(curChar == '\n'){
            row++;
            col = 0;
        }
        else{
            schematic[row][col] = curChar;
            col++;
        } 
        curChar = fgetc(fptr);
    }

    fclose(fptr); 
}

int checkChar(char** schematic, int row, int col){
    if(schematic[row][col] == '.')
        return -1;
    
}