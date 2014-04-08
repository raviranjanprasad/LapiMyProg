/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  send_status_ovmsg
 *
 *        Version:  1.0
 *        Created:  03/20/2014 02:20:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */

#include<aupecpp.h>
#include<satusMsg.h>
int main(int argc,char *argv[]){
	
	char *who="main";
	int status = 0;

	send_msgs_ovmsgf(MSERROR,MSG_PROGRESSLOGONLY,who,status,"PrgFis1110N","Get bpfis state failed. status = %d",status);	
	send_msgs_ovmsgf(MSINFO,MSG_PROGRESSLOGONLY|MSG_DEBUGLOGONLY,who,status,"PrgFis1110N","MSG_PROGRESSLOGONLY|MSG_DEBUGLOGONLY = %d",status);	
	send_msgs_ovmsgf(MSDEBUG,MSG_ALL,who,status,"PrgFis1110N","MSG_ALL = %d",status);	
	send_msgs_ovmsgf(MSCRITICAL,MSG_DEBUGLOGONLY|MSG_SERVERONLY,who,status,"PrgFis1110N","MSG_DEBUGLOGONLY|MSG_SERVERONLY = %d",status);	
	return 0;
}
