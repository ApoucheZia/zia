//
// Created by mart_- on 05/01/17.
//

#include <iostream>
#include "Logger.hh"

void apouche::Logger::debug(const std::string &message) {
    write("[DEBUG] " + message);
}

void apouche::Logger::error(const std::string &message) {
    write("[ERROR] " + message);
}

void apouche::Logger::fatal(const std::string &message) {
    write("[FATAL] " + message);
}

void apouche::Logger::info(const std::string &message) {
    write("[INFO] " + message);
}

void apouche::Logger::warning(const std::string &message) {
    write("[WARNING] " + message);
}

void apouche::Logger::write(const std::string &message) {
    std::cerr << message << std::endl;
}
