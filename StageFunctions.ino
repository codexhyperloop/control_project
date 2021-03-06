// Pre-launch
void preLaunchLoop () {
	// Probably don't need this function... but maybe
}

// First Stage - Acceleration
void accelerationStage(/*getproximitydata here and use it in the function*/) {
	
	/* how do you lower it down? 
		use the proximity sensor to do this and check this with this data. 
	
	// Lower levitation array to 2.8 inches 
	
	// PID loops using proximity data and encoder 
	 if(getproximitydata==2.8)
	 
	 */
}

// Second Stage - Coasting
void coastingStage () {
	// Make sure levitation arrays are in the right position
		//Monitoring should be done at all times in the main loop
	
	// Determine when and where to brake based on velocity and position (will need to know mass and friction coefficient)
	
	//!!!!!!**************************Theoretical braking distance (will need engineers to modify)*******************************!!!!!!
	//int brakeDistance = (essentialData.velocity * essentialData.velocity)/(2 * frictionK * gravity) ;

	//Calculate track position to brake
	//int stopLocation = (trackLength - brakeDistance - safety);
	
	//int formula = 3/*this 3 needs to be replaced with some formula to calculate when we need to brake*/;
	//startBrakingPosition = formula;
}

// Third Stage - Activate magnetic brakes
void activateMagneticBrakes () {
	// Not entirely sure how this will work. We may not be controlling magnet
	// position using the stepper motors bc they may not have enough power
	
	// PID loops using encoder, proximity sensor
	
//PID_activateMagneticBrakes.Compute();
	
	
	// stop at 0.1 inches from I-beam
	if (3/* mag brakes are fully activated*/) {
		magBrakesActivated = HIGH;
	}
}

// Fourth Stage - Lift levitation arrays
void liftLevitationArrays () {
	// PID loops using proximity data and encoder
	
	// stop when distance (0.1 inches) from I beam
	if (3/* levitation arrays have been lifted */) {
		levArraysLifted = HIGH;
	}
}

// Fifth Stage - Activate disk brakes (at 60 or 80 m/s)
void activateDiskBrakes () {
	// PID encoders to keep all 4 wheels braking equally, ABS (Anti-Lock Braking System)
}

// Sixth Stage - Stop magnetic brakes (at 6 or 8 m/s)
void deactivateMagneticBrakes () {
	//  stop when distance is 1.0962 inches from the I-beam
}