/*************************************************************************************************************
FILE:         input_fact.c
AUTHOR:       RC
DESCRIPTION:  Prompts user for integer, returns its factorial.
HEADER:       input_fact.h
SOURCE:       input_fact.c
COMPILE:      $ gcc -o fact input_fact.c
RUN:          $ ./fact
*************************************************************************************************************/

#include "input_fact.h"

int main()
{
    char message[] = "Do you want to find a factorial?  Y/N: ";
    PlayOrQuit(message);
    return 0;
}

/*  Returns a factorial, function is recursive  */
int Factorial(int n)
{
    int answer;
    if(n==1 || n==0) {            // base case
        return 1;
    }
    answer = Factorial(n-1)*n;
    return answer;
}

/*  Gets an integer from user, range = lo:hi  */
int GetInteger(int lo, int hi)
{
    while(1) {
        printf("Enter an integer between %d and %d: ", lo, hi);
        int user_int = -1;
        char buf[4];
        // Reads in 3 chars or until \n from stdin.  Adds \0 to end.
        fgets(buf, 4, stdin);

        // Check for a newline stored in buf, indicating all chars captured.
        if(!strchr(buf, '\n')) {
            // CLEAR BUFFER - gets additional chars out up to newline.
            while ((getchar()) != '\n');                
        }
        sscanf(buf, "%d", &user_int);
        if(user_int >= lo && user_int <= hi) {
            return user_int;
        } else {                                          
            printf("Input out of range\n");
        }
    }
}

/*  Keeps program looping w/ quit option  */
void PlayOrQuit(char *msg)         
{
    while(1) {
        printf("%s", msg);
        char user_char = getchar(); 
        if (user_char == '\n') {  
            // if only enter pressed, carry on...
            continue;
        } else {
            // CLEAR BUFFER - gets any additional chars out up to newline.
            while ((getchar()) != '\n');                
        }
        if(user_char == 'Y' || user_char == 'y') { 	
            TaskCalls();
        } else if(user_char == 'N' || user_char == 'n') {
            printf("exiting program....\n");
            break;
        } else {
            printf("not a valid option, try again\n");
        }
    }
}

/*  Tasks to be called, along with parameters  */
void TaskCalls(void) 
{
    int lo = 0;
    int hi = 12;
    int user_num = GetInteger(lo, hi);   
    int solution;
    solution = Factorial(user_num);
    printf("The factorial of %d is %d. \n", user_num, solution);
}