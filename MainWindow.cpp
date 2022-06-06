//
// Created by Aleksej on 05.06.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.hpp"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openFileButton, &QPushButton::pressed,
            this, &MainWindow::getPEFileName);

    connect(this, &MainWindow::fileNameReady,
            this, &MainWindow::analyzePE);

    connect(ui->ntButton, &QPushButton::pressed,
            this, &MainWindow::openNTHeadersEditor);

    connect(ui->saveButton, &QPushButton::pressed,
            this, &MainWindow::save);
}

MainWindow::~MainWindow()
{
    delete peInfo;
    delete ui;
}

void MainWindow::getPEFileName()
{
    filename = QFileDialog::getOpenFileName(this, tr("Open PE"),
                                                 "C:\\", tr("PE (*.exe *.dll)"));

    if (!filename.isEmpty()) emit fileNameReady();
}

void MainWindow::analyzePE()
{
    Architecture arch;

    try
    {
        arch = PEUtils::getFileArchitecture(filename.toStdString());
    }
    catch (std::exception&)
    {
        QMessageBox::warning(this, tr("Warning"), tr("Incorrect file structure"));
        return;
    }

    if (arch != x86)
    {
        QMessageBox::warning(this, tr("Warning"), tr("PE32+ is not supported"));
        return;
    }

    try
    {
        peInfo = new PortableExecutableInfo(filename.toStdString());
    }
    catch (std::exception& e)
    {
        QMessageBox::warning(this, tr("Warning"), tr(e.what()));
    }

    ui->ntButton->setEnabled(true);
}

void MainWindow::openNTHeadersEditor()
{
    auto editor = new NTEditor(peInfo);

    connect(editor, &NTEditor::closed,
            this, &MainWindow::allowSave);

    editor->show();

    ui->ntButton->setDisabled(true);
    ui->saveButton->setDisabled(true);
}

void MainWindow::save()
{
    std::ifstream peInput(filename.toStdString(), std::ios::binary);
    std::ofstream peOutput(filename.toStdString() + ".PEEdit", std::ios::binary);

    peOutput.write(reinterpret_cast<const char*>(&peInfo->dosHeader), sizeof(IMAGE_DOS_HEADER));

    for (int i = 0; i < peInfo->dosHeader.e_lfanew - sizeof(IMAGE_DOS_HEADER); ++i)
        peOutput << (BYTE)0;

    peOutput.write(reinterpret_cast<const char*>(&peInfo->ntHeaders), sizeof(IMAGE_NT_HEADERS32));
    for (auto& section : peInfo->sections)
        peOutput.write(reinterpret_cast<const char*>(&section), sizeof(IMAGE_SECTION_HEADER));
    peInput.seekg(peOutput.tellp());

    peOutput << peInput.rdbuf();

    QMessageBox::information(this, tr("Success"), tr("Saved"));
}

void MainWindow::allowSave()
{
    ui->ntButton->setEnabled(true);
    ui->saveButton->setEnabled(true);
}

