#include "GigeV/AppleSockets.hpp"
#include <stdio.h>

gigev::AppleSockets::AppleSockets() {}

bool gigev::AppleSockets::InitSocketAPI() { return true; }

bool gigev::AppleSockets::CloseSocketAPI() { return true; }

int gigev::AppleSockets::GetSocketError(int sock) { 
  uint8_t err = 1;
  socklen_t len = sizeof(err);

  if (-1 == getsockopt(sock,SOL_SOCKET,SO_ERROR,static_cast<uint8_t*>(&err),&len))
  {
    // return errno;
    return static_cast<int>(err);
  }
  else{
    if (err){
      return static_cast<int>(err);
    }
  }

  return 0; 
}

int gigev::AppleSockets::GetMaxNetworkInterfaces() { 
  auto _socket = socket(AF_INET,SOCK_DGRAM,0);
  auto _num_adapters = 0;

  if (_socket >= 0){
    char ipbuf[1024];
    auto ipconfig = new struct ifconf();
    ipconfig->ifc_len = sizeof(ipbuf);
    ipconfig->ifc_buf = ipbuf;
    if (ioctl(_socket,SIOCGIFCONF,ipconfig)<0){
      printf("socket failed\n");
      _num_adapters = 0;
    }
    else{
      _num_adapters = ipconfig->ifc_len / sizeof(struct ifreq);
    }
  }

  closeSocket(_socket);
  return _num_adapters; 
}

bool gigev::AppleSockets::open_close_socket(){

}

bool gigev::AppleSockets::GetMacAddress(int indexAdapter, UINT16 *pMacHigh,
                                        UINT32 *pMacLow, UINT32 *pIpAddr,
                                        UINT32 *pAdapterIndex) {
  
  auto _socket = socket(AF_INET,SOCK_DGRAM,0);
  auto _num_adapters = 0;

  if (_socket >= 0){
    char ipbuf[1024];
    auto ipconfig = new struct ifconf();
    ipconfig->ifc_len = sizeof(ipbuf);
    ipconfig->ifc_buf = ipbuf;
    if (ioctl(_socket,SIOCGIFCONF,ipconfig)<0){
      printf("socket failed\n");
      _num_adapters = 0;
    }
    else{
      _num_adapters = ipconfig->ifc_len / sizeof(struct ifreq);
    }
  }
  return true;
}
bool gigev::AppleSockets::SetIPAddress(UINT32 ipClient, UINT32 ipMask) {
  return true;
}

bool gigev::AppleSockets::GetMTUSetting(int indexAdapter, int *pMtu) {
  return true;
}

bool gigev::AppleSockets::closeSocket(int socket) { 
  bool status = false;
  if (socket >=0)
  {
    return GetSocketError(socket);
    status = (close(socket) == 0) ? true : false;
  }

  return status;
}