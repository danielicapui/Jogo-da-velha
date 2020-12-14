#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractButton>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_fechar_clicked();
    void ganhou();

    void on_azulclaro_clicked();

    void on_azul_clicked();

    void on_verde_clicked();

    void on_roxo_clicked();

    void on_amarelo_clicked();

    void turnos();

    //void on_pushButton1_clicked();

   // void on_pushButton_2_clicked();

    //void on_pushButton_clicked();

    void on_vez_clicked();

    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

    void on_b4_clicked();

    void on_b5_clicked();

    void on_b6_clicked();

    void on_b7_clicked();

    void on_b8_clicked();

    void on_b9_clicked();

    void on_cpu_clicked();

    void on_vermelho_clicked();

    void on_reinicio_clicked();
    void imagem(QAbstractButton *botao);

    void invisivel(QAbstractButton *botao,bool escolha);

    void on_placar_clicked();

    void on_zerar_clicked();

    void on_dicas_clicked();

    void on_opcoes_clicked();

    void on_inicio_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
