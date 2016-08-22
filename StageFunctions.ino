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
}

// --------------------------------------------------------
// concern- having a set brake position might not work depending on speed variability, must consider the distance needed to brake.
// --------------------------------------------------------

// Third Stage - Activate magnetic brakes
void activateMagneticBrakes () {
	// PID loops using encoder, proximity sensor
	
	// stop at 0.1 inches from I-beam
}

// Fourth Stage - Lift levitation arrays
void liftLevitationArrays () {
	// PID loops using proximity data and encoder
	
	// stop when distance (0.1 inches) from I beam
}

// Fifth Stage - Activate disk brakes (at 60 or 80 m/s)
void activateDiskBrakes () {
	
}

// Sixth Stage - Stop magnetic brakes (at 6 or 8 m/s)
void deactivateMagneticBrakes () {
	//  stop when distance is 1.0962 inches from the I-beam
}