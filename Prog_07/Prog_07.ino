//prog_07

//deklarace promennych
long a,b;
long s; 
//metoda set up
void setup()
{
	Serial.begin(9600);
	while (!Serial) {	;} // wait for serial port to connect. Needed for native USB
	Serial.println("Serial ok");
	Serial.print("Zadej stranu a: ");
}

//metoda loop
void loop()
{
	if(Serial.available())
	{
		a = Serial.readString().toInt();
		Serial.println(a);
		Serial.print("Zadej stranu b: ");
		while(!Serial.available()) {	;}
		b = Serial.readString().toInt();
		Serial.println(b);
		s = a*b;
		Serial.print("Obsah obdelniku je S: ");
		Serial.println(s);
		Serial.print("Zadej stranu a: ");
	}
}
