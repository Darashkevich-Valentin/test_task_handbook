#ifndef PHONECONTACT_H
#define PHONECONTACT_H

#include <QObject>
#include "model/contact.h"

class PhoneContact : public Contact
{
    Q_OBJECT
public:
    QString name();
    QString phoneNumber();

    void setName(QString name);
    void setPhoneNumber(QString phoneNumber);
};

#endif // PHONECONTACT_H
