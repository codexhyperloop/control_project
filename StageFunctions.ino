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
}

// Third Stage - Braking (Magnetic & Friction)
int brakeStage = 0;
void brakingStage () {
	// Determine which braking stage we're in
	
	switch (brakeStage) {
		case 0: { 	// Activate magnetic braking


					// PID loops using encoder, proximity sensor 
					
					// stop at 0.1 inches from I-beam
		}; 
		break;
		
		case 1: { // Lift levitation array
			// PID loops using proximity data and encoder 
			
			// stop when distance (0.1 inches) from I beam
		}; 
		break;
		 
		case 2: { // activate disk brakes (60 or 80 m/s)
 			
		};
		break;
		
		case 3: { // stop magnetic brakes ( 6 or 8 m/s)
			
				  //  stop when distance is 1.0962 inches from the I-beam
		};
		break;
		
	}
	 // concern- having a set brake position might not work depending on speed variability, must consider the distance needed to brake. 
	
	// Lower Magnetic brakes 
	
	// Activate disk brakes
	
	
	// Stop Magnetic brakes
}