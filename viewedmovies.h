#ifndef VIEWEDMOVIES_H
#define VIEWEDMOVIES_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QSqlRecord>
#include "addform.h"
#include "filmmodel.h"
#include "infoform.h"

namespace Ui {
    class ViewedMovies;
}

class ViewedMovies : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewedMovies(QWidget *parent = 0); // конструктор
    ~ViewedMovies();

    void createTable();

private:
    Ui::ViewedMovies *ui;
    FilmModel *model;

private slots:
    void on_filmList_doubleClicked(QModelIndex index);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_lineEdit_textChanged(QString );
    void on_pushButton_3_clicked();
};

#endif // VIEWEDMOVIES_H
