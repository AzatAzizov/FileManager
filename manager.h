#ifndef MANAGER_H
#define MANAGER_H
#include <QAbstractListModel>
#include <QFileInfo>
#include <QObject>

class Manager: public QAbstractListModel
{
    Q_OBJECT
public:
    Manager(QObject *parent = nullptr);
    enum Roles{
        Name,
        Path
    };

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;


   Q_INVOKABLE void createDir();


private:
    QList<QFileInfo> m_data;

    void update();

};


#endif // MANAGER_H
