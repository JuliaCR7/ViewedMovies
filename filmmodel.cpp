#include <QDebug>
#include "filmmodel.h"

FilmModel::FilmModel(QObject *parent) :
    QSqlTableModel(parent)
{
    setTable("films");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    setSort(0, Qt::AscendingOrder);
    setFilter("");
    select();
    setHeaderData(1, Qt::Horizontal, "Name");
    setHeaderData(2, Qt::Horizontal, "Year");
    setHeaderData(3, Qt::Horizontal, "Country");
    setHeaderData(4, Qt::Horizontal, "Director");
    setHeaderData(5, Qt::Horizontal, "Actors");
    setHeaderData(6, Qt::Horizontal, "Type");
    setHeaderData(7, Qt::Horizontal, "Genre");
    setHeaderData(8, Qt::Horizontal, "Score");
}
bool FilmModel::addFilm(Film &f)
{
    QSqlRecord r = record();
    r.setValue("name", f.name);
    r.setValue("year", f.year);
    r.setValue("country", f.country);
    r.setValue("director", f.director);
    r.setValue("actors", f.actors);
    r.setValue("type", f.type);
    r.setValue("genre", f.genre);
    r.setValue("score", f.score);
    r.setValue("poster", "");
    insertRecord(-1, r);
    bool resSubmit = submitAll();
    return resSubmit;
}
QVariant FilmModel::data(const QModelIndex &idx, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (idx.column() == 6)
        {
            int type = QSqlTableModel::data(idx,role).toInt();
            return type==0 ? "Film" : "Serial";

        }
        if (idx.column() == 7)
        {
            quint64 mask = QSqlTableModel::data(idx,role).toUInt();
            return makeStringByMask(mask);
        }

        if (idx.column() == 2)
        {
            quint64 year = QSqlTableModel::data(idx,role).toInt();
            if (year == 0) return "Unknown";
        }



        return QSqlTableModel::data(idx,role);
    }
    return QSqlTableModel::data(idx,role);
}

QString FilmModel::makeStringByMask(quint64 mask) const
{
    QString res("");
    res += mask & Action ? "Action, " : "";
    res += mask & Adventure ? "Adventure, " : "";
    res += mask & Anime ? "Anime, " : "";
    res += mask & Comedy ? "Comedy, " : "";
    res += mask & Detective ? "Detective, " : "";
    res += mask & Drama ? "Drama, " : "";
    res += mask & Catastrophe ? "Catastrophe, " : "";
    res += mask & Fantasy ? "Fantasy, " : "";
    res += mask & Fantastic ? "Fantastic, " : "";
    res += mask & Family ? "Family, " : "";
    res += mask & Horror ? "Horror, " : "";
    res += mask & Melodrama ? "Melodrama, " : "";
    res += mask & Multfilm ? "Multfilm, " : "";
    res += mask & Musical ? "Musical, " : "";
    res += mask & Sport ? "Sport, " : "";
    res += mask & Thriller ? "Thriller, " : "";
    if (!res.isEmpty())
        res.chop(2);
    return res;
}

void FilmModel::deleteFilms(QList<int> rows)
{
    for (int i = 0; i < rows.size(); i++)
    {
        removeRow(rows.at(i));
    }
     submitAll();
}

Film FilmModel::getFilmByRow(int row) //just for test
{
    QSqlRecord r = record(row);
    Film f;
    f.name = r.value("name").toString();
    f.country = r.value("country").toString();
    f.actors = r.value("actors").toString();
    f.director = r.value("director").toString();
    f.year = r.value("year").toInt();
    f.genre = r.value("genre").toUInt();
    f.type = r.value("type").toInt() == 1 ? serial : film;
    f.score = r.value("score").toInt();
    return f;
}

void FilmModel::updateFilm(int row, Film f)
{
    QSqlRecord r = record(row);
    r.setValue("name", f.name);
    r.setValue("country", f.country);
    r.setValue("year", f.year);
    r.setValue("actors", f.actors);
    r.setValue("director", f.director);
    r.setValue("type", f.type == serial ? 1 : 0);
    r.setValue("genre", f.genre);
    r.setValue("score", f.score);
    r.setValue("poster", "");
    setRecord(row,r);
    submitAll();
}
