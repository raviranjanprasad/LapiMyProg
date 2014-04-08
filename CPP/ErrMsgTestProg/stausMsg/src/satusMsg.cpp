/*
 * =====================================================================================
 *
 *       Filename:  satusMsg.cpp
 *
 *    Description:  Implementation of send_msgs_ovmsgf
 *
 *        Version:  1.0
 *        Created:  03/20/2014 02:46:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */
#define DEFINE_STR
#include<satusMsg.h>
#include<aupecpp.h>
#include<vstring.h>

char *getSeverityString(int severity){

	V_strlcpy(INF_str, "INF - ", V_countof(INF_str));
	V_strlcpy(ACT_str, "INF - ACT=", V_countof(ACT_str));
	V_strlcpy(TRV_str, "TRV - ", V_countof(TRV_str));
	V_strlcpy(WRN_str, "WRN - ", V_countof(WRN_str));
	V_strlcpy(ERR_str, "ERR - ", V_countof(ERR_str));
	V_strlcpy(FTL_str, "FTL - ", V_countof(FTL_str));

        switch(severity){
		case MSINFO: return INF_str;break;
		case MSDEBUG: return ACT_str;break;
		case MSERROR: return ERR_str;break;
		case MSWARNING: return WRN_str;break;
		case MSCRITICAL: return FTL_str;break;
		case MSUNKNOWN: return TRV_str;
	}
	return NULL;
}

void allMsgLogging(char *buf){
	cout << string(buf) << endl;
}
void progressMsgLogging(char *buf){
	cout << string(buf) << endl;
}
void debugMsgLogging(char *buf){
	cout << string(buf) << endl;
}
void serverMsgLogging(char *buf){
	cout << buf << endl;
}
char *statusmsg_vovgetmsg(const char *format, va_list args){

    int size = strlen(format) * 2;
    char* buffer = (char*)malloc(size);
    while (V_vsnprintf(buffer, size,format, args) < 0)
    {
       free(buffer);
       size *= 2;
       buffer = (char*)malloc(size);
    }

    return buffer;

  	
}
void send_msgs_ovmsgf(int severity, int destination,char *who,int nbuServerStatus,const char *ovmsgid,const char *deffmt, ...){
    va_list args;
    va_start(args, deffmt);
    char *res = statusmsg_vovgetmsg(deffmt, args);
    va_end(args);
    
    char *sev = getSeverityString(severity);
    const char *add_msg="Error %d sending <%s> to server";
    int size =  strlen(res) + strlen(sev) + strlen(add_msg)+ 1;
    char *buffer = new char[size];
	V_snprintf(buffer,size,"Error %d sending <%s>%s to server",severity,sev,res);
    //char buf[1024];

    switch(destination){
	case 0: allMsgLogging(buffer);
		break;

	case 1:	progressMsgLogging(buffer);
		break;

	case 2: debugMsgLogging(buffer);
		break;

	case 3: progressMsgLogging(buffer);
		debugMsgLogging(buffer);
		break;

	case 4: serverMsgLogging(buffer);
		break;

	case 5: progressMsgLogging(buffer);
		serverMsgLogging(buffer);
		break;

	case 6: debugMsgLogging(buffer);
		serverMsgLogging(buffer);
	
    }

}
