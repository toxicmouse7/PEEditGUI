//
// Created by Aleksej on 06.06.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SectionEditor.h" resolved

#include "SectionEditor.hpp"
#include "ui_SectionEditor.h"


SectionEditor::SectionEditor(PortableExecutableInfo* peInfo, int index, QWidget* parent) :
        QWidget(parent), ui(new Ui::SectionEditor), peInfo(peInfo)
{
    ui->setupUi(this);

    sectionHeader = &peInfo->sections[index];

    ui->nameEdit->setText((char*) sectionHeader->Name);
    ui->charsEdit->setText("0x" + QString::number(sectionHeader->Characteristics, 16));
    ui->noLinenumbersEdit->setText("0x" + QString::number(sectionHeader->NumberOfLinenumbers, 16));
    ui->noRelocsEdit->setText("0x" + QString::number(sectionHeader->NumberOfRelocations, 16));
    ui->ptrToRawDataEdit->setText("0x" + QString::number(sectionHeader->PointerToRawData, 16));
    ui->ptrToRelocsEdit->setText("0x" + QString::number(sectionHeader->PointerToRelocations, 16));
    ui->ptrToLinenumsEdit->setText("0x" + QString::number(sectionHeader->PointerToLinenumbers, 16));
    ui->sizeOfRawDataEdit->setText("0x" + QString::number(sectionHeader->SizeOfRawData, 16));
    ui->vSizeEdit->setText("0x" + QString::number(sectionHeader->Misc.VirtualSize, 16));
    ui->vaEdit->setText("0x" + QString::number(sectionHeader->VirtualAddress, 16));

    connect(ui->saveButton, &QPushButton::pressed,
            this, &SectionEditor::save);
}

SectionEditor::~SectionEditor()
{
    delete ui;
}

void SectionEditor::save()
{
    if (ui->nameEdit->text().length() > 7)
    {
        QMessageBox::warning(this, tr("Warning"), tr("Name length must be < 8"));
        ui->nameEdit->setText("");
        return;
    }

    memcpy_s(&(sectionHeader->Name), IMAGE_SIZEOF_SHORT_NAME,
             ui->nameEdit->text().toStdString().c_str(), ui->nameEdit->text().size());

    try
    {
        sectionHeader->VirtualAddress = Convert::parseDword(ui->vaEdit->text());
        sectionHeader->Characteristics = Convert::parseDword(ui->charsEdit->text());
        sectionHeader->NumberOfRelocations = Convert::parseWord(ui->noRelocsEdit->text());
        sectionHeader->NumberOfLinenumbers = Convert::parseWord(ui->noLinenumbersEdit->text());
        sectionHeader->PointerToLinenumbers = Convert::parseDword(ui->ptrToLinenumsEdit->text());
        sectionHeader->PointerToRelocations = Convert::parseDword(ui->ptrToRelocsEdit->text());
        sectionHeader->PointerToRawData = Convert::parseDword(ui->ptrToRawDataEdit->text());
        sectionHeader->SizeOfRawData = Convert::parseDword(ui->sizeOfRawDataEdit->text());
        sectionHeader->Misc.VirtualSize = Convert::parseDword(ui->vSizeEdit->text());
    }
    catch (std::exception& e)
    {
        QMessageBox::warning(this, tr("Parse error"), e.what());
        return;
    }

    QMessageBox::information(this, tr("Success"), tr("Saved"));
}

