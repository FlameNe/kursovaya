#ifndef FIRSTSTORE_H
#define FIRSTSTORE_H

#include <QWidget>
#include <QTableWidget>
#include <QStringList>
#include <QVector>

class FirstStore : public QWidget
{
    Q_OBJECT
public:
    explicit FirstStore(const QVector<QStringList> &data, QWidget *parent = nullptr);

private:
    QTableWidget *tableWidget;
    void loadData(const QVector<QStringList> &data);
    QVector<double> prices;

};

#endif // FIRSTSTORE_H
