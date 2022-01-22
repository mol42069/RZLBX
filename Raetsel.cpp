#include <iostream>
#include "Ausgabe.cpp"

class Raetsel {

public:
	
	/*
			LED-RÄTSEL								(An/Aus-schalt-Rätsel)
	*/
	bool LEDFIN = false;
	bool LEDs[8];									//<-- Das LED-Array bestimmen
	bool LEDinit(int configLED1, int configLED2, int z) {	//initialisierung des LED-rätsels
		if (z != configLED1 && z != configLED2) {
			LEDs[z] = false;
		}
		else{
			LEDs[z] = true;
		}
		
		return LEDs[z];
	}

	bool getLEDs(int z){
		return LEDs[z];
	}



	void LEDRaezl(int num) {
		  												//num ist vom NumPad
		  if (LEDFIN == false) {
			  if (0 < num && num < 9) {					//Wir checken ob eine gültige taste gedrückt wurde
				  if (num == 1) {						//Wir schauen ob die Linke Rand-LED gewählt wurde
					  LEDs[num - 1] = !LEDs[num - 1];	//Wir schalten die LED um
					  LEDs[num] = !LEDs[num];			//sowie die anligende LED
				  }
				  else if (num == 8) {					//Wir schauen ob die Rechte Rand-LED gewählt wurde
					  LEDs[num - 1] = !LEDs[num - 1];	//Siehe oben 
					  LEDs[num - 2] = !LEDs[num - 2];	//Siehe oben 
				  }
				  else {								//Wir ändern die ausgewählte LED sowie die beiden anliegenden
					  LEDs[num] = !LEDs[num];
					  LEDs[num - 1] = !LEDs[num - 1];
					  LEDs[num - 2] = !LEDs[num - 2];
				  }
				  int Goal = 0;
				  for (int i = 0; i < 8; i++) {			//Wir schauen ob alle LEDs aus sind!
					  if (LEDs[i] == 0) {
						  Goal++;
						  if (Goal == 8) {
							  LEDFIN = true;
						  }
					  }
				  }
				  return;
			  }
			  else {
				  return;
			  }
		  }

	  }
	
	/*
			TEMPERATUR-RÄTSEL
	*/
	
	double FinalTemp;						//speichern der zu erreichenden Temperatur
	void Tempinit(double tc) {				//Temprätsel wird initialisiert (Console)
		Ausgaben A;
		double StartTemp = A.doubin();		//Speichern der Anfangstemperatur(Sensor)
		double tempchange = tc;				//einstellung wv wärmer es werden soll(Console)
		FinalTemp = StartTemp + tempchange;
	}
	void TempRaezl(){
		Ausgaben A;
		double curTemp = A.doubin();		//bekomme die momentane Temperatur!(Sensor)
		while (FinalTemp > curTemp) {
			A.strausgeben("Es ist etwas zu kalt fuer die Box: ");
			A.doubout(curTemp);
			cout << endl;
			curTemp = A.doubin();			//bekomme die momentane Temperatur!(Sensor)
		}
	}


	/*
			...-RÄTSEL
	*/

	/*
	
	neop.set(Red,i);
	neop.show();
	neop.clear();
	HAL_UART_Transmit(&huart2,buf,strlen((char*)buf), HAL_MAX_DELAY);
	sprintf...
	*/





};

