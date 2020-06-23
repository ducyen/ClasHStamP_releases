#ifndef __COMMON_INCLUDE_H__
#define __COMMON_INCLUDE_H__                                        /* 複数インクルード防止 */

typedef unsigned long   uint32_t;
typedef unsigned short  uint16_t;
typedef unsigned char   uint8_t;
typedef int             bool;

#define false   ( 0 )
#define true    ( 1 )

typedef unsigned long   UINT32;
typedef unsigned short  UINT16;
typedef unsigned char   UINT8;
typedef int             BOOL;
typedef char            TCHAR;
#define _T(x)           x

#define FALSE   ( 0 )
#define TRUE    ( 1 )

#define STATE_UNDEF                 ( 0x00000000UL )
#define STATE_TOP                   ( 0xFFFFFFFFUL )
#define IS_IN( leaf, composite )    ( composite >= leaf && ( composite & leaf ) > 0 )
#define POWER_OF_TWO( x )           ( ( ( x ) & ( ( x ) - 1 ) ) == 0 )
#define IS_COMPOSITE( s )           ( !POWER_OF_TWO( s ) )
#define UNREF( x )                  ( ( x ) = ( x ) )

#define null                        ( ( void* )0 )
#ifndef NULL
#define NULL                        ( ( void* )0 )
#endif

#define P( ... )                    __VA_ARGS__


#endif//__COMMON_INCLUDE_H__
