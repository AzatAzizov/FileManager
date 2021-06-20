#include "manager.h"
#include <QDir>
#include <QDebug>

static QString PATH = QDir::homePath();

Manager::Manager(QObject *parent): QAbstractListModel (parent)
{
    qDebug() << PATH;

    QDir way(PATH);
    m_data = way.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    for(int i=0; i<m_data.length(); ++i)
    {
        qDebug() << m_data[i].filePath();
    }
}

QVariant Manager::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role) {
    case Name:
        return m_data[index.row()].fileName();
    case Path:
        return m_data[index.row()].filePath();
    }
    return QVariant();
}

int Manager::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.length();
}

QHash<int, QByteArray> Manager::roleNames() const
{
    QHash<int, QByteArray> role;
    role[Name]="name";
    role[Path] ="path";
    return role;
}

void Manager::createDir()
{
    QString string("newDir");
    QDir dir;
    dir.mkdir(PATH + "/" + string);

    update();
}

void Manager::update()
{
    m_data.clear();
    QDir way(PATH);
    m_data = way.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

    beginResetModel();
    endResetModel();
}
