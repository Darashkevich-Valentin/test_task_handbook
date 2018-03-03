#include <QObject>
#include "model/contact.h"

class PhoneContact : public Contact
{
    Q_OBJECT
public:
    PhoneContact();

    QString name();
    QString phoneNumber();
    int id();

    void setName(QString name);
    void setPhoneNumber(QString phoneNumber);

};

