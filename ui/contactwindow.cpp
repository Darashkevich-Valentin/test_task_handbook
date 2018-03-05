#include "contactwindow.h"

ContactWindow::ContactWindow(QWidget *parent): QDialog(parent)
{
    createObjects();
    initUI();
    connectSignals();
}

void ContactWindow::createObjects() {
    w_button_cancel = new QPushButton;
    w_button_ok = new QPushButton;

    w_label_name = new QLabel("Имя:");
    w_label_phone = new QLabel("Номер телефона:");
    w_label_img = new QLabel("<img src='qrc://resources/img/contact.png'>");

    w_line_name = new QLineEdit;
    w_line_phone = new QLineEdit;

    l_vlay_root = new QVBoxLayout;

    l_hlay_buttons = new QHBoxLayout;
    l_hlay_name_field = new QHBoxLayout;
    l_hlay_phone_field = new QHBoxLayout;
}

void ContactWindow::initUI() {
    setLayout(l_vlay_root);
    setContentsMargins(0, 0, 0, 0);
    setMinimumSize(400, 300);
    setWindowTitle("Контакт");

    l_vlay_root->addWidget(w_label_img);
    l_vlay_root->addLayout(l_hlay_name_field);
    l_vlay_root->addLayout(l_hlay_phone_field);
    l_vlay_root->addLayout(l_hlay_buttons);
    l_vlay_root->setContentsMargins(0, 0, 0, 0);

    l_hlay_name_field->addWidget(w_label_name);
    l_hlay_name_field->addWidget(w_line_name);
    l_hlay_name_field->setContentsMargins(5, 5, 5, 5);

    l_hlay_phone_field->addWidget(w_label_phone);
    l_hlay_phone_field->addWidget(w_line_phone);
    l_hlay_phone_field->setContentsMargins(5, 5, 5, 5);

    l_hlay_buttons->addWidget(w_button_ok);
    l_hlay_buttons->addWidget(w_button_cancel);
    l_hlay_buttons->setSpacing(1);
    l_hlay_buttons->setContentsMargins(0, 0, 0, 0);

    w_label_name->setMinimumWidth(100);
    w_label_name->setAlignment(Qt::AlignRight);

    w_label_phone->setMinimumWidth(100);
    w_label_phone->setAlignment(Qt::AlignRight);

    w_label_img->setAlignment(Qt::AlignCenter);

    w_line_name->setMinimumHeight(20);

    w_line_phone->setMinimumHeight(20);

    w_button_ok->setMinimumHeight(40);
    w_button_ok->setStyleSheet("QPushButton { background: rgb(66, 134, 244); border: none; }"
                               "QPushButton:hover { background: rgb(66, 134, 180); border: none; }"
                               "QPushButton:pressed { background: rgb(66, 134, 160); border: none; }");
    w_button_ok->setIcon(QIcon(":/resources/img/accept.png"));
    w_button_ok->setToolTip("ОК");

    w_button_cancel->setMinimumHeight(w_button_ok->minimumHeight());
    w_button_cancel->setStyleSheet("QPushButton { background: rgb(226, 40, 40); border: none; }"
                                   "QPushButton:hover { background: rgb(210, 40, 40); border: none; }"
                                   "QPushButton:pressed { background: rgb(200, 40, 40); border: none; }");
    w_button_cancel->setIcon(QIcon(":/resources/img/cancel.png"));
    w_button_cancel->setToolTip("Отмена");
}

void ContactWindow::connectSignals() {
    connect(w_button_ok, SIGNAL(clicked(bool)), SLOT(accept()));
    connect(w_button_cancel, SIGNAL(clicked(bool)), SLOT(reject()));
}

QString ContactWindow::name() {
    return w_line_name->text();
}

QString ContactWindow::phoneNumber() {
    return w_line_phone->text();
}

void ContactWindow::setName(QString name) {
    w_line_name->setText(name);
}

void ContactWindow::setPhoneNumber(QString phoneNumber) {
    w_line_phone->setText(phoneNumber);
}
