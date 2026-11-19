/*  Prog_08 - Samostatná práce (upraveno v tvém stylu)
    Blikani LED tam i zpet
*/
//deklarace promennych
int Pins_Out[] = {2,3,4,5,6,7,8,9};
char pozice = 0;
boolean smer;
boolean start_stop;
char pocetLED;
int cas[] = {200, 400, 800, 1600};
char indexCasu;

//metoda setup
void setup()
{
	smer = true;
	for (int i = 0; i < 8; i++)
	{
		pinMode(Pins_Out[i], OUTPUT);
		digitalWrite(Pins_Out[i], LOW);
	}

	pinMode(10, INPUT);
	pinMode(11, INPUT);
	pinMode(18, INPUT);
}

void zobrazLED(char startPozice, char pocet, boolean stav)
{
	for (char i = 0; i < pocet; i++)
	{
		char akt_poz = startPozice + i;
		if (akt_poz >= 0 && akt_poz < 8)
		{
			digitalWrite(Pins_Out[akt_poz], stav);
		}
	}
}

//metoda loop
void loop()
{
	if (digitalRead(A4) == LOW) {
		pocetLED = 2;
	} else {
		pocetLED = 1;
	}

	// Ètení rychlosti ze dvou pinù (10 a 11) -> 4 kombinace (index 0 až 3)
	indexCasu = digitalRead(10) * 1 + digitalRead(11) * 2;

	// Samotná logika blikání
	zobrazLED(0, 8, LOW);
	if (smer)
	{
		if (++pozice > (8 - pocetLED)) 
		{
			pozice = 8 - pocetLED - 1;
			smer = false;
		}
	}
	else
	{
		if (--pozice < 0) 
		{
			pozice = 0;
			smer = true;
		}
	}
	zobrazLED(pozice, pocetLED, HIGH);
	delay(cas[indexCasu]);
}