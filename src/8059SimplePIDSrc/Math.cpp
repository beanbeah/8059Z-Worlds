#include "main.h"
double boundRad(double rad){
  double res = fmod(rad, twoPI);
  if(res < 0) res += twoPI;
  return res;
}
double boundDeg(double deg){
  double res = fmod(deg, 360);
  if(res < 0) res += 360;
  return res;
}
double boundDegTurn(double deg){
  double res = boundDeg(deg);
  if(res>180) res -= 360;
  return res;
}
double boundRadTurn(double rad){
  double res = boundRad(rad);
  if(res > PI) res -= twoPI;
  return res;
}
double abscap(double x, double abscap){
  if(x > abscap) return abscap;
  else if(x < -abscap) return -abscap;
  else return x;
}
int sign(double x){
  if(fabs(x) <= 1/1e9) return 0;
  else if(x > 0) return 1;
  else return -1;
}