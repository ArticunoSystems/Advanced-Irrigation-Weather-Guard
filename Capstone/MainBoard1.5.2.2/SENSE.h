//---Global Variables----
int NODE, TEMP, FLOW, PRES;//Used in the MESH.h library
float z1Temp=999;
float z2Temp=999;
float z3Temp=999;
float z4Temp=999;
float z1Flow, z2Flow, z3Flow, z4Flow;

void sExtract(){
  if (NODE==1){
    z1Temp = (float)TEMP/1000;
    z1Flow = (float)FLOW/1000;
    Serial.print("Zone 1 Temp: ");
    Serial.println(z1Temp);
    Serial.print("Zone 1 Flow: ");
    Serial.println(z1Flow);
  }
  else if (NODE==2){
    z2Temp = (float)TEMP/1000;
    z2Flow = (float)FLOW/1000;
    Serial.print("Zone 2 Temp: ");
    Serial.println(z2Temp);
    Serial.print("Zone 2 Flow: ");
    Serial.println(z2Flow);
  }
  else if (NODE==3){
    z3Temp = (float)TEMP/1000;
    z3Flow = (float)FLOW/1000;
    Serial.print("Zone 3 Temp: ");
    Serial.println(z3Temp);
    Serial.print("Zone 3 Flow: ");
    Serial.println(z3Flow);
  }
  else if (NODE==4){
    z4Temp = (float)TEMP/1000;
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
