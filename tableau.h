#ifndef TABLEAU_H
#define TABLEAU_H_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class tableau
{
public:
    //constructer
    tableau();
    tableau(QString,QString,QString,int,QString,QString);

    //Getters
    QString getNom() ;
    QString getArtiste() ;
    int getPrix() ;
    QString getDateCreation() ;
    QString getStatut() ;

      // Setters
    void setNom( QString &nom);
    void setArtiste( QString &artiste);
    void setPrix( int &prix);
    void setDateCreation( QString &date);
    void setStatut( QString &statut);


    //fonctiononalities
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(nom);

private:
    QString nom;
    QString artiste;
    int prix;
    QString dateCreation;
    QString statut;

};

#endif // TABLEAU_H
*
