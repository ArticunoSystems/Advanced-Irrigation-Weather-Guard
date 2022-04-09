float tarFlow = 10;//target/ideal flow rate
float tolFlow = 1;//tolerable deviance from target
bool z1Leak = false;
bool z1Clog = false;
bool z2Leak = false;
bool z2Clog = false;
bool z3Leak = false;
bool z3Clog = false;

void LnCSetup(){
  
}

void z1Check(){
  if(((tarFlow+tolFlow) >= z1Flow) && ((tarFlow-tolFlow) <= z1Flow)){
    Serial.println("z1 is good");
    z1Leak = false;
    z1Clog = false;
  }
  if(z1Flow > (tarFlow+tolFlow)){
    Serial.println("z1 Leak");
    z1Leak = true;
    z1Clog = false;
  }
  if(z1Flow < (tarFlow-tolFlow)){
    Serial.println("z1 Clog");
    z1Leak = false;
    z1Clog = true;
  }
}
void z2Check(){
  if((z2Flow <= (tarFlow+tolFlow)) && (z2Flow >= (tarFlow-tolFlow))){
    if((z2Clog == true) || (z2Leak == true)){
      Serial.println("z2 is good");
    }
    z2Leak = false;
    z2Clog = false;
  }
  if(z2Flow > (tarFlow+tolFlow)){
    if(z2Leak == false){
      Serial.println("z2 Leak");
    }
    z2Leak = true;
    z2Clog = false;
  }
  if(z2Flow < (tarFlow-tolFlow)){
    if(z2Clog == false){
      Serial.println("z2 Clog");
    }
    z2Leak = false;
    z2Clog = true;
  }
}
void z3Check(){
  if((z3Flow <= (tarFlow+tolFlow)) && (z3Flow >= (tarFlow-tolFlow))){
    Serial.println("z3 is good");
    z3Leak = false;
    z3Clog = false;
  }
  if(z3Flow > (tarFlow+tolFlow)){
    Serial.println("z3 Leak");
    z3Leak = true;
    z3Clog = false;
  }
  if(z3Flow < (tarFlow-tolFlow)){
    Serial.println("z3 Clog");
    z3Leak = false;
    z3Clog = true;
  }
}
