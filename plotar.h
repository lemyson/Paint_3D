#ifndef PLOTAR_H
#define PLOTAR_H

#include <QWidget>
#include <vector>
#include <QColor>
#include <QString>
#include "dialogo.h"
#include "escultor.h"

using namespace std;

class Plotter : public QWidget{
    Q_OBJECT
private:
    int num_linhas, num_colunas, num_planos;
    vector<vector<vector<Voxel>>> painter_sculptor;
    vector<vector<Voxel>> plano_atual;
    Sculptor* sculptor;
    int id_plano, id_linha, id_coluna;
    double h_altura, h_largura;
    QString acao;

    int x_caixa, y_caixa, z_caixa, raioEsfera,raioXEllipsoid, raioYEllipsoid, raioZEllipsoid;

    QColor cor;
    void ativaVoxel(Voxel &v, QColor cor);
    void desativaVoxel(Voxel &v);
    bool dentroDosLimites(int linha, int coluna, int plano);

public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:
    void alteraSlidersX(int,int);
    void alteraSlidersY(int,int);
    void alteraSlidersZ(int,int);
    void alteraSliderRaioEsfera(int,int);
    void alteraSliderR(int);
    void alteraSliderG(int);
    void alteraSliderB(int);

public slots:
    void abreDialogEscultor();
    void alteraCor();
    void salvaEscultor();
    void executaGeomview();
    void limpaEscultor();
    void mudaPlanoZ(int planoZ);
    void acaoSelecionada(QString _acao);
    void mudaXCaixa(int _x);
    void mudaYCaixa(int _y);
    void mudaZCaixa(int _z);
    void mudaRaioEsfera(int _re);
    void mudaRaioXEllipsoid(int _rx);
    void mudaRaioYEllipsoid(int _ry);
    void mudaRaioZEllipsoid(int _rz);
    void mudaR(int _r);
    void mudaB(int _b);
    void mudaG(int _g);
};

#endif // PLOTAR_H
