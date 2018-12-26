#ifndef GIGEV_ISOCKETS_H_
#define GIGEV_ISOCKETS_H_

#include "GigeV/cordef.hpp"

namespace gigev {

class Sockets {

public:
  virtual bool InitSocketAPI() = 0;
  virtual bool CloseSocketAPI() = 0;
  virtual int GetSocketError(int sock) = 0;

  // IP stack and network card
  virtual int GetMaxNetworkInterfaces(void) = 0;
  virtual bool GetMacAddress(int indexAdapter, UINT16 *pMacHigh,
                             UINT32 *pMacLow, UINT32 *pIpAddr,
                             UINT32 *pAdapterIndex) = 0;
  virtual bool SetIPAddress(UINT32 ipClient, UINT32 ipMask) = 0;
  virtual bool GetMTUSetting(int indexAdapter, int *pMtu) = 0;
  virtual bool closeSocket(int socket) = 0;

  // Event function prototypes
  //   bool _CreateEvent(_EVENT *pEvent);
  //   bool _DestroyEvent(_EVENT *pEvent);
  //   bool _WaitForEvent(_EVENT *pEvent, UINT32 timeout);
  //   bool _ClearEvent(_EVENT *pEvent);
  //   bool _SetEvent(_EVENT *pEvent);

  // Mutex function prototype.
  //   bool _CreateMutex(_MUTEX *pMutex);
  //   bool _DestroyMutex(_MUTEX *pMutex);
  //   bool _AcquireMutex(_MUTEX *pMutex, UINT32 timeout);
  //   bool _ReleaseMutex(_MUTEX *pMutex);

  // Critical section prototypes
  //   bool _InitCriticalSection(_CRITICAL_SECTION *pCriticalSection);
  //   bool _ReleaseCriticalSection(_CRITICAL_SECTION *pCriticalSection);
  //   bool _EnterCriticalSection(_CRITICAL_SECTION *pCriticalSection);
  //   bool _LeaveCriticalSection(_CRITICAL_SECTION *pCriticalSection);

  // Thread function prototypes
  // bool _CreateThread (unsigned int fct(void *), void *context, int priority,
  // _THREAD *pThread);
  //   bool _CreateThread(unsigned int _stdcall fct(void *), void *context,
  //                      int priority, _THREAD *pThread);
  //   bool _WaitForThread(_THREAD *pThread, UINT32 timeout);
  //   int _GetNumCpus();

  // Timeout handling.
  //   bool _IsTimedOut(struct timeval *due_time);
  //   void _GetTimeOut(int interval_ms, struct timeval *due_time);

  // Miscellaneous
  //   void _Wait(UINT32 delay_ms);
  //   bool _GetTimestamp(UINT32 *pHighTime, UINT32 *pLowTime);
  //   UINT32 _Convert_to_LEFeature_Order(UINT32 cpu_data);
  //   UINT32 _Convert_from_LEFeature_Order(UINT32 cpu_data);
  //   UINT32 _CPU_to_LE32(UINT32 cpu_data);
  //   UINT32 _LE32_to_CPU(UINT32 le_data);
  //   UINT32 _CPU_to_BE32(UINT32 cpu_data);
  //   UINT32 _BE32_to_CPU(UINT32 be_data);

}; // end class IGev

} // end namespace gigev

#endif // GIGEV_ISOCKETS_H_