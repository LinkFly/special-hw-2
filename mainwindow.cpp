#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "home-work-4.h"

#include <QErrorMessage>

#include <string>

using namespace std;

extern const int hw3_2_num1;
extern const int hw3_2_num2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setNum("edNumA", hw3_2_num1);
    setNum("edNumB", hw3_2_num2);
    relations_with_10();
    print_odd_nums();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_edNum1_textEdited(const QString &arg1)
{
    num1 = arg1.toInt();
    run_hw3_1();
}

void MainWindow::on_edNum2_textEdited(const QString &arg1)
{
    num2 = arg1.toInt();
    run_hw3_1();

}

void MainWindow::on_edNumA_textEdited(const QString &arg1)
{
    relations_with_10();
}

void MainWindow::on_edNumB_textEdited(const QString &arg1)
{
    relations_with_10();
}

void MainWindow::run_hw3_1() {
    // set expression
    const string str = to_string(num1) + " + " + to_string(num2);
    setStr("lbExpr", str);
    setStr("lbAnswer", isRange_10_20(num1, num2));
}

void MainWindow::setNum(const QString& edName, int num) {
    QLineEdit* ed = findChild<QLineEdit*>(edName);
    if (!checkFindRes(ed)) return;
    ed->setText(QString::number(num));
}
int MainWindow::getNum(const QString& edName) {
    QLineEdit* ed = findChild<QLineEdit*>(edName);
    if (!checkFindRes(ed)) return 0;
    return ed->text().toInt();
}

void MainWindow::setStr(const QString& edName, const string& str) {
    QLabel* lbAnswer = findChild<QLabel*>(edName);
    if (!checkFindRes(lbAnswer)) return;
    lbAnswer->setText(QString::fromStdString(str));
}
void MainWindow::setBool(const QString& edName, bool b) {
    QLabel* lbAnswer = findChild<QLabel*>(edName);
    if (!checkFindRes(lbAnswer)) return;
    lbAnswer->setText(QString::fromStdString(b ? "true" : "false"));
}
void MainWindow::relations_with_10() {
    int a = getNum("edNumA");
    int b = getNum("edNumB");
    auto resRel10 = both_10_or_sum_10(a, b);
    setStr("lbAnswer_2", resRel10);
}

void MainWindow::print_odd_nums() {
    setStr("lb_odd_nums", odd_nums_1_50());
}

void MainWindow::on_edMaybePrime_textEdited(const QString &arg1)
{
    int maybePrime = arg1.toInt();
    bool res = isPrime(maybePrime);
    setBool("lbIsPrime", res);
}

void MainWindow::print_error(const string& errMsg) {
    setStr("lbErrorMessage", errMsg);
}

bool MainWindow::checkFindRes(QWidget* pWidget) {
    if (pWidget == nullptr) {
        // show error
        QErrorMessage qErrMsg;
        qErrMsg.showMessage("Q-element not found");
        qErrMsg.exec();
        QApplication::quit();
        return false;
    }
    return true;
}

void MainWindow::on_edMaybeLeapYear_textEdited(const QString &arg1)
{
    print_error("");
    int maybeLeapYear = arg1.toInt();
    if (!(maybeLeapYear >= 1 && maybeLeapYear <= 3000)) {
        print_error("Failed: year must be in 1..3000 range");
        return;
    }
    bool bIsLeap = isLeapYear(maybeLeapYear);
    setBool("lbIsLeapYear", bIsLeap);
}


