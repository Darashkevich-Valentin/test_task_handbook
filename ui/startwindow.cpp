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
    w_button_edit_contact = new QPushButton;
    w_button_remove_contact = new QPushButton;
    w_tablewidget_book = new QTableWidget;

    l_vlay_root = new QVBoxLayout;
    l_hlay_buttons = new QHBoxLayout;
}

void StartWindow::connectSignals() {

}

void StartWindow::initUI() {
    setLayout(l_vlay_root);
    setContentsMargins(0,0,0,0);

    QStringList horizontal_header;
    horizontal_header << "Имя" << "Номер телефона";

    l_vlay_root->addWidget(w_tablewidget_book);
    l_vlay_root->addLayout(l_hlay_buttons);
    l_vlay_root->setContentsMargins(0,0,0,0);
    l_vlay_root->setSpacing(0);

    l_hlay_buttons->addWidget(w_button_add_contact, 3);
    l_hlay_buttons->addWidget(w_button_edit_contact, 1);
    l_hlay_buttons->addWidget(w_button_remove_contact, 1);
    l_hlay_buttons->setSpacing(0);

    w_tablewidget_book->setColumnCount(2);
    w_tablewidget_book->setEditTriggers(QTableWidget::NoEditTriggers);
    w_tablewidget_book->setSelectionMode(QTableWidget::SingleSelection);
    w_tablewidget_book->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    w_tablewidget_book->setSelectionBehavior(QTableWidget::SelectRows);
    w_tablewidget_book->setWordWrap(true);
    w_tablewidget_book->setHorizontalHeaderLabels(horizontal_header);

}

void StartWindow::setRepository(Repository *repository) {
    ob_repository = repository;
    connect(ob_repository,SIGNAL(error(QString)),SLOT(repositoryError(QString)));
    connect(ob_repository,SIGNAL(updated()),SLOT(repositoryUpdated()));
    ob_repository->readAll();
}

StartWindow::~StartWindow()
{

}

// Slots

void StartWindow::repositoryError(QString msg) {
    qDebug() << msg;
}

void StartWindow::repositoryUpdated() {
    w_tablewidget_book->clear();
    w_tablewidget_book->setRowCount(ob_repository->getContacts()->count());
    for(int i = 0; i < ob_repository->getContacts()->count(); i++) {
        QTableWidgetItem *name = new QTableWidgetItem(ob_repository->getContacts()->at(i)->name());
        QTableWidgetItem *phone = new QTableWidgetItem(ob_repository->getContacts()->at(i)->phoneNumber());
        w_tablewidget_book->setItem(i, 0, name);
        w_tablewidget_book->setItem(i, 1, phone);
    }
}

void StartWindow::addContact() {

}

void StartWindow::removeContact() {

}

void StartWindow::editContact() {

}
