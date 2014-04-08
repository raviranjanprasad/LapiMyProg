/*
 * =====================================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  common header file for the stack with middle point support.
 *
 *        Version:  1.0
 *        Created:  01/30/2014 02:05:32 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */
#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <string>
#include <iomanip>

/*typedef struct DLLNode{
	DLLNode *head;
	DLLNode *mid;
	int count;
}numStack;*/

class DLLNode
{
protected:

    DLLNode* head;
    DLLNode* mid;
    int count;

public:

    DLLNode(int d){count=d;}
    friend class BasicStack;
};

#endif


