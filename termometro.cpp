#include "termometro.h"
#include "ui_termometro.h"
#include<QDebug>

Termometro::Termometro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro)
{
    ui->setupUi(this);
//Conexion del Dial(cmdCent)con el metodo de tansforamacion a Fahrenheit
    connect(ui->cmdCent,SIGNAL(valueChanged(int)),
            this, SLOT(cent2Fahr(int)));
// Conexion del Dial(cmdFahr)con el metodo de tansforamacion a Celsius

    connect(ui->cmdFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2Cent(int)));
 // Conexion del Dial(cmdCent)con el metodo de tansforamacion a Kelvin
    connect(ui->cmdCent,SIGNAL(valueChanged(int)),
            this,SLOT(cent2Kel(int)));
 // Conexion del Dial(cmdCent)con el metodo de tansforamacion a Centigrados

   connect(ui->cmdKel, SIGNAL(valueChanged(int)),
            this, SLOT(kel2cent(int)));

   connect(ui->cmdFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2Kel(int)));
   connect(ui->cmdKel, SIGNAL(valueChanged(int)),
            this, SLOT(kel2Fahr(int)));



}

Termometro::~Termometro()
{
    delete ui;
}
//Metodo para transformar de Centigrados a Fahrenheit
void Termometro::cent2Fahr(int valor)
{
    if(ui->cmdCent->hasFocus()){
        float f=valor*9.0/5+32;
        ui->cmdFahr->setValue(f);

    }
}
//Metodo para transformar de Fahrenheit a Centigrados
void Termometro::fahr2Cent(int valor)
{
    if(ui->cmdFahr->hasFocus()){
        float c=(valor-32)*5.0/9;
        ui->cmdCent->setValue(c);
    }
}
//Metodo para transformar de Centigrados a Kelvin
void Termometro::cent2Kel(int valor)
{
    if(ui->cmdCent->hasFocus()){
        float k= valor+ 273.15;
        ui->cmdKel->setValue(k);

    }
}
//Metodo para transformar de Kelvin a Centigrados
void Termometro::kel2cent(int valor)
{
    if(ui->cmdKel->hasFocus()){
        float c = valor - 273.15;
        ui->cmdCent->setValue(c);
    }
}
//Metodo para transformar de Fahrenheit a Kelvin
void Termometro::fahr2Kel(int valor)
{
    if(ui->cmdFahr->hasFocus()){
        float k = (valor - 32) * (5.0/9) +273.15;
        ui->cmdKel->setValue(k);

    }
}
    //Metodo para transformar de Kelvin a Fahrenheit
void Termometro::kel2Fahr(int valor)
{
    if(ui->cmdKel->hasFocus()){
        float f = (valor - 273.15) * (5.0/9) + 32;
        ui->cmdFahr->setValue(f);

    }
}
