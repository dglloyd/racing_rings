#include <Arduino.h>

int redPin = 5;
int greenPin = 6;
int bluePin = 3;

int end[3] = { 220, 0, 230 };
int start[3] = { 74, 1, 30 };
int current[3] = { 0, 0, 0 };


void setup()
{
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
Serial.begin(9600);
}

void loop()
{
    for (int i = 0; i <= 100; i++) {
    current[0] = ((start[0] * (100 - i)) + (end[0] * i)) / 100;
    current[1] = ((start[1] * (100 - i)) + (end[1] * i)) / 100;
    current[2] = ((start[2] * (100 - i)) + (end[2] * i)) / 100;

    analogWrite(redPin, current[0]);
    analogWrite(greenPin, current[1]);
    analogWrite(bluePin, current[2]);
    char buffer[256];
    sprintf(buffer,"%d,%d,%d\n",current[0], current[1], current[2]);
    Serial.print(buffer);
    delay(60);
    }
    for (int i = 0; i <= 100; i++) {
    current[0] = ((end[0] * (100 - i)) + (start[0] * i)) / 100;
    current[1] = ((end[1] * (100 - i)) + (start[1] * i)) / 100;
    current[2] = ((end[2] * (100 - i)) + (start[2] * i)) / 100;

    analogWrite(redPin, current[0]);
    analogWrite(greenPin, current[1]);
    analogWrite(bluePin, current[2]);
    char buffer[256];
    sprintf(buffer,"%d,%d,%d\n",current[0], current[1], current[2]);
    Serial.print(buffer);
    delay(60);
    }
}
