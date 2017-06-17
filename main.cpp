#include"smoothie.h"
using namespace std;

int main()
{
    Zutat z1{"Apfel"};
    try
    {
        Zutat z1{""};
        cout << "Error 1\n";
    }
    catch (runtime_error& e)
    {
        cout << "Leerer Name nicht erlaubt!\n";
    }
    try
    {
        Zutat z2("Abfel", 200);
        cout << "Error 2\n";
    }
    catch (runtime_error& e)
    {
        cout << "Brennwert zu hoch!\n";
    }
    try
    {
        Zutat z2("Apfel", 0);
        cout << "Error 3\n";
    }
    catch (runtime_error& e)
    {
        cout << "Brennwert zu niedrig!\n";
    }
    cout << (z1==Zutat{"Apfel", 12}) << (Zutat{"Birne"}==z1) << (z1==Zutat{"Apfel", 32}) << '\n';
    cout << z1.brennwert() << Zutat{"Birne", 17} .brennwert() << '\n';
    cout << Zutat{"Birne", 17} << z1 << '\n';
    try
    {
        Smoothie s{""};
        cout << "Error 3\n";
    }
    catch (runtime_error& e)
    {
        cout << "Smoothie muss eine Bezeichung haben!\n";
    }
    Smoothie s{"Turm von Hanoi"};
    s.hinzu(Zutat{"Apfel"});
    s.hinzu(Zutat{"Birne",31});
    s.hinzu(Zutat{"Apfel",32});
    cout << s << ", " << s.brennwert() << '\n';
    cerr << s << '\n';

    //Dekommentieren fuer Zusatzbeispiel unterheben

    s.unterheben(Zutat{"Banane", 40});
    cout << s << '\n';
    try
    {
        Smoothie{"Test"} .unterheben(z1);
        cout << "Error 4\n";
    }
    catch (runtime_error& e)
    {
        cout << "Unterheben nicht moeglich!\n";
    }


    //Dekommentieren fuer Zusatzbeispiel liste
    
    s.liste(cout);
    cout << '\n';
    s.liste(cerr);
    cerr << '\n';

    return 0;
}
