#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include "../filmmodel.h"
#include "../film.h"

class TestFilmModel : public QObject
{    Q_OBJECT

    FilmModel *fm;
    QSqlDatabase db;
public:
    TestFilmModel();
    ~TestFilmModel();
    bool init(); // function dlia soedineniya s bd i sozdanii tablici (inicializaciya)
    bool finish(); //  function dlia udaleniya bd posle testa
    bool createTable(); // sozdanie tablici v bd
private Q_SLOTS:
    void addFilm();
    void deleteFilm();
    void getFilmByRow();
};

TestFilmModel::TestFilmModel()
{
}
TestFilmModel::~TestFilmModel()
{
}

bool TestFilmModel::init()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("movies.db");
    bool res = db.open() && createTable();
    if (res)
        fm = new FilmModel(this);
    return res;
}
bool TestFilmModel::createTable()
{
    QSqlQuery query("CREATE TABLE IF NOT EXISTS films ("
               "id INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,"
               "name VARCHAR(255),"
               "year INTEGER UNSIGNED,"
               "country VARCHAR(255),"
               "director VARCHAR(255),"
               "actors VARCHAR(255),"
               "type INTEGER UNSIGNED,"
               "genre INTEGER UNSIGNED,"
               "score INTEGER UNSIGNED)");
    return query.exec();
}

bool TestFilmModel::finish()
{

    if (fm != NULL)
        delete fm;
    db.close();
    QFile::remove("movies.db");
    return true;
}

void TestFilmModel::addFilm()
{
    QCOMPARE(init(), true);
    Film f;
    int count1 = fm->rowCount();
    fm->addFilm(f);
    int count2 = fm->rowCount();
    QVERIFY(count2-count1 == 1);
    QCOMPARE(finish(), true);
}

void TestFilmModel::deleteFilm()
{
    QCOMPARE(init(), true);
    Film f;
    fm->addFilm(f);
    int count1 = fm->rowCount();
    QList<int> l;
    l.append(0);
    fm->deleteFilms(l);
    int count2 = fm->rowCount();
    QVERIFY(count2-count1 == -1);
    QCOMPARE(finish(), true);
}

void TestFilmModel::getFilmByRow()
{
    QCOMPARE(init(), true);
    Film f;
    f.name = "TEST";
    fm->addFilm(f);
    Film f2 = fm->getFilmByRow(fm->rowCount()-1);
    QVERIFY(f.name == f2.name);
    QCOMPARE(finish(), true);
}

QTEST_APPLESS_MAIN(TestFilmModel);


#include "tst_testfilmmodel.moc"
