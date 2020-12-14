#include "widget.h"
#include "ui_widget.h"
//#include <QtQuick>
#include<QMessageBox>
#include<QtDebug>
#include <random>
#include "QDateTime"
#include <QPixmap>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //connect(ui->fechar,SIGNAL(clicked()), this,SLOT(close()));
//    QPixmap x("C:\imagem\X.jpg");

//    QPixmap o("C:\imagem\O.jpg");
//    ui->l1->setPixmap(o.scaled(31,31,Qt::KeepAspectRatio));
//    ui->l1->show();

}


Widget::~Widget()
{
    delete ui;
}
int turno=0;
int linha1=0;
int linha2=0;
int linha3=0;
int diagonale=0;
int diagonald=0;
int coluna1=0;
int coluna2=0;
int coluna3=0;
int pts1=0;
int pts2=0;
int pates=0;
int verifica(int turno){
    if (turno==0)
        return 0;
    else
        return 1;
}
#include <random>
#include "QDateTime"

int aleatorio(int minimo, int maximo){
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> uid(minimo, maximo);
    return uid(gen);
}

bool reseta=false;
bool transparente=false;
void Widget::invisivel(QAbstractButton *botao,bool escolha=false)
{
    if (escolha==true){
        QBrush tb(Qt::transparent);
         botao->setPalette(QPalette(tb, tb, tb, tb, tb, tb, tb, tb, tb));
         botao->setHidden(true);
    }
    // Torna visivel
    else{
        botao->setPalette(QPalette());
        botao->setHidden(false);
   }
}
void Widget::ganhou(){
    int resposta;
    if ((linha1==30) || (linha2==30) || (linha3==30) || (diagonald==30) || (diagonale==30) || (coluna1==30) || (coluna2==30) || (coluna3==30)){
      resposta=1;
    }
    else if ((linha1==3) || (linha2==3) || (linha3==3) || (diagonald==3) || (diagonale==3) || (coluna1==3) || (coluna2==3) || (coluna3==3))
         resposta=2;
    else{
         resposta=0;}
    qDebug("linhas1 : %u " ,linha1);
    qDebug("linhas2 : %u " ,linha2);
    qDebug("linhas3 : %u " ,linha3);
    qDebug("coluna1 : %u " ,coluna1);
    qDebug("coluna2 : %u " ,coluna2);
    qDebug("coluna3 : %u " ,coluna3);
    qDebug("diagonle : %u " ,diagonale);
    qDebug("diagonld : %u " ,diagonald);
    if (resposta==1){
        QMessageBox::about(this,"Player 1 ganhou!","Parabéns vencedor!");
        pts1++;
        ui->reinicio->click();
    }
    else if(resposta==2){
        QMessageBox::about(this,"Player 2 ganhou!","Parabéns vencedor!");
        pts2++;
        ui->reinicio->click();

    }
    else if((ui->b9->isEnabled()==false) && (ui->b8->isEnabled()==false) && (ui->b7->isEnabled()==false) && (ui->b6->isEnabled()==false) && (ui->b5->isEnabled()==false) && (ui->b4->isEnabled()==false) && (ui->b3->isEnabled()==false) && (ui->b2->isEnabled()==false) && (ui->b1->isEnabled()==false)){
        QMessageBox::warning(this,"Empate!","Ninguém ganhou!");
        pates++;
        ui->reinicio->click();}
//    else if (resposta==0)
//        QMessageBox::about(this,"Aguarde","Espere a sua vez!");

}
void Widget::imagem(QAbstractButton *botao)
{
    QPixmap figura(":/imagens/imagem/O.jpg");
    QIcon icone (figura);
    QPixmap figura1(":/imagens/imagem/x.jpg");
    QIcon icone1 (figura1);
    if (turno==0){
        botao->setIcon(icone);
        //botao->setIconSize(QSize(31, 31));
        botao->setIconSize(botao->size());}
    else{
        botao->setIcon(icone1);
        //botao->setIconSize(QSize(31, 31));
        botao->setIconSize(botao->size());
    }
}


void Widget::turnos(){
    ui->vez->setEnabled(true);
    ui->vez->click();
    ui->vez->setEnabled(false);

}

void Widget::on_fechar_clicked()
{

     QMessageBox::StandardButton opcao= QMessageBox::question(this,"","Deseja encerrar o programa?",QMessageBox::Yes|QMessageBox::No);
   if (opcao==QMessageBox::Yes)
        //close();
        QApplication::quit();
   else{
       QMessageBox::about(this,"","OK!Se estiver jogando muito tempo considere uma pausa.");
        qDebug()<<"Programa não encerrado!";  //serve para ver valores de variaveis e coisa de QtDebug
   }
}

void Widget::on_vermelho_clicked()
{
    QString marrom="background-color:maroon";
    this->setStyleSheet(marrom);
}

void Widget::on_azulclaro_clicked()
{
    QString orange="background-color:orange";
    this->setStyleSheet(orange);
}

void Widget::on_azul_clicked()
{
    QString azul="background-color:blue";
    this->setStyleSheet(azul);
}

void Widget::on_verde_clicked()
{
    QString rosa="background-color:pink";
    this->setStyleSheet(rosa);
}

void Widget::on_roxo_clicked()
{
    QString roxo="background-color:purple";
    this->setStyleSheet(roxo);
}

void Widget::on_amarelo_clicked()
{
    QString amarelo="background-color:yellow";
    this->setStyleSheet(amarelo);
}



void Widget::on_vez_clicked()
{
    QString verde="background-color:green";
    QString vermelho="background-color:red";
    if (turno==0){
        ui->p1->setStyleSheet(vermelho);
        ui->p2->setStyleSheet(verde);
    }
    else{
        ui->p1->setStyleSheet(verde);
        ui->p2->setStyleSheet(vermelho);
    }

}

void Widget::on_b1_clicked()
{
    if(verifica(turno)==0){
        turnos();
        linha1=linha1+10;
        diagonale=diagonale+10;
        coluna1=coluna1+10;
        turno=1;
//        ui->l1->setPixmap(QPixmap("C:\imagem\X.jpg").scaled((31,31),Qt::KeepAspectRatio));
//        ui->l1->update();
    }
    else{
        turnos();
        linha1=linha1+1;
        diagonale=diagonale+1;
        coluna1=coluna1+1;
        turno=0;

    }
    imagem(ui->b1);
    ui->b1->setDisabled(true);
    ganhou();
}

void Widget::on_b2_clicked()
{
    if(verifica(turno)==0){
        turnos();
        linha1=linha1+10;
        coluna2=coluna2+10;
        turno=1;
    }
    else{
        turnos();
        linha1=linha1+1;
        coluna2=coluna2+1;
        turno=0;
    }
    imagem(ui->b2);
    ui->b2->setDisabled(true);
   ganhou();
}

void Widget::on_b3_clicked()
{
    if(verifica(turno)==0){
        turnos();
        linha1=linha1+10;
        diagonald=diagonald+10;
        coluna3=coluna3+10;
        turno=1;
    }
    else{
        turnos();
        linha1=linha1+1;
        diagonald=diagonald+1;
        coluna3=coluna3+1;
        turno=0;
    }

    imagem(ui->b3);
    ui->b3->setDisabled(true);
    ganhou();
}

void Widget::on_b4_clicked()
{
    if(verifica(turno)==0){
        turnos();
        linha2=linha2+10;
        coluna1=coluna1+10;
        turno=1;

    }
    else{
        turnos();
        linha2=linha2+1;
        coluna1=coluna1+1;
        turno=0;

    }
    imagem(ui->b4);
    ui->b4->setDisabled(true);
    ganhou();
}

void Widget::on_b5_clicked()
{
    if(verifica(turno)==0){
        turnos();
        linha2=linha2+10;
        coluna2=coluna2+10;
        diagonald=diagonald+10;
        diagonale=diagonale+10;
        turno=1;

    }
    else{
        turnos();
        linha2=linha2+1;
        coluna2=coluna2+1;
        diagonald=diagonald+1;
        diagonale=diagonale+1;
        turno=0;

    }
    imagem(ui->b5);
    ui->b5->setDisabled(true);
    ganhou();
}

void Widget::on_b6_clicked()
{
    if(verifica(turno)==0){
        turnos();
        linha2=linha2+10;
        coluna3=coluna3+10;
        turno=1;

    }
    else{
        turnos();
        linha2=linha2+1;
        coluna3=coluna3+1;
        turno=0;

    }
    imagem(ui->b6);
    ui->b6->setDisabled(true);
    ganhou();
}

void Widget::on_b7_clicked()
{
    if(verifica(turno)==0){
        turnos();
        linha3=linha3+10;
        coluna1=coluna1+10;
        diagonald=diagonald+10;
        turno=1;

    }
    else{
        turnos();
        linha3=linha3+1;
        coluna1=coluna1+1;
        diagonald=diagonald+1;
        turno=0;

    }
    imagem(ui->b7);
    ui->b7->setDisabled(true);
    ganhou();
}

void Widget::on_b8_clicked()
{
    if(verifica(turno)==0){
        turnos();
        linha3=linha3+10;
        coluna2=coluna2+10;
        turno=1;
    }
    else{
        turnos();
        linha3=linha3+1;
        coluna2=coluna2+1;
        turno=0;
    }
    imagem(ui->b8);
    ui->b8->setDisabled(true);
    ganhou();
}

void Widget::on_b9_clicked()
{
    if(verifica(turno)==0){
        turnos();
        linha3=linha3+10;
        coluna3=coluna3+10;
        diagonale=diagonale+10;
        turno=1;

    }
    else{
        turnos();
        linha3=linha3+1;
        coluna3=coluna3+1;
        diagonale=diagonale+1;
        turno=0;

    }
    imagem(ui->b9);
    ui->b9->setDisabled(true);
    ganhou();
}

void Widget::on_cpu_clicked()
{
    QMessageBox::StandardButton opcao= QMessageBox::question(this,"","Deseja que o cpu jogue?Aperte me Yes para ele fazer uma jogada.",QMessageBox::Yes|QMessageBox::No);
  if (opcao==QMessageBox::Yes){
       //close();
//    QMessageBox::StandardButton epico= QMessageBox::question(this,"","Deseja que outro cpu jogue?Aperte  Yes para ele fazer uma jogada.",QMessageBox::Yes|QMessageBox::No);
//    if (epico==QMessageBox::No)
//         tpu=false;
//    else
//         tpu=true;
//        do {
        bool numero_sorteado=false;
        while(numero_sorteado!=true)
        {

              int t=aleatorio(0,10);
              qDebug("linhas1 : %u " ,t);
              if (t==1 && ui->b1->isEnabled()==true){
                  numero_sorteado=true;
                  ui->b1->click();}

              else if (t==2 && ui->b2->isEnabled()==true){
                  numero_sorteado=true;
                  ui->b2->click();}
              else if (t==3 && ui->b3->isEnabled()==true){
                  numero_sorteado=true;
                  ui->b3->click();}
              else if (t==4 && ui->b4->isEnabled()==true){
                  numero_sorteado=true;
                  ui->b4->click();}
              else if (t==5 && ui->b5->isEnabled()==true){
                  numero_sorteado=true;
                  ui->b5->click();}
              else if (t==6 && ui->b6->isEnabled()==true){
                  numero_sorteado=true;
                  ui->b6->click();}
              else if (t==7 && ui->b7->isEnabled()==true){
                  numero_sorteado=true;
                  ui->b7->click();}
              else if (t==8 && ui->b8->isEnabled()==true){
                  numero_sorteado=true;
                  ui->b8->click();}
              else if (t==9 && ui->b9->isEnabled()==true){
                  numero_sorteado=true;
                  ui->b9->click();}
              else if((ui->b9->isEnabled()==false) && (ui->b8->isEnabled()==false) && (ui->b7->isEnabled()==false) && (ui->b6->isEnabled()==false) && (ui->b5->isEnabled()==false) && (ui->b4->isEnabled()==false) && (ui->b3->isEnabled()==false) && (ui->b2->isEnabled()==false) && (ui->b1->isEnabled()==false)){
                  QMessageBox::warning(this,"Empate!","Ninguém ganhou!");
                  this->close();
                  break;
              qDebug("valordet : %u " ,t);
              }

          }
//        }while(tpu==true);
   }
  else{
      QMessageBox::about(this,"","OK!Lembre-se aperte em  cpu e em yes sempre que terminar usa jogada caso queria que o cpu jogue.");
      reseta=true;
       qDebug()<<"Funcionando!";  //serve para ver valores de variaveis e coisa de QtDebug
  }
}


void Widget::on_reinicio_clicked()
{
    //Reseta valores
    turno=0;
    linha1=0;
    linha2=0;
    linha3=0;
    diagonale=0;
    diagonald=0;
    coluna1=0;
    coluna2=0;
    coluna3=0;

    //Reseta botões
    ui->b1->setEnabled(true);
    ui->b2->setEnabled(true);
    ui->b3->setEnabled(true);
    ui->b4->setEnabled(true);
    ui->b5->setEnabled(true);
    ui->b6->setEnabled(true);
    ui->b7->setEnabled(true);
    ui->b8->setEnabled(true);
    ui->b9->setEnabled(true);

    //Reseta imagem
    ui->b1->setIcon(QIcon());
    ui->b2->setIcon(QIcon());
    ui->b3->setIcon(QIcon());
    ui->b4->setIcon(QIcon());
    ui->b5->setIcon(QIcon());
    ui->b6->setIcon(QIcon());
    ui->b7->setIcon(QIcon());
    ui->b8->setIcon(QIcon());
    ui->b9->setIcon(QIcon());
    reseta=true;
}


void Widget::on_placar_clicked()
{
    QString  j1 = QString::number(pts1);
    QString j2= QString::number(pts2);
    QString p= QString::number(pates);
    QMessageBox::about(this,"Placar","Player1 pontos: "+j1+"\n"+"Player2 pontos: "+j2+"\n"+"Números de empates: "+p);
}

void Widget::on_zerar_clicked()
{
    QMessageBox::StandardButton opcao= QMessageBox::question(this,"","Deseja zerar o placar?",QMessageBox::Yes|QMessageBox::No);
  if (opcao==QMessageBox::Yes){
       //close();
        QMessageBox::warning(this,"","Placar zerado!");
       pts1=0;
       pts2=0;
       pates=0;
  }
  else{
      QMessageBox::warning(this,"","Placar não zerado!");
       qDebug()<<"Funcionou!";  //serve para ver valores de variaveis e coisa de QtDebug
  }
}



void Widget::on_dicas_clicked()
{
    QMessageBox::StandardButton opcao= QMessageBox::question(this,"Ajude melhorar o aplicativo","Caso encontrou algum problema, deseja notificar?",QMessageBox::Yes|QMessageBox::No);
    if (opcao==QMessageBox::Yes){
         //close();
         QMessageBox::warning(this,"Email","Envie um email para daniel.icapui@hotmail.com notificando o ocorrido");
    }
    else{
        QMessageBox::warning(this,"","Agredecemos por usar Hash!");
    }
}

void Widget::on_opcoes_clicked()
{

    QMessageBox::StandardButton opcao= QMessageBox::question(this,"Opções","Ativar cpu automática?",QMessageBox::Yes|QMessageBox::No);
    if (opcao==QMessageBox::Yes){
         QMessageBox::warning(this,"Aviso!","CPU automática ativa!");
         reseta=false;
         while(reseta==false){
             ui->cpu->click();
         }
    }
    else{
        QMessageBox::warning(this,"Aviso!","cpu desativado!");}

    QMessageBox::StandardButton opcao2= QMessageBox::question(this,"Opções","Deixa a cor tranparente?",QMessageBox::Yes|QMessageBox::No);
        bool escolha;
        if (opcao2==QMessageBox::Yes){
             QMessageBox::warning(this,"Aviso!","Cores estão transparentes!");
            //deixa invisível
            escolha=true;
            invisivel(ui->azul,escolha);
            invisivel(ui->verde,escolha);
            invisivel(ui->vermelho,escolha);
            invisivel(ui->azulclaro,escolha);
            invisivel(ui->roxo,escolha);
            invisivel(ui->amarelo,escolha);

            //desativa
            ui->azul->setEnabled(false);
            ui->verde->setEnabled(false);
            ui->vermelho->setEnabled(false);
            ui->azulclaro->setEnabled(false);
            ui->roxo->setEnabled(false);
            ui->amarelo->setEnabled(false);

        }
        else{
            escolha=false;
            QMessageBox::warning(this,"Aviso!","Transparência desligada!");
            //deixa visível
            invisivel(ui->azul,escolha);
            invisivel(ui->verde,escolha);
            invisivel(ui->vermelho,escolha);
            invisivel(ui->azulclaro,escolha);
            invisivel(ui->roxo,escolha);
            invisivel(ui->amarelo,escolha);
            //Ativa o botão
            ui->azul->setEnabled(true);
            ui->verde->setEnabled(true);
            ui->vermelho->setEnabled(true);
            ui->azulclaro->setEnabled(true);
            ui->roxo->setEnabled(true);
            ui->amarelo->setEnabled(true);
    }
}

void Widget::on_inicio_clicked()
{
    if(ui->velha->isHidden()){
        ui->velha->setHidden(false);
    }
    else{
        ui->velha->setHidden(true);
    }
}
