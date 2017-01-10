//
// Created by Julien Karst on 05/01/2017.
//

#include "FileLogger.hh"

void FileLoggerTest() {
    apouche::FileLogger *logger;

    logger = new apouche::FileLogger("myFileLogger.log");
    logger->write("Write 1");
    logger->warning("This is a warning");
    logger->write("Write 2");
    delete(logger);
}

void FileLoggerTest2() {
    apouche::FileLogger *logger;

    logger = new apouche::FileLogger();
    logger->write("Write 1");
    logger->warning("This is a warning");
    logger->write("Write 2");
}

void FileLoggerTest3() {
    apouche::FileLogger *logger;

    logger = new apouche::FileLogger();
    logger->write("Write 1");
    logger->warning("This is a warning");
    logger->write("Write 2");
    logger->clearFile();
    logger->write("Write 3");
}