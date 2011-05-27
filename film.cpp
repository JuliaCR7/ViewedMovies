#include "film.h"

Film::Film()
{
     name = "";
     country = "";
     director = "";
     actors = "";
     type = film;
     genre = 0;

     year = 0;
     score = 0;
   //  poster = new QImage();
     pathToImg = "";
}

Film::~Film()
{

}
