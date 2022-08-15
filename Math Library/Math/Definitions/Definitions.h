
/*****************************************************************************************************
 *
 *  This library imports all the definitions and shortcuts into the project.
 *
 *  Current Features:
 *  - Sized numbers, such as int8, uint64 etc.
 *  - inline defined as FORCEINLINE
 *  
 *****************************************************************************************************/

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define uint uint32
#define FORCEINLINE inline

typedef signed char        int8;
typedef short              int16;
typedef int                int32;
typedef long long          int64;
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned long long uint64;

#endif