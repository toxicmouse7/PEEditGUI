//
// Created by Aleksej on 05.06.2022.
//

#ifndef PEEDITGUI_DATADIRECTORYEDITOR_HPP
#define PEEDITGUI_DATADIRECTORYEDITOR_HPP

#include <QWidget>
#include <QMessageBox>

#include "PortableExecutableInfo.hpp"
#include "Convert.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class DataDirectoryEditor; }
QT_END_NAMESPACE

class DataDirectoryEditor : public QWidget
{
Q_OBJECT

public:
    explicit DataDirectoryEditor(PortableExecutableInfo* peInfo, QWidget* parent = nullptr);

    ~DataDirectoryEditor() override;

private:
    Ui::DataDirectoryEditor* ui;
    PortableExecutableInfo* peInfo = nullptr;

public slots:
    void save();
};


#endif //PEEDITGUI_DATADIRECTORYEDITOR_HPP
