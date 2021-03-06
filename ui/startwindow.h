#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include "model-impl/phonecontact.h"
#include "model-impl/xmlrepository.h"
#include "ui/contactwindow.h"
#include "ui/deletewindow.h"

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = 0);
    ~StartWindow();

    void setRepository(Repository *repository);

private:
    QTableWidget *w_tablewidget_book;

    QPushButton *w_button_add_contact,
                *w_button_edit_contact,
                *w_button_remove_contact;

    QVBoxLayout *l_vlay_root;
    QHBoxLayout *l_hlay_buttons;

    ContactWindow *w_contactwindow;

    DeleteWindow *w_deletewindow;

    Repository *ob_repository;

    QTimer *ob_timer;

    QLabel *w_label_error;

    void createObjects();
    void initUI();
    void connectSignals();

private slots:
    void repositoryError(QString msg);
    void repositoryUpdated();

    void selectedContact();

    void addContact();
    void removeContact();
    void editContact();

    void hideError();
};

#endif // STARTWINDOW_H
