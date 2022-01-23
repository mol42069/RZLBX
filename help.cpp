#include <string>
#include <iostream>
enum E{BLUE =000,
        GREEN = 001,
        RED = 002       
    };


static const double curTemp = 20;
static const int curHum = 50;
static const int HumChange = 0;
static const void HAL_DELAY(int i);
class neo{
public:

    void clear();
    void set(E str, int b){
        std::cout << b;
    };
    void show();

};

 
