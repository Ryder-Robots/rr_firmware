/*!
 * Ryder Robots Shared Micro-Processor
 * Copyright (C) 2024  Ryder Robots
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * =====================================================================
 * 
 * Header files for micro-processors. Constants will shared with SBC to 
 * allow for communication using I2C or other protocols.
 */

#ifndef RRFIRMARE_H
#define RRFIRMARE_H

// current version.
#define RRFIRMWARE_H_VERSION 0.0.1


/*************************************************************
 * Commands
 *************************************************************/
#define RR_CMD_U1    0x00  /* Motor A */
#define RR_CMD_U2    0x01  /* MOtor B */

// CAVEAT MUST BE LAST FUNCTION
#define RR_IO_SZ RR_CMD_U2

// Responses
#define RR_IO_RES_OK          0x00  /* Action was sent */
#define RR_IO_RES_TIMEOUT     0x01  /* Recieved request but no bytes to read */
#define RR_IO_RES_ACTION_SENT 0x02  /* Sent action to handler */
#define RR_IO_RES_UNSUPPORTED 0x03  /* An unsupported operation.*/
#define RR_IO_RES_BAD_RQ      0x04  /* Bad request was recieved */

// Arguments for motors
// Constants specifc to MC1
#define RR_MOTOR_FLAG_IN1 0b00000001  // Toggle IN1 HIGH
#define RR_MOTOR_FLAG_IN2 0b00000010  // Toggle IN2 HIGH
#define RR_MOTOR_FLAG_IN3 0b00000100  // Toggle IN3 HIGH
#define RR_MOTOR_FLAG_IN4 0b00001000  // Toggle IN3 HIGH

// For Testing use I2C bus, or console will not work.
//#if (BUSTYPE == I2C)
//#include <Wire.h>
//#define BUS Wire
//#else
#define BUS Serial
//#endif

#endif