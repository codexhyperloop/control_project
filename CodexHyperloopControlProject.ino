struct {
	float position, velocity, acceleration;
} physicsData;

// Declare variables
int stage = 0; 
float startBrakingPosition;
physicsData essentialData;


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
	
	if (essentialData.velocity >= 10 && essentialData.acceleration >= 15) // Acceleration stage
	{
		stage = 1;
	} 
	else if (essentialData.position <= startBrakingPosition && essentialData.velocity >= ) // coasting
	{
		stage = 2;
	}
	else if (essentialData.position <=  && essentialData.velocity >= ) // activate magnetic braking
	{
		stage = 3;
	}
	else if (essentialData.position <=  && essentialData.velocity >= ) // Lift levitation arrays
	{
		stage = 4;
	}
	else if (essentialData.position <=  && essentialData.velocity >= 80 ) // Activate disk brakes (at 60 or 80 m/s)
	{
		stage = 5;
	}
	else if (essentialData.position <=  && essentialData.velocity >= 8) //Deactivate magnetic brakes (at 6 or 8 m/s)
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
