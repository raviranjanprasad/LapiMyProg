#ifndef _STATUSMSG_H
#define _STATUSMSG_H
#include<aupecpp.h>

#define MSG_ALL 0  
#define MSG_PROGRESSLOGONLY 0x1
#define MSG_DEBUGLOGONLY 0x2
#define MSG_SERVERONLY 0x4

#define MSUNKNOWN       0x01
#define MSDEBUG         0x02
#define MSINFO          0x04
#define MSWARNING       0x08
#define MSERROR         0x10
#define MSCRITICAL      0x20

//char buf[1024];

#ifndef DEFINE_STR
#define EXTERN extern
#else
#define EXTERN
#endif
EXTERN char    INF_str[30];
EXTERN char    ACT_str[30];
EXTERN char    TRV_str[30];
EXTERN char    WRN_str[30];
EXTERN char    ERR_str[30];
EXTERN char    FTL_str[30];

void allMsgLogging(char *buf);
void progressMsgLogging(char *buf);
void debugMsgLogging(char *buf);
void serverMsgLogging(char *buf);

char *getSeverityString(int severity);
char *statusmsg_vovgetmsg(const char * format, va_list args);
void send_msgs_ovmsgf(int severity, int destination,char *who,int nbuServerStatus,const char *ovmsgid,const char *deffmt, ...);

#endif
