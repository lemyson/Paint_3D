#ifndef DIALOGO_H
#define DIALOGO_H

#include <QDialog>

namespace Ui {
class DialogEscultor;
}
class DialogEscultor : public QDialog
{
    Q_OBJECT
public:
    explicit DialogEscultor(QWidget *parent = nullptr);
    ~DialogEscultor();
    int getNumLinhas();
    int getNumColunas();
    int getNumPlanos();
private:
    Ui::DialogEscultor *ui;
};
#endif
