
#define _USE_MATH_DEFINES
#include <cmath>



#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <memory>

// Basis-Klasse für Funktionen
class Funktion {
public:
    virtual double berechneWert(double t) const = 0;
    virtual ~Funktion() {}
};

// Sinus-Funktion
class Sinus : public Funktion {
    double amplitude;
    double frequenz;
public:
    Sinus(double a, double f) : amplitude(a), frequenz(f) {}
    double berechneWert(double t) const override {
        return amplitude * sin(2 * M_PI * frequenz * t);
    }
};

// Cosinus-Funktion
class Cosinus : public Funktion {
    double amplitude;
    double frequenz;
public:
    Cosinus(double a, double f) : amplitude(a), frequenz(f) {}
    double berechneWert(double t) const override {
        return amplitude * cos(2 * M_PI * frequenz * t);
    }
};

// Hauptprogramm
int main() {
    std::vector<std::shared_ptr<Funktion>> funktionen;
    int anzahlFunktionen;
    double abtastrate, anzahlPunkte;
    std::string dateiname;

    std::cout << "Anzahl der Funktionen (1-4): ";
    while (!(std::cin >> anzahlFunktionen) || anzahlFunktionen < 1 || anzahlFunktionen > 4) {
        std::cout << "Bitte eine gültige Anzahl zwischen 1 und 4 eingeben: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < anzahlFunktionen; ++i) {
        int funktionstyp;
        double amplitude, frequenz;
        std::cout << "Wählen Sie den Typ der Funktion (1: Sinus, 2: Cosinus): ";
        while (!(std::cin >> funktionstyp) || (funktionstyp != 1 && funktionstyp != 2)) {
            std::cout << "Bitte 1 für Sinus oder 2 für Cosinus eingeben: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Amplitude: ";
        while (!(std::cin >> amplitude) || amplitude <= 0) {
            std::cout << "Bitte eine positive Amplitude eingeben: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Frequenz: ";
        while (!(std::cin >> frequenz) || frequenz <= 0) {
            std::cout << "Bitte eine positive Frequenz eingeben: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (funktionstyp == 1) {
            funktionen.push_back(std::make_shared<Sinus>(amplitude, frequenz));
        }
        else {
            funktionen.push_back(std::make_shared<Cosinus>(amplitude, frequenz));
        }
    }

    std::cout << "Abtastrate (Ta): ";
    while (!(std::cin >> abtastrate) || abtastrate <= 0) {
        std::cout << "Bitte eine positive Abtastrate eingeben: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Anzahl der Punkte (N): ";
    while (!(std::cin >> anzahlPunkte) || anzahlPunkte <= 0) {
        std::cout << "Bitte eine positive Anzahl von Punkten eingeben: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Dateiname für CSV-Datei: ";
    std::cin >> dateiname;

    std::ofstream datei(dateiname);
    if (!datei.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei!" << std::endl;
        return 1;
    }

    datei << "Zeit";
    for (int i = 0; i < anzahlFunktionen; ++i) {
        datei << ",Funktion " << (i + 1);
    }
    datei << "\n";

    for (int i = 0; i < anzahlPunkte; ++i) {
        double t = i * abtastrate;
        datei << t;
        for (const auto& funktion : funktionen) {
            datei << "," << funktion->berechneWert(t);
        }
        datei << "\n";
    }std::string dateiname = "C:\\Users\\DeinBenutzername\\Desktop\\test1.csv";


    datei.close();
    std::cout << "Daten wurden erfolgreich in " << dateiname << " gespeichert." << std::endl;
    return 0;
}

