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

    ob_repository = new XMLRepository;
    Contact *d = new PhoneContact;
    d->setName("name1");
    d->setPhoneNumber("+34123");
    ob_repository->add(d);
}

void StartWindow::connectSignals() {

}

void StartWindow::initUI() {
    setLayout(l_vlay_root);

    l_vlay_root->addWidget(w_tablewidget_book);
    l_vlay_root->addWidget(w_button_add_contact);

    w_tablewidget_book->hide();
}

void StartWindow::setRepository(Repository *repository) {
    ob_repository = repository;
}

StartWindow::~StartWindow()
{

}

// Slots

void StartWindow::repositoryError(QString msg) {
    qDebug() << msg;
}

void StartWindow::repositoryUpdated() {

}

void StartWindow::addContact() {

}

void StartWindow::removeContact() {

}

void StartWindow::editContact() {

}
