#include "GigeV/AppleSockets.hpp"

gigev::AppleSockets::AppleSockets() {}

bool gigev::AppleSockets::InitSocketAPI() { return true; }

bool gigev::AppleSockets::CloseSocketAPI() { return true; }

int gigev::AppleSockets::GetSocketError() { return 0; }

int gigev::AppleSockets::GetMaxNetworkInterfaces() { return 0; }

bool gigev::AppleSockets::GetMacAddress(int indexAdapter, UINT16 *pMacHigh,
                                        UINT32 *pMacLow, UINT32 *pIpAddr,
                                        UINT32 *pAdapterIndex) {
  return true;
}
bool gigev::AppleSockets::SetIPAddress(UINT32 ipClient, UINT32 ipMask) {
  return true;
}

bool gigev::AppleSockets::GetMTUSetting(int indexAdapter, int *pMtu) {
  return true;
}

bool gigev::AppleSockets::closeSocket(int socket) { return true; }