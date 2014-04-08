#ifndef CFITRACELOG
#define CFITRACELOG
#include"cfismartptr.h"
#include"cficontextsingleton.h"
#include"aupe.h"
#include<iostream>
#include<string>


#define CFiTrace                   VFI_PDK_NAMESPACE::CFiContextSingleton<VFI_PDK_NAMESPACE::CFiTraceLog>::instance()->trace
#define UNSET_MARKER_VAL ((FI_TRACELEVEL)12345)
#define VXFITEXT(x) (char *)x
#define INIT_BUF_SIZE 1024
#define MAX_BUF_SIZE 8192



namespace VFI_PDK_NAMESPACE {

typedef int FI_TRACELEVEL;

class CFiTraceLog :virtual public CFiRefCount{

    bool                __m_bDoneInit;
    bool                __m_traceStdout;
    bool                __m_traceUpdate;
    FI_TRACELEVEL       __m_FiTraceLevel;
    //const char 		*__m_function;

protected:

    ~CFiTraceLog(){}
    //Allow the smart pointer to 'new' and 'delete' our CFiTraceLog singleton
    friend class CFiContextSingletonAllocator<CFiTraceLog>;
public:

    CFiTraceLog()//:__m_function(__func__)
    {
        __m_bDoneInit = false;
        __m_FiTraceLevel = UNSET_MARKER_VAL;
        __m_traceStdout = false;
        __m_traceUpdate = false;
	
    }

//void trace(char *who="",FI_TRACELEVEL InpTraceLevel=0, const char *Fmt="", ... );
void trace(const char *who, FI_TRACELEVEL InpTraceLevel, const char *Fmt, ... );
};

void CFiTraceLog::trace(const char *who,FI_TRACELEVEL InpTraceLevel, const char *Fmt, ... )
//void CFiTraceLog::trace(FI_TRACELEVEL InpTraceLevel, const char *Fmt, ... )
{
    va_list ArgList;
    string MsgString = "";
    char *buf = NULL;
    size_t bufSize = 0;
    char *newbuf = NULL;
    size_t nextSize = 0;
    ssize_t outSize = 0;


    bufSize = 0;
    nextSize = 0;
    for (;;)
    {
        if (bufSize == 0)  //firsttime malloc buffer of size INIT_BUF_SIZE
        {
            if ((buf = (char *)malloc(INIT_BUF_SIZE)) == NULL)
            {
                return; //malloc failed
            }
            bufSize = INIT_BUF_SIZE;
        }
        else if ((newbuf = (char *)realloc(buf, nextSize)) != NULL)
        {
            buf = newbuf;
            bufSize = nextSize;
        }
        else //realloc failed
        {
            free(buf);
            return;
        }

        va_start(ArgList, Fmt);
        outSize = vsnprintf(buf, bufSize, Fmt, ArgList);

        va_end(ArgList);

        if (outSize == -1)
        {
            /* Clear indication that output was truncated, but no
             * clear indication of how big buffer needs to be, so
             * simply double existing buffer size for next time.
             */
             nextSize = bufSize * 2;
             //this can lead to infinite loop so better avoid it
        }
        else if (static_cast<size_t> (outSize) == bufSize)
        {
            /* Output was truncated (since at least the \0 could
             * not fit), but no indication of how big the buffer
             * needs to be, so just double existing buffer size
             * for next time.
             */
            nextSize = bufSize * 2;
        }
        else if (static_cast<size_t> (outSize) > bufSize)
        {
            /* Output was truncated, but we were told exactly how
             * big the buffer needs to be next time. Add two chars
             * to the returned size. One for the \0, and one to
             * prevent ambiguity in the next case below.
             */
             nextSize = outSize + 2;
        }
        else if (static_cast<size_t> (outSize) == bufSize - 1)
        {
            /* This is ambiguous. May mean that the output string
             * exactly fits, but on some systems the output string
             * may have been trucated. We can't tell.
             * Just double the buffer size for next time.
             */

             nextSize = bufSize * 2;
        }
        else
        {
            /* Output was not truncated */
            break;
        }
        if ( nextSize > MAX_BUF_SIZE ) // avoid runaways
        {
                break;
        }
    }
    if(who != NULL)
    	printf("Method=%s  Severity=%d  Msg=%s\n",who,InpTraceLevel,buf);
    else
    	printf("Severity=%d  Msg=%s\n",InpTraceLevel,buf);

}
}
#endif


