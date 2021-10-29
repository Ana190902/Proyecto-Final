#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

#include "utilidades.h"
#include "fmanager.h"
#include "gamewindow.h"
using std::string;

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(bool login, QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_ContinueButton_clicked();

private:
    Ui::Register *ui;
    GameWindow *gw;
    fmanager *Manager;
    P::pair<string> LoginData;
    bool LoR;
};

#endif // REGISTER_H
