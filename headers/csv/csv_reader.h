//
// Created by mrnotgramatika on 5/25/25.
//

#ifndef CSV_READER_H
#define CSV_READER_H
#include <fstream>

#include "../utils/loop.h"

class CSV_Reader {
public:
    CSV_Reader() = default;
    constexpr CSV_Reader(const std::string& fileName) { open(fileName); }

    constexpr bool isOpen() const { return m_File.is_open(); }
    constexpr bool isEOF() const { return m_File.eof(); }

    constexpr std::string getLastLine() const { return m_lastLine; }

    constexpr bool open(const std::string& fileName) {
        m_File.open(fileName);

        return m_File.is_open();
    }
    constexpr bool close() {
        if (!m_File.is_open()) return false;

        m_File.close();
        return !m_File.is_open();
    }

    constexpr std::string read(const char delim = '\n') {
        if (!m_File.is_open()) return "";

        std::string line;
        if (std::getline(m_File, line, delim)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();

            return m_lastLine = line;
        }
        return m_lastLine = "";
    }

    constexpr std::string readLine() { return read('\n'); }
    constexpr std::string readAll() { return read('\0'); }

private:
    std::string m_lastLine;
    std::ifstream m_File;
};



#endif //CSV_READER_H
