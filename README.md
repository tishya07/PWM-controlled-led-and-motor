# PWM for LED Dimming and Servo Control

This project demonstrates the use of hardware PWM (Pulse Width Modulation) on the STM32L4 Nucleo board. PWM is used to control both the brightness of the onboard green LED and the angle of a micro servo motor (SG90).

## Features

- Generate PWM signal on TIM2 CH1 (PA5) to dim the green LED
- Generate PWM signal on TIM5 CH1 (PA0) to control SG90 servo angle
- Smoothly vary LED brightness and servo position using changing duty cycle
- Timer configuration using ARR and CCR to control PWM period and duty

## Hardware Requirements

- STM32L4 Nucleo Board  
- SG90 Micro Servo Motor  
- Breadboard and jumper wires  
- USB cable for power/debugging  

## Circuit Setup

| Signal        | Pin  | Purpose                    |
|---------------|------|----------------------------|
| Green LED     | PA5  | TIM2 CH1 (PWM LED control) |
| Servo PWM     | PA0  | TIM5 CH1 (PWM signal)      |
| Servo VCC     | 5V   | Power for servo motor      |
| Servo GND     | GND  | Ground for servo motor     |

## Configuration Summary

### PWM for LED (TIM2 CH1 on PA5)

- Clock Source: Default 4 MHz system clock
- Prescaler: Set to slow down timer ticks
- ARR: Sets PWM period
- CCR1: Sets duty cycle for brightness
- Mode: PWM Mode 1 (active high)

### PWM for Servo (TIM5 CH1 on PA0)

- PWM frequency: 50 Hz (20 ms period)
- Duty cycles:
  - ~1.0 ms → -90°  
  - ~1.5 ms → 0°  
  - ~2.0 ms → +90°  
- CCR1 value adjusted to smoothly track LED brightness

## Behavior

- LED brightness increases and decreases in a periodic loop
- Servo motor rotates in sync with LED brightness:
  - When LED is off → servo at max rotation
  - When LED is fully on → servo at opposite end
  - Smooth transition throughout
