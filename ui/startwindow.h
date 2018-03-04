#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <model-impl/phonecontact.h>
#include <model-impl/xmlrepository.h>

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = 0);
    ~StartWindow();

private:
    QTableWidget *w_tablewidget_book;

    QVBoxLayout *l_vlay_root;

    QPushButton *w_button_add_contact;

    Contact *contact;

    XMLRepository *ob_repo;

    void createObjects();
    void initUI();
private slots:
    void contactChanged();

};

#endif // STARTWINDOW_H
