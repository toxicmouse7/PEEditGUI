//
// Created by Aleksej on 05.06.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_NTEditor.h" resolved

#include "NTEditor.hpp"
#include "ui_NTEditor.h"


NTEditor::NTEditor(PortableExecutableInfo* peInfo, QWidget* parent) :
        QWidget(parent), ui(new Ui::NTEditor), peInfo(peInfo)
{
    ui->setupUi(this);

    ui->peSignEdit->setText("0x" + QString::number(peInfo->ntHeaders.Signature, 16));

    QDateTime time;
    time.setSecsSinceEpoch(peInfo->ntHeaders.FileHeader.TimeDateStamp);
    ui->dateTimeEdit->setDateTime(time);

    ui->sizeOfOptHeaderEdit->setText(QString::number(peInfo->ntHeaders.FileHeader.SizeOfOptionalHeader));
    ui->noSectionsEdit->setText(QString::number(peInfo->ntHeaders.FileHeader.NumberOfSections));
    ui->charsEdit->setText("0x" + QString::number(peInfo->ntHeaders.FileHeader.Characteristics, 16));
    ui->imgBaseEdit->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.ImageBase, 16));
    ui->entryEdit->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.AddressOfEntryPoint, 16));
    ui->secAlignEdit->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.SectionAlignment, 16));
    ui->fileAlignEdit->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.FileAlignment, 16));
    ui->sizeOfImageEdit->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.SizeOfImage, 16));
    ui->sizeOfHeadersEdit->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.SizeOfHeaders, 16));
    ui->subsystemEdit->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.Subsystem, 16));
    ui->rvaAndSizesEdit->setText(QString::number(peInfo->ntHeaders.OptionalHeader.NumberOfRvaAndSizes));

    connect(ui->dataDirButton, &QPushButton::pressed,
            this, &NTEditor::openDataDirectoryEditor);

    connect(ui->sectionTableButton, &QPushButton::pressed,
            this, &NTEditor::openSectionTableEditor);

    connect(ui->saveButton, &QPushButton::pressed,
            this, &NTEditor::save);
}

NTEditor::~NTEditor()
{
    delete ui;
}

void NTEditor::openDataDirectoryEditor()
{
    dataDirEditor = new DataDirectoryEditor(peInfo);
    dataDirEditor->show();
}

void NTEditor::openSectionTableEditor()
{
    sectionTableEditor = new SectionTableEditor(peInfo);
    sectionTableEditor->show();
}

void NTEditor::save()
{
    try
    {
        peInfo->ntHeaders.Signature = Convert::parseDword(ui->peSignEdit->text());
        peInfo->ntHeaders.FileHeader.TimeDateStamp = ui->dateTimeEdit->dateTime().toSecsSinceEpoch();
        peInfo->ntHeaders.FileHeader.SizeOfOptionalHeader = Convert::parseWord(ui->sizeOfOptHeaderEdit->text());
        peInfo->ntHeaders.FileHeader.NumberOfSections = Convert::parseWord(ui->noSectionsEdit->text());
        peInfo->ntHeaders.FileHeader.Characteristics = Convert::parseWord(ui->charsEdit->text());
        peInfo->ntHeaders.OptionalHeader.ImageBase = Convert::parseDword(ui->imgBaseEdit->text());
        peInfo->ntHeaders.OptionalHeader.AddressOfEntryPoint = Convert::parseDword(ui->entryEdit->text());
        peInfo->ntHeaders.OptionalHeader.SectionAlignment = Convert::parseDword(ui->secAlignEdit->text());
        peInfo->ntHeaders.OptionalHeader.FileAlignment = Convert::parseDword(ui->fileAlignEdit->text());
        peInfo->ntHeaders.OptionalHeader.SizeOfImage = Convert::parseDword(ui->sizeOfImageEdit->text());
        peInfo->ntHeaders.OptionalHeader.SizeOfHeaders = Convert::parseDword(ui->sizeOfHeadersEdit->text());
        peInfo->ntHeaders.OptionalHeader.Subsystem = Convert::parseWord(ui->subsystemEdit->text());
        peInfo->ntHeaders.OptionalHeader.NumberOfRvaAndSizes = Convert::parseDword(ui->rvaAndSizesEdit->text());
    }
    catch (std::exception& e)
    {
        QMessageBox::warning(this, tr("Parse error"), e.what());
        return;
    }

    QMessageBox::information(this, tr("Success"), tr("Saved"));
}

void NTEditor::closeEvent(QCloseEvent* event)
{
    emit closed();

    return QWidget::closeEvent(event);
}

