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
 *  Wiring for Arduino Uno,  will be included as a build flag for Arduino UNO
 */

#ifndef ARDUINOUNOCONF_H
#define ARDUINOUNOCONF_H


// Pin layout for motor driver A
#define M1_U1_ENA 2  // (Enable A) - pin  8 (L298N) 
#define M1_U1_ENB 5  // (Enables B) - pin 14 (L298N) 

#define M1_U1_IN1 4  // pin  7(L298N)
#define M1_U1_IN2 3  // pin  9(L298N)
#define M1_U1_IN3 7  // pin 13(L298N)
#define M1_U1_IN4 6  // pin 15(L298N)


#endif
