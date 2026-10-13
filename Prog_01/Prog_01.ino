
/*	Prog_01
	Blikani LED tam i zpet
*/
//deklarace promennych
int Pins_Out[] = {2,3,4,5,6,7,8,9};
unsigned char pozice=0;
boolean smer;

//metoda setup
void setup()
{
	smer=true;
	for (int i=0; i<8; i++)
	{
		pinMode(Pins_Out[i], OUTPUT);
		digitalWrite(Pins_Out[i], LOW);
	}
	digitalWrite(Pins_Out[pozice], HIGH);
	delay(1000);

}

//metoda loop
void loop()
{
	digitalWrite(Pins_Out[pozice], LOW);
	if (smer)
	{
		if (++pozice > 7)
		{
			pozice=6;
			smer=false;
		}
	}else
	{
		digitalWrite(Pins_Out[pozice], LOW);
		if (--pozice == 255)
		{
			pozice=1;
			smer=true;
		}
	}
	digitalWrite(Pins_Out[pozice], HIGH);
	delay(1000);
}
