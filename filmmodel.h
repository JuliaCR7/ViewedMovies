#ifndef FILMMODEL_H
#define FILMMODEL_H

#include <QSqlTableModel>
#include <QSqlRecord>
#include <QBuffer>
#include <QModelIndex>
#include "film.h"

class FilmModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit FilmModel(QObject *parent = 0);
    bool addFilm(Film &f);
    QVariant data(const QModelIndex &idx, int role) const;
    QString makeStringByMask( quint64 mask ) const;
    void deleteFilms(QList<int> rows);
    Film getFilmByRow(int row);
    void updateFilm (int row, Film f);

signals:

public slots:

};

#endif // FILMMODEL_H
