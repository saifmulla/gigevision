#ifndef GIGEV_APPLESOCKETS_H_
#define GIGEV_APPLESOCKETS_H_

#include "GigeV/Sockets.hpp"
#include <sys/socket.h>
#include <net/if.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <unistd.h>

namespace gigev {

class AppleSockets : public Sockets {
public:
  AppleSockets();

  virtual bool InitSocketAPI() override;
  virtual bool CloseSocketAPI() override;
  virtual int GetSocketError(int sock) override;

  // IP stack and network card
  virtual int GetMaxNetworkInterfaces(void) override;
  virtual bool GetMacAddress(int indexAdapter, UINT16 *pMacHigh,
                             UINT32 *pMacLow, UINT32 *pIpAddr,
                             UINT32 *pAdapterIndex) override;
  virtual bool SetIPAddress(UINT32 ipClient, UINT32 ipMask) override;
  virtual bool GetMTUSetting(int indexAdapter, int *pMtu) override;
  virtual bool closeSocket(int socket) override;

private:
  bool open_close_socket();

}; // end class

} // namespace gigev
#endif // GIGEV_APPLESOCKETS_H_