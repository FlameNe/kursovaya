#ifndef SECONDSTORE_H
#define SECONDSTORE_H

#include <QWidget>
#include <QTableWidget>
#include <QStringList>
#include <QVector>

class SecondStore : public QWidget
{
    Q_OBJECT
public:
    explicit SecondStore(const QVector<QStringList> &data, QWidget *parent = nullptr);

private:
    QTableWidget *tableWidget;
    QVector<double> prices; // Массив цен
    void loadData(const QVector<QStringList> &data);
};

#endif // SECONDSTORE_H

