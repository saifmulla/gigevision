#ifndef GIGEV_APPLESOCKETS_H_
#define GIGEV_APPLESOCKETS_H_

#include "GigeV/ISockets.hpp"

namespace gigev {

class AppleSockets : public ISockets {
public:
  AppleSockets();

  virtual bool InitSocketAPI() override;
  virtual bool CloseSocketAPI() override;
  virtual int GetSocketError() override;

  // IP stack and network card
  virtual int GetMaxNetworkInterfaces(void) override;
  virtual bool GetMacAddress(int indexAdapter, UINT16 *pMacHigh,
                             UINT32 *pMacLow, UINT32 *pIpAddr,
                             UINT32 *pAdapterIndex) override;
  virtual bool SetIPAddress(UINT32 ipClient, UINT32 ipMask) override;
  virtual bool GetMTUSetting(int indexAdapter, int *pMtu) override;
  virtual bool closeSocket(int socket) override;

}; // end class

} // namespace gigev
#endif // GIGEV_APPLESOCKETS_H_