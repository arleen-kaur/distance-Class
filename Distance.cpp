#include <iostream>
using namespace std;
#include "Distance.h"

 Distance::Distance() {
     _feet = 0;
     _inches = 0.0;
 }
 Distance::Distance(unsigned ft, double in) {
    _feet = ft;
    _inches = in;
    init();
 }
Distance::Distance(double in) {
    _feet = 0;
    _inches = in;
    init();
}
unsigned Distance::getFeet() const {
    return _feet;
}
double Distance::getInches() const {
    return _inches;
}
double Distance::distanceInInches() const {
    return (_feet * 12) + _inches;
}
double Distance::distanceInFeet() const {
    return (_inches / 12) + _feet;
}
double Distance::distanceInMeters() const {
    return ((_feet * 12) + _inches) * .0254;
}
Distance Distance::operator+(const Distance &rhs) const {
    double totalInches = distanceInInches() + rhs.distanceInInches();
    return Distance(totalInches);
}
Distance Distance::operator-(const Distance &rhs) const {
    double totalInches = distanceInInches() - rhs.distanceInInches();
    if (totalInches < 0) {
        totalInches = totalInches * -1;
    }
    return Distance(totalInches);
}
ostream & operator<<(ostream &out, const Distance &rhs) {
    out << rhs.getFeet() << "\' " << rhs.getInches() << "\"";
    return out;
}
void Distance::init() {
    if (_inches < 0) {
        _inches = _inches * -1;
    }
    if (_feet < 0) {
        _feet = _feet * -1;
    }
    while (_inches > 12) {
        _inches = _inches - 12;
        _feet = _feet + 1;
    }
}
    
