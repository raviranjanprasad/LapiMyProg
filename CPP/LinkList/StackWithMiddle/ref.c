/*
 * =====================================================================================
 *
 *       Filename:  ref.c
 *
 *    Description:  This is a reference program only ignore it.
 *
 *        Version:  1.0
 *        Created:  02/02/2014 12:42:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */
#include<iostream.h>
#include<conio.h>

class Node
{
protected:

    Node* next;
    int data;

public:

    Node(int d){data=d;}
    friend class Stack;
};

class Stack
{
public:
    Stack(){top->next='\0';length=0;}

void push(int d)
{
    Node *n=new Node(top->data);
    n->next='\0';
    top->next=n;
    top->data=d;
    length++;
}

int pop()
{
    top=top->next;
    length--;
    return top->data;
}

void displaystack()
{
    while(top->next!='\0')
    {
        cout<<top->data<<endl;
    top=top->next;
    }
}

int getlength()
{
    return length;
}

private:
    Node *top;
    int length;

};

void main()
{
    clrscr();
    Stack s;
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(5);
    s.push(3);
    s.displaystack();
    int len=s.getlength();
    cout<<"length of stack is "<<len<<endl;
    getch();
}

