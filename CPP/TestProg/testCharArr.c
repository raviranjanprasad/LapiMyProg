/*
 * =====================================================================================
 *
 *       Filename:  testCharArr.c
 *
 *    Description:  testing return of char array.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 11:58:45 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */

#include "aupe.h"

//char m_name[30];
char *getName(char *name){
	//char m_name[30];
	strcpy(m_name,name);
	return m_name;
}

int main(int argc,char *argv[]){

    char *myname=getName(argv[1]);
    printf("Name=%s\n",myname);
    return 0;
}
