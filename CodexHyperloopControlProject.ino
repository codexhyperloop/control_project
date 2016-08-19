// Declare variables
int stage = 0;

void setup()
{	
	// -------------------------------------------------------------------
	// Make sure the Control UDOO is receiving sensor data from Read UDOO
	// -------------------------------------------------------------------
	
	// Temperature, Voltage, Current
	
	// Accelerometer
	
	// Proximity
	
	// Light
	
	// Encoder
	
	// Make sure levitation and magnetic arrays are movable
	
	// --------------------------------------------------------
	// Make sure communication link is made to remote computer 	
	// --------------------------------------------------------

	// Send green light signal to remote computer

}

void loop()
{
	// Get critical info (velocity and pod position) only and determine logic stage
	
	
	
	// Get other data every 1000 iterations (and send to remote computer?)
	
	
	switch (stage) {
		case 0: { // Pre-launch stage 
			//preLaunchLoop();
		};
		break;
		
		case 1: { // First stage - Acceleration 
			accelerationStage();
		};
		break;
		
		case 2: { // Second stage - Coasting
			coastingStage();
		};
		break;
		
		case 3: { // Third stage - Braking (Magnetic & Friction)
			brakingStage();
		}
		break;
		
		default:
		break;
	}
}
