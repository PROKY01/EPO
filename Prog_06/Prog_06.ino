
/*	This is a default program--
	Use File->Load Prog to load a different program
*/

int cislo;

void setup()
{
	
}

void loop()
{
	cislo = analogRead(A0);
	analogWrite(11, map(cislo, 0, 1023, 0, 255))
}
