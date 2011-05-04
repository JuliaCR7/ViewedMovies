#include "viewedmovies.h"
#include "ui_viewedmovies.h"

ViewedMovies::ViewedMovies(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewedMovies)
{
    ui->setupUi(this);
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("films");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "Номер");

    ui->filmList->setModel(model);
}

ViewedMovies::~ViewedMovies()
{
    delete ui;
}

void ViewedMovies::on_pushButton_3_clicked()
{

}
