typedef struct {
	float position, velocity, acceleration;
} physicsData;

// Declare variables
int stage = 0; 
float startBrakingPosition = 750; // The position at which we need to start braking
bool magBrakesActivated = LOW; // Lets us know when the magnetic brakes have finished activating
bool levArraysLifted = HIGH; // Lets us know when the levitation arrays are lifted
physicsData essentialData; // Current position, velocity, and acceleration


void setup()
{	
	// -------------------------------------------------------------------
	// Make sure the Control UDOO is receiving sensor data from Read UDOO
	// -------------------------------------------------------------------
	
	// Temperature, Voltage, Current (possibly unnecessary?)
	
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
	// --> measured in m, m/s, m/s^2 respectively
	essentialData.position = 1; // really will be something like - essentialData.position = readUDOO.position; or something like that idk
    essentialData.velocity = 1;
	essentialData.acceleration = 1;
	 
	if ((essentialData.acceleration >= 15 /* || spaceX.begun */) && stage == 0) // Acceleration stage
	{	// If acceleration is greater than 15 m/s^2 or if spaceX gives us the signal that the run has begun
		stage = 1;
		/* spaceX.begun = LOW; */
	} 
	else if ((essentialData.acceleration <= 5 /* || spaceX.done */) && stage == 1) // coasting
	{   // If acceleration falls below 5 m/s^2 or if spaceX gives us the signal that they stopped pushing our pod
		stage = 2;
		/* spaceX.done = LOW; */
	}
	else if (essentialData.position >= startBrakingPosition && stage == 2) // activate magnetic braking
	{   // If we have reached the calculated position to start braking, then start braking
		stage = 3;
	}
	else if (magBrakesActivated && stage == 3) // Lift levitation arrays
	{
		stage = 4;
	}
	else if (essentialData.velocity <= 80 && levArraysLifted && stage == 4) // Activate disk brakes (at 60 or 80 m/s)
	{
		stage = 5;
	}
	else if (essentialData.velocity <= 8 && stage == 5) //Deactivate magnetic brakes (at 6 or 8 m/s)
	{
		stage = 6;
	}
	
		
	// Get other data every ¿1000? iterations (and send to remote computer?)
	// Check voltage, temperature, and current
	
	
	switch (stage) {
		case 0: { // Pre-launch stage - For waiting period.
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
		
		case 3: { // Third stage - Activate magnetic brakes
			activateMagneticBrakes();
		}
		break;
		
		case 4: { // Fourth stage - Lift levitation arrays
			liftLevitationArrays();
		}
		break;
		
		case 5: { // Fifth stage - Activate disk brakes (at 60 or 80 m/s)
			activateDiskBrakes();
		}
		break;
		
		case 6: { // Sixth stage - Deactivate magnetic brakes (at 6 or 8 m/s)
			deactivateMagneticBrakes();
		}
		break;
		
		default:
		break;
	}
}
