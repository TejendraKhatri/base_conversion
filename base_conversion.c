/**************************************************
*
* File Name: base_conversion.c
*
* CSIS 320 Architecture
* Minnesota State University
*
* Developer: Tejendra, Khatri
* Date: Jan 21, 2020 at 11:00 pm
* Updated: Jan 21, 2020 at 11:30 pm
* Compile: gcc base_conversion.c -o base_conversion.out
*
/**************************************************/


/*
Algorithm: Convert the original number to decimal number first
            and then convert the decimal to the desired number system
Notes: Alphabets MUST be typed in uppercase letters
*/

#include <stdio.h>
#include <stdlib.h>

int getDecimalNumber(const char inputValue[],int initBase)
{
    int value = 0; 
    int tracker = 0;
    int digit = 0;
    char tempChar;
    while (inputValue[tracker] != 0) {
        tempChar = inputValue[tracker];
        tracker++;   //move ahead to next position
        if (tempChar >= '0' && tempChar <= '9') 
        {
            digit = tempChar - '0';   //convert char to int
        }
        else if (tempChar >= 'A' && tempChar <= 'F')
        {
            digit = tempChar - 'A';  //convert char to int and adjust numbers 
            digit += 10;             //so that A represents 10 and so forth
        }
        else 
        {
            printf("%c is an INVALID CHARACTER!!\nProgram exiting.", tempChar);
            exit(0);
        }
        if (digit >= initBase) //check to see that the digit is always less than base
        {
            printf("%c is an INVALID CHARACTER!!\nProgram exiting.", tempChar);
            exit(0);
        }
        value = value * initBase + digit;
    }
    return value;
}

void getDesiredNumber(int decimalValue, int finalBase,char *outputValue)
{
    int digit,tracker = 0;
    while (decimalValue > 0) {
        digit = decimalValue % finalBase;
        decimalValue = decimalValue / finalBase;
        if(digit <10)
        {
            outputValue[tracker++] = digit + '0';   
        }
        else
        {
            outputValue[tracker++] = digit + 'A' - 10;
        }
    }
    outputValue[tracker] ='\0'; //terminate char array
}


void main(void)
{
    //DECLARE AND INITIALIZE THE VARIABLES
    int initBase;  
    int finalBase;
    char inputValue[100];   //stores the number in initial base
    char outputValue[] = "";  //stores the number in desired base
    char tempChar;
    int digit;
    int decimalValue;
    int tracker = 0 ;

    //GET INPUTS FROM THE USER
    printf ("Enter initial base, b1: "); 
    scanf("%d", &initBase);
    printf ("Enter desired base, b2: "); 
    scanf("%d", &finalBase);
    printf ("Enter number in base %d : ", initBase); 
    scanf("%s", inputValue);

    //CONVERT THE NUMBER IN INITIAL BASE TO DECIMAL BASE
    decimalValue = getDecimalNumber(inputValue,initBase);
    
    //CONVERT THE DECIMAL NUMBER TO REQUIRED BASE
    getDesiredNumber(decimalValue,finalBase,outputValue);
    
    //FIND THE SIZE OF THE OUTPUT ARRAY
    tracker = 0;
    while(outputValue[tracker]!='\0')
    {
        tracker++;
    }

    printf("So, the equivalent in base %d is ",finalBase);

    //REVERSE THE SEQUENCE OF REMAINDERS
    for(int j=tracker-1; j>=0; j--){
        printf("%c", outputValue[j]);
    }
    printf("\nThank you for using my program!\n");
}