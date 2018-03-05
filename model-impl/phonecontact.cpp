#include "phonecontact.h"

void PhoneContact::setName(QString name) {
    if(!name.isEmpty()) {
        _name = name;
        emit contactChanged();
    }
}

void PhoneContact::setPhoneNumber(QString phoneNumber) {
    if(!phoneNumber.isEmpty()) {
        _phoneNumber = phoneNumber;
        emit contactChanged();
    }
}

QString PhoneContact::phoneNumber() {
    return _phoneNumber;
}

QString PhoneContact::name() {
    return _name;
}
