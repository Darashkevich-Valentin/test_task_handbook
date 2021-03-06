#include "xmlrepository.h"

XMLRepository::XMLRepository(QString filename)
{
    ob_file_repository = new QFile(filename);
    ob_xmlreader = new QXmlStreamReader(ob_file_repository);
    ob_xmlwriter = new QXmlStreamWriter(ob_file_repository);
    contacts = new QList<Contact*>();

    ob_xmlwriter->setAutoFormatting(true);
}

void XMLRepository::open(QIODevice::OpenMode mode) {
    if(!ob_file_repository->open(mode)) {
        emit error(ob_file_repository->errorString());
    }
}

void XMLRepository::close() {
    ob_file_repository->flush();
    ob_file_repository->close();
    emit updated();
}

void XMLRepository::add(Contact *contact) {
    contacts->append(contact);
    connect(contact, SIGNAL(contactChanged()),SLOT(contactChanged()));
    writeAll();
}

void XMLRepository::remove(Contact *contact) {
    if(contacts->contains(contact)) {
        contacts->removeAll(contact);
    }
    writeAll();
}

void XMLRepository::update(Contact *contact) {
    if(contacts->contains(contact)) {
        contacts->removeAll(contact);
        add(contact);
    }
}

void XMLRepository::writeAll() {
    open(QIODevice::WriteOnly);
    ob_xmlwriter->writeStartDocument();
    ob_xmlwriter->writeStartElement("Contacts");
    for(int i = 0; i < contacts->count(); i++) {
        ob_xmlwriter->writeStartElement("Contact");
        ob_xmlwriter->writeAttribute("name", contacts->at(i)->name());
        ob_xmlwriter->writeAttribute("phone", contacts->at(i)->phoneNumber());
        ob_xmlwriter->writeEndElement();
    }
    ob_xmlwriter->writeEndElement();
    ob_xmlwriter->writeEndDocument();
    close();
}

QList<Contact*>* XMLRepository::getContacts() {
    return contacts;
}

void XMLRepository::readAll() {
    contacts->clear();
    open(QIODevice::ReadOnly);
    if(ob_file_repository->exists()) {
        while(!ob_xmlreader->atEnd()) {
            QXmlStreamReader::TokenType type = ob_xmlreader->readNext();
            if(!ob_xmlreader->hasError()) {
                if(type == QXmlStreamReader::StartElement && ob_xmlreader->name() == "Contact" && ob_xmlreader->attributes().count() == 2) {
                    if(ob_xmlreader->attributes().at(0).name() == "name" && ob_xmlreader->attributes().at(1).name() == "phone") {
                        Contact *contact = new PhoneContact;
                        contact->setName(ob_xmlreader->attributes().at(0).value().toString());
                        contact->setPhoneNumber(ob_xmlreader->attributes().at(1).value().toString());
                        contacts->append(contact);
                        connect(contact,SIGNAL(contactChanged()),SLOT(contactChanged()));
                    }
                }
            } else {
                emit error(ob_xmlreader->errorString());
                break;
            }
        }
    }
    close();
}

XMLRepository::~XMLRepository() {
    contacts->clear();
    delete contacts;
    delete ob_xmlreader;
    delete ob_xmlwriter;
    delete ob_file_repository;
}

// Slots

void XMLRepository::contactChanged() {
    writeAll();
}
