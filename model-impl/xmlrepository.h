#ifndef XMLREPOSITORY_H
#define XMLREPOSITORY_H

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "model-impl/phonecontact.h"
#include "model/repository.h"

class XMLRepository: public Repository
{
    Q_OBJECT
public:
    XMLRepository(QString filename);
    ~XMLRepository();
    void open(QIODevice::OpenMode mode);
    void close();
    QList<Contact *>* getContacts();
    void update(Contact *contact);
    void remove(Contact *contact);
    void add(Contact *contact);
    void writeAll();
    void readAll();

private:
    QXmlStreamReader *ob_xmlreader;

    QXmlStreamWriter *ob_xmlwriter;

    QFile *ob_file_repository;

private slots:
    void contactChanged();
};

#endif // XMLREPOSITORY_H
