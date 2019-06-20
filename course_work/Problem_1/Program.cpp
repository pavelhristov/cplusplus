#include "ConsoleReader.h"
#include "ConsoleWriter.h"
#include "FileWriter.h"
#include "FileReader.h"

#include "Program.h"

void Program::run(ConsoleReader& cReader, ConsoleWriter& cWriter,
        FileReader& fReader, FileWriter& fWriter) {
    Program program(cReader, cWriter, fReader, fWriter);
    program.initialaze();
    program.start();
}

