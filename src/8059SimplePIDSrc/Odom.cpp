#include "main.h"
/*-----------------------------------------USER INPUT-----------------------------------------*/
const double baseWidth = 10.51829263080055; //Enter distance in inches between side encoders
const double inPerDeg = 0.000242496919917864458; //Determine empirically using at least 1 rotation


//assume robot programmed 50 inches, moved 48 inches, real life 47 inches. 
//47/48 * whatever value we have

//assume we turn the robot 7 times, 7 *360 degrees, robot value is 6.5 * 360. ratio
/*--------------------------------------------------------------------------------------------*/
double X = 0, Y = 0, bearing = 0, angle = halfPI, prevEncdL = 0, prevEncdR = 0;
void setCoords(double x, double y, double b){
  X = x;
  Y = y;
  bearing = b*toRad;
}
void Odometry(void * ignore){
  double changeX = 0, changeY = 0, changeBearing = 0;
  while(!COMPETITION_MODE || competition::is_autonomous()){
    double encdChangeL = encdL-prevEncdL;
    double encdChangeR = encdR-prevEncdR;

    double distance = (encdChangeL + encdChangeR)/2*inPerDeg;
    changeBearing = (encdChangeL - encdChangeR)*inPerDeg/baseWidth;
    changeX = distance * cos(angle);
    changeY = distance * sin(angle);
    /** update prev variables */
    X += changeX;
    Y += changeY;
    bearing += changeBearing;
    angle = halfPI - bearing;
    prevEncdL = encdL;
    prevEncdR = encdR;
    Task::delay(5);
  }
}