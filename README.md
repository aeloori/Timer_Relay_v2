# Timer_Relay_v2

Timer_Relay
control relay using arduino at a set of time intervels

mode index for selecting a relay are

* 1
* 2
* 3
* 4

time intervels that to be used for controlling the relay are mentioned below :-

30 mins of time intervel
60 mins of time intervel
90 minutes of time intervel
120 mins of time intervel
Pin connections

relay1 - 1 (relay)
relay2 - 2 (relay)
relay3 - 3 (relay)
relay4 - 4 (relay)
setPin - 13 (push button)
modePin - 12 (push button)
Specification of this project

Does not required any ctc module for that time intervel
controlled easily using two push buttons
can be build using any other micro controllers like attiny 85, atmega 16, atmega 32 ,attiny 13 and also using attiny 13-a.
Further code will be updated to use esp 8266 wifi module to make this project controlled by internet

* All Arduino boards having 13,12, 1,2,3,4, pin numbers.
* All Atmel Atmega boards.
* All Atmel Atting boards with exemptions.
  - pushbutton no 13 to be replaced with pin Number '4'
  - pushbutton no 12 to be replaced with pin number '3'.
  - relay no 1, to be replaced with pin number '0'.
  - relay no 2, to be replaced with pin number '1'.
  - relay no 3, to be replaced with pin number '2'.
  - Only four relays can be used when working with Attiny microcontrollers.
