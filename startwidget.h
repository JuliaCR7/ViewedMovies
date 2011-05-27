#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QDialog>

namespace Ui {
    class StartWidget;
}

class StartWidget : public QDialog
{
    Q_OBJECT

public:
    explicit StartWidget(QDialog *parent = 0);
    ~StartWidget();

private:
    Ui::StartWidget *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // STARTWIDGET_H
