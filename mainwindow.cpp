#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->actionEscultor,
            SIGNAL(triggered(bool)),
            ui->widget,
            SLOT(abreDialogEscultor()));
    connect(ui->widget,
            SIGNAL(alteraSlidersX(int,int)),
            ui->horizontalRaioXEllipsoid,
            SLOT(setRange(int,int)));
    connect(ui->widget,
            SIGNAL(alteraSlidersX(int,int)),
            ui->horizontalDimXCaixa,
            SLOT(setRange(int,int)));
    connect(ui->widget,
            SIGNAL(alteraSlidersY(int,int)),
            ui->horizontalRaioYEllipsoid,
            SLOT(setRange(int,int)));
    connect(ui->widget,
            SIGNAL(alteraSlidersY(int,int)),
            ui->horizontalDimYCaixa,
            SLOT(setRange(int,int)));
    connect(ui->widget,
            SIGNAL(alteraSlidersZ(int,int)),
            ui->horizontalZ,
            SLOT(setRange(int,int)));
    connect(ui->widget,
            SIGNAL(alteraSlidersZ(int,int)),
            ui->horizontalRaioZEllipsoid,
            SLOT(setRange(int,int)));
    connect(ui->widget,
            SIGNAL(alteraSlidersZ(int,int)),
            ui->horizontalDimZCaixa,
            SLOT(setRange(int,int)));
    connect(ui->widget,
            SIGNAL(alteraSliderRaioEsfera(int,int)),
            ui->horizontalRaioEsfera,
            SLOT(setRange(int,int)));
    connect(ui->horizontalZ,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaPlanoZ(int)));
    connect(this,
            SIGNAL(nomeAcao(QString)),
            ui->widget,
            SLOT(acaoSelecionada(QString)));
    connect(ui->horizontalDimXCaixa,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaXCaixa(int)));
    connect(ui->horizontalDimYCaixa,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaYCaixa(int)));
    connect(ui->horizontalDimZCaixa,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaZCaixa(int)));
    connect(ui->horizontalRaioEsfera,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaRaioEsfera(int)));
    connect(ui->horizontalRaioXEllipsoid,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaRaioXEllipsoid(int)));
    connect(ui->horizontalRaioYEllipsoid,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaRaioYEllipsoid(int)));
    connect(ui->horizontalRaioZEllipsoid,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaRaioZEllipsoid(int)));
    connect(ui->widget,
            SIGNAL(alteraSliderR(int)),
            ui->horizontalR,
            SLOT(setValue(int)));
    connect(ui->widget,
            SIGNAL(alteraSliderG(int)),
            ui->horizontalG,
            SLOT(setValue(int)));
    connect(ui->widget,
            SIGNAL(alteraSliderB(int)),
            ui->horizontalB,
            SLOT(setValue(int)));
    connect(ui->horizontalR,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaR(int)));
    ultimaAcao = "";
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::capturaAcao(bool checked)
{
    if (ultimaAcao.compare(ui->actionPutVoxel->text()) == 0){
        ui->actionPutVoxel->setChecked(false);
    }
    else if (ultimaAcao.compare(ui->actionCutVoxel->text()) == 0) {
        ui->actionCutVoxel->setChecked(false);
    }
    else if (ultimaAcao.compare(ui->actionPutBox->text()) == 0) {
        ui->actionPutBox->setChecked(false);
    }
    else if (ultimaAcao.compare(ui->actionCutBox->text()) == 0) {
        ui->actionCutBox->setChecked(false);
    }
    else if (ultimaAcao.compare(ui->actionPutSphere->text()) == 0) {
        ui->actionPutSphere->setChecked(false);
    }
    else if (ultimaAcao.compare(ui->actionCutSphere->text()) == 0) {
        ui->actionCutSphere->setChecked(false);
    }
    else if (ultimaAcao.compare(ui->actionPutEllipsoid->text()) == 0) {
        ui->actionPutEllipsoid->setChecked(false);
    }
    else if (ultimaAcao.compare(ui->actionCutEllipsoid->text()) == 0) {
        ui->actionCutEllipsoid->setChecked(false);
    }
    if(ui->actionPutVoxel->isChecked()){
        qDebug() << ui->actionPutVoxel->text();
        emit nomeAcao(ui->actionPutVoxel->text());
        ultimaAcao = ui->actionPutVoxel->text();
    }
    else if (ui->actionCutVoxel->isChecked()) {
        qDebug() << ui->actionCutVoxel->text();
        emit nomeAcao(ui->actionCutVoxel->text());
        ultimaAcao = ui->actionCutVoxel->text();
    }
    else if (ui->actionPutBox->isChecked()) {
        qDebug() << ui->actionPutBox->text();
        emit nomeAcao(ui->actionPutBox->text());
        ultimaAcao = ui->actionPutBox->text();
    }
    else if (ui->actionCutBox->isChecked()) {
        qDebug() << ui->actionCutBox->text();
        emit nomeAcao(ui->actionCutBox->text());
        ultimaAcao = ui->actionCutBox->text();
    }
    else if (ui->actionPutSphere->isChecked()) {
        qDebug() << ui->actionPutSphere->text();
        emit nomeAcao(ui->actionPutSphere->text());
        ultimaAcao = ui->actionPutSphere->text();
    }
    else if (ui->actionCutSphere->isChecked()) {
        qDebug() << ui->actionCutSphere->text();
        emit nomeAcao(ui->actionCutSphere->text());
        ultimaAcao = ui->actionCutSphere->text();
    }
    else if (ui->actionPutEllipsoid->isChecked()) {
        qDebug() << ui->actionPutEllipsoid->text();
        emit nomeAcao(ui->actionPutEllipsoid->text());
        ultimaAcao = ui->actionPutEllipsoid->text();
    }
    else if (ui->actionCutEllipsoid->isChecked()) {
        qDebug() << ui->actionCutEllipsoid->text();
        emit nomeAcao(ui->actionCutEllipsoid->text());
        ultimaAcao = ui->actionCutEllipsoid->text();
    }
}


