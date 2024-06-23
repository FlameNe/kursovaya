#ifndef THIRDSTORE_H
#define THIRDSTORE_H

#include <QWidget>
#include <QTableWidget>
#include <QStringList>
#include <QVector>

class ThirdStore : public QWidget
{
    Q_OBJECT
public:
    explicit ThirdStore(const QVector<QStringList> &data, QWidget *parent = nullptr);

private:
    QTableWidget *tableWidget;
    QVector<double> prices; // Массив цен
    void loadData(const QVector<QStringList> &data);
};

#endif // THIRDSTORE_H
