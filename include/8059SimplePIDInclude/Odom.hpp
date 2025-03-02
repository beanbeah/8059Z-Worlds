#ifndef _8059_SIMPLE_PID_ODOM_HPP_
#define _8059_SIMPLE_PID_ODOM_HPP_
extern double X, Y, bearing, angle;
extern const double inPerDeg;
void setCoords(double x, double y, double b);
void Odometry(void * ignore);
#endif