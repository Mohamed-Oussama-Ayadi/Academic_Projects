#include "dumessangersocket.h"

namespace DurateCorporation {
DuMessangerSocket::DuMessangerSocket(qintptr handle, QObject *parent )
    :QTcpSocket(parent)
{
setSocketDescriptor(handle);
connect(this, &DuMessangerSocket::readyRead, [&](){
    emit DuReadyRead(this);
});
connect(this,&DuMessangerSocket::stateChanged,[&](int S){
    emit DuStateChanged(this,S);
});
}
} //end namespace
