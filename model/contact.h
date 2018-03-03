#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>

class Contact: public QObject
{
    Q_OBJECT
public:
    virtual QString name() = 0;
    virtual QString phoneNumber() = 0;

    virtual int id() = 0;

    virtual void setName(QString name) = 0;
    virtual void setPhoneNumber(QString phoneNumber) = 0;

protected:
    QString _name,
            _phoneNumber;
    int _id;

signals:
    void nameChanged();
    void phoneNumberChanged();
};

#endif // CONTACT_H
