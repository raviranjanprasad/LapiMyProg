#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<unistd.h>
#include<limits.h>
int myatoi(char *str)
{
	int num=0,i,j;
	char *temp;
	temp = str;
	for(i=0;i<strlen(str);i++){
		j = str[i] - 48;
		num  = num * 10 + j;
        	if(num >= INT_MAX/10) {
          		printf("The no passed is out of integer range\n");
          		exit(0);
		}
	}
	printf("num=%d\n",num);
        
	return num;
}

char *myconcat(char *source,char *dest)
{
	char *res,*sp,*dp;
        sp = source; dp=dest;
        printf("\nSource= %s Dest = %s\n",sp,dp);
        res = (char*)malloc(strlen(sp) + strlen(dp) + 1);
        int i=0;
        while(*sp != '\0') res[i++] = *sp++;
        while(*dp != '\0') res[i++] = *dp++;
	res[i] = '\0';
        return res;	
                
}

int main(int argc, char *argv[])
{
	int a,b;
	int sum=0,flag = 0,ch;
	char *str;
	do {

		printf("\n 1.Add ");
		printf("\n 2.Concanate ");
		printf("\n 3.Quit ");
		printf("\n Enter Your choice :");
		scanf("%d", &ch);
		switch(ch){

			case 1:

				assert(argc == 3);
				a = myatoi(argv[1]);
				printf("a = %d\n",a);
				b = myatoi(argv[2]);
				printf("b = %d\n",b);
				sum = a + b;
                                if(sum >= INT_MAX){
				   printf("The sum is out of interger range\n");
				   break;
				}
				printf("Sum = %d\n",a+b);
				break;
		       case 2:
                                assert(argc == 3);
				str=myconcat(argv[1],argv[2]);
 				printf("String = %s\n",str);
				break;

		       case 3:
                                flag = 1;
		}
	}while(flag == 0);
	return 0;
}

