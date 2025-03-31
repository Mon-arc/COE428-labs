#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void displayStates(char stateTable[][3])
{
    for (int i = 0; i < 8; i++) {
        if (stateTable[i][0] != '-') {
            printf("%c: %c %c\n", stateTable[i][0], stateTable[i][1], stateTable[i][2]);
        }
    }
}

void updateState(char command[100], char currentState, char stateTable[][3])
{
    for (int i = 0; i < 8; i++) {
        if (stateTable[i][0] == currentState && stateTable[i][0] != '-') {
            if (command[2] == '0') {
                stateTable[i][1] = command[4];
            }
            else if (command[2] == '1') {
                stateTable[i][2] = command[4];
            }
            break;
        }
    }
}

char getNextState(char stateTable[8][3], char currentState, int input)
{
    char current[2] = { currentState, '\0' };
    int currentIndex = 0;
    int isValid = 0;

    if (input != 0 && input != 1) {
        printf("Invalid input\n");
    }

    for (int i = 0; i < 8; i++) {
        if (stateTable[i][0] == currentState) {
            currentIndex = i;
            break;
        }
    }

    if (stateTable[currentIndex][0] == currentState) {
        isValid = 1;
    } else {
        printf("%d Error in code\n", currentIndex);
    }

    if (isValid == 1) {
        if (input == 0) {
            return stateTable[currentIndex][1];
        }
        else if (input == 1) {
            return stateTable[currentIndex][2];
        }
        else {
            printf("Error somewhere?\n");
        }
    }

    return ' ';
}

void removeSpecificState(char stateTable[][3], int stateCount, char userInput, char garbageStates[8])
{
    int removedCount = 0;
    int size = (sizeof(garbageStates) / sizeof(garbageStates[0]));
    
    for (int i = 0; i < size; i++)
    {
        if (garbageStates[i] == userInput)
        {
            for (int index = 0; index < 8; index++)
            {
                if (garbageStates[i] == stateTable[index][0])
                {
                    stateTable[index][0] = '-';
                    stateTable[index][1] = '-';
                    stateTable[index][2] = '-';
                    printf("Deleted: %c\n", userInput);
                }
            }
            removedCount++;
        }
    }
    stateCount -= removedCount;
    if (removedCount == 0)
    {
        printf("State was not deleted.\n");
    }
}

void removeStates(char stateTable[][3], int stateCount, char garbageStates[8])
{
    int removedCount = 0;
    int size = (sizeof(garbageStates) / sizeof(garbageStates[0]));
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (garbageStates[i] == stateTable[j][0])
            {
                printf("Deleted: %c\n", stateTable[j][0]);
                stateTable[j][0] = '-';
                stateTable[j][1] = '-';
                stateTable[j][2] = '-';
                removedCount++;
            }
        }
    }
    stateCount -= removedCount;
    if (removedCount == 0)
    {
        printf("No garbage states.\n");
    }
}

void identifyUnreachableStates(char stateTable[][3], int stateCount, char garbageStates[8])
{
    int unreachableCount = 0;
    int refCount = 0;
    int garbageIndex = 0;
    
    for (int i = 0; i < 8; i++)
    {
        if (stateTable[i][1] == stateTable[i][2]) {
            for (int j = 0; j < 8; j++) {
                if (j != i) {
                    garbageStates[j] = stateTable[j][0];
                    unreachableCount++;
                }
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((stateTable[i][0] == (stateTable[j][1])) || (stateTable[i][0] == stateTable[j][2]))
            {
                refCount++;
            }
        }
        if (refCount == 0)
        {
            garbageStates[garbageIndex] = stateTable[i][0];
            garbageIndex++;
            unreachableCount++;
        }
        refCount = 0;
    }
    
    int garbageSize = sizeof(garbageStates) / sizeof(garbageStates[0]);
    if (unreachableCount == 0)
    {
        printf("No Garbage Detected\n");
    }
    else
    {
        for (int i = 0; i < garbageSize; i++)
        {
            if (garbageStates[i] >= 'A' && garbageStates[i] <= 'H')
            {
                printf("Garbage: %c\n", garbageStates[i]);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    char garbageStates[8];
    memset(garbageStates, '\0', sizeof(garbageStates));
    int userInput;
    int stateCount = 8;
    char inputString[100];
    char initialState = 'A';
    char currentState = initialState;
    char stateTable[8][3] = {
        {'A','F','E'},
        {'B','B','H'},
        {'C','A','D'},
        {'D','G','B'},
        {'E','C','G'},
        {'F','B','E'},
        {'G','D','F'},
        {'H','A','C'}
    };

    printf("Starting state: < %c >\n", initialState);

    while (1) {
        userInput = 5;
        inputString[0] = '`';
        inputString[1] = '`';
        inputString[2] = '`';
        inputString[3] = '`';
        inputString[4] = '`';
        inputString[5] = '`';

        while (1) {
            printf("\nEnter a input: ");
            fgets(inputString, 100, stdin);
            if (inputString[0] == '1' && strlen(inputString) == 2) {
                userInput = 1;
                break;
            }
            else if (inputString[0] == '0' && strlen(inputString) == 2) {
                userInput = 0;
                break;
            }
            else if (inputString[0] == 'c' && (inputString[2] == '0' || inputString[2] == '1') && inputString[4] >= 'A' && inputString[4] <= 'H') {
                break;
            }
            else if (inputString[0] == 'p' && strlen(inputString) == 2) {
                break;
            }
            else if (inputString[0] == 'd' && (strlen(inputString) == 2 || strlen(inputString) == 3)) {
                break;
            }
            else if (inputString[0] == 'g' && strlen(inputString) == 2) {
                break;
            }
            else if (inputString[0] == 'e') {
                exit(0);
            }
            else {
                printf("\nInvalid input, try again.\n");
            }
        }

        if (userInput == 1) {
            currentState = getNextState(stateTable, currentState, 1);
            printf("Current state is: < %c >\n", currentState);
        }
        else if (userInput == 0) {
            currentState = getNextState(stateTable, currentState, 0);
            printf("Current state is: < %c >\n", currentState);
        }
        else if (inputString[0] == 'c') {
            updateState(inputString, currentState, stateTable);
        }
        else if (inputString[0] == 'p') {
            displayStates(stateTable);
        }
        else if (inputString[0] == 'd') {
            if (strlen(inputString) == 2) {
                removeStates(stateTable, stateCount, garbageStates);
            }
            else if (strlen(inputString) == 3) {
                removeSpecificState(stateTable, stateCount, inputString[1], garbageStates);
                stateCount--;
            }
        }
        else if (inputString[0] == 'g') {
            identifyUnreachableStates(stateTable, stateCount, garbageStates);
        }
    }

    return 0;
}

