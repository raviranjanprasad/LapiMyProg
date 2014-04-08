/*
 * =====================================================================================
 *
 *       Filename:  errMsg.c
 *
 *    Description:  Error message key value Link List
 *
 *        Version:  1.0
 *        Created:  08/27/2013 11:44:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (), 
 *   Organization:  Symantec
 *
 * =====================================================================================
 */

#include "errcode.h"
/*typedef struct errCodeMsg{
	int errCode;
	char *msg;
	struct errCodeMsg *next;
}errCodeMsg;

errCodeMsg *errMsg=NULL;*/
#define SIZE 1
#define ERRMSGBUFF 1024

void Add_EC_Error_Code(int err, char *msg){
	errCodeMsg *temp;
	temp = (errCodeMsg*)malloc(sizeof(errCodeMsg));
	temp->errCode=err;
	temp->msg=(char*)malloc(strlen(msg) + 1);
	strcpy(temp->msg,msg);


	if(errMsg == NULL){
		temp->next = NULL;
	}     
	else{
		temp->next=errMsg;
	}
	errMsg=temp;
        temp=NULL;
}

char *Display(errCodeMsg *errList){
	FILE  *err_msg=NULL;
	char  buff[ERRMSGBUFF];
        char *msg_buff;
        static int len=0,cx=0,wr=0,count=0;
        errCodeMsg *temp;
        
        /*Create a file with timestamp*/
        char filename[255];
	struct tm* tm;
	time_t now;
	now = time(0); // get current time
	tm = localtime(&now); // get structure
	sprintf(filename, "/tmp/ErrMsgStack_%02d%02d%04d_%02d%02d%02d", tm->tm_mon+1,tm->tm_mday, tm->tm_year+1900,tm->tm_hour,tm->tm_min,tm->tm_sec);
 
	memset(buff,0,sizeof(buff));
	//err_msg=fopen("/home/ravi/LapiMyProg/CPP/ErrMsgTestProg/test.txt","a");
	err_msg=fopen(filename,"a");
        temp = errList;
	while(temp != NULL){
		printf("\n%d-->%s\n",temp->errCode,temp->msg);
		fprintf(err_msg,"%d-->%s\n",temp->errCode, temp->msg);
                len = len + sizeof(temp->errCode) + strlen(temp->msg);
                count++;
		temp=temp->next;
                
	}
        len =  len + 4*count;
        printf("Length of the buffer is %d\n",len);
	fclose(err_msg);

        msg_buff = (char*)malloc(len);
        while(errList != NULL){
        	wr = snprintf(msg_buff + cx,len - cx,"%d-->%s\n",errList->errCode,errList->msg);
		cx = cx + wr;
                errList = errList->next;
        }
        //printf("%s",msg_buff);
	return msg_buff;
}

void FreeList(errCodeMsg *errList){
	errCodeMsg *current = errList;
	errCodeMsg *next=NULL;
	while (current != NULL)
	{
		next = current->next;
                free(current->msg);
		free(current);
		current = next;
	}
	errList =  NULL;
}

int main(){
	int n,roll;
	char name[1024];
        char *msg;
	printf("\nEnter the no of records::");
	scanf("%d",&n);
	while(n--){
		printf("\nEnter the Roll No::");
		scanf("%d", &roll);
		printf("\nEnter the name::");
		scanf(" %[^\n]s",name);
		Add_EC_Error_Code(roll,name);
	}

	msg = Display(errMsg);
        printf("In main The message is \n");
        printf("%s\n",msg);
        FreeList(errMsg);
	return 0;
}
