#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

class ContactWindow : public QDialog
{
public:
    ContactWindow(QWidget *parent = 0);

    QString name();
    QString phoneNumber();

    void setName(QString name);
    void setPhoneNumber(QString phoneNumber);

private:
    QLabel *w_label_name,
           *w_label_phone,
           *w_label_img;

    QPushButton *w_button_ok,
                *w_button_cancel;

    QVBoxLayout *l_vlay_root;

    QHBoxLayout *l_hlay_name_field,
                *l_hlay_phone_field,
                *l_hlay_buttons;

    QLineEdit *w_line_name,
              *w_line_phone;

    void createObjects();
    void initUI();
    void connectSignals();
};

#endif // CONTACTWINDOW_H
