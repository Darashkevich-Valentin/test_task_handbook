#include "ui/startwindow.h"
#include <QDebug>


StartWindow::StartWindow(QWidget *parent)
    : QWidget(parent)
{
    createObjects();
    initUI();
}

void StartWindow::createObjects() {
    w_button_add_contact = new QPushButton;
    w_tablewidget_book = new QTableWidget;

    l_vlay_root = new QVBoxLayout;

    contact = new PhoneContact;
    ob_repo = new XMLRepository;
    contact->setName("name1");
    contact->setPhoneNumber("sdfsd");
    ob_repo->readAll();
    qDebug() << ob_repo->getContacts()->at(0)->phoneNumber();
    connect(contact, SIGNAL(phoneNumberChanged()), SLOT(contactChanged()));

}

void StartWindow::initUI() {
    setLayout(l_vlay_root);

    l_vlay_root->addWidget(w_tablewidget_book);
    l_vlay_root->addWidget(w_button_add_contact);

    w_tablewidget_book->hide();
}

void StartWindow::contactChanged() {
    qDebug() << "111";
}

StartWindow::~StartWindow()
{
}
