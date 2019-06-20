#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <map>
#include <vector>
#include <functional>
#include <sstream>
#include <iterator>

#include "MinMax.h"
#include "Matrix.h"
#include "ConsoleReader.h"
#include "ConsoleWriter.h"
#include "FileWriter.h"
#include "FileReader.h"

class Program {
private:
    ConsoleReader cReader;
    ConsoleWriter cWriter;
    FileReader fReader;
    FileWriter fWriter;
    Matrix matrix;

    const std::string PRINT_TO_CMD = "print-cmd";
    const std::string POPULATE_FROM_CMD = "populate-cmd";
    const std::string PRINT_TO_FILE = "print-file";
    const std::string POPULATE_FROM_FILE = "populate-file";
    const std::string CHANGE_FILEPATH = "change-file";
    const std::string GET_ROWS_SUM = "sum-rows";
    const std::string GET_SUM = "sum";
    const std::string GET_MIN_AND_MAX_FROM_ROWS_SUM = "min-max";
    const std::string HELP = "help";
    const std::string EXIT = "exit";

    std::map<std::string, std::function<void() >> mapFunctions;

    void initialaze() {
        this->mapFunctions[this->PRINT_TO_CMD] = [&] {
            this->matrix.print(this->cWriter);
        };
        this->mapFunctions[this->POPULATE_FROM_CMD] = [&] {
            this->populateCmd();
        };
        this->mapFunctions[this->PRINT_TO_FILE] = [&] {
            this->printFile();
        };
        this->mapFunctions[this->POPULATE_FROM_FILE] = [&] {
            this->populateFile();
        };
        this->mapFunctions[this->CHANGE_FILEPATH] = [&] {
            this->changeFile();
        };
        this->mapFunctions[this->GET_ROWS_SUM] = [&] {
            this->getRowsSum();
        };
        this->mapFunctions[this->GET_SUM] = [&] {
            int sum = this->matrix.getSum();
            this->cWriter.printLine("Sum of all elements in the matrix = " +
                    std::to_string(sum));
        };
        this->mapFunctions[this->GET_MIN_AND_MAX_FROM_ROWS_SUM] = [&] {
            this->getMinMax();
        };
        this->mapFunctions[this->HELP] = [&] {
            this->showHelp();
        };
    };

    void start() {
        this->setSize();
        std::string command = this->HELP;

        while (command != this->EXIT) {
            if (this->mapFunctions.count(command) == 1) {
                this->mapFunctions[command]();
            } else {
                cWriter.printLine(
                        "Invalid command. Use 'help' for commands list.");
            }

            command = cReader.readLine();
        }

        this->cWriter.printLine("Program terminating...");
    };

    void setSize() {
        this->cWriter.printLine("Maximum size is set to " + std::to_string(M)
                + " and size can not be lower then 1");
        this->cWriter.printLine("Set length(N) for the matrix: ");
        int length = 0;
        try {
            length = std::stoi(cReader.readLine());
        } catch (const char* ex) {
            // for some reason stoi under cygwin only terminates programs if
            // fails to convert with success
            this->cWriter.printLine(ex);
        }

        if (length < 1 || length > M) {
            this->cWriter.printLine("Size must be between 1 and " +
                    std::to_string(M));
            this->setSize();
        } else {
            this->matrix.setLength(length);
        }
    };

    void populateCmd() {
        this->cWriter.printLine("Provide values for the matrix each item "
                "separated by whitespace and each row on new line:");
        this->matrix.insertValue(this->cReader);
        this->cWriter.printLine("Matrix populated");
    };

    void populateFile() {
        this->cWriter.printLine("Matrix data will be populated from '" +
                this->fReader.getFilePath() +
                "' if exists. To change use '" + this->CHANGE_FILEPATH + "'.");
        this->matrix.insertValue(this->fReader);
        this->cWriter.printLine("Matrix populated");
    };

    void printFile() {
        this->cWriter.printLine("Matrix data will be saved in '" +
                this->fWriter.getFilePath() +
                "'. To change use '" + this->CHANGE_FILEPATH + "'.");
        this->matrix.print(this->fWriter);
    };

    void changeFile() {
        this->cWriter.printLine("File path: ");
        std::string filePath = this->cReader.readLine();
        this->fReader.setFilePath(filePath);
        this->fWriter.setFilePath(filePath);
        this->cWriter.printLine("File path set to '" + filePath + "'.");
    };

    void getRowsSum() {
        std::vector<int> sumByRows = this->matrix.getSumByRows();

        std::stringstream result;
        std::copy(sumByRows.begin(), sumByRows.end(),
                std::ostream_iterator<int>(result, " "));
        this->cWriter.printLine(result.str());
    };

    void getMinMax() {
        std::vector<int> sumByRows = this->matrix.getSumByRows();
        MinMax minMax = MinMax::getMinMaxValue(sumByRows);
        this->cWriter.printLine("Min sum = " + std::to_string(minMax.min));
        this->cWriter.printLine("Max sum = " + std::to_string(minMax.max));
    };

    void showHelp() {
        std::vector<std::string> help{
            "List of commands:",
            " - '" + this->PRINT_TO_CMD +
            "': Prints the matrix to the console.",
            " - '" + this->PRINT_TO_FILE + "': Prints the matrix to file",
            " - '" + this->POPULATE_FROM_CMD +
            "': Populates the matrix from console input",
            " - '" + this->POPULATE_FROM_FILE +
            "': Populates the matrix from file if exits",
            " - '" + this->CHANGE_FILEPATH +
            "': Changes file directory for read and write operations",
            " - '" + this->GET_ROWS_SUM +
            "': Prints sum of each row to console",
            " - '" + this->GET_SUM +
            "': Prints all sum of all elements in the matrix to console",
            " - '" + this->GET_MIN_AND_MAX_FROM_ROWS_SUM +
            "': Prints min and max of row sums to console",
            " - '" + this->HELP + "': Shows list with commands",
            " - '" + this->EXIT + "': Closes the program"};

        this->cWriter.printLines(help);
    };

    Program(ConsoleReader& cReader, ConsoleWriter& cWriter,
            FileReader& fReader, FileWriter& fWriter) {
        this->cReader = cReader;
        this->cWriter = cWriter;
        this->fReader = fReader;
        this->fWriter = fWriter;
    };

    ~Program() {
    };

public:

    static void run(ConsoleReader& cReader, ConsoleWriter& cWriter,
            FileReader& fReader, FileWriter& fWriter);
};

#endif /* PROGRAM_H */

