#include <iostream>
#include <string>
using namespace std;

int i = -1;
string s;

int getSymbol()
{
    i = i + 1;
    return s[i];
}

bool state24() {
    char symbol = getSymbol();
    if (symbol == '\0') return true;
    return false;
}

bool state23() {
    char symbol = getSymbol();
    if (symbol == '}') return state24();
    return false;
}

bool state22() {
    char symbol = getSymbol();
    if (symbol == ';') return state23();
    return false;
}

bool state21() {
    char symbol = getSymbol();
    if ((symbol >= 'a' && symbol <= 'z') || (symbol >= '0' && symbol <= '9')) return state22();
    return false;
}

bool state20() {
    char symbol = getSymbol();
    if ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/')) return state21();
    return false;
}

bool state19() {
    char symbol = getSymbol();
    if (symbol == '+') return state22();
    return false;
}

bool state18() {
    char symbol = getSymbol();
    if ((symbol >= 'a' && symbol <= 'z') || (symbol >= '0' && symbol <= '9')) return state20();
    return false;
}

bool state17() {
    char symbol = getSymbol();
    if (symbol == '=') return state18();
    if (symbol == '+') return state19();
    return false;
}

bool state16() {
    char symbol = getSymbol();
    if (symbol >= 'a' && symbol <= 'z') return state17();
    return false;
}

bool state15() {
    char symbol = getSymbol();
    if (symbol == ':') return state16();
    return false;
}

bool state14() {
    char symbol = getSymbol();
    if (symbol >= '0' && symbol <= '9') return state15();
    return false;
}

bool state25() {
    char symbol = getSymbol();
    if (symbol == ' ') return state14();
    return false;
}

bool state13() {
    char symbol = getSymbol();
    if (symbol == 'e') return state25();
    return false;
}

bool state12() {
    char symbol = getSymbol();
    if (symbol == 's') return state13();
    return false;
}

bool state11() {
    char symbol = getSymbol();
    if (symbol == 'a') return state12();
    return false;
}

bool state10() {
    char symbol = getSymbol();
    if (symbol == 'c') return state11();
    return false;
}

bool state9() {
    char symbol = getSymbol();
    if (symbol == '{') return state10();
    return false;
}

bool state8() {
    char symbol = getSymbol();
    if (symbol == ')') return state9();
    return false;
}

bool state7() {
    char symbol = getSymbol();
    if (symbol >= 'a' && symbol <= 'z') return state8();
    return false;
}

bool state6() {
    char symbol = getSymbol();
    if (symbol == '(') return state7();
    return false;
}

bool state5() {
    char symbol = getSymbol();
    if (symbol == 'h') return state6();
    return false;
}

bool state4() {
    char symbol = getSymbol();
    if (symbol == 'c') return state5();
    return false;
}

bool state3() {
    char symbol = getSymbol();
    if (symbol == 't') return state4();
    return false;
}

bool state2() {
    char symbol = getSymbol();
    if (symbol == 'i') return state3();
    return false;
}

bool state1() {
    char symbol = getSymbol();
    if (symbol == 'w') return state2();
    return false;
}

bool state0() {
    char symbol = getSymbol();
    if (symbol == 's') return state1();
    return false;
}


int main()
{
    cout << "Enter a string to be checked by the parser: ";
    getline(cin, s);
    if (state0()) cout << "String entered correctly\n";
    else cout << "Error\n";
    system("pause");
    return 0;
}