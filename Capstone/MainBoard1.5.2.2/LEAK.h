float tarFlow = 6;//target/ideal flow rate
float tolFlow = 0.5;//tolerable deviance from target

bool z1Leak = false;
bool z1Clog = false;
bool z2Leak = false;
bool z2Clog = false;
bool z3Leak = false;
bool z3Clog = false;

bool CalFlow = false;
float Calz1Flow = 6;
float Calz2Flow = 6;
float Calz3Flow = 6;

void LnCSetup(){
  
}

void z1Check(){
  if(CalFlow == true){
    Calz1Flow = z1Flow;
  }
  if(((Calz1Flow+tolFlow) >= z1Flow) && ((Calz1Flow-tolFlow) <= z1Flow)){
    if((z1Clog == true) || (z1Leak == true)){
      Serial.println("update: z1 good");
    }
    z1Leak = false;
    z1Clog = false;
  }
  if(z1Flow > (Calz1Flow+tolFlow)){
    if(z1Leak == false){
      Serial.println("update: z1 Leak");
    }
    z1Leak = true;
    z1Clog = false;
  }
  if(z1Flow < (Calz1Flow-tolFlow)){
    if(z1Clog == false){
      Serial.println("update: z1 Clog");
    }
    z1Leak = false;
    z1Clog = true;
  }
}
//--------Zone 2--------
void z2Check(){
  if(CalFlow == true){
    Calz2Flow = z2Flow;
  }
  if(((Calz2Flow+tolFlow) >= z2Flow) && ((Calz2Flow-tolFlow) <= z2Flow)){
    if((z2Clog == true) || (z2Leak == true)){
      Serial.println("update: z2 good");
    }
    z2Leak = false;
    z2Clog = false;
  }
  if(z2Flow > (Calz2Flow+tolFlow)){
    if(z2Leak == false){
      Serial.println("update: z2 Leak");
    }
    z2Leak = true;
    z2Clog = false;
  }
  if(z2Flow < (Calz2Flow-tolFlow)){
    if(z2Clog == false){
      Serial.println("update: z2 Clog");
    }
    z2Leak = false;
    z2Clog = true;
  }
}
//--------Zone 3--------
void z3Check(){
  if(CalFlow == true){
    Calz3Flow = z3Flow;
  }
  if(((Calz3Flow+tolFlow) >= z3Flow) && ((Calz3Flow-tolFlow) <= z3Flow)){
    if((z3Clog == true) || (z3Leak == true)){
      Serial.println("update: z3 good");
    }
    z3Leak = false;
    z3Clog = false;
  }
  if(z3Flow > (Calz3Flow+tolFlow)){
    if(z3Leak == false){
      Serial.println("update: z3 Leak");
    }
    z3Leak = true;
    z3Clog = false;
  }
  if(z3Flow < (Calz3Flow-tolFlow)){
    if(z3Clog == false){
      Serial.println("update: z3 Clog");
    }
    z3Leak = false;
    z3Clog = true;
  }
}
