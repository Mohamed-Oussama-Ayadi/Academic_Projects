#ifndef DUMESSANGERCONNECTIONDIALOG_H
#define DUMESSANGERCONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class DuMessangerConnectionDialog;
}

namespace Duratecorporation {
class DuMessangerConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DuMessangerConnectionDialog(QWidget *parent = nullptr);
    ~DuMessangerConnectionDialog();
    QString Hostname() const;
    quint16 Port()const;
private slots:
    void on_accepter_clicked();

    void on_annuler_clicked();

private:
    Ui::DuMessangerConnectionDialog *ui;
    QString mHostname;
    quint16 mPort;
};
 inline QString DuMessangerConnectionDialog::Hostname() const
 {return mHostname;}
 inline quint16 DuMessangerConnectionDialog::Port() const
 {return  mPort;}
}
#endif // DUMESSANGERCONNECTIONDIALOG_H
