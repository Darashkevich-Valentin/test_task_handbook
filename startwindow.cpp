#include "startwindow.h"
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
    //contact->setName(name);
    contact->setPhoneNumber("sdfs1");
    contact->setPhoneNumber("sdfsd");

    setWindowTitle(contact->phoneNumber());
}

void StartWindow::initUI() {
    setLayout(l_vlay_root);

    l_vlay_root->addWidget(w_tablewidget_book);
    l_vlay_root->addWidget(w_button_add_contact);

    w_tablewidget_book->hide();
}



StartWindow::~StartWindow()
{
}
