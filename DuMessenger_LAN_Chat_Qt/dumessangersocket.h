#ifndef DUMESSANGERSOCKET_H
#define DUMESSANGERSOCKET_H
#include <QTcpSocket>
namespace DurateCorporation {
class DuMessangerSocket :public QTcpSocket
{
    Q_OBJECT
public:
    DuMessangerSocket(qintptr handle, QObject *parent = nullptr);

signals:
    void DuReadyRead(DuMessangerSocket *);
    void DuStateChanged(DuMessangerSocket *, int);
};
} //end namespace
#endif // DUMESSANGERSOCKET_H
