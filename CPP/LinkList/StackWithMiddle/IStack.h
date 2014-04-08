/*
 * =====================================================================================
 *
 *       Filename:  BasicStack.h
 *
 *    Description:  The is the Basic Stack header file with basic funcitonalilty of 
		    Stack push,pop,top
 *
 *        Version:  1.0
 *        Created:  02/02/2014 11:21:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */
#ifndef _BASICSTACK_
#define _BASICSTACK
class IStack{
	virtual void push(int item)=0;
	virtual int pop()=0;
	virtual int top()=0;
};
#endif _BASICSTACK_

