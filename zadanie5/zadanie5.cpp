#include <ctime>
#include <fstream>

enum State {SEVERE = 0, WARNING = 1, INFO = 2, CONFIG = 3, FINE = 4, FINER = 5, FINEST = 6};
class Dziennik
{
private:
    State _currentState;

public:
    void GetCurrentState () {
        switch(_currentState)
        {
            case SEVERE     : std::cout << "SEVERE\n";      break;
            case WARNING    : std::cout << "WARNING\n";     break;
            case INFO       : std::cout << "INFO\n";        break;
            case CONFIG     : std::cout << "CONFIG\n";      break;
            case FINE       : std::cout << "FINE\n";        break;
            case FINER      : std::cout << "FINER\n";       break;
            case FINEST     : std::cout << "FINEST\n";      break;
        }
    }

    void SetState (State _state) {
        _currentState = _state;
    }

    void Print (std::string message) {
        std::time_t now = std::time(nullptr);
        std::string timestamp = ctime(&now);
        switch(_currentState)
        {
            case SEVERE     : std::cout << timestamp << "   [SEVERE] "  +  message  +  '\n';    break;
            case WARNING    : std::cout << timestamp << "   [WARNING] " +  message  +  '\n';    break;
            case INFO       : std::cout << timestamp << "   [INFO] "    +  message  +  '\n';    break;
            case CONFIG     : std::cout << timestamp << "   [CONFIG] "  +  message  +  '\n';    break;
            case FINE       : std::cout << timestamp << "   [FINE] "    +  message  +  '\n';    break;
            case FINER      : std::cout << timestamp << "   [FINER] "   +  message  +  '\n';    break;
            case FINEST     : std::cout << timestamp << "   [FINEST] "  +  message  +  '\n';    break;
        }
    }

    void Print (std::string sciezka, std::string message) {
        std::fstream plik_0;
        plik_0.open(sciezka, std::ios_base::app);

        std::time_t now = std::time(nullptr);
        std::string timestamp = ctime(&now);
        switch(_currentState)
        {
            case SEVERE     : plik_0 << timestamp << "    [SEVERE] "   +  message  +  '\n';     break;
            case WARNING    : plik_0 << timestamp << "    [WARNING] "  +  message  +  '\n';     break;
            case INFO       : plik_0 << timestamp << "    [INFO] "     +  message  +  '\n';     break;
            case CONFIG     : plik_0 << timestamp << "    [CONFIG] "   +  message  +  '\n';     break;
            case FINE       : plik_0 << timestamp << "    [FINE] "     +  message  +  '\n';     break;
            case FINER      : plik_0 << timestamp << "    [FINER] "    +  message  +  '\n';     break;
            case FINEST     : plik_0 << timestamp << "    [FINEST] "   +  message  +  '\n';     break;
        }
        plik_0.close();
    }
};




int zadanie5_main() {
    std::string sciezka = "./plik_0.txt";

    Dziennik* log = new Dziennik;
    log->SetState(WARNING);
    log->Print("przykladowa wiadomosc");
    log->SetState(FINER);
    log->Print("wiadomosc powinna byc w finer");
    log->Print(sciezka, "to powinno sie wpisac do pliku");
    log->SetState(SEVERE);
    log->Print(sciezka, "najwyzszy stan");



    delete log;
    log = nullptr;
    return 0;
}