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
enum RR_CMD : uint8_t {
    // Actions
    RR_CMD_U1            =0x00,  /* command for Motor Driver A */
    RR_CMD_U2            =0x01,  /* command for Motor Driver B */

    // Response codes.
    RR_IO_RES_OK         =0x02,  /* successfully processed result, with return response */
    RR_IO_RES_TIMEOUT    =0x03,  /* timed out while waiting to recieve data */
    RR_IO_RES_ACTION_SENT=0x04,  /* Action was sent */
    RR_IO_RES_UNSUPPORTED=0x05,  /* An unsupported operation.*/
    RR_IO_RES_BAD_RQ     =0x06   /* Bad request was recieved */
};


// CAVEAT MUST BE LAST FUNCTION
#define RR_IO_SZ RR_CMD_U2



// Arguments for motors
// Constants specifc to MC1
#define RR_MOTOR_FLAG_IN1 0b00000001  // Toggle IN1 HIGH
#define RR_MOTOR_FLAG_IN2 0b00000010  // Toggle IN2 HIGH
#define RR_MOTOR_FLAG_IN3 0b00000100  // Toggle IN3 HIGH
#define RR_MOTOR_FLAG_IN4 0b00001000  // Toggle IN3 HIGH

#endif