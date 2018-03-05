#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <model-impl/phonecontact.h>
#include <model-impl/xmlrepository.h>
#include <model/repository.h>
#include <QHeaderView>
#include <QHBoxLayout>
#include <ui/contactwindow.h>


class StartWindow : public QWidget
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = 0);
    ~StartWindow();

    void setRepository(Repository *repository);

private:
    QTableWidget *w_tablewidget_book;
    QPushButton *w_button_add_contact;
    QPushButton *w_button_edit_contact;
    QPushButton *w_button_remove_contact;

    QVBoxLayout *l_vlay_root;
    QHBoxLayout *l_hlay_buttons;

    ContactWindow *w_contactwindow;

    Repository *ob_repository;

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
};

#endif // STARTWINDOW_H
