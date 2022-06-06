//
// Created by Aleksej on 06.06.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SectionTableEditor.h" resolved

#include "SectionTableEditor.hpp"
#include "ui_SectionTableEditor.h"


SectionTableEditor::SectionTableEditor(PortableExecutableInfo* peInfo, QWidget* parent) :
        QWidget(parent), ui(new Ui::SectionTableEditor), peInfo(peInfo)
{
    ui->setupUi(this);

    for (int i = 0; i < peInfo->sections.size(); ++i)
    {
        auto* button = new IndexButton;
        button->setText((char*)peInfo->sections[i].Name);
        ui->verticalLayout->addWidget(button);

        connect(button, &IndexButton::pressed,
                this, &SectionTableEditor::editSection);

        button->index = i;
    }

}

SectionTableEditor::~SectionTableEditor()
{
    delete ui;
}

void SectionTableEditor::editSection()
{
    auto editor = new SectionEditor(peInfo, ((IndexButton*)sender())->index);
    editor->show();
}

