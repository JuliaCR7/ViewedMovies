#include "infoform.h"
#include "ui_infoform.h"

InfoForm::InfoForm(Film *film, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoForm)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = windowFlags();
    flags ^= Qt::WindowContextHelpButtonHint;
    setWindowFlags(flags);
    setWindowTitle("Film info");

    if (film != NULL)
    {
        loadFilm(film);
    }
}

InfoForm::~InfoForm()
{
    delete ui;
}

void InfoForm::loadFilm(Film *film)
{
    ui->name->setText(film->name);
    QString s = film->type == serial ? "(serial)" : "(film)";
    ui->type->setText(s);
    ui->l_actors->setText(film->actors);
    ui->l_country->setText(film->country);
    ui->l_director->setText(film->director);
    ui->l_year->setText(QString::number(film->year));
    ui->l_genre->setText(makeStringByMask(film->genre));
    for(int i = 0; i < film->score; i++)
    {
        ui->l_score->setText(ui->l_score->text() + "P");
    }

}

QString InfoForm::makeStringByMask(quint64 mask) const
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

