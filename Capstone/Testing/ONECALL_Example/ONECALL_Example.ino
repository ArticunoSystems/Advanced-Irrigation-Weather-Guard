//Arduino Source: https://www.arduino.cc/reference/en/libraries/openweatheronecall/
//GitHub Source: https://github.com/JHershey69/OpenWeatherOneCall

//Required libraries
#include <OpenWeatherOneCall.h>
#include <WiFi.h>

//----WiFi Settings----
#define ssid "Z Islander"
#define password ""

//----OneCall Settings----
#define ONECALLKEY "524354176fc7e786cc3d2a113aa043ac" //API Key for OpenWeather
//#define GKEY "";
float myLAT = 30.6744;
float myLONG = -96.3700;
int myUNITS = IMPERIAL; //Request values in imperial units
int myCITYID = 4677008; //Bryan,US
int myEXCLUDES = EXCL_C+EXCL_M+EXCL_A;
int myHISTORY = NULL;

//EXCL_C = Current
//EXCL_D = Daily
//EXCL_H = Hourly
//EXCL_M = Minutely
//EXCL_A = Alerts

OpenWeatherOneCall OWOC;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  OneCallLoop();
}

void OneCallLoop(){
//----OneCall Settings----
  OWOC.setOpenWeatherKey(ONECALLKEY);
  //OWOC.setLatLon(myLAT, myLONG);
  OWOC.setLatLon(myCITYID);
  OWOC.setExcl(myEXCLUDES);
  OWOC.setHistory(myHISTORY);
  OWOC.setUnits(myUNITS);
  OWOC.parseWeather();
  
//----OneCall Display----
  Serial.printf("\nLocation: % s, % s % s\n", OWOC.location.CITY, OWOC.location.STATE, OWOC.location.COUNTRY);
  if (myHISTORY){ //Remember you can't get historical and current weather at the same time
    if (OWOC.history){
      printf("Mean Temp for % s : % .0f\n", OWOC.history[0].weekDayName, OWOC.history[0].temperature);
    }
  }
  else{
    if (OWOC.current){
      printf("Current Temp : % .0f\n", OWOC.current->temperature);
      printf("Current Humidity : % .0f\n", OWOC.current->humidity);
    }
    if (OWOC.forecast){
      printf("\nForecast Temp Tomorrow : % .0f\n", OWOC.forecast[1].temperatureHigh);
    }
    if (OWOC.hour){
      printf("\nTemp this Hour : % .0f\n", OWOC.hour[0].temperature);
    }
    if (OWOC.alert) {
      printf("ALERT *** ALERT *** ALERT\n");
      printf("Sender : % s\n", OWOC.alert->senderName);
      printf("Event : % s\n", OWOC.alert->event);
      printf("ALERT : % s\n", OWOC.alert->summary);
    }

  }
}

void loop(){

}
