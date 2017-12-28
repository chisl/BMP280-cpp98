/*
 * name:        BMP280
 * description: The BMP280 is an absolute barometric pressure sensor especially designed for mobile applications.
 * manuf:       Bosch Sensortec
 * version:     0.1
 * url:         https://ae-bst.resource.bosch.com/media/_tech/media/datasheets/BST-BMP280-DS001-18.pdf
 * date:        2017-09-02
 * author       https://chisl.io/
 * file:        BMP280.hpp
 */

#include <cinttypes>

/* Derive from class BMP280_Base and implement the read and write functions! */

/* BMP280: The BMP280 is an absolute barometric pressure sensor especially designed for mobile applications. */
class BMP280_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	virtual uint32_t read32(uint16_t address, uint16_t n=32) = 0;  // 32 bit read
	virtual void write(uint16_t address, uint32_t value, uint16_t n=32) = 0;  // 32 bit write
	virtual void read(uint16_t address, uint8_t* buf, uint16_t n) = 0;  // arbitrary length read
	virtual void write(uint16_t address, uint8_t* buf, uint16_t n) = 0;  // arbitrary length write
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG DEVID                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DEVID:
	 * Fixed device ID
	 */
	struct DEVID
	{
		static const uint16_t __address = 0;
		
		/* Bits DEVID: */
		struct DEVID_
		{
			/* Mode:r */
			static const uint8_t dflt = 0b11100101; // 8'b11100101
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register DEVID */
	void setDEVID(uint8_t value)
	{
		write(DEVID::__address, value, 8);
	}
	
	/* Get register DEVID */
	uint8_t getDEVID()
	{
		return read8(DEVID::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                              REG ID                                               *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ID:
	 * The "id" register contains the chip identification number chip_id[7:0], which is 'h58.
	 * This number can be read as soon as the device finished the power-on-reset.
	 */
	struct ID
	{
		static const uint16_t __address = 208;
		
		/* Bits ID: */
		struct ID_
		{
			/* Mode:r */
			static const uint8_t dflt = 0b01011000; // 8'h58
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ID */
	void setID(uint8_t value)
	{
		write(ID::__address, value, 8);
	}
	
	/* Get register ID */
	uint8_t getID()
	{
		return read8(ID::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG RESET                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG RESET:
	 * The "reset" register contains the soft reset word reset[7:0].
	 * If the value 'hB6 is written to the register, the device is reset using the
	 * complete power-on-reset procedure. Writing other values than 'hB6 has no effect.
	 * The readout value is always 0x00.
	 */
	struct RESET
	{
		static const uint16_t __address = 224;
		
		/* Bits RESET: */
		struct RESET_
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
			static const uint8_t Reset = 0xb6; // The device is reset using the complete power-on-reset procedure
		};
	};
	
	/* Set register RESET */
	void setRESET(uint8_t value)
	{
		write(RESET::__address, value, 8);
	}
	
	/* Get register RESET */
	uint8_t getRESET()
	{
		return read8(RESET::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG STATUS                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG STATUS:
	 * The "status" register contains two bits which indicate the status of the device.
	 */
	struct STATUS
	{
		static const uint16_t __address = 243;
		
		/* Bits IM_UPDATE: */
		/*
		 * Automatically set to ‘1’ whenever a conversion is running and
		 * back to ‘0’ when the results have been transferred to the data registers.
		 */
		struct IM_UPDATE
		{
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t Running = 0b0; // 
			static const uint8_t Done = 0b1; // 
		};
		/* Bits MEASURING: */
		/*
		 * Automatically set to ‘1’ when the NVM data are being copied to image registers
		 * and back to ‘0’ when the copying is done. The data are copied at power-on-reset
		 * and before every conversion.
		 */
		struct MEASURING
		{
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t Running = 0b0; // 
			static const uint8_t Done = 0b1; // 
		};
	};
	
	/* Set register STATUS */
	void setSTATUS(uint8_t value)
	{
		write(STATUS::__address, value, 8);
	}
	
	/* Get register STATUS */
	uint8_t getSTATUS()
	{
		return read8(STATUS::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_MEAS                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_MEAS:
	 * The "ctrl_meas" register sets the data acquisition options of the device.
	 */
	struct CTRL_MEAS
	{
		static const uint16_t __address = 244;
		
		/* Bits OSRS_T: */
		/* Controls oversampling of temperature data. See chapter 3.3.2 for details.  */
		struct OSRS_T
		{
			static const uint8_t mask = 0b11100000; // [5,6,7]
			static const uint8_t Skipped = 0b00; // output set to 0x80000
			static const uint8_t Oversamplingx1 = 0b01; // 
			static const uint8_t Oversamplingx2 = 0b10; // 
			static const uint8_t Oversamplingx4 = 0b11; // 
			static const uint8_t Oversamplingx8 = 0b100; // 
			static const uint8_t Oversamplingx16 = 0b101; // 
		};
		/* Bits OSRS_P: */
		/* Controls oversampling of pressure data. See chapter 3.3.1 for details.  */
		struct OSRS_P
		{
			static const uint8_t mask = 0b00011100; // [2,3,4]
			static const uint8_t Skipped = 0b00; // output set to 0x80000
			static const uint8_t Oversamplingx1 = 0b01; // 
			static const uint8_t Oversamplingx2 = 0b10; // 
			static const uint8_t Oversamplingx4 = 0b11; // 
			static const uint8_t Oversamplingx8 = 0b100; // 
			static const uint8_t Oversamplingx16 = 0b101; // 
		};
		/* Bits MODE: */
		/* Controls the power mode of the device. See chapter 3.6 for details.  */
		struct MODE
		{
			static const uint8_t mask = 0b00000011; // [0,1]
			/*
			 * In sleep mode, no measurements are performed and power consumption (IDDSM)
			 * is at a minimum. All registers are accessible.
			 */
			static const uint8_t Sleep = 0b00;
			/*
			 * In forced mode, a single measurement is performed according to selected
			 * measurement and filter options. When the measurement is finished, the sensor
			 * returns to sleep mode and the measurement results can be obtained from the
			 * data registers. For a next measurement, forced mode needs to be selected again.
			 */
			static const uint8_t Forced = 0b01;
			/*
			 * Normal mode 16ontinuously cycles between an (active) measurement period
			 * and an (inactive) standby period, whose time is defined by tstandby.
			 */
			static const uint8_t Normal = 0b00;
		};
	};
	
	/* Set register CTRL_MEAS */
	void setCTRL_MEAS(uint8_t value)
	{
		write(CTRL_MEAS::__address, value, 8);
	}
	
	/* Get register CTRL_MEAS */
	uint8_t getCTRL_MEAS()
	{
		return read8(CTRL_MEAS::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG CONFIG                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG CONFIG:
	 * The "config" register sets the rate, filter and interface options of the device. Writes to the "config"
	 * register in normal mode may be ignored. In sleep mode writes are not ignored.
	 */
	struct CONFIG
	{
		static const uint16_t __address = 245;
		
		/* Bits T_SB: */
		/* Controls inactive duration tstandby in normal mode. See chapter 3.6.3 for details.  */
		struct T_SB
		{
			static const uint8_t mask = 0b11100000; // [5,6,7]
			static const uint8_t tsb0_5 = 0b00; // 0.5ms
			static const uint8_t tsb62_5 = 0b01; // 62.5ms
			static const uint8_t tsb125 = 0b10; // 125ms
			static const uint8_t tsb250 = 0b11; // 250ms
			static const uint8_t tsb500 = 0b100; // 500ms
			static const uint8_t tsb1000 = 0b101; // 1s
			static const uint8_t tsb2000 = 0b110; // 2s
			static const uint8_t tsb4000 = 0b111; // 4s
		};
		/* Bits FILTER: */
		/* Controls the time constant of the IIR filter. See chapter 3.3.3 for details.  */
		struct FILTER
		{
			static const uint8_t mask = 0b00011100; // [2,3,4]
			static const uint8_t COEFF_OFF = 0b00; // 1 sample to reach ≥75 % of step response
			static const uint8_t COEFF_2 = 0b01; // 2 samples to reach ≥75 % of step response
			static const uint8_t COEFF_4 = 0b10; // 5 samples to reach ≥75 % of step response
			static const uint8_t COEFF_8 = 0b11; // 11 samples to reach ≥75 % of step response
			static const uint8_t COEFF_16 = 0b100; // 22 samples to reach ≥75 % of step response
		};
		/* Bits unused_0: */
		struct unused_0
		{
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits SPI3WEN: */
		/* Enables 3-wire SPI interface when set to ‘1’. See chapter 5.3 for details.  */
		struct SPI3WEN
		{
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register CONFIG */
	void setCONFIG(uint8_t value)
	{
		write(CONFIG::__address, value, 8);
	}
	
	/* Get register CONFIG */
	uint8_t getCONFIG()
	{
		return read8(CONFIG::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG PRESS                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG PRESS:
	 * The "press" register contains the raw pressure measurement output data up[19:0].
	 * For details on how to read out the pressure and temperature information from the device,
	 * please consult chapter 3.9.
	 */
	struct PRESS
	{
		static const uint16_t __address = 247;
		
		/* Bits PRESS: */
		/* raw pressure measurement output data § */
		struct PRESS_
		{
			static const uint32_t mask = 0b000011111111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19]
		};
	};
	
	/* Set register PRESS */
	void setPRESS(uint32_t value)
	{
		write(PRESS::__address, value, 24);
	}
	
	/* Get register PRESS */
	uint32_t getPRESS()
	{
		return read32(PRESS::__address, 24);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG TEMP                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG TEMP:
	 * The "temp" register contains the raw temperature measurement output data ut[19:0].
	 * For details on how to read out the pressure and temperature information from the device,
	 * please consult chapter 3.9.
	 */
	struct TEMP
	{
		static const uint16_t __address = 250;
		
		/* Bits TEMP: */
		/* raw temperature measurement output data § */
		struct TEMP_
		{
			static const uint32_t mask = 0b000011111111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19]
		};
	};
	
	/* Set register TEMP */
	void setTEMP(uint32_t value)
	{
		write(TEMP::__address, value, 24);
	}
	
	/* Get register TEMP */
	uint32_t getTEMP()
	{
		return read32(TEMP::__address, 24);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG CALIB                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/* REG CALIB:
	 */
	struct CALIB
	{
		static const uint16_t __address = 136;
		
		/* Bits CALIB: */
		struct CALIB_
		{
			/* Mode:r */
			static const uint8_t mask[]; // Initialised in .cpp
		};
	};
	
	/* Set register CALIB */
	void setCALIB(uint8_t* buf)
	{
		write(CALIB::__address, buf, 208);
	}
	
	/* Get register CALIB */
	void getCALIB(uint8_t* buf)
	{
		read(CALIB::__address, buf, 208);
	}
	
};
