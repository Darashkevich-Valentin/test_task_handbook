#include "phonecontact.h"

PhoneContact::PhoneContact() {

}

void PhoneContact::setName(QString name) {
    if(!name.isEmpty()) {
        _name.clear();
        _name.append(name);
        emit nameChanged();
    }
}

void PhoneContact::setPhoneNumber(QString phoneNumber) {
    if(!phoneNumber.isEmpty()) {
        _phoneNumber.clear();
        _phoneNumber.append(phoneNumber);
        emit phoneNumberChanged();
    }
}

QString PhoneContact::phoneNumber() {
    return _phoneNumber;
}

QString PhoneContact::name() {
    return _name;
}

int PhoneContact::id() {
    return _id;
}
