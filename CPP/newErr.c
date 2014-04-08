/*
 * =====================================================================================
 *
 *       Filename:  newErr.c
 *
 *    Description:  New Error code mapping program.
 *
 *        Version:  1.0
 *        Created:  08/29/2013 04:38:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (), 
 *   Organization:  Symantec
 *
 * =====================================================================================
 */

#include "aupe.h"

typedef struct errCodeMsg{
        int errCode;
        char *msg;
        struct errCodeMsg *next;
}errCodeMsg;

errCodeMsg *errMsg=NULL;
#define SIZE 1
#define ERRMSGBUFF 1024

void Add_EC_Error_Code(int err, char *msg){
	errCodeMsg *temp;
	FILE  *err_msg=NULL;
	char  buff[ERRMSGBUFF];

	memset(buff,0,sizeof(buff));

	temp = (errCodeMsg*)malloc(sizeof(errCodeMsg));
	temp->errCode=err;
	temp->msg=(char*)malloc(strlen(msg) + 1);
	strcpy(temp->msg,msg);

	err_msg=fopen("test.txt","a");
	fprintf(err_msg,"%d-->%s\n",temp->errCode, temp->msg);
	fclose(err_msg);
	free(temp);
	temp=NULL; 
}

int main(){
        int n,roll;
        char name[1024];
        printf("\nEnter the no of records::");
        scanf("%d",&n);
        while(n--){
                printf("\nEnter the Roll No::");
                scanf("%d", &roll);
                printf("\nEnter the name::");
                scanf(" %[^\n]s",name);
                Add_EC_Error_Code(roll,name);
        }
        return 0;
}


