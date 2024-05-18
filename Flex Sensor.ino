#define led_pin 9
#define flex_pin A0

int flex_reading;
int led_brightness;

void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{ 
  flex_reading = analogRead(A0);
  Serial.println(flex_reading);
  
  led_brightness = map(flex_reading, 0, 300, 0, 1023);
  analogWrite(9, led_brightness);
  
  delay(200);
}
