int strCnt = 1;
String Str1 = "time=" + String(millis()) + "&purgeStatus=" + (String)purgeState + "&waterStatus=Startup&z1Temp=" + String(z1Temp) + "&z2Temp=" + String(z2Temp) + "&z3Temp=" + String(z3Temp) + "&fTemp0=" + (String)fTemp0 + "&fTemp1=" + (String)fTemp1 + "&fTemp2=" + (String)fTemp2 + "&fTemp3=" + (String)fTemp3 + "&fRain0=" + (String)fRain0 + "&fRain1=" + (String)fRain1;
String Str2, Str3, Str4, Str5, Str6, Str7, Str8, Str9, Str10;
String tmpStr;
//https://script.google.com/macros/s/AKfycbwlrN0zYBenWA40GM7irsbZz9EgJR19gSKhbT3jrvlKbbFe3ww/exec?time=1000&purgeStatus=true&waterStatus=false&z1Temp=888&z2Temp=888&z3Temp=888&fTemp0=999&fTemp1=999&fTemp2=999&fTemp3=999&fRain0=0.1&fRain1=0.1
void strWrite() {
  String tmpState = "time=" + String(millis()) + "&purgeStatus=" + (String)purgeState + "&waterStatus=" + (String)waterState;
  String tmpZone = "&z1Temp=" + String(z1Temp) + "&z2Temp=" + String(z2Temp) + "&z3Temp=" + String(z3Temp);
  String tmptcast = "&fTemp0=" + (String)fTemp0 + "&fTemp1=" + (String)fTemp1 + "&fTemp2=" + (String)fTemp2 + "&fTemp3=" + (String)fTemp3;
  String tmprcast = "&fRain0=" + (String)fRain0 + "&fRain1=" + (String)fRain1;
  tmpStr = tmpState + tmpZone + tmptcast + tmprcast;
  //Str[strCnt] = tmpStr;
  //strCnt ++;
  Serial.println("String Write");
  switch (strCnt) {
    case 1:
      Str1 = tmpStr;
      strCnt ++;
      break;
    case 2:
      Str2 = tmpStr;
      strCnt ++;
      break;
    case 3:
      Str3 = tmpStr;
      strCnt ++;
      break;
    case 4:
      Str4 = tmpStr;
      strCnt ++;
      break;
    case 5:
      Str5 = tmpStr;
      strCnt ++;
      break;
    case 6:
      Str6 = tmpStr;
      strCnt ++;
      break;
    case 7:
      Str7 = tmpStr;
      strCnt ++;
      break;
    case 8:
      Str8 = tmpStr;
      strCnt ++;
      break;
    case 9:
      Str9 = tmpStr;
      strCnt ++;
      break;
    case 10:
      Str10 = tmpStr;
      strCnt ++;
      break;
    default;
      strCnt = 1;
  }
}

void sendData(String params) {
  String URL = "https://script.google.com/macros/s/AKfycbwlrN0zYBenWA40GM7irsbZz9EgJR19gSKhbT3jrvlKbbFe3ww/exec?";
  HTTPClient http;
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  http.begin(URL + params);
  int httpCode = http.GET();
  http.end();
  Serial.println(URL + params);
  Serial.println("Completed http: " + String(httpCode));
}

void resetList() {
  //for (int i = 0; i < strCnt; i++) {
  //  Str[i] = "empty";
  //}
  Str1 = "";
  Str2 = "";
  Str3 = "";
  Str4 = "";
  Str5 = "";
  Str6 = "";
  Str7 = "";
  Str8 = "";
  Str9 = "";
  Str10 = "";
  strCnt = 1;
}

void sendFinal() {
  //for (int i = 0; i < strCnt; i++) {
  //  sendData(Str[i]);
  //  delay(100);
  //}
  if (Str1 != "") {
    Serial.println("String 1 sending");
    sendData(Str1);
    delay(100);
  }
  if (Str2 != "") {
    sendData(Str2);
    delay(100);
  }
  if (Str3 != "") {
    sendData(Str3);
    delay(100);
  }
  if (Str4 != "") {
    sendData(Str4);
    delay(100);
  }
  if (Str5 != "") {
    sendData(Str5);
    delay(100);
  }
  if (Str6 != "") {
    sendData(Str6);
    delay(100);
  }
  if (Str7 != "") {
    sendData(Str7);
    delay(100);
  }
  if (Str8 != "") {
    sendData(Str8);
    delay(100);
  }
  if (Str9 != "") {
    sendData(Str9);
    delay(100);
  }
  if (Str10 != "") {
    sendData(Str10);
    delay(100);
  }
  resetList();
}
