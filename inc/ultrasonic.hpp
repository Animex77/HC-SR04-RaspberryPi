#include <wiringPi.h>
#include <iostream>

#define SONIC_SPEED 343

class ultrasonic{
    private:
    int trigger_pin;
    int echo_pin;
    int timeout_micros;
    double dist;
    public:
    ultrasonic(int trig_pin, int echo_pin);
    ultrasonic(int trig_pin, int echo_pin, int timeout_micros);
    ~ultrasonic();
    double detect_distance();
    void detect_distance(double& distBuffer);
};