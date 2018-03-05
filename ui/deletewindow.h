#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class DeleteWindow : public QDialog
{
public:
    DeleteWindow(QWidget *parent = 0);

    void setQuestionText(QString name);
private:

    QPushButton *w_button_ok,
                *w_button_cancel;

    QLabel *w_label_question,
           *w_label_img;

    QVBoxLayout *l_vlay_root;

    QHBoxLayout *l_hlay_buttons;

    void createObjects();
    void initUI();
    void connectSignals();
};

#endif // DELETEWINDOW_H
