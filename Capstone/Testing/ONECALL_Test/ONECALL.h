//Arduino Source: https://www.arduino.cc/reference/en/libraries/openweatheronecall/
//GitHub Source: https://github.com/JHershey69/OpenWeatherOneCall

//Required libraries
#include <OpenWeatherOneCall.h>


//----Global Weather Variables----
float fTemp0,fTemp1,fTemp2,fTemp3,fTemp4,fTemp5,fTemp6,fTemp7;
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
  //OWOC.setLatLon(myLAT, myLONG);
  OWOC.setLatLon(myCITYID);
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
      Serial.println(fTemp0); //Fahrenheit
      Serial.print("fTemp1: ");
      Serial.println(fTemp2);
      Serial.print("fTemp3: ");
      Serial.println(fTemp3);
      Serial.print("fTemp4: ");
      Serial.println(fTemp4);
      
      fRain0 = OWOC.hour[0].rainVolume;
      fRain1 = OWOC.hour[1].rainVolume;
      fRain2 = OWOC.hour[2].rainVolume;
      fRain3 = OWOC.hour[3].rainVolume;
      fRain4 = OWOC.hour[4].rainVolume;
      fRain5 = OWOC.hour[5].rainVolume;
      fRain6 = OWOC.hour[6].rainVolume;
      fRain7 = OWOC.hour[7].rainVolume;
      fRain8 = OWOC.hour[8].rainVolume;
      fRain9 = OWOC.hour[9].rainVolume;
      fRain10 = OWOC.hour[10].rainVolume;
      Serial.print("fRain0: ");
      Serial.println(fRain0); //inches of rain
      Serial.print("fRain1: ");
      Serial.println(fRain1);
      Serial.print("fRain2: ");
      Serial.println(fRain2);
      Serial.print("fRain3: ");
      Serial.println(fRain3);
      Serial.print("fRain4: ");
      Serial.println(fRain4);
      Serial.print("fRain5: ");
      Serial.println(fRain5);
      Serial.print("fRain6: ");
      Serial.println(fRain6);
      Serial.print("fRain7: ");
      Serial.println(fRain7);
      Serial.print("fRain8: ");
      Serial.println(fRain8);
      Serial.print("fRain9: ");
      Serial.println(fRain9);
      Serial.print("fRain10: ");
      Serial.println(fRain10);
    }
    if (OWOC.alert) {
      printf("ALERT *** ALERT *** ALERT\n");
      printf("Sender : % s\n", OWOC.alert->senderName);
      printf("Event : % s\n", OWOC.alert->event);
      printf("ALERT : % s\n", OWOC.alert->summary);
    }

  }
}
