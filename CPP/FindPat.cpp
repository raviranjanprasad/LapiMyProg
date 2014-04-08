#include<iostream>
#include<string>
#include<cstdlib>
#include<stdio.h>

#define FICONF_CONST_VALUE_STR_NBU_LOGLEVEL 	  "VERBOSE"
#define FICONF_CONST_VALUE_STR_NBU_BPFIS_LOGLEVEL "BPFIS_VERBOSE"
using namespace std;

int getBpfisTraceConfigFileInfo (string &infoFilePath, string &infoFileName)
{
        infoFileName = "bp.conf";
        infoFilePath = "/home/ravi/CPP/";
    return 0;
}

bool findBpfisVerboseValue(string &confFileName){

    string lineString;
    const size_t LINELENGTH = 255;
    char line[LINELENGTH + 1];

    FILE *nbuFile;
    if((nbuFile = fopen(confFileName.c_str(), "r")) == NULL)
    {
        cout<<"Unable to open the File" <<endl;
        return 1;
    }
    while(fgets(line, LINELENGTH, nbuFile) != NULL)
    {
        line[LINELENGTH] ='\0';
        lineString = line;
        string::size_type pos = lineString.find (FICONF_CONST_VALUE_STR_NBU_BPFIS_LOGLEVEL,0);
        if(pos != string::npos) return true;
    }
    return false;
}

int getBpfisTraceLevel(string &infoFilePath, string &infoFileName, int &traceLevel)
{
    string lineString;
    string pattern;
    string fullFileName = infoFilePath;
    fullFileName +=infoFileName;

    const size_t LINELENGTH = 255;
    char line[LINELENGTH + 1];
    FILE *nbuFile;

    string fullFileNameStr = fullFileName;
    /*if(findBpfisVerboseValue(fullFileNameStr)){
	pattern = FICONF_CONST_VALUE_STR_NBU_BPFIS_LOGLEVEL;
        cout <<"The pattern to be found is " << pattern <<endl;
    }
    else{ 
	pattern = FICONF_CONST_VALUE_STR_NBU_LOGLEVEL;
        cout <<"The pattern to be found is " << pattern<<endl;
    }*/
    if(findBpfisVerboseValue(fullFileNameStr))
	pattern = FICONF_CONST_VALUE_STR_NBU_BPFIS_LOGLEVEL;
    else 
	pattern = FICONF_CONST_VALUE_STR_NBU_LOGLEVEL;

    if((nbuFile = fopen(fullFileNameStr.c_str(), "r")) == NULL)
    {
	cout<<"Unable to open the File" <<endl;
        return 1;
    }
    while(fgets(line, LINELENGTH, nbuFile) != NULL)
    {
        line[LINELENGTH] ='\0';
        lineString = line;
        string::size_type pos = lineString.find (pattern,0);
        if ( pos != string::npos ) {
            /* Entry for log level found
 *              * Syntax is "BPFIS_VERBOSE = level"
 *                           */
            pos = lineString.find ("=", 0);
            if ( pos == string::npos ) {
                /* Case of Corrupted bp.conf */
                return 1;
            }
            else {
		    string verbose = lineString.substr(pos + 1);
		    cout <<"Verbose Value="<<verbose<<endl;
                    return 1;
            }
        }/* End of gets */
    }
    /* No verbose entry found */
    return 1;
}

int main()
{
    /* Get NBU trace level and check if higher logging level is set and change
 *        provider level trace accordingly */
    string nbuFile, nbuPath;
    int nbuLevel = -1;


    getBpfisTraceConfigFileInfo (nbuPath, nbuFile);
    getBpfisTraceLevel (nbuPath, nbuFile, nbuLevel);

}
