#include <regex>

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

    return 0;
}