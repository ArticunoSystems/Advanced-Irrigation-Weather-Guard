
#include "painlessMesh.h"
#include <Arduino_JSON.h>
#include "FLOW.h"
#include "TEMP.h"

// MESH Details
#define   MESH_PREFIX     "GuardMesh" //name for your MESH
#define   MESH_PASSWORD   "Capstone123" //password for your MESH
#define   MESH_PORT       5555 //default port

//Number for this node
int nodeNumber = 3;

//String to send to other nodes with sensor readings
String readings;

Scheduler userScheduler; // to control your personal task
painlessMesh  mesh;

// User stub
void sendMessage() ; // Prototype so PlatformIO doesn't complain
String getReadings(); // Prototype for sending sensor readings

//Create tasks: to send messages and get readings;
Task taskSendMessage(TASK_SECOND * 1 , TASK_FOREVER, &sendMessage);

String getReadings () {
  JSONVar jsonReadings;
  JSONVar FLOW;
  JSONVar TEMP;
  TEMP = (JSONVar)(Temp*1000);
  FLOW = (JSONVar)(flowRate*1000);
  jsonReadings["node"] = nodeNumber;
  jsonReadings["temp"] = TEMP;
  jsonReadings["flow"] = FLOW;
  jsonReadings["pres"] = 30;
  readings = JSON.stringify(jsonReadings);
  return readings;
}

void sendMessage () {
  String msg = getReadings();
  mesh.sendBroadcast(msg);
}

// Needed for painless library
void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf("Received from %u msg=%s\n", from, msg.c_str());
  JSONVar myObject = JSON.parse(msg.c_str());
  int node = myObject["node"];
  double temp = myObject["temp"];
  double flow = myObject["flow"];
  double pres = myObject["pres"];
  Serial.print("Node: ");
  Serial.println(node);
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.print("Flow Rate: ");
  Serial.print(flow);
  Serial.println(" %");
  Serial.print("Pressure: ");
  Serial.print(pres);
  Serial.println(" hpa");
}

void newConnectionCallback(uint32_t nodeId) {
  Serial.printf("New Connection, nodeId = %u\n", nodeId);
}

void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}

void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(),offset);
}

void setup() {
  Serial.begin(115200);
  FlowSetup();
  TempSetup();
  
//mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC | COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
  mesh.setDebugMsgTypes( ERROR | STARTUP );  // set before init() so that you can see startup messages

  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

  userScheduler.addTask(taskSendMessage);
  taskSendMessage.enable();
}
void loop() {
  mesh.update();
  Current_Time = millis();
  //TempLoop();
  if(Current_Time >= (LoopFlow_Time + 1000)){
    LoopFlow_Time = Current_Time;
    Liter_per_min = (Pulse_Count / 5.5);
    flowRate = (Liter_per_min / 3.785);
    Pulse_Count = 0; //gal/min
    //Serial.print(flowRate, 3);
    //Serial.println(" Gal/min");
  }
  if(Current_Time >= (LoopTmp_Time + 100)){
    LoopTmp_Time = Current_Time;
    Temp = TempLoop();
    //Serial.print("Temp: ");
    //Serial.print(Temp);
    //Serial.println(" F");
  }
  
}
