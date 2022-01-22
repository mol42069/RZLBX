#include "Rätsel.cpp"
#include <iostream>

using namespace std;


int main(void) {
	bool ledrdy = false;
	int Z = 0; 
	bool LED;
	int num = getKey();
	


	if (ledrdy == false) {
		Raetsel r;
		neop.clear();

		if (Z == 0) {
			for (int i = 0; i < 8; i++) {
				LED = r.LEDinit(1, 5, i);
				Z++;
				if (LED == true) {
					neop.set(BLUE, i);
				}
			}
			neop.show();
			
		}
		else if (Z != 0) {
			num = getKey();
			r.LEDRaezl(num);
			for(int i = 0; i < 8; i++){
				LED = r.getLEDs(i);
				if (LED == true) {
					neop.set(BLUE, i);
				}

			}
			neop.show();
			
		}
	}
	
	

};
