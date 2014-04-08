/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main program to implement the listArray.
 *
 *        Version:  1.0
 *        Created:  02/09/2014 09:16:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */

 #include"common.h"

int main(int argc,char *argv[]){

	int *a;
	a = new int[5];
	display(a,5);
	try{
		changeLength1D(a,5,10);
	}
	catch(MyException e){
		e.msg();
	}
	for(int i=5;i<10;i++) a[i] = i+ i;
	display(a,10);

	try{
		changeLength1D(a,5,-5);
	}
	catch(MyException e){
		e.msg();
	}


	return 0;

 }


