//
// Created by Julien Karst on 05/01/2017.
//

#include "FileLogger.hh"

/*
apouche::FileLogger::~FileLogger() {
}*/

apouche::FileLogger::FileLogger() {
    _filename = "server.log";
    _file.open(_filename);
}

apouche::FileLogger::FileLogger(const std::string &file) {
    _filename = file;
    _file.open(_filename);
}

void apouche::FileLogger::clearFile() {
    _file.close();
    _file.open(_filename, std::ios::out | std::ios::trunc);
    _file << "";
}

void apouche::FileLogger::write(const std::string &message) {
    if (_file.is_open()) {
        _file << message << std::endl;
        _file.flush();
    }
}
