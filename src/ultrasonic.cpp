#include "ultrasonic.hpp"

ultrasonic::ultrasonic(int trig_pin, int echo_pin):
    trigger_pin(trig_pin),
    echo_pin(echo_pin),
    timeout_micros(300000){
    pinMode(trigger_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    digitalWrite(trigger_pin, LOW);
}

ultrasonic::ultrasonic(int trig_pin, int echo_pin, int timeout_micros):
    trigger_pin(trig_pin),
    echo_pin(echo_pin),
    timeout_micros(timeout_micros){
    pinMode(trigger_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    digitalWrite(trigger_pin, LOW);
}

ultrasonic::~ultrasonic(){
    digitalWrite(trigger_pin, LOW);
    pinMode(trigger_pin, INPUT);
    pinMode(echo_pin, INPUT);
}

double ultrasonic::detect_distance(){

    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);

    double timeoutBegin = micros();
    while(!digitalRead(echo_pin)){
        // std::cout<<micros()-timeoutBegin<<std::endl;
        if(micros() - timeoutBegin >= timeout_micros){
            // std::cout<<"Ultrasonic timeout"<<std::endl;
            return -1;
        }
    }

    double beginTime = micros();
    while (digitalRead(echo_pin)){}
    double endTime = micros();

    // std::cout<<"distance: "<<((endTime - beginTime) * SONIC_SPEED)/(2*1000*1000)<<std::endl;
    return ((endTime - beginTime) * (double)SONIC_SPEED)/(2.0*1000.0*1000.0);
}