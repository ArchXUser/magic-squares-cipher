#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class EncryptionMode { Encode, Decode };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void convertButton();
    void setEncodeMode();
    void setDecodeMode();
    void toggleConvertButton();

private:
    Ui::MainWindow *ui;
    EncryptionMode encryptor_mode;
};
#endif // MAINWINDOW_H
