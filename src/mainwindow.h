#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlRecord>
#include <vector>
#include <QScrollBar>
// #include <chrono>
// #include <random>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db;
    int anzahl;
    int counter = 0;
    int counterText = 0;
    bool gameStarted = false;
    QString randomWord;
    std::vector<QString> nameList;
    QMessageBox NachrichtFenster;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void menuZurueckclicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void errorQuery(QSqlError);

    void errorDB(QSqlDatabase);

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
