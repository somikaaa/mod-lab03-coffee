#include <iostream>
#include <vector>
#include <string>

enum class STATES {
    OFF, ON, READY, COOKING, FINISHED
};

class Automata {
private:
    double cash;
    std::vector<std::string> menu;
    std::vector<double> prices;
    STATES state;
    int choiceIndex;

public:
    Automata();
    void on();
    void off();
    void coin(double amount);
    void choice(int index);
    void check() const;
    void cancel();
    void cook();
    void finish();
};
