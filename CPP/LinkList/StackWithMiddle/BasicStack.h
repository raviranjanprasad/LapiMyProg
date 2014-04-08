/*
 * =====================================================================================
 *
 *       Filename:  BasicStack.h
 *
 *    Description:  This class inheritates the IStack interface class and implements the 
		    Basic Stack functionality and add a new functionality count of elements.
 *
 *        Version:  1.0
 *        Created:  02/02/2014 11:46:37 AM
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

#include "common.h"
class BasicStack : public IStack{
public:
    BasicStack();
    void push(int item);
    int pop();
    int top();
    int count(); 	
    ~virtual BasicStack();
private:
    DLLNode *m_head;
    DLLNode *m_mid;
    int m_count;
	
};
#endif _BASICSTACK_
