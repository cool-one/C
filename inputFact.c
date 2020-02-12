/*************************************************************************************************************
FILE:         inputFact.c
AUTHOR:       RC
DESCRIPTION:  Run from Linux command prompt, prompts user for input and returns the factorial.
HEADER:       inputFact.h
SOURCE:       inputFact.c
COMPILE:      $ gcc -o fact inputFact.c
RUN:          $ ./fact
*************************************************************************************************************/

#include "inputFact.h"

/*----------------------------------------------------------
Main
----------------------------------------------------------*/
int main()
{ 
  playOrQuit();
  return 0;
}

/*----------------------------------------------------------
[1] Returns a factorial, function is recursive
----------------------------------------------------------*/
int factorial(int n)
{
  int answer;
  if(n==1 || n==0)        //base case.
  {
    //printf("n! of n = %d is 1\n", n);             //CK
    return 1;
  }
  answer = factorial(n-1)*n;
  //printf("n! of n = %d is: %d\n", n, answer);     //CK
  return answer;
}

/*----------------------------------------------------------
[2] Gets an integer from user, restricted input         
----------------------------------------------------------*/
int getInteger(void)
{
  while(1) 
  {
    printf("Enter an integer between 0 and 12 to find its factorial: ");
    int userInt = -1;
    char buf[4];
    fgets(buf, 4, stdin);                           //reads in 3 chars or until \n.
    if(strchr(buf, '\n')) {
    } else {
        while ((getchar()) != '\n');                //clear buffer.
    }
    sscanf(buf, "%d", &userInt);      
    //printf("integer entered is: %d\n", userInt);  //CK
    
    if(userInt >= 0 && userInt <= 12)               //range of input.
    {
      return userInt;
    }
    else {                                          //catch out of range.
      printf("Input out of range\n");
    }
  }
}

/*----------------------------------------------------------
[3] Keeps program looping w/ quit option
----------------------------------------------------------*/
void playOrQuit(void)         
{
  while(1)              
  {
    printf("Do you want to find a factorial?  Y/N: ");
    char userChar = getchar(); 
    if (userChar == '\n') 
    {  //printf("triggered\n");                     //CK
    } else {
        while ((getchar()) != '\n');                //clear buffer.
    }
    //printf("Character used is: %c\n", userChar);  //CK
    if(userChar == 'Y' || userChar == 'y')    
    { 
      //functions to call
      int userNum = getInteger();   
      int answer;
      answer = factorial(userNum);
      printf("The factorial of %d is %d. \n", userNum, answer);           
    }
    else if(userChar == 'N' || userChar == 'n')
    {
      printf("exiting program....\n");
      printf("Have a nice day!\n");
      break;
    }
    else
    {
      printf("not a valid option, try again\n");
    }
  }
}

