#include "mainwindow.h"
#include "tableau.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submit_clicked()
{
           int cin=ui->cin->text().toInt ();
           QString nom=ui->nom->text();
           QString prenom=ui->prenom->text();
           QString mail=ui->mail->text();
           int num=ui->num->text().toInt ();
           QString dateNaissance=ui->dateNaissance->text();
           QString dateDebut=ui->dateDebut->text();

           client c(cin,nom,prenom,mail,num,dateNaissance,dateDebut);
           bool test=c.ajouter();
           if(test) // Si requete executee == > QMessageBox :: information
           {
               ui->tableView->setModel(C.afficher());
               QMessageBox::information (nullptr, QObject :: tr("OK"),
               QObject :: tr("'Ajout effectue\n"
                             "Click Cancel to exit."),QMessageBox::Cancel);

           }
           else
               QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                     QObject::tr("ajout non effectue.\n"
                                                 "click cancel."),QMessageBox::Cancel);
}
void MainWindow::on_deleteassure_clicked()
{
    int cin=ui->cin_2->text().toInt();
    bool test=C.supprimer(cin);

    if(test)
    {
        ui->tableView->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Suppression effectuée\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr,QObject::tr("Not OK"),
                QObject::tr("Suppression non effectuée\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
