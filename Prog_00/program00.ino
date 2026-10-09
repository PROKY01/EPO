
/*	Prog_00
	Blikani LED
*/
//deklarace promennych
int Pins_Out[] = {2,3,4,5,6,7,8,9};
unsigned char pozice=0;

//metoda setup
void setup()
{
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
	if (++pozice > 7) pozice=0;
	digitalWrite(Pins_Out[pozice], HIGH);
	delay(1000);
}
