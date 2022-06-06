//
// Created by Aleksej on 05.06.2022.
//

#pragma once

#ifndef PEEDITGUI_PORTABLEEXECUTABLEINFO_HPP
#define PEEDITGUI_PORTABLEEXECUTABLEINFO_HPP

#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>

enum Architecture
{
    x64,
    x86,
    undefined
};

class PEUtils
{
public:
    static Architecture getFileArchitecture(const std::string& filename)
    {
        std::ifstream file(filename, std::ios::binary);
        file.seekg(0x3c, std::ios::beg);

        DWORD e_lfanew;
        file.read(reinterpret_cast<char*>(&e_lfanew), sizeof(DWORD));
        file.seekg(e_lfanew + sizeof(DWORD), std::ios::beg); // NOLINT(cppcoreguidelines-narrowing-conversions)

        WORD machine;
        file.read(reinterpret_cast<char*>(&machine), sizeof(WORD));

        switch (machine)
        {
            case IMAGE_FILE_MACHINE_AMD64:
                return x64;
            case IMAGE_FILE_MACHINE_I386:
                return x86;
            default:
                return undefined;
        }
    };
};

struct PortableExecutableInfo
{
    IMAGE_DOS_HEADER dosHeader{0};
    IMAGE_NT_HEADERS32 ntHeaders{0};
    std::vector<IMAGE_SECTION_HEADER> sections;

    explicit PortableExecutableInfo(const std::string& filename)
    {
        std::ifstream peFile(filename, std::ios::binary);
        peFile.read(reinterpret_cast<char*>(&dosHeader), sizeof(IMAGE_DOS_HEADER));

        if (dosHeader.e_magic != IMAGE_DOS_SIGNATURE)
            throw std::runtime_error("Wrong DOS signature");

        peFile.seekg(dosHeader.e_lfanew, std::ios::beg);
        peFile.read(reinterpret_cast<char*>(&ntHeaders), sizeof(IMAGE_NT_HEADERS32));

        if (ntHeaders.Signature != IMAGE_NT_SIGNATURE)
            throw std::runtime_error("Wrong NT signature");

        sections.resize(ntHeaders.FileHeader.NumberOfSections);
        for (auto& section : sections)
        {
            peFile.read(reinterpret_cast<char*>(&section), sizeof(IMAGE_SECTION_HEADER));
        }
    }
};


#endif //PEEDITGUI_PORTABLEEXECUTABLEINFO_HPP
