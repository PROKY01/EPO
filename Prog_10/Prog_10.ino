
/*	Prog_10
	vypis cisla pozadu
*/
//deklarace promennych
int x;
int y = 0;
int pom;
//metoda setup
void setup()
{
	Serial.begin(9600);
	while(!Serial) {	;}
	Serial.println("Serial OK");
	Serial.print("Zadejte velikost cislo: ");

}

//metoda loop
void loop()
{
	if(Serial.available())
	{
		x = Serial.readString().toInt();
		Serial.println(x);
		pom = x;
		y = 0;
		//while(pom)
		for(int i = 0; i<3; i++)
		{
			y *= 10;
			y += pom % 10;
			pom = pom / 10;
		}

/*
		y = x % 10;
		y *= 10;
		y += x / 10 % 10;
		y *= 10;
		y += x / 10 % 10;
		*/	
		Serial.print("Reverzni cislo: ");
		Serial.println(y);

		Serial.print("Zadejte velikost cislo: ");
	}
}
