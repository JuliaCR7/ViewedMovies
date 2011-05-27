#include <QtGui/QApplication>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include "viewedmovies.h"
#include "startwidget.h"
const char * const nameDB = "movies.db";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec* textCodec = QTextCodec::codecForName("UTF8");
    QTextCodec::setCodecForLocale(textCodec);
    QTextCodec::setCodecForTr(textCodec);
    QTextCodec::setCodecForCStrings(textCodec);
    StartWidget sw;
    if (sw.exec() != QDialog::Accepted)
        return 0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName(nameDB);
    if (!db.open()){
        QMessageBox::critical(NULL, "Error!", "Can't connect to database", QMessageBox::Ok);
        return 1;
    }
    ViewedMovies w;
    w.show();
    return a.exec();
}
