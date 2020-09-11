#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

/*Pins**/ 
//Please Enter The pin values here
int BUZZER_PIN = ; 
int LED_PIN = ;
int PIR_PIN = ;

/*Wifi Credentials****/
//Please Enter you own credentials here
char* ssid = "";
char* pwd = "";
HTTPClient http;

boolean sendNotification = false;

//Enter your IFTTT Webhooks key here
char* key = "";

//timer setup
boolean startTimer = false;
int runDetector = true;
int now = millis();
int prevTime = 0;
int on_time = 30;


void setup() {  
  Serial.begin(9600);
  Serial.println("Starting...");

  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  
  WiFi.mode(WIFI_OFF);
  delay(1000);
  WiFi.mode(WIFI_STA); 
  
  pinMode(LED_PIN,OUTPUT);
  pinMode(PIR_PIN,INPUT_PULLUP);
  pinMode(BUZZER_PIN,OUTPUT);
  
  //Low level trigger buzzer
  digitalWrite(BUZZER_PIN,HIGH);

  now = millis();
  prevTime = millis();
  
  WiFi.begin(ssid,pwd);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");    
    delay(500);
  }  
  Serial.print("Connected to ");
  Serial.println(WiFi.localIP());

  now = millis();
  int time_passed = (int)((now - prevTime)/1000);
  int i = 0;
  //To calibrate the PIR MOTION Sensor
  for(i = 0; i < 30 - time_passed; i++){
    blk(500);  
  }
  attachInterrupt(digitalPinToInterrupt(PIR_PIN),motionDetected,RISING);
}

void loop() {  
  now = millis();
  
  if(startTimer && (now - prevTime) >= on_time*000){
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN,HIGH);
    runDetector = true;
  }

  if(sendNotification){    
    sendNotification = false;      
    http.begin("http://maker.ifttt.com/trigger/motion_detected/with/key/" + key);
    delay(1000);  
    http.GET();  
    http.end();
    Serial.println("NOTIFICATION SENT");  
  }
}

ICACHE_RAM_ATTR void motionDetected(){
  if(runDetector){  
    startTimer = true;  
    prevTime = millis();
  
    digitalWrite(LED_PIN,HIGH);
    Serial.println("Motion Detected");

    digitalWrite(BUZZER_PIN,LOW);
    sendNotification = true;
    runDetector = false;
  }
}


void blk(int x){  
  digitalWrite(LED_PIN,HIGH);
  delay(x);  
  digitalWrite(LED_PIN,LOW);
  delay(x);
}
