#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int MAX_BINARY_NUMBER_SIZE = 16;

char* enterUserString()
{
    printf("Enter number in binary format (no more than 16 symbols):\n");
    char* binaryNumber = (char*)malloc(sizeof(char) * (MAX_BINARY_NUMBER_SIZE + 2));
    scanf("%s", binaryNumber);
    int stringSize = strlen(binaryNumber);
    if (stringSize > MAX_BINARY_NUMBER_SIZE)
    {
        return "string is too large";
    }
    bool isCorrect = true;
    for (int i = 0; i < stringSize; ++i)
    {
        if (binaryNumber[i] != '0' && binaryNumber[i] != '1')
        {
            isCorrect = false;
            break;
        }
    }
    if (isCorrect)
    {
        return binaryNumber;
    }
    else return "not parsed";
}

int convertNumber(char* binaryNumber)
{
    int decimalNumber = 0;
    int currentDegreeOfTwo = 1;

    int stringSize = strlen(binaryNumber);
    for (int i = stringSize - 1; i >= 0; --i)
    {
        if (binaryNumber[i] == '1')
        {
            decimalNumber += currentDegreeOfTwo;
        }
        currentDegreeOfTwo *= 2;
    }

    return decimalNumber;
}

bool test(void)
{
    bool result = convertNumber("101") == 5;
    result &= convertNumber("1111") == 15;
    result &= convertNumber("11111111") == 255;
    result &= convertNumber("10100111100000") == 10720;
    result &= convertNumber("111111111111111") == 32767;
    return result;
}

int main()
{
    if (!test())
    {
        printf("Test failed");
        return 1;
    }
    printf("Test succced\n");
    char* userNumber = enterUserString();
    if (strcmp(userNumber, "not parsed") == 0)
    {
        printf("entered number is incorrect, process terminated\n");
        return 1;
    }
    if (strcmp(userNumber, "string is too large") == 0)
    {
        printf("entered number is too large, process terminated\n");
        return 1;
    }
    printf("%s has been converted successfully to %d", userNumber, convertNumber(userNumber));
    return 0;
}
