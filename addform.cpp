#include "addform.h"
#include "ui_addform.h"
#include <QDebug>
AddForm::AddForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddForm)
{
    init();
}

AddForm::AddForm(Film f, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddForm)
{
     init();
     loadFromFilm(f);
}

void AddForm::init()
{
    ui->setupUi(this);
    setStyles();
    Qt::WindowFlags flags = windowFlags();
    flags ^= Qt::WindowContextHelpButtonHint;
    setWindowFlags(flags);
    setWindowTitle(tr("Add film"));

    ui->label_9->setHidden(true);
    ui->poster->setHidden(true);
    ui->browseButton->setHidden(true);
    //ui->horizontalLayout_11->set

}


AddForm::~AddForm()
{
    delete ui;
}

void AddForm::on_browseButton_clicked()
{
    QString path;
    path = QFileDialog::getOpenFileName(0, "Choose a poster", "", "*.jpg *.jpeg *.png *.gif");
    if (!path.isEmpty())
        ui->poster->setText(path);
}

void AddForm::on_cancelButton_clicked()
{
    reject();
}

void AddForm::on_addButton_clicked()
{
    if (checkForm())
    {
        accept();
    }
}

void AddForm::setStyles()
{
    setStyleSheet("QLineEdit {"
                    "border: 1px solid black;"
                    "background-color: #FFFFFF;"
                    "}"
                 );
    setStyleSheet("QLineEdit:focus {"
                    "background-color: #D0D6F9;"
                    "border: 1px solid #070E3A;"
                    "}"
                 );
}

void AddForm::makeEditError(QLineEdit *le)
{
    le->setStyleSheet("background-color: #FFD9EC;"
                      "border: 1px solid #480024;"
                      );
    le->setFocus();
}

bool AddForm::checkForm()
{
    QLineEdit* mandField[] = {ui->name, ui->country, ui->actor, NULL};
    int i = 0;
    while (mandField[i])
    {
        if (mandField[i]->text().isEmpty())
        {
            makeEditError(mandField[i]);
            return false;
        }
        i++;
    }
    if (!ui->poster->text().isEmpty())
    {
        QImage img(ui->poster->text());
        if (img.isNull())
        {
            makeEditError(ui->poster);
            return false;
        }
    }
    return true;
}

void AddForm::on_name_editingFinished()
{
    if (!ui->name->text().isEmpty())
            setStyles(ui->name);
}

void AddForm::on_country_editingFinished()
{
    if (!ui->country->text().isEmpty())
           setStyles(ui->country);
}

void AddForm::on_actor_editingFinished()
{
    if (!ui->actor->text().isEmpty())
           setStyles(ui->actor);
}

void AddForm::on_year_editingFinished()
{
    if (!ui->year->text().isEmpty())
           setStyles(ui->year);
}

void AddForm::on_director_editingFinished()
{
    if (!ui->director->text().isEmpty())
          setStyles(ui->director);
}

void AddForm::on_poster_editingFinished()
{
    if (!ui->poster->text().isEmpty())
            setStyles(ui->poster);
}

void AddForm::setStyles(QLineEdit *le)
{
    le->setStyleSheet("QLineEdit {"
                    "border: 1px solid black;"
                    "background-color: #FFFFFF;"
                    "}"
                 );
    le->setStyleSheet("QLineEdit:focus {"
                    "background-color: #D0D6F9;"
                    "border: 1px solid #070E3A;"
                    "}"
                 );
}

Film AddForm::getFilm()
{
    Film f;
    f.name = ui->name->text();
    f.year = ui->year->text().toInt();
    f.country = ui->country->text();
    f.director = ui->director->text();
    f.actors = ui->actor->text();
    f.score = ui->score->currentText().toInt();
    f.type = ui->radioSerial->isChecked() ? serial : film;
    f.genre |= ui->checkAction->isChecked() ? Action : 0;
    f.genre |= ui->checkAdventure->isChecked() ? Adventure : 0;
    f.genre |= ui->checkAnime->isChecked() ? Anime : 0;
    f.genre |= ui->checkComedy->isChecked() ? Comedy : 0;
    f.genre |= ui->checkDetective->isChecked() ? Detective : 0;
    f.genre |= ui->checkDrama->isChecked() ? Drama : 0;
    f.genre |= ui->checkCatastrophe->isChecked() ? Catastrophe : 0;
    f.genre |= ui->checkFantasy->isChecked() ? Fantasy : 0;
    f.genre |= ui->checkFantastic->isChecked() ? Fantastic : 0;
    f.genre |= ui->checkFamily->isChecked() ? Family : 0;
    f.genre |= ui->checkHorror->isChecked() ? Horror : 0;
    f.genre |= ui->checkMelodrama->isChecked() ? Melodrama : 0;
    f.genre |= ui->checkMultfilm->isChecked() ? Multfilm : 0;
    f.genre |= ui->checkMusical->isChecked() ? Musical : 0;
    f.genre |= ui->checkSport->isChecked() ? Sport : 0;
    f.genre |= ui->checkThriller->isChecked() ? Thriller : 0;
    f.pathToImg = ui->poster->text();
   // f.poster->load(ui->poster->text());
    return f;
}

void AddForm::loadFromFilm(Film f)
{
    ui->name->setText(f.name);
    ui->year->setText(QString::number(f.year));
    ui->country->setText(f.country);
    ui->director->setText(f.director);
    ui->actor->setText(f.actors);
    if (f.type == 1)
        ui->radioSerial->setChecked(true);
    ui->poster->setText(f.pathToImg);
    ui->score->setCurrentIndex(f.score-1);
    if (f.genre & Action)
        ui->checkAction->setChecked(true);
    if (f.genre & Adventure)
        ui->checkAnime->setChecked(true);
    if (f.genre & Anime)
        ui->checkAnime->setChecked(true);
    if (f.genre & Comedy)
        ui->checkComedy->setChecked(true);
    if (f.genre & Detective)
        ui->checkDetective->setChecked(true);
    if (f.genre & Drama)
        ui->checkDrama->setChecked(true);
    if (f.genre & Catastrophe)
        ui->checkCatastrophe->setChecked(true);
    if (f.genre & Fantasy)
        ui->checkFantasy->setChecked(true);
    if (f.genre & Fantastic)
        ui->checkFantastic->setChecked(true);
    if (f.genre & Family)
        ui->checkFamily->setChecked(true);
    if (f.genre & Horror)
        ui->checkHorror->setChecked(true);
    if (f.genre & Melodrama)
        ui->checkMelodrama->setChecked(true);
    if (f.genre & Multfilm)
        ui->checkMultfilm->setChecked(true);
    if (f.genre & Musical)
        ui->checkMusical->setChecked(true);
    if (f.genre & Sport)
        ui->checkSport->setChecked(true);
    if (f.genre & Thriller)
        ui->checkThriller->setChecked(true);
}
