//
// Created by Aleksej on 05.06.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DataDirectoryEditor.h" resolved

#include "DataDirectoryEditor.hpp"
#include "ui_DataDirectoryEditor.h"


DataDirectoryEditor::DataDirectoryEditor(PortableExecutableInfo* peInfo, QWidget* parent) :
        QWidget(parent), ui(new Ui::DataDirectoryEditor), peInfo(peInfo)
{
    ui->setupUi(this);

    ui->size0->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[0].Size));
    ui->va0->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[0].VirtualAddress, 16));

    ui->size1->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[1].Size));
    ui->va1->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[1].VirtualAddress, 16));

    ui->size2->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[2].Size));
    ui->va2->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[2].VirtualAddress, 16));

    ui->size3->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[3].Size));
    ui->va3->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[3].VirtualAddress, 16));

    ui->size4->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[4].Size));
    ui->va4->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[4].VirtualAddress, 16));

    ui->size5->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[5].Size));
    ui->va5->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[5].VirtualAddress, 16));

    ui->size6->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[6].Size));
    ui->va6->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[6].VirtualAddress, 16));

    ui->size7->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[7].Size));
    ui->va7->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[7].VirtualAddress, 16));

    ui->size8->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[8].Size));
    ui->va8->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[8].VirtualAddress, 16));

    ui->size9->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[9].Size));
    ui->va9->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[9].VirtualAddress, 16));

    ui->size10->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[10].Size));
    ui->va10->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[10].VirtualAddress, 16));

    ui->size11->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[11].Size));
    ui->va11->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[11].VirtualAddress, 16));

    ui->size12->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[12].Size));
    ui->va12->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[12].VirtualAddress, 16));

    ui->size13->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[13].Size));
    ui->va13->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[13].VirtualAddress, 16));

    ui->size14->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[14].Size));
    ui->va14->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[14].VirtualAddress, 16));

    ui->size15->setText(QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[15].Size));
    ui->va15->setText("0x" + QString::number(peInfo->ntHeaders.OptionalHeader.DataDirectory[15].VirtualAddress, 16));

    connect(ui->saveButton, &QPushButton::pressed,
            this, &DataDirectoryEditor::save);
}

DataDirectoryEditor::~DataDirectoryEditor()
{
    delete ui;
}

void DataDirectoryEditor::save()
{
    try
    {
        peInfo->ntHeaders.OptionalHeader.DataDirectory[0].Size = Convert::parseDword(ui->size0->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[0].VirtualAddress = Convert::parseDword(ui->va0->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[1].Size = Convert::parseDword(ui->size1->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[1].VirtualAddress = Convert::parseDword(ui->va1->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[2].Size = Convert::parseDword(ui->size2->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[2].VirtualAddress = Convert::parseDword(ui->va2->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[3].Size = Convert::parseDword(ui->size3->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[3].VirtualAddress = Convert::parseDword(ui->va3->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[4].Size = Convert::parseDword(ui->size4->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[4].VirtualAddress = Convert::parseDword(ui->va4->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[5].Size = Convert::parseDword(ui->size5->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[5].VirtualAddress = Convert::parseDword(ui->va5->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[6].Size = Convert::parseDword(ui->size6->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[6].VirtualAddress = Convert::parseDword(ui->va6->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[7].Size = Convert::parseDword(ui->size7->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[7].VirtualAddress = Convert::parseDword(ui->va7->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[8].Size = Convert::parseDword(ui->size8->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[8].VirtualAddress = Convert::parseDword(ui->va8->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[9].Size = Convert::parseDword(ui->size9->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[9].VirtualAddress = Convert::parseDword(ui->va9->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[10].Size = Convert::parseDword(ui->size10->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[10].VirtualAddress = Convert::parseDword(ui->va10->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[11].Size = Convert::parseDword(ui->size11->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[11].VirtualAddress = Convert::parseDword(ui->va11->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[12].Size = Convert::parseDword(ui->size12->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[12].VirtualAddress = Convert::parseDword(ui->va12->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[13].Size = Convert::parseDword(ui->size13->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[13].VirtualAddress = Convert::parseDword(ui->va13->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[14].Size = Convert::parseDword(ui->size14->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[14].VirtualAddress = Convert::parseDword(ui->va14->text());

        peInfo->ntHeaders.OptionalHeader.DataDirectory[15].Size = Convert::parseDword(ui->size15->text());
        peInfo->ntHeaders.OptionalHeader.DataDirectory[15].VirtualAddress = Convert::parseDword(ui->va15->text());
    }
    catch (std::exception& e)
    {
        QMessageBox::warning(this, tr("Parse error"), e.what());
        return;
    }

    QMessageBox::information(this, tr("Success"), tr("Saved"));
}

