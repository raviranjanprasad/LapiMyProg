/*
 * =====================================================================================
 *
 *       Filename:  cfitracelog.cpp
 *
 *    Description:  Program to test the adding method name in CFITrace macro.
 *
 *        Version:  1.0
 *        Created:  11/30/2013 09:02:07 PM
 *       Revision:  none
 *       Compiler:  g++
 *                  g++ -g -Wall cfitracelog.cpp -o cfitracelog
 *         Author:  Ravi Prasad (), 
 *   Organization:  Symantec
 *
 * =====================================================================================
 */
#include "cfitracelog.h"

void  funSum(int a,int b){
	//const char *who="funSum";
	int sum = a + b;
        
	//CFiTrace(who,3,"This is to test %d", sum);
	CFiTrace(__func__,3,"This is to test %d", sum);
}
/*void  SecondSum(int a,int b){
	int sum = a + b;
        
	CFiTrace(1,"In SecondSum without method name  %d", sum);
}*/

int main(int argc,char *argv[]){

	funSum(atoi(argv[1]), atoi(argv[2]));
        //SecondSum((argv[1]), atoi(argv[2]));
	return 0;
}

