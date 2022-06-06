//
// Created by Aleksej on 06.06.2022.
//

#ifndef PEEDITGUI_SECTIONEDITOR_HPP
#define PEEDITGUI_SECTIONEDITOR_HPP

#include <QWidget>
#include <QMessageBox>

#include "PortableExecutableInfo.hpp"
#include "Convert.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class SectionEditor; }
QT_END_NAMESPACE

class SectionEditor : public QWidget
{
Q_OBJECT

public:
    explicit SectionEditor(PortableExecutableInfo* peInfo, int index, QWidget* parent = nullptr);

    ~SectionEditor() override;

private:
    Ui::SectionEditor* ui;
    PortableExecutableInfo* peInfo = nullptr;
    IMAGE_SECTION_HEADER* sectionHeader;

public slots:
    void save();
};


#endif //PEEDITGUI_SECTIONEDITOR_HPP
