#include <iostream>
#include "FoliumOfDescrates.h"
#include <math.h>

namespace lab2{
FOD::FOD() {
    n = 1;
}

FOD::FOD(double m){
  if (m == 0)
     throw "Invalid input";
  n = m;
}

FOD& FOD::set(double n0){
    if (n0 == 0)
      throw "Invalid input";
    n = n0;
    return *this;
}

double FOD::DistanceInPolarSystem(double alpha) const {
    double res;
    res = (n*sin(alpha)*cos(alpha))/(sin(alpha)*sin(alpha)*sin(alpha) + cos(alpha)*cos
            (alpha)*cos(alpha));
    return abs(res);
}

double FOD::SideOfSquare() const{
  return abs(n)/sqrt(2);
}

double FOD::RadiusOfCurvatureTop() const{
  return n/(8*sqrt(2));
}

double FOD::RadiusOfCurvatureKnot() const{
  return n/2;
}

double FOD::AreaOfList() const{
  return 1.5*(n/3)*(n/3);
}

double FOD::LoopDiameter() const{
  return (abs(n)*sqrt(2)*sqrt(2*sqrt(3)-3))/3;
}

double FOD::DistanceFromLoopDiameter() const{
  return abs(n)/sqrt(6);
}

double FOD::get() const{
  return n;
}
}
