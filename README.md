# motionDetectorESP8266

### For this project the following will be required:

  * #### ESP8266 (ESP-12E) Board 
  
  ![1](https://github.com/yagdev99/motionDetectorESP8266/blob/master/pics/2.png)
      
This has been selected as the controller for this system due to its compact size, compatibility, stress-free interfacing over several other type of controller. ESP8266 is an open source Wi-Fi enabled module. It is integrated with TCP/IP protocol stack that can give any microcontroller access to your Wi-Fi network. The ESP8266 is capable of either hosting an application or offloading all Wi-Fi networking functions from another application processor.
  
  * #### PIR Motion Sensor (HR SC501)
  
  *![1](https://github.com/yagdev99/motionDetectorESP8266/blob/master/pics/4.png)
  
A passive infrared sensor (PIR sensor) is an electronic sensor which measures infrared radiation in its field of view from objects. PIR sensors sense general movement, but don’t have information on who moved or what. These sensors allow you to sense motion, generally used to detect whether a human has moved in or out of the sensor range. They are small, inexpensive, low-power, easy to use and don’t wear out.

  * #### Buzzer(One we have used in this project is LOW LEVEL TRIGGER i.e. will be triggered when the input is LOW)
  
  *![1](https://github.com/yagdev99/motionDetectorESP8266/blob/master/pics/7.png)
  
Here we have used active buzzer to make sound after motion detected. The active buzzer has an internal oscillating source, the buzzer will sound as soon as it is energized.
  
  * #### Jumper Wires
  
  *![1](https://github.com/yagdev99/motionDetectorESP8266/blob/master/pics/9.jpg)
  
Jumper wires are simply wires that have connector pins at each end, allowing them to be used to connect to each other without soldering. Jumper wires are typically used with breadboards and other prototyping tools in order to make it easy to change a circuit as needed.
  
  * #### LED
  
  *![1](https://github.com/yagdev99/motionDetectorESP8266/blob/master/pics/5.jpg)
  
A light emitting diode (LED) is a semiconductor device that emits visible light when an electric current passes through it.
  
  * #### Breadboard
  
  *![1](https://github.com/yagdev99/motionDetectorESP8266/blob/master/pics/8.jpg)
  
A breadboard is a platform you can use to build and test electronic circuits, usually without having to do any soldering. Certain parts of the breadboard are wired together so that electricity can flow from component to component in orderly rows. Breadboards are useful for quickly testing and prototyping electronics ideas.
Also Breadboard can also be used without soldering, which makes it easy to remove components and reuse them after doing experiment.


## Google Drive Link to Working project
[Intruder Alarm with ESP8266](https://drive.google.com/file/d/19tFv1GG8p5I7XCJ6Q0uwpn3n2osI7TKg/view?usp=drivesdk "Click to view Google Drive Link")


## Working Theory
*![1](https://github.com/yagdev99/motionDetectorESP8266/blob/master/pics/10.png)

*	We have connected the PIR motion sensor to to the digital pin D8 (GPIO 15) of NodeMCU.
*	Whenever the PIR detects motion then the output state of the PIR sensor will change which will be detected by the controller.
*	We have programmed the NodeMCU to make an HTTP GET request to our IFTTT Webhooks app.
*	Whenever the HTTP GET request has been made then it will trigger a notification alert on our mobile phone or the device connected.


