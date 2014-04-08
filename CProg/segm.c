#include<stdio.h>

char *func(char *p)

{

p=p+3;//change local variable

return p;

}

int main()

{

char *y="HELLO";

y = func(y);//although call by value

// but u end up changing original variable

printf("%s",y);
return 0;
}

