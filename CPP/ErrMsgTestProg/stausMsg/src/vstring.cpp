#include<vstring.h>
size_t V_strlcpy ( char *dst, const char *src, size_t sizeDst )
{
        size_t sizeResult = 0;

        if ( sizeDst > 0 &&
             src != NULL &&
             dst != NULL ) {

                size_t i;

                for ( i = 0;  i < ( sizeDst - 1 ) && src [ i ]; i++ ) {
                        dst[ i ] = src [ i ];
                }

                sizeResult = i;
                dst[ sizeResult ] = '\0';


        }
        return( sizeResult );
}

size_t V_strlcat ( char *dst, const char *src, size_t sizeDst )
{
        size_t sizeResult = 0;

        if ( sizeDst > 0 &&
             src != NULL &&
             dst != NULL ) {

                char *pNext;

                /* watch for non-terminated dst */

                pNext = dst;
                while ( ( sizeDst > 0 ) && *pNext ) {
                        sizeDst--;
                        pNext++;
                }

                if ( sizeDst > 1 ) {
                        sizeResult = V_strlcpy ( pNext, src, sizeDst );
                }
        }
        return( sizeResult );
}

/*
 * These functions provide the functionality of strncpy(3) and strncat(3)
 * with the safety fo V_strlcpy() and V_strlcat().
 *
 * The third argument is the maximum number of source characters to
 * copy as in strncpy(3) and strncat(3).  The fourth argument is the
 * number of characters in the destination array as in V_strlcpy() and
 * V_strlcat().
 *
 * For the strlncpy variants, if the actual src string length is less than
 * nChars, then null characters will be [p]added to complete the nChars copy.
 */

size_t V_strlncpy ( char *dst, const char *src, size_t nChars, size_t sizeDst )
{
        size_t result = 0;

        if ( sizeDst > 0 &&
             src != NULL &&
             dst != NULL ) {

                size_t actualSrcLen;

                nChars = (nChars < sizeDst) ? nChars : sizeDst;

                for ( actualSrcLen = 0;
                      ( actualSrcLen < nChars ) && ( src[ actualSrcLen ] != '\0' );
                      actualSrcLen++ )
                {

                        dst[ actualSrcLen ] = src[ actualSrcLen ];
                }

                if (nChars > actualSrcLen) {
                        /* zero fill the remainder of dst */
                        memset( dst + actualSrcLen , 0, (nChars - actualSrcLen) );
                }

                if (nChars  < sizeDst) {
                        /* sufficient room in dst for all chars */
                        dst[ nChars ] = '\0';
                        result = nChars;
                }
                else
                {
                        /* not enough room in dst,  or
                         * exactly enough room (without a '\0')..
                         * regardless.. whack the last char
                         */
                        dst[ sizeDst - 1 ] = '\0';
                        result = sizeDst - 1;
                }
        }

        return( result );
}

size_t V_strlncat ( char *dst, const char *src, size_t nChars, size_t sizeDst )
{
        size_t len = strlen( dst ) + nChars + 1;

        return( V_strlcat( dst, src, (len < sizeDst) ? len : sizeDst ) );
}

/*
 * These functions provide similar functionality and safety as the
 * snprintf(3) and vsnprintf(3) functions.
 *
 * The destination string will always be terminated with a zero byte.
 *
 * The return value is the actual length of the destination string
 * not counting the null character, and will always be >= 0, and
 * < sizeDst.
 *
 */

int V_vsnprintf ( char *dst, size_t sizeDst, const char *format, va_list ap )
{
        int     ret;

        if ( sizeDst < 1 || dst == NULL ) {
                return( -1 );
        }


        ret = vsnprintf( dst, sizeDst, format, ap );

        if (ret < 0) {
                /*
                 * >assume< a catastrophic error, and the
                 * dst string is corrupt.
                 */

                ret = 0;
                dst[ ret ] = '\0';

        } else if (ret >= (int)sizeDst) {
                /*
                 * coerce a terminating null at the end,
                 * and return the de facto strlen(dst) as
                 * the result.
                 */
                ret = (int)(sizeDst - 1);
                dst[ ret ] = '\0';              /* should be unnecessary, but I like the way it looks */

        }
        return( ret );
}
int V_snprintf ( char *dst, size_t sizeDst, const char *format, ... )
{
        int ret;
        va_list ap;

        va_start( ap, format );
        ret = V_vsnprintf( dst, sizeDst, format, ap );
        va_end( ap );
        return( ret );
}

