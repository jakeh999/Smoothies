#include "zutat.h"

Zutat::Zutat(string name, int bwert) {
  if (static_cast<int>(name.size()) < 1) {
    throw runtime_error("Name nicht erlaubt!");
  }
  if ((bwert < 10) || (bwert > 75)) {
    throw runtime_error("Brennwert nicht erlaubt!");
  }
  this->name = name;
  this->bwert = bwert;
}

int Zutat::brennwert() const {
  return this->bwert;
}

string Zutat::get_name() const {
  return this->name;
}

bool Zutat::operator==(const Zutat& z) {
  return ((this->bwert==z.brennwert()) && (this->name==z.get_name()));
}

ostream& Zutat::print(ostream& o) const {
  o << '[' << this->name << ' ' << this->bwert << " kJ]";
  return o;
}

ostream& operator<<(ostream& o, const Zutat& z) {
  return z.print(o);
}
