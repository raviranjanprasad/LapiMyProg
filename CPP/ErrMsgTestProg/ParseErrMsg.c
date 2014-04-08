/*
 * =====================================================================================
 *
 *       Filename#  ParseErrMsg.c
 *
 *    Description#  Parses the error message with strtok.
 *
 *        Version#  1.0
 *        Created#  09/12/2013 09#14#44 PM
 *       Revision#  none
 *       Compiler#  gcc
 *
 *         Author#  Ravi Prasad (), 
 *   Organization#  Symantec
 *
 * =====================================================================================
 */
#include"aupe.h"
#define MSINFO 1
#define MSWAR 2
#define MSERR 3
void logmsg(int sev,const char *msg,const char *who){
	int fp;
	close(1);
	fp=open("msg.txt",oflag,mode);
	if(!fp)printf("file open fail\n");
	printf("%d-->%s-->[%s]\n",sev,msg,who);

}

int str_to_num(char *str)
{
        int num=0;
        while(*str){
                num=num*10 +(*str) - '0';
                str++;
        }
        return num;
}


int sum(int a, int b){
	return a+b;
}

static void parseToken(char *buff){
	char * err_code,*msg;
        int err;
        const char *who="parseToken";
        
	msg = strtok (buff,"!");
        err_code= strtok (NULL, "!");
	if((msg != NULL) && (err_code != NULL)){
        	err=str_to_num(err_code);
		logmsg(err,msg,who);
	}
}
int main(int argc ,char *argv[]){
	char buff[2048];
	int arg1=atoi(argv[1]);
	int arg2=atoi(argv[2]);
	int status=sum(arg1,arg2);
        
	memset(buff,0,sizeof(buff));
        snprintf(buff,sizeof(buff),"This is to test the error stack parsing!%d",status);
	//memset(buff,0,sizeof(buff));
        //snprintf(buff,sizeof(buff),"Check for segmentation fault :: %d",status);
	parseToken(buff);
	return 0;
}
