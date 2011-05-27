#ifndef FILM_H
#define FILM_H

#include <QObject>
#include <QImage>

enum Type
{
    film,
    serial
};
enum Genre
{
    Action = 1,
    Adventure = 2,
    Anime = 4,
    Comedy = 8,
    Detective = 16,
    Drama = 32,
    Catastrophe = 64,
    Fantasy = 128,
    Fantastic = 256,
    Family = 512,
    Horror = 1024,
    Melodrama = 2048,
    Multfilm = 4096,
    Musical = 8192,
    Sport = 16384,
    Thriller = 32768
};

struct Film
{
    Film();
    ~Film();
    QString name;
    QString country;
    QString director;
    QString actors;
    Type type;
    quint64 genre;

    int year;
    int score;
   // QImage *poster;
    QString pathToImg;
};

#endif // FILM_H
