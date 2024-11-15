#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool startsWithB(const char *stringInfo) {
    if (stringInfo == NULL) {
        return false;
    }
    return stringInfo[0] == 'B';
}

bool endsWithB(const char *stringInfo) {
    if (stringInfo == NULL || strlen(stringInfo) == 0) {
        return false;
    }
    return stringInfo[strlen(stringInfo) - 1] == 'b';
}

int filterString(char *names[], int arrayLength, bool (*predicate)(const char*), char *result[], int maxResults) {
    int count = 0;
    for (int loopIdxCounter = 0; loopIdxCounter < arrayLength; loopIdxCounter++) {
        /* Compare the first or last char of the names with the given alphabet */
        if (predicate(names[loopIdxCounter])) {
            if (count < maxResults) {
                result[count] = names[loopIdxCounter];
                count++;
            }
        }
    }
    return count;
}
void printOnConsole(char *resultStr[], int countInfo)
{    
    /* Print the filtered names */
    printf("Names starting or ending with 'B' or 'b':\n");
    for (int loopIdxCounter = 0; loopIdxCounter < countInfo; loopIdxCounter++) 
    {
        printf("%s\n", resultStr[loopIdxCounter]);
    }
}
int main() 
{
    // Define an array of names
    char *listOfStrings[] = {"bosch", "Bob", "Lenovo", "Bengaluru", "Rubic", "Dumb"};
    int size = sizeof(listOfStrings) / sizeof(listOfStrings[0]);
    char *result[10]; /* Array for the filtered results */

    /* Use the startsWithB predicate to filter names */
    int count = filterString(listOfStrings, size, startsWithB, result, 10);
    printOnConsole(result,count);
    count = filterString(listOfStrings, size, endsWithB, result, 10);
    printOnConsole(result,count);
    return 0;
}
