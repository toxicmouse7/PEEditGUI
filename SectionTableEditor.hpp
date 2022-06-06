//
// Created by Aleksej on 06.06.2022.
//

#ifndef PEEDITGUI_SECTIONTABLEEDITOR_HPP
#define PEEDITGUI_SECTIONTABLEEDITOR_HPP

#include <QWidget>

#include "PortableExecutableInfo.hpp"
#include "SectionEditor.hpp"
#include "IndexButton.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class SectionTableEditor; }
QT_END_NAMESPACE

class SectionTableEditor : public QWidget
{
Q_OBJECT

public:
    explicit SectionTableEditor(PortableExecutableInfo* peInfo, QWidget* parent = nullptr);

    ~SectionTableEditor() override;

private:
    Ui::SectionTableEditor* ui;
    PortableExecutableInfo* peInfo = nullptr;

public slots:
    void editSection();
};


#endif //PEEDITGUI_SECTIONTABLEEDITOR_HPP
