#include <cstdlib>
#include <string>
#include <iostream>

std::string CaeserCipher(std::string theString, int shifts, bool isEncrypting);

int main() {

    std::string theString = "Make me secret";
    std::string encrypted = CaeserCipher(theString, 5, true);
    std::string decrypted = CaeserCipher(encrypted, 5, false);
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}

std::string CaeserCipher(std::string theString, int shifts, bool isEncrypting) {
    std::string result = "";

    if (!isEncrypting) {
        shifts *= -1;
    }

    int charCode = 0;
    char letter;
    for (char ch : theString) {
        //result += (char) ((int) ch + shifts);
        if (isalpha(ch)) {
            charCode = (int) ch;
            charCode += shifts;

            if (isupper(ch)) {
                if (charCode > (int) 'Z') {
                    charCode -= 26;
                } else if (charCode < (int) 'A') {
                    charCode += 26;
                }
            } else {
                if (charCode > (int) 'z') {
                    charCode -= 26;
                } else if (charCode < (int) 'a') {
                    charCode += 26;
                }
            }

            letter = charCode;
        } else {
            letter = ch;
        }

        result += letter;
    }

    return result;
}
