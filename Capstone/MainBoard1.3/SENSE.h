//---Global Variables----
int NODE, TEMP, FLOW, PRES;//Used in the MESH.h library
int z1Temp, z2Temp, z3Temp, z4Temp;
int z1Flow, z2Flow, z3Flow, z4Flow;

void sExtract(){
  if (NODE==1){
    z1Temp = TEMP;
    z1Flow = FLOW;
    Serial.print("Zone 1 Temp: ");
    Serial.println(z1Temp);
    Serial.print("Zone 1 Flow: ");
    Serial.println(z1Flow);
  }
  else if (NODE==2){
    z2Temp = TEMP;
    z2Flow = FLOW;
    Serial.print("Zone 2 Temp: ");
    Serial.println(z2Temp);
    Serial.print("Zone 2 Flow: ");
    Serial.println(z2Flow);
  }
  else if (NODE==3){
    z3Temp = TEMP;
    z3Flow = FLOW;
    Serial.print("Zone 3 Temp: ");
    Serial.println(z3Temp);
    Serial.print("Zone 3 Flow: ");
    Serial.println(z3Flow);
  }
  else if (NODE==4){
    z4Temp = TEMP;
    z4Flow = FLOW;
    Serial.print("Zone 4 Temp: ");
    Serial.println(z4Flow);
    Serial.print("Zone 4 Flow: ");
    Serial.println(z4Flow);
  }
  else{
    Serial.println("Zone Sense Error");
  }
}
