#include "register.h"
#include "ui_register.h"

Register::Register(bool login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    LoR = login;
    Manager = new fmanager("Data.txt");

    if(LoR){
        ui->TitleLabel->setText("Ingresar");
        ui->ContinueButton->setText("Ingresar");
    }
    else{
        ui->TitleLabel->setText("Registro");
        ui->ContinueButton->setText("Registrar");
    }
    //ui->UserNameData->clear();
}

Register::~Register()
{
    delete ui;
}

void Register::on_ContinueButton_clicked()
{
    LoginData.x = ui->UserNameData->text().toStdString();
    LoginData.y = ui->UserPassData->text().toStdString();
    bool exist = false;

    for(uint i = 0; Manager->Data().size() > i; i++){

        if(Manager->Data()[i][0] == LoginData.x && Manager->Data()[i][1] == LoginData.y){
            /// Ingresar al menu del juego
            exist = false;
            gw = new GameWindow(this);
            gw->show();
            this->hide();
            return;
        }


        else if(Manager->Data()[i][0] == LoginData.x){
            /// Mandar Texto de ya existe
            ui->UserNameData->clear();
            ui->UserPassData->clear();
            exist = true;
            break;
        }

    }
    if(!exist){
        Manager->addItem(LoginData.x, LoginData.y);
        gw = new GameWindow(this);
        gw->show();
        this->hide();
    }
}

