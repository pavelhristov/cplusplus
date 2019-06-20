/*
 *  Задача 1. Даден е масив "A" с максимална размерност M реда и М стълба.
 *  а) Да се създаде клас със следната функционалност поддържана от подпрограми 
 *          (методи) и необходимите свойства.
 *  -	въвеждане на елементите на масива при въведена стойност на N (текуща 
 *          размерност на масива) от клавиатурата;
 *  -	извеждане на елементите на масива под формата на таблица на екрана;
 *  -	съхраняване на масива в текстови файл;
 *  -	четене на масива от текстови файл;
 *  -	намиране на сума на елементите на масива;
 *  -	намиране на сумата на елементите по редове и записването им в 
 *          едномерен масив "B";
 *  -	намиране минимум и максимум на получения масив "B" от предходната точка;
 *
 *  б) Да се тества създаденият в предходната точка клас.
 */

#include <cstdlib>
#include <string>

#include "ConsoleReader.h"
#include "ConsoleWriter.h"
#include "FileWriter.h"
#include "FileReader.h"
#include "Program.h"

int main() {
    std::string filePath = "array.txt";
    ConsoleReader cReader;
    ConsoleWriter cWriter;
    FileWriter fWriter(filePath);
    FileReader fReader(filePath);

    Program::run(cReader, cWriter, fReader, fWriter);

    return 0;
}


