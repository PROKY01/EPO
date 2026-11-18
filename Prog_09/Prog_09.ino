//prog_09
//matice a diagonaly

//deklarace promennych
int x,n;
int matice[10][10];
int suma_h;
int suma_y;

//metoda set up
void setup()
{
	Serial.begin(9600);
	while(!Serial) {	;}
	Serial.println("Serial OK");
	Serial.print("Zadej velikost matice (2 az 10): ");

}

//metoda loop
void loop()
{
	if(Serial.available())
	{
		suma_h = 0;
		suma_y = 0;
		x = Serial.readString().toInt();
		Serial.println(x);
		if(x >= 2 && x<= 10)
		{
			for(int j = 0; j <x; j++)
			{
				for(int i = 0; i < x; i++)
				{
					n = random(-99, 100);
					matice[j][i] = n;
					if(j == i) suma_h += n;
					if(j + i == (x - 1)) suma_y += n;
					if(n > -1) Serial.print(" ");
					if(n < 10 && n > - 1) Serial.print(" ");
					if(n > -10 && n < 0) Serial.print(" ");
					Serial.print(n);
					Serial.print(" ");
				}
				Serial.println();
			}
		}
		Serial.print("Zadej velikost matice (2 az 10): ");
	}
}
