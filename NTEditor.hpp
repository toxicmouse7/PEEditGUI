//
// Created by Aleksej on 05.06.2022.
//

#ifndef PEEDITGUI_NTEDITOR_HPP
#define PEEDITGUI_NTEDITOR_HPP

#include <QWidget>
#include <QTime>

#include "PortableExecutableInfo.hpp"
#include "DataDirectoryEditor.hpp"
#include "SectionTableEditor.hpp"
#include "Convert.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class NTEditor; }
QT_END_NAMESPACE

class NTEditor : public QWidget
{
Q_OBJECT

public:
    explicit NTEditor(PortableExecutableInfo* peInfo, QWidget* parent = nullptr);

    ~NTEditor() override;

private:
    Ui::NTEditor* ui;
    PortableExecutableInfo* peInfo;
    DataDirectoryEditor* dataDirEditor = nullptr;
    SectionTableEditor* sectionTableEditor = nullptr;

    void closeEvent(QCloseEvent* event) override;

public slots:

    void openDataDirectoryEditor();

    void openSectionTableEditor();

    void save();

signals:
    void closed();

};


#endif //PEEDITGUI_NTEDITOR_HPP
