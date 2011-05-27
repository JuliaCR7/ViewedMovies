#include "viewedmovies.h"
#include "ui_viewedmovies.h"

ViewedMovies::ViewedMovies(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewedMovies)
{
    ui->setupUi(this);
    createTable();
    model = new FilmModel(this);
    ui->filmList->setModel(model);
    ui->filmList->setColumnHidden(0,true);
    ui->filmList->setColumnHidden(9,true);
  //  ui->pushButton_2->setVisible(false);
}

ViewedMovies::~ViewedMovies()
{
    delete ui;
}

void ViewedMovies::on_pushButton_3_clicked()
{
    AddForm form(this);
    if (form.exec() == QDialog::Accepted)
    {
        Film f = form.getFilm();
        model->addFilm(f);
    }
}

void ViewedMovies::createTable()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS films ("
               "id INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,"
               "name VARCHAR(255),"
               "year INTEGER UNSIGNED,"
               "country VARCHAR(255),"
               "director VARCHAR(255),"
               "actors VARCHAR(255),"
               "type INTEGER UNSIGNED,"
               "genre INTEGER UNSIGNED,"
               "score INTEGER UNSIGNED,"
               "poster LONGBLOB)");
}

void ViewedMovies::on_lineEdit_textChanged(QString text)
{
    if (text.isEmpty())
    {
        model->setFilter("");
    }
    else
    {
        QString s = QString("name LIKE '%%1%' OR country LIKE '%%1%' OR year LIKE '%%1%' OR director LIKE '%%1%' OR year LIKE '%%1%' OR score LIKE '%%1%'").arg(text);
        model->setFilter(s);
    }
}

void ViewedMovies::on_pushButton_clicked()
{
    int count = ui->filmList->selectionModel()->selectedRows().count();
    QList<int> rowsToDel;
    for( int i = 0; i < count; i++)
    {
        rowsToDel << ui->filmList->selectionModel()->selectedRows().at(i).row();
    }
    model->deleteFilms(rowsToDel);
}

void ViewedMovies::on_pushButton_2_clicked()
{
    int count = ui->filmList->selectionModel()->selectedRows().count();
    if (count > 0)
    {
        int row = ui->filmList->selectionModel()->selectedRows().at(0).row();
        Film f = model->getFilmByRow(row);


        AddForm form(f, this);
        if (form.exec() == QDialog::Accepted)
        {
            Film f2 = form.getFilm();
            model->updateFilm(row, f2);

        }
    }

}

void ViewedMovies::on_filmList_doubleClicked(QModelIndex index)
{

    Film f = model->getFilmByRow(index.row());
    InfoForm *form = new InfoForm(&f, this);
    form->setAttribute(Qt::WA_DeleteOnClose); // удалять после закрытия, чтобы не было утечки памяти
    form->show();
    form->raise();
    form->activateWindow();
}
