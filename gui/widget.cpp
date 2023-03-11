#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 绑定fileInputRadio的点击事件
    connect(ui->fileInputRadio, &QRadioButton::clicked, this, [&]() {
        inputMode = FILE_INPUT_MODE;
        ui->screenInputBox->setEnabled(false);
        ui->chooseFileButton->setEnabled(true);
    });
    // 绑定screenInputRadio的点击事件
    connect(ui->screenInputRadio, &QRadioButton::clicked, this, [&]() {
        inputMode = SCREEN_INPUT_MODE;
        ui->screenInputBox->setEnabled(true);
        ui->chooseFileButton->setEnabled(false);
    });
    // 绑定chooseFileButton的点击事件
    connect(ui->chooseFileButton, &QPushButton::clicked, this, [&]() {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
        if (fileName != nullptr) {
            strcpy(selectedFileName, fileName.toStdString().c_str());
            ui->label->setText(fileName);
        }
    });
    // 绑定nOptionRadio的点击事件
    connect(ui->nOptionRadio, &QRadioButton::clicked, this, [&]() {
        taskType = N_TASK;
        ui->additionGroup->setEnabled(false);
        ui->hOptionInput->setEnabled(false);
        ui->tOptionInput->setEnabled(false);
        ui->jOptionInput->setEnabled(false);
        qDebug() << "nOptionRadio clicked";
    });
    // 绑定wOptionRadio的点击事件
    connect(ui->wOptionRadio, &QRadioButton::clicked, this, [&]() {
        taskType = W_TASK;
        ui->additionGroup->setEnabled(true);
        ui->hOptionInput->setEnabled(true);
        ui->tOptionInput->setEnabled(true);
        ui->jOptionInput->setEnabled(true);
        qDebug() << "wOptionRadio clicked";
    });
    // 绑定cOptionRadio的点击事件
    connect(ui->cOptionRadio, &QRadioButton::clicked, this, [&]() {
        taskType = C_TASK;
        ui->additionGroup->setEnabled(true);
        ui->hOptionInput->setEnabled(true);
        ui->tOptionInput->setEnabled(true);
        ui->jOptionInput->setEnabled(true);
        qDebug() << "cOptionRadio clicked";
    });
    // 绑定hOptionInput的输入事件
    connect(ui->hOptionInput, &QLineEdit::textChanged, this, [&](QString text) {
        if (text.isEmpty() || text.toStdString().c_str()[0] == ' ') {
            hOption = '\0';
        } else {
            hOption = text.toStdString().c_str()[0];
        }
        qDebug() << hOption;
    });
    // 绑定tOptionInput的输入事件
    connect(ui->tOptionInput, &QLineEdit::textChanged, this, [&](QString text) {
        if (text.isEmpty() || text.toStdString().c_str()[0] == ' ') {
            tOption = '\0';
        } else {
            tOption = text.toStdString().c_str()[0];
        }
        qDebug() << tOption;
    });
    // 绑定jOptionInput的输入事件
    connect(ui->jOptionInput, &QLineEdit::textChanged, this, [&](QString text) {
        if (text.isEmpty() || text.toStdString().c_str()[0] == ' ') {
            jOption = '\0';
        } else {
            jOption = text.toStdString().c_str()[0];
        }
        qDebug() << jOption;
    });
    // 绑定rOptionInput的选择事件
    connect(ui->rOptionSelect, &QComboBox::currentTextChanged, this, [&](QString text) {
        if (ui->rOptionSelect->currentIndex() == 0) {
            rOption = true;
        } else {
            rOption = false;
        }
        qDebug() << rOption;
    });
    // 绑定startButton的点击事件
    connect(ui->startButton, &QPushButton::clicked, this, &Widget::work);
    // 绑定exportButton的点击事件
    connect(ui->exportButton, &QPushButton::clicked, this, [&]() {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));
        QTextCodec *code = QTextCodec::codecForName("UTF-8");
        fileName = QString::fromStdString(code->fromUnicode(fileName).data());
        if (fileName != nullptr) {
            qDebug() << fileName.toStdString().c_str();
            FILE* file = fopen(fileName.toStdString().c_str(), "w");
            if (file == nullptr) {
                QMessageBox::critical(this, "出错啦!", "指定路径的文件无法打开");
            } else {
                fputs(ui->outputBox->toPlainText().toStdString().c_str(), file);
            }
            fclose(file);
        }
    });
}

void Widget::work() {
    // todo:修改lastStatus, 并且设置导出按钮的可用性
}

Widget::~Widget()
{
    delete ui;
}

