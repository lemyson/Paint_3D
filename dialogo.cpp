#include "dialogo.h"
#include "ui_dialogescultor.h"

DialogEscultor::DialogEscultor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEscultor){
    ui->setupUi(this);
}

DialogEscultor::~DialogEscultor(){
    delete ui;
}

int DialogEscultor::getNumLinhas(){
    return ui->spinBoxLinhas->value();
}

int DialogEscultor::getNumColunas(){
    return ui->spinBoxColunas->value();
}

int DialogEscultor::getNumPlanos(){
    return ui->spinBoxPlanos->value();
}
