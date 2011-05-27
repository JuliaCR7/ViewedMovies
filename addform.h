#ifndef ADDFORM_H
#define ADDFORM_H

#include <QDialog>
#include <QFileDialog>
#include <QLineEdit>
#include <QImage>
#include "film.h"

namespace Ui {
    class AddForm;
}

class AddForm : public QDialog
{
    Q_OBJECT

public:
    AddForm(QWidget *parent = 0);
    AddForm(Film film, QWidget *parent);
    ~AddForm();
    Film getFilm();

private:
    Ui::AddForm *ui;
    void setStyles();
    void setStyles(QLineEdit *le);
    void makeEditError(QLineEdit *le);
    bool checkForm();
    void loadFromFilm(Film film);
    void init();

private slots:
    void on_poster_editingFinished();
    void on_director_editingFinished();
    void on_year_editingFinished();
    void on_actor_editingFinished();
    void on_country_editingFinished();
    void on_name_editingFinished();
    void on_addButton_clicked();
    void on_cancelButton_clicked();
    void on_browseButton_clicked();
};

#endif // ADDFORM_H
