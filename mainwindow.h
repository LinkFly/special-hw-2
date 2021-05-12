#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString sNum1;
    QString sNum2;

private slots:
    void on_edNum1_textEdited(const QString &arg1);
    void on_edNum2_textEdited(const QString &arg1);


    void on_edNumA_textEdited(const QString &arg1);

    void on_edNumB_textEdited(const QString &arg1);

    void on_edMaybePrime_textEdited(const QString &arg1);

    void on_edMaybeLeapYear_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    int num1 = 0, num2 = 0;
    void run_hw3_1();
    void setNum(const QString& edName, int num);
    int getNum(const QString& edName);
    void setStr(const QString& edName, const string& str);
    void setBool(const QString& edName, bool b);
    void relations_with_10();
    void print_odd_nums();
    void print_error(const string& errMsg);
    bool checkFindRes(QWidget* pWidget);


};
#endif // MAINWINDOW_H
