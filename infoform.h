#ifndef INFOFORM_H
#define INFOFORM_H

#include <QDialog>
#include <QImage>
#include <QDebug>
#include "film.h"

namespace Ui {
    class InfoForm;
}

class InfoForm : public QDialog
{
    Q_OBJECT

    void loadFilm(Film *film);
    QString makeStringByMask(quint64 mask) const;
public:
    explicit InfoForm(Film *film, QWidget *parent = 0);
    ~InfoForm();

private:
    Ui::InfoForm *ui;
};

#endif // INFOFORM_H
