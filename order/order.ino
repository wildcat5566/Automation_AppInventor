void setup(){
	Serial.begin(9600);
}

void client_info(byte _client){
	switch(_client){
		case 1:
			Serial.print("Angela");
			break;
		case 2:
			Serial.print("Warren");
			break;
		case 3:
			Serial.print("Tobby");
			break;
		case 4:
			Serial.print("Tom");
			break;
		case 5:
			Serial.print("Johnson");
			break;
	}
}

void merchandise_info(byte _merchandise){
        switch(_merchandise){
                case 1:
                        Serial.println("Red");
                        break;
                case 2:
                        Serial.println("Orange");
                        break;
                case 3:
                        Serial.println("Yellow");
                        break;
                case 4:
                        Serial.println("Green");
                        break;
                case 5:
                        Serial.println("Blue");
                        break;
		case 6:
			Serial.println("Purple");
        }
}



void loop(){
       while(Serial.available()>1){
                byte client = Serial.read()-'0';
                byte merchandise = Serial.read()-'0';
                client_info(client);
                Serial.print(",");
                merchandise_info(merchandise);
       }
	delay(100);
}


