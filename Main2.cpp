#include "Raetsel.cpp"
#include "help.cpp"
#include <iostream>

using namespace std;


int main(void) {
    neo neop;
	bool ledrdy = false;
	bool Humrdy = false;
    bool rightTemp;
	int Z = 0;
    int x = 0; 
	int y = 0;
	bool LED;
	int num;

	Raetsel r;

    if (ledrdy == false) {

        //Wir schauen ob die Temperatur hoch genug ist."Damit es der Box nicht zu kalt wird"

        if(x == 0){
         r.Tempinit(0,curTemp);           //ANSTATT "curTemp" hier die Temeratur vom sensor einfügen!
         x++;   
        }
        if (r.TempRaezl(curTemp)){        //ANSTATT "curTemp" hier die Temeratur vom sensor einfügen!
		neop.clear();

        //Temperatur ist warm genug also zum LED-Rätsel

		if (Z == 0) {
			for (int i = 0; i < 8; i++) { //Falls das Rätsel noch nicht initalisiert wurde wird es hier initialisiert
				LED = r.LEDinit(1, 5, i);
				Z++;
				if (LED == true) {
					neop.set(BLUE, i);
				}
			}
			neop.show();
            HAL_Delay(500);			
		}
		else if (Z != 0) {                 //Falls es bereits initialisiert wurde ändern wir hier welche LEDs an sind via Keypad
			num = getKey();                 //Wir bekommen welche Tasteam Keypad gedrückt wurde
			ledrdy = r.LEDRaezl(num);
            neop.clear();
			for(int i = 0; i < 8; i++){    //Wir setzen die LEDs an der richtigen stelle auf an
				LED = r.getLEDs(i);            
				if (LED == true) {
					neop.set(BLUE, i);
				}
			}
			neop.show();
            HAL_Delay(500);			
			}
		}
    }   

		
	/*				Humidity-Rätsel 				*/


	if(ledrdy == true){
		if(Humrdy == false){
			if(y == 0){
				r.Humidityinit(curHum, HumChange);
			}
			else{
				int HumW = r.HumRaetsel(curHum);
				neop.clear();
				switch(HumW){
					case(0):
						neop.set(BLUE, 1);
						neop.set(BLUE, 2);
						neop.set(BLUE, 0);
						//sprintf...
						//HAL_UART_Transmit(&huart2,buf,strlen((char*)buf),HAL_MAX_DELAY);
						break;
					case(1):
						neop.set(GREEN, 1);
						neop.set(GREEN, 2);
						neop.set(GREEN, 0);
						//sprintf...
						//HAL_UART_Transmit(&huart2,buf,strlen((char*)buf),HAL_MAX_DELAY);
						break;
					case(2):
						neop.set(RED, 1);
						neop.set(RED, 2);
						neop.set(RED, 0);
						//sprintf...
						//HAL_UART_Transmit(&huart2,buf,strlen((char*)buf),HAL_MAX_DELAY);
						break;
				}
				neop.show();			
			}
		}
	}





    //Helping Func

	

};
int getKey(void){
        return 2;
    }  
void HAL_Delay(int i){
    return;
}
