#include "ui/startwindow.h"
#include <QDebug>


StartWindow::StartWindow(QWidget *parent)
    : QWidget(parent)
{
    createObjects();
    initUI();
    connectSignals();
}

void StartWindow::createObjects() {
    w_button_add_contact = new QPushButton;
    w_button_edit_contact = new QPushButton;
    w_button_remove_contact = new QPushButton;
    w_tablewidget_book = new QTableWidget;

    l_vlay_root = new QVBoxLayout;
    l_hlay_buttons = new QHBoxLayout;

    w_contactwindow = new ContactWindow;
}

void StartWindow::connectSignals() {
    connect(w_button_add_contact, SIGNAL(clicked(bool)), SLOT(addContact()));
    connect(w_button_edit_contact, SIGNAL(clicked(bool)), SLOT(editContact()));
    connect(w_button_remove_contact, SIGNAL(clicked(bool)), SLOT(removeContact()));
    connect(w_tablewidget_book, SIGNAL(itemSelectionChanged()), SLOT(selectedContact()));
    connect(w_tablewidget_book, SIGNAL(cellDoubleClicked(int,int)), SLOT(editContact()));
}

void StartWindow::initUI() {
    setLayout(l_vlay_root);
    setContentsMargins(0,0,0,0);

    l_vlay_root->addWidget(w_tablewidget_book);
    l_vlay_root->addLayout(l_hlay_buttons);
    l_vlay_root->setContentsMargins(0,0,0,0);
    l_vlay_root->setSpacing(0);

    l_hlay_buttons->addWidget(w_button_add_contact, 3);
    l_hlay_buttons->addWidget(w_button_edit_contact, 1);
    l_hlay_buttons->addWidget(w_button_remove_contact, 1);
    l_hlay_buttons->setSpacing(1);

    w_tablewidget_book->setColumnCount(2);
    w_tablewidget_book->setEditTriggers(QTableWidget::NoEditTriggers);
    w_tablewidget_book->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    w_tablewidget_book->setSelectionBehavior(QTableWidget::SelectRows);
    w_tablewidget_book->setWordWrap(true);
    w_tablewidget_book->verticalHeader()->hide();
    w_tablewidget_book->setStyleSheet("QTableWidget { border: none; }");

    w_button_add_contact->setStyleSheet("QPushButton { background: rgb(66, 134, 244); border: none; }"
                                        "QPushButton:hover { background: rgb(66, 134, 180); border: none; }"
                                        "QPushButton:pressed { background: rgb(66, 134, 160); border: none; }");
    w_button_add_contact->setMinimumHeight(40);
    w_button_add_contact->setIcon(QIcon(":/resources/img/add.png"));
    w_button_add_contact->setToolTip("Добавить");

    w_button_edit_contact->setStyleSheet(w_button_add_contact->styleSheet());
    w_button_edit_contact->setMinimumHeight(w_button_add_contact->minimumHeight());
    w_button_edit_contact->setIcon(QIcon(":/resources/img/edit.png"));
    w_button_edit_contact->setToolTip("Редактировать");
    w_button_edit_contact->hide();

    w_button_remove_contact->setStyleSheet("QPushButton { background: rgb(226, 40, 40); border: none; }"
                                           "QPushButton:hover { background: rgb(210, 40, 40); border: none; }"
                                           "QPushButton:pressed { background: rgb(200, 40, 40); border: none; }");
    w_button_remove_contact->setMinimumHeight(w_button_add_contact->minimumHeight());
    w_button_remove_contact->setIcon(QIcon(":/resources/img/remove.png"));
    w_button_remove_contact->setToolTip("Удалить");
    w_button_remove_contact->hide();

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

    QStringList horizontal_header;
    horizontal_header << "Имя" << "Номер телефона";
    w_tablewidget_book->setHorizontalHeaderLabels(horizontal_header);
}

void StartWindow::addContact() {
    w_contactwindow->setName("");
    w_contactwindow->setPhoneNumber("");

    if(w_contactwindow->exec() == ContactWindow::Accepted) {
        Contact *contact = new PhoneContact;
        contact->setName(w_contactwindow->name());
        contact->setPhoneNumber(w_contactwindow->phoneNumber());
        ob_repository->add(contact);
    };
}

void StartWindow::removeContact() {

}

void StartWindow::editContact() {
    QTableWidgetItem *itemSelected = w_tablewidget_book->selectedItems().at(0);
    Contact *contact = ob_repository->getContacts()->at(itemSelected->row());

    w_contactwindow->setName(contact->name());
    w_contactwindow->setPhoneNumber(contact->phoneNumber());

    if(w_contactwindow->exec() == ContactWindow::Accepted) {
        contact->setName(w_contactwindow->name());
        contact->setPhoneNumber(w_contactwindow->phoneNumber());
    }
}

void StartWindow::selectedContact() {
    QList<QTableWidgetItem*> selected =  w_tablewidget_book->selectedItems();
    if(selected.count() == 2) {
        w_button_remove_contact->show();
        w_button_edit_contact->show();
    } else if(selected.count() > 2) {
        w_button_edit_contact->hide();
    } if(selected.count() == 0) {
        w_button_edit_contact->hide();
        w_button_remove_contact->hide();
    }
}
