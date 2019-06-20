#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> StringToVector(std::string theString, char separator) {
    std::vector<std::string> vecsWords;
    std::stringstream ss(theString);
    std::string sIndivStr;

    while (getline(ss, sIndivStr, separator)) {
        vecsWords.push_back(sIndivStr);
    }

    return vecsWords;
}

std::string intArrayToString(int array[], int arraySize, char separator) {
    std::ostringstream oss("");
    for (int i = 0; i < arraySize; i++) {
        oss << array[i];
        if (i < arraySize - 1) {
            oss << separator;
        }
    }

    return oss.str();
}
