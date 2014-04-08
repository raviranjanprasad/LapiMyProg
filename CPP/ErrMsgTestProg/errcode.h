#include"aupe.h"

typedef struct errCodeMsg{
        char *msg;
        struct errCodeMsg *next;
}errCodeMsg;

errCodeMsg *errMsg=NULL;

