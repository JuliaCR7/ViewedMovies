#include "startwidget.h"
#include "ui_startwidget.h"

StartWidget::StartWidget(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::StartWidget)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = windowFlags();
    flags ^= Qt::WindowContextHelpButtonHint;
    setWindowFlags(flags);
    setWindowTitle("ViewedMovies");
}

StartWidget::~StartWidget()
{
    delete ui;
}

void StartWidget::on_pushButton_clicked()
{
    accept();
}

void StartWidget::on_pushButton_2_clicked()
{
    reject();
}
