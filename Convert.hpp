//
// Created by Aleksej on 06.06.2022.
//

#ifndef PEEDITGUI_CONVERT_HPP
#define PEEDITGUI_CONVERT_HPP

#include <stdexcept>
#include <QString>

class Convert
{
private:
    static int getBase(const QString& string)
    {
        if (string.startsWith("0x")) return 16;
        else return 10;
    }

public:

    static unsigned long parseDword(const QString& string)
    {
        int base = getBase(string);

        bool ok;
        auto result = string.toULong(&ok, base);

        if (!ok) throw std::runtime_error("Parse error. Incorrect DWORD " + string.toStdString());

        return result;
    }

    static unsigned short parseWord(const QString& string)
    {
        int base = getBase(string);

        bool ok;
        auto result = string.toUShort(&ok, base);

        if (!ok) throw std::runtime_error("Parse error. Incorrect WORD " + string.toStdString());

        return result;
    }
};

#endif //PEEDITGUI_CONVERT_HPP
