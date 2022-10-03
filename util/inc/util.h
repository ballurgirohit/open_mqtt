#ifndef __UTIL_H__
#define __UTIL_H__

typedef unsigned char ubyte8;
typedef unsigned long ubyte32;
typedef unsigned short ubyte16;
typedef signed long sbyte32;

#define _DEBUG_

#ifdef _DEBUG_
#define DBG(X) printf("%u %s ", __LINE__, __FUNCTION__); printf X; printf("\n")
#else
#define DBG(X)
#endif

typedef enum{
	SUCCESS,
	INVALID_PARAM,
	SOCKET_ERROR,
	ERROR
}STATUS;



#endif //__UTIL_H__
