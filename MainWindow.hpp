//
// Created by Aleksej on 05.06.2022.
//

#ifndef PEEDITGUI_MAINWINDOW_HPP
#define PEEDITGUI_MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>

#include "NTEditor.hpp"

#include "PortableExecutableInfo.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow* ui;

    PortableExecutableInfo* peInfo = nullptr;
    QString filename;

public slots:

    void getPEFileName();

    void analyzePE();

    void save();

    void openNTHeadersEditor();

    void allowSave();

signals:

    void fileNameReady();
};


#endif //PEEDITGUI_MAINWINDOW_HPP
