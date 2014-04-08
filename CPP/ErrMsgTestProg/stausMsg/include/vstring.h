#ifndef _VSTRING_H
#define _VSTRING_H

#include<aupecpp.h>
#define V_countof(x) (sizeof((x))/sizeof((x)[0]))

size_t V_strlcpy ( char *dst, const char *src, size_t sizeDst );
size_t V_strlcat ( char *dst, const char *src, size_t sizeDst );

size_t V_strlncpy ( char *dst, const char *src, size_t nChars, size_t sizeDst );
size_t V_strlncat ( char *dst, const char *src, size_t nChars, size_t sizeDst );


int V_vsnprintf ( char *dst, size_t sizeDst, const char *format, va_list ap );
int V_snprintf ( char *dst, size_t sizeDst, const char *format, ... );

#endif
