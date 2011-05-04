#ifndef VIEWEDMOVIES_H
#define VIEWEDMOVIES_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
    class ViewedMovies;
}

class ViewedMovies : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewedMovies(QWidget *parent = 0); // конструктор
    ~ViewedMovies();

private:
    Ui::ViewedMovies *ui;

private slots:
    void on_pushButton_3_clicked();
};

#endif // VIEWEDMOVIES_H
