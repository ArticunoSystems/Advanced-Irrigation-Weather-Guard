//---Global Variables----
int NODE, TEMP, FLOW, PRES;//Used in the MESH.h library
float z1Temp=999;
float z2Temp=999;
float z3Temp=999;
float z4Temp=999;
float z1Flow, z2Flow, z3Flow, z4Flow;
float cal1Temp,cal2Temp,cal3Temp,cal4Temp;

void calTemp(){
  if(z1Temp <900){
    cal1Temp = fTemp0 - z1Temp;
  }
  if(z2Temp <900){
    cal2Temp = fTemp0 - z2Temp;
  }
  if(z3Temp <900){
    cal3Temp = fTemp0 - z3Temp;
  }
  if(z4Temp <900){
    cal4Temp = fTemp0 - z4Temp;
  }
}

void sExtract(){
  if (NODE==1){
    z1Temp = ((float)TEMP/1000)+cal1Temp;
    z1Flow = (float)FLOW/1000;
    Serial.print("Zone 1 Temp: ");
    Serial.println(z1Temp);
    Serial.print("Zone 1 Flow: ");
    Serial.println(z1Flow);
  }
  else if (NODE==2){
    z2Temp = ((float)TEMP/1000)+cal2Temp;
    z2Flow = (float)FLOW/1000;
    Serial.print("Zone 2 Temp: ");
    Serial.println(z2Temp);
    Serial.print("Zone 2 Flow: ");
    Serial.println(z2Flow);
  }
  else if (NODE==3){
    z3Temp = ((float)TEMP/1000)+cal3Temp;
    z3Flow = (float)FLOW/1000;
    Serial.print("Zone 3 Temp: ");
    Serial.println(z3Temp);
    Serial.print("Zone 3 Flow: ");
    Serial.println(z3Flow);
  }
  else if (NODE==4){
    z4Temp = ((float)TEMP/1000)+cal4Temp;
    z4Flow = (float)FLOW/1000;
    Serial.print("Zone 4 Temp: ");
    Serial.println(z4Flow);
    Serial.print("Zone 4 Flow: ");
    Serial.println(z4Flow);
  }
  else{
    Serial.println("Zone Sense Error");
  }
}
