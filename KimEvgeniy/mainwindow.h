#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector<QStringList> getData() const;

private slots:
    void openFirstStore();
    void openSecondStore();
    void openThirdStore();

private:
    Ui::MainWindow *ui;
    QTableWidget *tableWidget;

    void loadCsvData();
    QVector<QStringList> data;
};

#endif // MAINWINDOW_H
