#ifndef TERMOMETRO_H
#define TERMOMETRO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Termometro; }
QT_END_NAMESPACE

class Termometro : public QMainWindow
{
    Q_OBJECT

public:
    Termometro(QWidget *parent = nullptr);
    ~Termometro();

public slots:

    void cent2Fahr(int);
    void fahr2Cent(int);

    void cent2Kel(int);
    void kel2cent(int);

    void fahr2Kel(int);
    void kel2Fahr(int);

private:
    Ui::Termometro *ui;
};
#endif // TERMOMETRO_H
