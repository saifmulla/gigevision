#ifndef GIGEV_CORDEF_H_
#define GIGEV_CORDEF_H_

#include "GigeV/corenv.hpp"

#ifdef COR_APPLE
#define CORPROCESS_MAX_NUMBER 16
#define CORECO_VENDORID 0x11ec

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#define CCONV
#define CORKEVENT UINT32
#define CorIsBadReadPtr(ptr, size) 0
#define CorIsBadWritePtr(ptr, size) 0
#define CorIsBadStringPtr(ptr, size) 0

#define ASSERT_PTR(ptr) ASSERT(((ptr) != NULL))

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef int8_t CHAR;
typedef int8_t INT8;
typedef u_int8_t UINT8;
typedef int16_t INT16;
typedef u_int16_t UINT16;
typedef int32_t INT32;
typedef u_int32_t UINT32;
typedef long long INT64;
typedef long long _int64;
typedef u_int64_t UINT64;
typedef char WCHAR;
typedef WCHAR *PWCHAR;

#ifndef IS_HANDLE_VALID
#define IS_HANDLE_VALID(handle)                                                \
  ((handle != NULL) && (handle != INVALID_HANDLE_VALUE))
#endif

typedef float FLOAT;
typedef unsigned int UINT;
typedef unsigned int *PUINT;
typedef int INT;
typedef int *PINT;
typedef char *PSTR, *LPSTR, *LPTSTR;
typedef const char *LPCSTR, *LPCTSTR;
typedef double DOUBLE;
typedef UINT8 UCHAR;
typedef UINT8 *PUCHAR;
typedef INT16 SHORT;
typedef UINT16 USHORT;
//	typedef INT32		LONG;
//	typedef UINT32		ULONG;
typedef UINT32 *PDWORD;
typedef INT32 LRESULT;

typedef UINT32 NTSTATUS;
typedef void VOID;
typedef unsigned long ULONG_PTR, *PULONG_PTR;
typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;
typedef unsigned long SIZE_T;
typedef unsigned long *PSIZE_T;
typedef long SSIZE_T;
static __inline unsigned long _PtrToUlong(ULONG_PTR p) {
  return ((unsigned long)p);
}
static __inline ULONG_PTR _UlongToPtr(unsigned long l) {
  return ((ULONG_PTR)l);
}

// Usefull for converting addresses from a pointer to a ULONG as long as the
// pointer is in the 1st 4GB of memory.
#define PtrToUlong(p) _PtrToUlong((ULONG_PTR)(p))
#define UlongToPtr(p) _UlongToPtr((ULONG)(p))
#define UlongPtrToUlong(p) _PtrToUlong((ULONG_PTR)(p))

#define POINTER_32
#define POINTER_64

#endif // COR_APPLE

#ifndef NULL
#define NULL nullptr // FIXME: check c++ standard >= 11 and use nullptr
#endif

#ifndef far
#define far
#endif

typedef INT8 *PINT8;
typedef UINT8 *PUINT8;
typedef INT16 *PINT16;
typedef UINT16 *PUINT16;
typedef INT32 *PINT32;
typedef UINT32 *PUINT32;

typedef INT8 BOOL8;
typedef BOOL8 *PBOOL8;
typedef INT16 BOOL16;
typedef BOOL16 *PBOOL16;
typedef INT32 BOOL32;
typedef BOOL32 *PBOOL32;
typedef const char *PCSTR;
typedef UINT8 *PBYTE;
typedef UINT8 *LPBYTE;
typedef UINT16 *PWORD;
typedef UINT8 BYTE;
typedef UINT16 WORD;
typedef void *LPVOID, *PVOID;

typedef char CORSTR[256];
// Scatter/Gather memory structure shared between user, kernel, and firmware
// drivers.
typedef struct __attribute__((packed)) _CORSGENTRY {
  ULONG_PTR address; // Physical Address for segment.(*)
  UINT32 length;     // Length (in bytes) of the segment.
} CORSGENTRY, *PCORSGENTRY;

// volatile definitions
typedef UINT8 volatile VUINT8;
typedef UINT8 volatile *PVUINT8;

typedef UINT8 volatile VBYTE;
typedef UINT8 volatile *PVBYTE;

typedef UINT16 volatile VUINT16;
typedef UINT16 volatile *PVUINT16;

typedef UINT16 volatile VWORD;
typedef UINT16 volatile *PVWORD;

typedef UINT32 volatile VUINT32;
typedef UINT32 volatile *PVUINT32;

typedef UINT32 volatile VDWORD;
typedef UINT32 volatile *PVDWORD;

// Ethernet-related definitions
typedef struct {
  UINT8 i1;
  UINT8 i2;
  UINT8 i3;
  UINT8 i4;
} CORIP_ADDRESS;

#endif // GIGEV_CORDEF_H