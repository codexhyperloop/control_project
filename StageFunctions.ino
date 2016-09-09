// Pre-launch
void preLaunchLoop () {
	// Probably don't need this function... but maybe
}

// First Stage - Acceleration
void accelerationStage () {
	// Lower levitation array to 2.8 inches 
	
	// PID loops using proximity data and encoder 
	
}

// Second Stage - Coasting
void coastingStage () {
	// Make sure levitation arrays are in the right position
	
	// Determine when and where to brake based on velocity and position
	int formula = 3/*this 3 needs to be replaced with some formula to calculate when we need to brake*/;
	startBrakingPosition = formula;
}

// Third Stage - Activate magnetic brakes
void activateMagneticBrakes () {
	// Not entirely sure how this will work. We may not be controlling magnet
	// position using the stepper motors bc they may not have enough power
	
	// PID loops using encoder, proximity sensor
	
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