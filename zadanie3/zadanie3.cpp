#include <regex>
#include <string>
#include <bitset>

std::string intToHex (int num) {
    std::stringstream res;
    res << std::hex << num;
    return res.str();
}

std::string intToBin (int num) {
    std::string res;
    std::bitset<8> b1(num);
    res = b1.to_string();
    return res;
}

void convertAndPrint (std::string ip, std::string mask) {
    std::string hexIP;
    std::string binIP;
    std::string hexMask;
    std::string binMask;
    std::string hexSubNet;
    std::string binSubNet;
    std::string decSubNet;

    int ipArr[4];
    int maskArr[4];
    int subNetArr[4];

    int start = 0;
    int len = ip.find('.');
    int size = ip.size();
    int i = 0;
    while (start < size) {
        std::string part = ip.substr(start, len);
        start += part.size() + 1;
        len = ip.find('.', start) - start;

        ipArr[i] = std::stoi(part);
        binIP += intToBin(ipArr[i]);
        hexIP += intToHex(ipArr[i]);
        if (i != 3) {
            binIP += '.';
            hexIP += '.';
        }
        i++;
    }

    int startM = 0;
    int lenM = mask.find('.');
    int sizeM = mask.size();
    int iM = 0;
    while (startM < sizeM) {
        std::string partM = mask.substr(startM, lenM);
        startM += partM.size() + 1;
        lenM = mask.find('.', startM) - startM;

        maskArr[iM] = std::stoi(partM);
        binMask += intToBin(maskArr[iM]);
        hexMask += intToHex(maskArr[iM]);
        if (iM != 3) {
            binMask += '.';
            hexMask += '.';
        }
        iM++;
    }

    for (int j = 0; j < 4; j++) {
        std::bitset<8> res = std::bitset<8>(ipArr[j]) & std::bitset<8>(maskArr[j]);
        subNetArr[j] = res.to_ulong();
        binSubNet += res.to_string();
        hexSubNet += intToHex(subNetArr[j]);
        decSubNet += std::to_string(subNetArr[j]);
        if (j != 3) {
            binSubNet += '.';
            hexSubNet += '.';
            decSubNet += '.';
        }
    }

    // wypisywanie
    std::cout << "system dziesietny: \n" << "IPv4:           " << ip << '\n' << "Maska:          " << mask << '\n' << "Adres podsieci: " << decSubNet << "\n\n";
    std::cout << "system dwojkowy: \n" << "IPv4:           " << binIP << '\n' << "Maska:          " << binMask << '\n' << "Adres podsieci: " << binSubNet << "\n\n";
    std::cout << "system szesnastkowy: \n" << "IPv4:           " << hexIP << '\n' << "Maska:          " << hexMask << '\n' << "Adres podsieci: " << hexSubNet << "\n\n";

}

std::string inputIP () {
    std::string str;
    std::regex ipReg ("([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])[.]"
                      "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])[.]"
                      "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])[.]"
                      "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
    std::cout << "Wprowadz adres IPv4: \n";
    std::cin >> str;
    while (!std::regex_match(str, ipReg)) {
        std::cout << "Wprowadz poprawny adres IPv4: \n";
        std::cin >> str;
    }
    return str;
}

std::string inputMask () {
    std::string str;
    std::regex maskReg ("((128|192|224|240|248|252|254|255)[.]0[.]0[.]0)|"
                        "(255[.](128|192|224|240|248|252|254|255)[.]0[.]0)|"
                        "(255[.]255[.](128|192|224|240|248|252|254|255)[.]0)|"
                        "(255[.]255[.]255[.](128|192|224|240|248|252|254|255))");
    std::cout << "Wprowadz maske podsieci: \n";
    std::cin >> str;
    while (!std::regex_match(str, maskReg)) {
        std::cout << "Wprowadz poprawna maske podsieci: \n";
        std::cin >> str;
    }
    return str;
}



int zadanie3_main () {      //glowna funkcja dla zadania 3 (przez to w main.cpp mozna wywolac tylko jedna funkcje w celu przetestowania zadania)
    std::string ip = inputIP();
    std::string mask = inputMask();

    convertAndPrint(ip, mask);

    return 0;
}