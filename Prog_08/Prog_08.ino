//prog_07

//deklarace promennych
long cislo;

boolean test(long hodnota)
{
	bool tmp = true;
	long prvo_i = 2;
	if(hodnota <2)
	{
		tmp = false;
		return tmp;	
	}
	while(tmp && prvo_i <= sqrt(hodnota))
	{
		Serial.println(prvo_i);
		if(hodnota % prvo_i == 0) tmp = false;
		prvo_i++;
		if(prvo_i>3) prvo_i++;
	}

	return tmp;	
}

//metoda set up
void setup()
{
	Serial.begin(9600);
	while (!Serial) {	;} // wait for serial port to connect. Needed for native USB
	Serial.println("Program test na prvocislo");
	Serial.print("Zadej cislo: ");
}

//metoda loop
void loop()
{
	if(Serial.available())
	{
		cislo = Serial.readString().toInt();
		Serial.println(cislo);
		if(test(cislo))
		{
			Serial.println("ano");
		}
		else
		{
			Serial.println("ne");
		}
		Serial.print("Zadej cislo: ");
	}
}
