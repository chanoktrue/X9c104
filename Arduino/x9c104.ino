  /*  
Modified on Dec 12, 2020
Modified by MehranMaleki from Arduino Examples
https://electropeak.com/learn/
*/

/*                                                                                                                                     
 * For this example, connect your X9C104 (or the like) as follows:
 * 1 - INC - Arduino pin 2
 * 2 - U/D - Arduino pin 3
 * 3 - RH  - 5V
 * 4 - VSS - GND
 * 5 - RW  - Output: Arduino pin A0 for analogRead
 * 6 - RL  - GND
 * 7 - CS  - Arduino pin 4
 * 8 - VCC - 5V
 */


#include <DigiPotX9Cxxx.h>


#define PIN1 D0
#define PIN2 D1
#define PIN3 D2

DigiPot pot(PIN1,PIN2,PIN3);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Starting");  
  float voltage;
  
  for (int i=0; i<100; i++) {
    pot.increase(1);
    voltage = 5.0 * analogRead(A0)  / 1024;
    Serial.println(voltage);
    delay(20);
  }
  
  
  for (int i=0; i<100; i++) {
    pot.decrease(1);
    voltage = 5.0 * analogRead(A0) / 1024;
    Serial.println(voltage);
    delay(20);
  }

}
 
