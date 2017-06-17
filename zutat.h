#ifndef ZUTAT_H
#define ZUTAT_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Zutat {
private:
  string name;
  int bwert;
public:
  Zutat(string, int=32);
  int brennwert() const;
  string get_name() const;
  bool operator==(const Zutat&);
  ostream& print(ostream&) const;
};
ostream& operator<<(ostream&, const Zutat&);
#endif
