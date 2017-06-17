#include "smoothie.h"

Smoothie::Smoothie(string b) {
  if (static_cast<int>(b.size()) > 0) {
    this->bezeichnung = b;
  } else {
    throw runtime_error("bezeichnung nicht erlaubt!");
  }
}

void Smoothie::hinzu(const Zutat& z) {
  this->zutaten.push_back(z);
}

int Smoothie::brennwert() const {
  if (this->zutaten.empty()) {
    throw runtime_error("Keine Zutaten!");
  }
  int summe_brennwert = 0;
  for (size_t i {0}; i < this->zutaten.size(); i++) {
    summe_brennwert += this->zutaten.at(i).brennwert();
  }
  return summe_brennwert;
}

void Smoothie::unterheben(const Zutat& z) {
  if (this->zutaten.empty()) {
    throw runtime_error("Keine Zutaten!");
  }
  for (int i {0}; i < static_cast<int>(this->zutaten.size()); i+=2) {
    this->zutaten.insert(this->zutaten.begin()+i, z);
  }
}

void Smoothie::liste(ostream& o) const {
  if (this->zutaten.empty()) {
    throw runtime_error("Keine Zutaten!");
  }
  vector<pair<Zutat, int>> v;
  for (const auto& it : this->zutaten) {
    bool found = false;
    for (size_t i {0}; i < v.size(); i++) {
      if (v.at(i).first == it) {
        v.at(i) = {v.at(i).first, v.at(i).second+1};
        found = true;
      }
    }
    if (!found) {
      v.push_back({it, 1});
    }
   }
  bool first = true;
  for (const auto& it : v) {
    if (!first) {
      o << ", ";
    }
    o << it.first << "*" << it.second;
    first = false;
  }
}

ostream& Smoothie::print(ostream& o) const {
  o << "[{";
  bool first = true;
  for (size_t i {0}; i < this->zutaten.size(); i++) {
    if (!first) {
      o << ", ";
    }
    o << this->zutaten.at(i);
    first = false;
  }
  o << "}, " << this->bezeichnung << ']';
  return o;
}

ostream& operator<<(ostream& o, const Smoothie& s) {
  return s.print(o);
}
