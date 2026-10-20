#include "dumessangerserver.h"
#include "dumessangersocket.h"
#include <QDebug>
#include <QTextStream>
namespace DurateCorporation {
DuMessangerServer::DuMessangerServer(QObject *parent)
    :QTcpServer(parent)
{

}
bool DuMessangerServer::startServer(quint16 port)
{
 return listen(QHostAddress::Any,port);


}
 void DuMessangerServer::incomingConnection(qintptr handle)
 {    qDebug()<<"Client connecte avec handle:"<<handle;
     auto socket = new DuMessangerSocket(handle,this);
     mSockets <<socket;
     for(auto i : mSockets){
     QTextStream T(i);
     T <<" server : a connecté:" <<handle;
     i->flush();
     }

      connect(socket, &DuMessangerSocket::DuReadyRead,[&](DuMessangerSocket *S){
         qDebug()<<"DuReadyRead";
         QTextStream T(S);
         auto text =T.readAll();
         for (auto i: mSockets){
             QTextStream K(i);
             K << text;
             i->flush();
         }
     });
     connect(socket, &DuMessangerSocket::DuStateChanged,
             [&](DuMessangerSocket *S, int ST){
         qDebug()<<"DuStateChanged avec handle"
                <<S->socketDescriptor();
         if (ST ==QTcpSocket::UnconnectedState){
             qDebug()<<"unconnected state with handle:"
                    <<S->socketDescriptor();
             mSockets.removeOne(S);
             for (auto i : mSockets){
                 QTextStream K(i);
                 K <<"Server : Le Client"
                  <<S->socketDescriptor()
                  <<"se deconnecter..";
                 i->flush();
             }
         }
     });
 }

} //end namespace
