#include "main.h"
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
	//initSelector(); //display selector, q hard to do ngl
	/** declaration and initialization of motors, encoders and controller */
	Motor FL (FLPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor BL (BLPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor FR (FRPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor BR (BRPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor lRoller (lRollerPort, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
	Motor rRoller (rRollerPort, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES);
	Motor shooter (shooterPort, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
	Motor indexer (indexerPort, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES);
	Controller master(E_CONTROLLER_MASTER);
	ADIDigitalIn intakeColor(intakeColorPort);
	ADIDigitalIn shootColor(shootColorPort);
	Rotation lRot(lRotPort);
	Rotation rRot(rRotPort);
	/**
	master.clear();
	bool autonlock = false;
	while(!autonlock){
		static const std::string display_name[] = {"Blue-Midl","Red-Midl", "Red-SAFE", "Blue-SAFE"};
  		master.print(0,0,"Auton: %s", display_name[autonNum].c_str());
  		delay(50);

  		if (master.get_digital_new_press(DIGITAL_B)){

    	autonNum+=1;
    	autonNum = autonNum % 4;
  		}
  		else if (master.get_digital_new_press(DIGITAL_X))autonlock=true;
  		printf("autonNum: %d", autonNum);
  		delay(5);
  		}

	*/
	lRot.reset_position();
	rRot.reset_position();
	rRot.set_reversed(true);
	FL.set_brake_mode(E_MOTOR_BRAKE_COAST);
	BL.set_brake_mode(E_MOTOR_BRAKE_COAST);
	FR.set_brake_mode(E_MOTOR_BRAKE_COAST);
	BR.set_brake_mode(E_MOTOR_BRAKE_COAST);
	/** declaration and initialization of asynchronous Tasks */
	Task ControlTask(Control);
	Task DebugTask(Debug);
	Task OdometryTask(Odometry);
	Task SensorsTask(Sensors);
	Task MechControlTask(MechControl);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	// while(imu.is_calibrating()) delay(5);
	/** numerical choice of which autonomous set to run */
	setCoords(0, 0, 0);
	driveMode = false;
	double start = millis();
	/**
	autonNum = 2;
	switch (autonNum){
		case 0: test(); break;
		case 1: blue(); break;
		case 2: red(); break;
		case 3: redSafe(); break;
		case 4: blueSafe(); break;
		default: red(); break;
	}
	*/
	red();
	printf("Time used: %.2f seconds\n", (millis() - start)/1000);
	Controller master(E_CONTROLLER_MASTER);
	double final = (millis() - start)/1000;
	while(true) master.print(0, 0, "Time: %.2f\n ", final);
}
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
 void opcontrol() {
 	/** declare references to motors and controller */
 	Motor FL (FLPort);
 	Motor BL (BLPort);
 	Motor FR (FRPort);
 	Motor BR (BRPort);
 	Motor lRoller (lRollerPort);
 	Motor rRoller (rRollerPort);
 	Motor indexer (indexerPort);
 	Motor shooter (shooterPort);
 	Controller master(E_CONTROLLER_MASTER);
 	master.clear();
 	/** boolean flag for whether the driver uses tank drive or not */
 	bool tankDrive = true;
	autoIndex = false;

 	while (true) {
 		driveMode=true;
 		if(!COMPETITION_MODE){

		if(master.get_digital_new_press(DIGITAL_Y)) tankDrive = !tankDrive;
		if(master.get_digital_new_press(DIGITAL_X)) autonomous();

		}

		if(master.get_digital_new_press(DIGITAL_A)) autoIndex = !autoIndex;
 		if(tankDrive){
       double l = master.get_analog(ANALOG_LEFT_Y);
       double r = master.get_analog(ANALOG_RIGHT_Y);
       FL.move(l);
       BL.move(l);
       FR.move(r);
       BR.move(r);
     }
	else{
       double x = master.get_analog(ANALOG_LEFT_X);
       double y = master.get_analog(ANALOG_RIGHT_Y);
       FL.move(y+x);
       BL.move(y+x);
       FR.move(y-x);
       BR.move(y-x);
     }

 		pros::delay(5);
 	}
 }
