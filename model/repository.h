#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QObject>
#include <QList>
#include "model/contact.h"

class Repository : public QObject
{
    Q_OBJECT
public:
    virtual void open(QIODevice::OpenMode mode) = 0;
    virtual void close() = 0;
    virtual void writeAll() = 0;
    virtual void readAll() = 0;
    virtual QList<Contact*>* getContacts()= 0;
    virtual void update(Contact *contact) = 0;
    virtual void remove(Contact *contact) = 0;
    virtual void add(Contact *contact) = 0;

protected:
    QList<Contact*> *contacts;

signals:
    void error(QString msg);
    void updated();
};

#endif // REPOSITORY_H
