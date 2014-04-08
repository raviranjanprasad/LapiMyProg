/*
 * =====================================================================================
 *
 *       Filename:  BasicStack.c
 *
 *    Description:  This is the implementation of BasicStack class defining all the functions
 *
 *        Version:  1.0
 *        Created:  02/02/2014 12:18:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */

ass BasicStack : public IStack{
public:
    IStack();
    void push(int item);
    int pop();
    int top();
    int count();
    ~virtual IStack();
private:
    struct DLLNode *m_head;
    struct DLLNode *m_mid;
    int m_count;

};


BasicStack::BasicStack(){
    m_count = 0;
    m_head = NULL;
    m_mid  = NULL;
}


