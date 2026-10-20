#include "dumessangerconnectiondialog.h"
#include "ui_dumessangerconnectiondialog.h"
namespace Duratecorporation {


DuMessangerConnectionDialog::DuMessangerConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DuMessangerConnectionDialog)
{
    ui->setupUi(this);
}

DuMessangerConnectionDialog::~DuMessangerConnectionDialog()
{
    delete ui;
}

void DuMessangerConnectionDialog::on_accepter_clicked()
{
  mHostname = ui->hostname->text();
  mPort = ui->port->value();
  accept();
}

void DuMessangerConnectionDialog::on_annuler_clicked()
{
 reject();
}
}
