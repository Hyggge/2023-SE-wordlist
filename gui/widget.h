#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <string>
#include <QLineEdit>
#include <QPushButton>
#include "Constant.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    int inputMode = SCREEN_INPUT_MODE;
    int taskType = N_TASK;
    char hOption = '\0';
    char jOption = '\0';
    char tOption = '\0';
    bool rOption = false;
    char* selectedFileName = nullptr;
    bool lastStatus = false;

};
#endif // WIDGET_H
