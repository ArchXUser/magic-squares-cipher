#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "textencryptor.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->convertButton->setDisabled(true);
    ui->encodeRadioButton->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::convertButton()
{
    TextEncryptor encryptor;

    if (encryptor_mode == EncryptionMode::Encode) {
        ui->output->setPlainText(encryptor.encrypt(ui->input->toPlainText()));
    }
    else {
        ui->output->setPlainText(encryptor.decrypt(ui->input->toPlainText()));
    }
}

void MainWindow::setEncodeMode()
{
    encryptor_mode = EncryptionMode::Encode;
}

void MainWindow::setDecodeMode()
{
    encryptor_mode = EncryptionMode::Decode;
}

void MainWindow::toggleConvertButton()
{
    if (not ui->input->toPlainText().isEmpty()) {
        ui->convertButton->setDisabled(false);
    }
    else {
        ui->convertButton->setDisabled(true);
    }
}
