#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "firststore.h"
#include "secondstore.h"
#include "thirdstore.h"

#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowTitle("Склад");
    ui->setupUi(this);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(4);
    QStringList headers = {"Имя продукта", "Товары первого магазина", "Товары второго магазина", "Товары третьего магазина"};
    tableWidget->setHorizontalHeaderLabels(headers);

    loadCsvData();
    tableWidget->resizeColumnsToContents();

    QPushButton *buttonFirstStore = new QPushButton("Перейти к магазину 1", this);
    QPushButton *buttonSecondStore = new QPushButton("Перейти к магазину 2", this);
    QPushButton *buttonThirdStore = new QPushButton("Перейти к магазину 3", this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableWidget);
    layout->addWidget(buttonFirstStore);
    layout->addWidget(buttonSecondStore);
    layout->addWidget(buttonThirdStore);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(buttonFirstStore, &QPushButton::clicked, this, &MainWindow::openFirstStore);
    connect(buttonSecondStore, &QPushButton::clicked, this, &MainWindow::openSecondStore);
    connect(buttonThirdStore, &QPushButton::clicked, this, &MainWindow::openThirdStore);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadCsvData()
{
    QFile file("E:/PROGGRAMIROVANIE/qt-project/CourseworkKimEvgeny/warehouse.csv");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        int row = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (row == 0) {
                row++;
                continue;
            }
            line.remove('"');

            QStringList fields = line.split(",");
            tableWidget->insertRow(tableWidget->rowCount());

            for (int col = 0; col < fields.size(); ++col) {
                tableWidget->setItem(row-1, col, new QTableWidgetItem(fields[col]));
            }


            row++;

            data.append(fields);
        }
        file.close();
    }
}

QVector<QStringList> MainWindow::getData() const
{
    return data;
}

void MainWindow::openFirstStore()
{
    FirstStore *store = new FirstStore(getData());
    store->setAttribute(Qt::WA_DeleteOnClose);
    store->show();
}

void MainWindow::openSecondStore()
{
    SecondStore *store = new SecondStore(getData());
    store->setAttribute(Qt::WA_DeleteOnClose);
    store->show();
}

void MainWindow::openThirdStore()
{
    ThirdStore *store = new ThirdStore(getData());
    store->setAttribute(Qt::WA_DeleteOnClose);
    store->show();
}
