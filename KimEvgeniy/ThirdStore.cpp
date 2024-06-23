#include "thirdstore.h"
#include <QVBoxLayout>

ThirdStore::ThirdStore(const QVector<QStringList> &data, QWidget *parent)
    : QWidget(parent), prices({11.3, 20.8, 40, 53, 33, 38})
{
    setWindowTitle("Третий магазин");

    setMinimumSize(600, 400);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(4);
    QStringList headers = {"Имя продукта", "Кол-во", "Цена за 1 шт", "Общая ценна товара"};
    tableWidget->setHorizontalHeaderLabels(headers);

    loadData(data);

    tableWidget->resizeColumnsToContents();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableWidget);
    setLayout(layout);
}

void ThirdStore::loadData(const QVector<QStringList> &data)
{
    for (int i = 0; i < data.size(); ++i) {
        tableWidget->insertRow(tableWidget->rowCount());

        QString productName = data[i][0];
        int quantity = data[i][3].toInt();
        double pricePerItem = prices[i % prices.size()];
        double totalPrice = quantity * pricePerItem;

        QTableWidgetItem *nameItem = new QTableWidgetItem(productName);
        nameItem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(i, 0, nameItem);

        QTableWidgetItem *quantityItem = new QTableWidgetItem(QString::number(quantity));
        quantityItem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(i, 1, quantityItem);

        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(pricePerItem));
        priceItem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(i, 2, priceItem);

        QTableWidgetItem *totalItem = new QTableWidgetItem(QString::number(totalPrice));
        totalItem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(i, 3, totalItem);
    }
}
