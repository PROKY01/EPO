/*	Prog_04
	Blikani LED tam i zpet
*/
//deklarace promennych
int Pins_Out[] = {2,3,4,5,6,7,8,9};
char pozice=0;
boolean smer;
boolean start_stop;
char pocetLED;

//metoda setup
void setup()
{
	smer=true;
	for (int i=0; i<8; i++)
	{
		pinMode(Pins_Out[i], OUTPUT);
		digitalWrite(Pins_Out[i], LOW);
	}
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);
	pinMode(A2, INPUT);
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
	start_stop = digitalRead(A2);
	pocetLED = digitalRead(A0) * 1 + digitalRead(A1) * 2 + 1;

	if(start_stop == HIGH)
	{
		zobrazLED(pozice, pocetLED , LOW);
		if (smer)
		{
			if (++pozice > 7) 
			{
				pozice=6;
				smer=false;
			}
		}
		else
		{
			if (--pozice <= -(pocetLED - 1)) 
			{
				smer=true;
			}
		}
		zobrazLED(pozice, pocetLED, HIGH);
		delay(1000);
	}
}
