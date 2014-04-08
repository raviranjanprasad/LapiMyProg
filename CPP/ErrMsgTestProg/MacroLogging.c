/*
 * =====================================================================================
 *
 *       Filename:  MacroLogging.c
 *
 *    Description:  Testing Macro with variable Argument.
 *
 *        Version:  1.0
 *        Created:  11/10/2013 02:42:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (), 
 *   Organization:  Symantec
 *
 * =====================================================================================
 */

#include"aupe.h"

#define INFO    1
#define ERR     2
#define STD_OUT stdout
#define STD_ERR stderr
 
#define LOG_MESSAGE(prio, stream, msg, ...) do {\
	char *str;\
	if (prio == INFO)\
	str = "INFO";\
	else if (prio == ERR)\
	str = "ERR";\
	fprintf(stream, "[%s] : %s : %d : "msg" \n", \
			str, __FILE__, __LINE__, ##__VA_ARGS__);\
} while (0)

#define LOG_PASS_METHOD(who) do{\
	char *who;\
	}while(0)
                      
void SumOfTwoNo(int num1, int num2){
    int res=num1 + num2;
    LOG_MESSAGE(INFO, STD_OUT, "Sum of two No is::%d", res);
}

void  MultiTwoNo(int num1, int num2){
    int res=num1 * num2;
    LOG_MESSAGE(INFO, STD_OUT, "Multiplication of two No is::%d", res);

} 

int main(int argc, char *argv[])
{
    char *s = "Hello";
 
    if(argc != 3){
	LOG_MESSAGE(ERR, STD_ERR, "Insufficient Command line agrument: e.g ./MacroLogging 40 60");
        return 0;
    }

    SumOfTwoNo(atoi(argv[1]),atoi(argv[2]));

    MultiTwoNo(atoi(argv[1]),atoi(argv[2]));

        /* display normal message */
    LOG_MESSAGE(ERR, STD_ERR, "Failed to open file");
 
    /* provide string as argument */
    LOG_MESSAGE(INFO, STD_OUT, "%s Ravi Testing for Macros", s);
 
    /* provide integer as arguments */
    LOG_MESSAGE(INFO, STD_OUT, "%d + %d = %d", 10, 20, (10 + 20));
 
    return 0;
}
