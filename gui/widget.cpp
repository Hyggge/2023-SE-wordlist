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
    // 修改lastStatus, 并且设置导出按钮的可用性
    ui->exportButton->setEnabled(false);

    // 设置buffer, 指向输入文本
    char * data = nullptr;
    int size = 0;
    if (inputMode == FILE_INPUT_MODE) {
        FILE* file = fopen(selectedFileName, "r");
        if (file == nullptr) {
            QMessageBox::critical(this, "出错啦!", "指定路径的文件无法打开");
            return;
        }
        fseek(file, 0, SEEK_END);
        size = (int)ftell(file);
        fseek(file, 0, SEEK_SET);
        data = (char*)malloc(( + 1) * sizeof(char));
        fread(data, sizeof(char), size, file);
        fclose(file);
    } else {
        size = ui->screenInputBox->toPlainText().size();
        data = (char*)malloc((size + 1) * sizeof(char));
        strcpy(data, ui->screenInputBox->toPlainText().toStdString().c_str());
    }

    // 对输入文本进行解析
    std::vector<char> buffer;
    char* words[20005];
    int wordsNum = 0;
    for (int i = 0; i < size; ++i) {
        char ch = data[i];
        if (isalpha(ch)) {
            buffer.push_back((char)tolower(ch));
        } else if (! isalpha(ch) && ! buffer.empty()) {
            int len = (int)buffer.size();
            words[wordsNum] = (char*)malloc((len + 1) * sizeof(char));
            for (int j = 0; j < len; ++j) {
                words[wordsNum][j] = buffer[j];
            }
            words[wordsNum][len] = '\0';
            wordsNum++;
            buffer.clear();
        }
    }
    if (! buffer.empty()) {
        int len = (int)buffer.size();
        words[wordsNum] = (char*)malloc((len + 1) * sizeof(char));
        for (int j = 0; j < len; ++j) {
            words[wordsNum][j] = buffer[j];
        }
        words[wordsNum][len] = '\0';
        wordsNum++;
        buffer.clear();
    }

    // 调用Core函数
    char *result[MAX_WORD_LENGTH] = {nullptr};
    int resultLen = 0;
    clock_t startTime, endTime;
    char totTime[10];
    try {
        startTime = clock();
        if (taskType == N_TASK) {
            resultLen = gen_chains_all(words, wordsNum, result);
        } else if (taskType == W_TASK) {
            resultLen = gen_chain_word(words, wordsNum, result, hOption, tOption, jOption, rOption);
        } else if (taskType == C_TASK) {
            resultLen = gen_chain_char(words, wordsNum, result, hOption, tOption, jOption, rOption);
        }
        endTime = clock();
    } catch (std::exception &e) {
        QMessageBox::critical(this, "出错啦!", "输入文本中隐含环");
        return;
    }

    // 显示任务执行的时间
    sprintf_s(totTime, "%.2f", (double)(endTime - startTime) / CLOCKS_PER_SEC);
    qDebug() << (double)(endTime - startTime) / CLOCKS_PER_SEC;
    ui->totTimeDisplay->setText(totTime);

    // 如果没有找到结果, 则弹出错误提示
    if (resultLen <= 0) {
        QMessageBox::critical(this, "出错啦!", "没有找到任何结果");
        return;
    }

    // 如果找到了结果, 则将结果输出到输出框
    ui->outputBox->clear();
    if (taskType == N_TASK) {
        ui->outputBox->append(QString::fromStdString(std::to_string(resultLen)));
    }
    for (int i = 0; i < resultLen; ++i) {
        ui->outputBox->append(QString::fromStdString(result[i]));
    }

    // 当前输出了结果，所以设置导出按钮为可用状态
    ui->exportButton->setEnabled(true);

    // 内存释放
    free(data);
    for(int i = 0; i < wordsNum; ++i) {
        free(words[i]);
    }
    for (int i = 0; i < resultLen; ++i) {
        free(result[i]);
    }

}

Widget::~Widget()
{
    delete ui;
}

