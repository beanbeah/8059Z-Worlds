/** Autonomous routines */
#include "main.h"

int autonNum = 0;	//initial declaration

/** programming skills run */
void test(){
	setCoords(0,0,30);	//25 degree offset
	baseTurn(90,1.35,0.95);
}
/** Autonomous routine for blue left spawn. */
void blue(){
	//goal 1
	//shoot
	setCoords(0,0,30);
	setMech(127,127);
	delay(200);

	//goal 2
	//get ball
	setMech(127,0);
	//delay(500);
	baseMove(28.6);
	waitBase(1000);	//check
	baseTurn(90,1.35,0.95);
	waitBase(800);
	baseMove(30.5);	//funny thing must check
	waitBase (1000);
	delay(850);
	//ram ball into centre
	baseTurn(0,1.35,0.95);
	waitBase(850);
	manualIndex();
	resetMech();
	baseMove(-24.7);
	waitBase(1200);

	//goal 3
	baseTurn(-48,1.45,0.85);
	waitBase(800);
	manualIndex();
	baseMove(69);
	waitBase(1550);
	manualIndex();
	setMech(-127,-127,0);
	delay(900);
	manualIndex();

	//goal 4
	baseMove(-74.5);
	waitBase(1250);
	baseTurn(-147.1); //tune kP & kD
	waitBase(1500);
	baseMove(105,0.0016,0);
	setMech(127,0);
	waitBase(1900);
	resetMech();
	delay(340);
	setMech(-127, 127, 127);
	delay(850);

}
void red(){
	//goal 1
	//shoot
	setCoords(0,0,30);
	setMech(127,127);
	delay(200);

	//goal 2
	//get ball
	setMech(127,0);
	//delay(500);
	baseMove(28.6);
	waitBase(1000);	//check
	baseTurn(90,1.35,0.95);
	waitBase(800);
	baseMove(30.5);	//funny thing must check
	waitBase (1000);
	delay(850);
	//ram ball into centre
	baseTurn(0,1.35,0.95);
	waitBase(850);
	manualIndex();
	resetMech();
	baseMove(-26);
	waitBase(1200);

	//goal 3
	baseTurn(-47.8,1.45,0.85);
	waitBase(800);
	manualIndex();
	baseMove(69);
	waitBase(1550);
	manualIndex();
	setMech(-127,-127,0);
	delay(900);
	manualIndex();

	//goal 4
	baseMove(-74.5);
	waitBase(1250);
	baseTurn(-144.1); //tune kP & kD
	waitBase(1300);
	baseMove(105);
	setMech(127,0);
	waitBase(1900);
	resetMech();
	setMech(-127,0);
	delay(450);
	resetMech();
	setMech(-127, 127, 127);
	delay(850);
}

void blueSafe(){
	setCoords(0, 0,0);
  //goal 1
  setMech(80,80,0,0);
  delay(40);
  baseMove(11);
  waitBase(700);
	manualIndex();
  setMech(0,107,127);
	delay(500);
	manualIndex();

  //goal 2
  resetMech();
  baseMove(-143.1);
  waitBase(1431);
  baseTurn(75);
  waitBase(750);

  baseMove(18);
  waitBase(450);
  setMech(0,127);
	delay(1500);

	//goal 3

	resetMech();
	baseMove(-24);
	waitBase(1000);
	baseTurn(137.2);
	waitBase(750);
	setMech(65,0);
	baseMove(69);
	waitBase(2340);
	delay(400);
	setMech(0,127);
	delay(2500);

}

void redSafe(){
	setCoords(0, 0,0);
	//goal 1
	setMech(80,0);
	delay(40);
	baseMove(11);
	waitBase(700);
	manualIndex();
	setMech(0,107,127);
	delay(500);
	manualIndex();

	//goal 2
	resetMech();
	baseMove(-143.1);
	waitBase(1431);
	baseTurn(75);
	waitBase(750);

	baseMove(18);
	waitBase(450);
	setMech(0,127);
	delay(1500);

	//goal 3

	resetMech();
	baseMove(-28);
	waitBase(1000);
	baseTurn(137.2);
	waitBase(750);
	setMech(52,0);
	baseMove(69);
	waitBase(2340);
	delay(400);
	setMech(0,127);
	delay(2500);
}
