#include <QCoreApplication>
#include "dumessangerserver.h"
using namespace DurateCorporation;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
  DuMessangerServer Server;
  if(!Server.startServer(3333))
  {

      qDebug()<<"Error:"<<Server.errorString();

return 1;
  }
  qDebug()<<"server started....";
    return a.exec();
}
