//Necessary for LSM9DS0 to communicate via SPI
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM9DS0.h>

//For PID loops
//#include <PID_v1.h>

typedef struct {
	float position, velocity, acceleration;
} physicsData;

// Declare variables
int stage = 0; 
float startBrakingPosition = 750; // The position at which we need to start braking
bool magBrakesActivated = LOW; // Lets us know when the magnetic brakes have finished activating
bool levArraysLifted = HIGH; // Lets us know when the levitation arrays are lifted

physicsData essentialData; // Current position, velocity, and acceleration

	// For LSM9DS0
		/* For Hardware SPI:
		SCK -> SPI CLK
		SDA -> SPI MOSI
		G_SDO + XM_SDO -> tied together to SPI MISO
		then select any two pins for the two CS lines:
		*/
		#define LSM9DS0_XM_CS 15
		#define LSM9DS0_GYRO_CS 14
		Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0(LSM9DS0_XM_CS, LSM9DS0_GYRO_CS, 1000);

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

// Object for PIDs
// PID PID_activateMagneticBrakes(&Input, &Output, &Setpoint,2,5,1, DIRECT);
// PID PID_liftLevitationArrays;
// PID PID_activateDiskBrakes;
// PID PID_deactivateMagneticBrakes;

void setup()
{	
	// -------------------------------------------------------------------
	// Make sure the Control UDOO is receiving sensor data from Read UDOO
	// -------------------------------------------------------------------
		
		// Temperature/Pressure & Voltage/Current (possibly unnecessary?)
		
		
	// -------------------------------------------------------------------
	// Make sure the Control UDOO is receiving sensor data from sensors
	// -------------------------------------------------------------------	
	
	// Accelerometer/Gyroscope - Reading directly from sensor via SPI
	
		#ifndef ESP8266
		while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
		#endif
		Serial.begin(9600);
		Serial.println(F("LSM9DS0 9DOF Sensor Test")); Serial.println("");
	
		/* Initialize the sensor */
		if(!lsm.begin())
		{
			/* There was a problem detecting the LSM9DS0 ... check your connections */
			Serial.print(F("Ooops, no LSM9DS0 detected ... Check your wiring or I2C ADDR!"));
			while(1);
		}
		Serial.println(F("Found LSM9DS0 9DOF"));
	
		/* Display some basic information on this sensor */
		displaySensorDetails();
	
		/* Setup the sensor gain and integration time */
		configureSensor();
	
		/* We're ready to go! */
		Serial.println("");
		
		
	// Proximity (Currently I2C - Will be SPI)
	
	// Light (I2C)
	
	// Encoder 
	
	// Make sure levitation and magnetic arrays are movable
	
	// --------------------------------------------------------
	// Make sure communication link is made to remote computer 	
	// --------------------------------------------------------

	// Send green light signal to remote computer

//
// PID_activateMagneticBrakes.SetMode(AUTOMATIC);

}

void loop()
{
		
	// --------------------------------------------------------	
	// Printing LSM9DS0 sensor data (Accelerometer/Gyroscope)
	// --------------------------------------------------------
		/* Get a new sensor event */
		sensors_event_t accel, mag, gyro, temp;

		lsm.getEvent(&accel, &mag, &gyro, &temp);

		// print out acceleration data
		Serial.print("Accel X: "); Serial.print(accel.acceleration.x); Serial.print(" ");
		Serial.print("  \tY: "); Serial.print(accel.acceleration.y);       Serial.print(" ");
		Serial.print("  \tZ: "); Serial.print(accel.acceleration.z);     Serial.println("  \tm/s^2");

		// print out magnetometer data
		Serial.print("Magn. X: "); Serial.print(mag.magnetic.x); Serial.print(" ");
		Serial.print("  \tY: "); Serial.print(mag.magnetic.y);       Serial.print(" ");
		Serial.print("  \tZ: "); Serial.print(mag.magnetic.z);     Serial.println("  \tgauss");
	
		// print out gyroscopic data
		Serial.print("Gyro  X: "); Serial.print(gyro.gyro.x); Serial.print(" ");
		Serial.print("  \tY: "); Serial.print(gyro.gyro.y);       Serial.print(" ");
		Serial.print("  \tZ: "); Serial.print(gyro.gyro.z);     Serial.println("  \tdps");

		// print out temperature data
		Serial.print("Temp: "); Serial.print(temp.temperature); Serial.println(" *C");

		Serial.println("**********************\n");

		delay(250);
	
	// --------------------------------------------------------
	// Place other sensor data here
	// --------------------------------------------------------
	
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
