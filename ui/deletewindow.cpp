#include "deletewindow.h"

DeleteWindow::DeleteWindow(QWidget *parent): QDialog(parent)
{
    createObjects();
    initUI();
    connectSignals();
}

void DeleteWindow::createObjects() {
    w_button_cancel = new QPushButton;
    w_button_ok = new QPushButton;

    w_label_img = new QLabel("<img src='qrc://resources/img/delete_contact.png'>");
    w_label_question = new QLabel;

    l_vlay_root = new QVBoxLayout;

    l_hlay_buttons = new QHBoxLayout;
}

void DeleteWindow::initUI() {
    setLayout(l_vlay_root);
    setContentsMargins(0, 0, 0, 0);
    setMinimumSize(300,250);

    l_vlay_root->addWidget(w_label_img);
    l_vlay_root->addWidget(w_label_question);
    l_vlay_root->addLayout(l_hlay_buttons);
    l_vlay_root->setContentsMargins(0, 0, 0, 0);

    l_hlay_buttons->addWidget(w_button_ok);
    l_hlay_buttons->addWidget(w_button_cancel);
    l_hlay_buttons->setContentsMargins(0, 0, 0, 0);
    l_hlay_buttons->setSpacing(1);

    w_label_img->setAlignment(Qt::AlignCenter);

    w_label_question->setAlignment(Qt::AlignCenter);

    w_button_ok->setStyleSheet("QPushButton { background: rgb(66, 134, 244); border: none; }"
                               "QPushButton:hover { background: rgb(66, 134, 180); border: none; }"
                               "QPushButton:pressed { background: rgb(66, 134, 160); border: none; }");
    w_button_ok->setIcon(QIcon(":/resources/img/accept.png"));
    w_button_ok->setToolTip("OK");
    w_button_ok->setMinimumHeight(40);

    w_button_cancel->setStyleSheet("QPushButton { background: rgb(226, 40, 40); border: none; }"
                                   "QPushButton:hover { background: rgb(210, 40, 40); border: none; }"
                                   "QPushButton:pressed { background: rgb(200, 40, 40); border: none; }");
    w_button_cancel->setIcon(QIcon(":/resources/img/cancel.png"));
    w_button_cancel->setToolTip("Отмена");
    w_button_cancel->setMinimumHeight(w_button_ok->minimumHeight());
}

void DeleteWindow::connectSignals() {
    connect(w_button_ok, SIGNAL(clicked(bool)), SLOT(accept()));
    connect(w_button_cancel, SIGNAL(clicked(bool)), SLOT(reject()));
}

void DeleteWindow::setQuestionText(QString name) {
    w_label_question->setText(name);
}

DeleteWindow::~DeleteWindow() {
    delete l_vlay_root;
}
