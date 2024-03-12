#include "tableau.h"
#include <QString>
using namespace std;

//constructer
tableau::tableau(QString nom ,QString artiste ,int prix ,QString dateCreation,QString statut)
{
    this->nom=nom;
    this->artiste=artiste;
    this->prix=prix;
    this->dateCreation=dateCreation;
    this->statut=statut;

}

tableau::tableau()
{
    this->nom="";
    this->artiste="";
    this->prix=0;
    this->dateCreation="";
    this->statut="";

}

// Getters
QString tableau::getNom()
{
    return nom;
}

QString tableau::getArtiste()
{
    return artiste;
}

int tableau::getprix()
{
    return prix;
}



QString tableau::getDateCreation()
{
    return dateCreation;
}

QString tableau::getstatut()
{
    return statut;
}

// Setters
void tableau::setNom( QString &nom)
{
    this->nom = nom;
}

void tableau::setartiste( QString &artiste)
{
    this->artiste = artiste;
}

void tableau::setprix( int &prix)
{
    this->prix = prix;
}

void tableau::setDateCreation( QString &dateCreation)
{
    this->dateCreation = dateCreation;
}

void tableau::setstatut(QString &statut)
{
    this->statut = statut;
}


//fonctions

bool tableau::ajouter()
{
    QSqlQuery query;

    QString res = QString::number(prix);

    //prepare() prend la requête en paramètre pour la préparer à l'exécution.
    query.prepare("INSERT INTO tableau (NOM,ARTISTE,DATEDECREATION,PRIX,STATUTDEDISPONIBILITE) "
                  "VALUES (:nom, :artiste,  :dateCreation, :prix, :statut)");

    //Creation des variables liees
    query.bindValue(":prix", prix);
    query.bindValue(":nom", nom);
    query.bindValue(":artiste", artiste);
    query.bindValue(":dateCreation", dateCreation);
    query.bindValue(":statut", statut);

    return query.exec(); //exec() envoie la requete pour l'exécuter
}


bool tableau::supprimer(nom)
{
    QSqlQuery query;
    QString res=QString::(nom);

    query.prepare("Delete from tableau where name= :nom");
    query.bindValue(":nom",nom);

    return query.exec();

}

QSqlQueryModel *tableau::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from tableau");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("artiste"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("dateCreation"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("statut"));
    return model;

}
