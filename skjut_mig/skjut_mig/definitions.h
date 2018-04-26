#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/******************************************************************
******************************** I2C ******************************
******************************************************************/
#define F_SCL 50UL
#define Prescaler 1
#define TWBR_value ((((F_CPU/F_SCL)/Prescaler)-16)/2)

#define ERROR 1
#define SUCCESS 0

#define I2C_WRITE 0
#define I2C_READ 1

//Accelerometer registers
#define accel_addr 0x32

#define ctrl_reg_1 0x20
#define acc_x_l 0x28
#define acc_x_h 0x29
#define acc_y_l 0x2A
#define acc_y_h 0x2B
#define acc_z_l 0x2C
#define acc_z_h 0x2D
#define ctrl_reg_acc_10 = 0b00100111 //10Hz
#define ctrl_reg_acc_50 0b01000111 //50Hz
#define ctrl_reg_acc_100 0b01010111 //100Hz
#define accel_MG_LSB 0.001f
#define gravity_value 9.821f

//Gyrometer registers
#define gyro_addr 0xD6

#define ctrl_reg_gyro_1 0x0F //default

//Gyro sensitivities
#define L3GD20_SENSITIVITY_250DPS (0.00875F)      // Roughly 22/256 for fixed point match
#define L3GD20_SENSITIVITY_500DPS (0.0175F)       // Roughly 45/256
#define L3GD20_SENSITIVITY_2000DPS (0.070F)       // Roughly 18/256
#define L3GD20_DPS_TO_RADS (0.017453293F)		  // degress/s to rad/s multiplier

//IR registers
#define temp_addr 0xD2
#define start_pixel 0x80 //Lowbyte för första pixeln (nr 0)
#define end_pixel 0xFE	//Lowbyte för sista pixeln (nr 63)
#define frame_rate 0x02
#define AMG8833_RESOLUTION 0.25f

/******************************************************************
******************************** SPI ******************************
******************************************************************/

#define ALL_DATA_REQUEST 0x01
#define ACC_DATA_REQUEST 0x02
#define ANGLE_DATA_REQUEST 0x03
#define DISTANCE_DATA_REQUEST 0x04
#define IR_DATA_REQUEST 0x05

#define SPI_DATA_OK 0x11

//USART-definitioner
#define TXD0_READY bit_is_set(UCSR0A,5)
#define TXD0_FINISHED bit_is_set(UCSR0A,6)
#define RXD0_READY bit_is_set(UCSR0A,7)
#define TXD0_DATA (UDR0)
#define RXD0_DATA (UDR0)

//Definiera baudrate
#define BAUD 1000000
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)			//Sätt baudrate för UBRR enligt formel i databladet


//Adresser i EEPROM dit olika data skrivs
#define MAX_SPEED				   0x20
#define GOAL_ANGLE				   0x1e
#define TORQUE					   0x22
#define RETURN_LEVEL			   0x10				//När servot ska skicka tillbaka data
#define LOWER_ANGLE_LIMIT    	   0x06
#define HIGHER_ANGLE_LIMIT         0x08
#define PRESENT_ANGLE			   0X24
#define LOWEST_VOLTAGE_LIMIT	   0X0c
#define HIGHEST_VOLTAGE_LIMIT	   0x0d
#define HIGHEST_TEMPERATURE_LIMIT  0x0b
#define SERVO_ID                   0x03
#define GLOBAL_ID				   0xfe

//Startvinklar då roboten står upp
#define STAND_DEG_00				150
#define STAND_DEG_03				150
#define STAND_DEG_06				150
#define STAND_DEG_09				150
#define STAND_DEG_12				150
#define STAND_DEG_15				150

#define STAND_DEG_01				 90
#define STAND_DEG_04				 90
#define STAND_DEG_07				 90
#define STAND_DEG_10				210
#define STAND_DEG_13				210
#define STAND_DEG_16				210

#define STAND_DEG_02				230
#define STAND_DEG_05				230
#define STAND_DEG_08				230
#define STAND_DEG_11				 70
#define STAND_DEG_14				 70
#define STAND_DEG_17				 70

//Kommandon för Cringebot
#define WALK_FORWARD			   0x01
#define WALK_BACKWARD			   0x02
#define ROTATE_LEFT			       0x03
#define ROTATE_RIGHT		       0x04
#define TURN_LEFT			       0x05
#define TURN_RIGHT			       0x06
#define STAND_UP			       0x07

#define NOT_READY				   0xD0
#define READY				       0xFF

#define SPI_DATA_ERROR			   0x11
