#include <FlexCAN.h>

static CAN_message_t inMsg;
  
void setup() {
  Serial.begin(115200);
  Can0.begin(500000); 
  Serial.println("Time,ID,Data");
}

void loop() {
  if (Can0.available()) {
    Can0.read(inMsg);
    log_msg(&inMsg);
  }
}


// prints the message to the console with the bus 
void log_msg(CAN_message_t* printMsg, uint8_t origin_bus) {
    Serial.print(micros()/100000);
    Serial.print(".");
    Serial.print(micros()); 
    Serial.print(",");
    Serial.print(printMsg->id); 
    // Serial.print(printMsg->id, HEX);  // for printing in hex
    Serial.print(",");  
    Serial.print(origin_bus);
    Serial.print(","); 
    uint8_t count = printMsg->len;
    for(size_t i = 0; i < count; i++) {    
        
        if(printMsg->buf[i] < 16) {   // Need to check for the 0X case.
            Serial.print("0"); Serial.print(printMsg->buf[i], HEX);
        } else {
            Serial.print(printMsg->buf[i], HEX); 
        }
    }
    Serial.println();
}

// prints the message to the console without the bus 
void log_msg(CAN_message_t* printMsg) {
    Serial.print(micros()/100000);
    Serial.print(".");
    Serial.print(micros()); 
    Serial.print(",");
    Serial.print(printMsg->id); 
    // Serial.print(printMsg->id, HEX);  // for printing in hex
    Serial.print(",");  
    uint8_t count = printMsg->len;
    for(size_t i = 0; i < count; i++) {    
        
        if(printMsg->buf[i] < 16) {   // Need to check for the 0X case.
            Serial.print("0"); Serial.print(printMsg->buf[i], HEX);
        } else {
            Serial.print(printMsg->buf[i], HEX); 
        }
    }
    Serial.println();
}
