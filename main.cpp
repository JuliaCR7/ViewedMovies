#include <QtGui/QApplication>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include "viewedmovies.h"
const char * const nameDB = "movies.sqlite";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nameDB);
    if (!db.open()){
        QMessageBox::critical(NULL, "Ошибка!", "Не могу открыть файл с базой фильмов.", QMessageBox::Ok);
        return 1;
    }
    ViewedMovies w;
    w.show();

    return a.exec();
}
