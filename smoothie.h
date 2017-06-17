#ifndef SMOOTHIE_H
#define SMOOTHIE_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "zutat.h"
using namespace std;

class Smoothie {
private:
  string bezeichnung;
  vector<Zutat> zutaten;
public:
  Smoothie(string);
  void hinzu(const Zutat&);
  int brennwert() const;
  void unterheben(const Zutat&);
  void liste(ostream&) const;
  ostream& print(ostream&) const;
};
ostream& operator<<(ostream&, const Smoothie&);
#endif
