//Arduino Source: https://www.arduino.cc/reference/en/libraries/openweatheronecall/
//GitHub Source: https://github.com/JHershey69/OpenWeatherOneCall

//Required libraries
#include <OpenWeatherOneCall.h>


//----Global Weather Variables----
float fTemp0,fTemp1,fTemp2,fTemp3,fTemp4;
float fRain0,fRain1,fRain2,fRain3,fRain4,fRain5,fRain6,fRain7,fRain8,fRain9,fRain10;

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

void OneCallLoop(){
//----Apply OneCall Settings----
  OWOC.setOpenWeatherKey(ONECALLKEY);
  OWOC.setLatLon(myLAT, myLONG);
  //OWOC.setLatLon(myCITYID);
  OWOC.setExcl(myEXCLUDES);
  OWOC.setHistory(myHISTORY);
  OWOC.setUnits(myUNITS);
  OWOC.parseWeather();
  
//----OneCall Display/Retrieve----
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
      //printf("\nForecast Temp Tomorrow : % .0f\n", OWOC.forecast[1].temperatureLow);
      //printf("\nForecast Rain Tomorrow : % .0f\n", OWOC.forecast[1].rainVolume);
    }
    if (OWOC.hour){
      fTemp0 = OWOC.hour[0].temperature;
      fTemp1 = OWOC.hour[1].temperature;
      fTemp2 = OWOC.hour[2].temperature;
      fTemp3 = OWOC.hour[3].temperature;
      fTemp4 = OWOC.hour[4].temperature;
      Serial.print("fTemp0: ");
      Serial.println(fTemp0);
      Serial.print("fTemp1: ");
      Serial.println(fTemp2);
      Serial.print("fTemp3: ");
      Serial.println(fTemp3);
      Serial.print("fTemp4: ");
      Serial.println(fTemp4);
    }
    if (OWOC.alert) {
      printf("ALERT *** ALERT *** ALERT\n");
      printf("Sender : % s\n", OWOC.alert->senderName);
      printf("Event : % s\n", OWOC.alert->event);
      printf("ALERT : % s\n", OWOC.alert->summary);
    }

  }
}
