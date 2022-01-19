#include <LiquidCrystal.h>                     //Dette er biblioteket vi bruker til å bruke lcd-panelet.
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // reisistor av R1 på 100K
float R2 = 10000.0; // resistor av R2  på 10K
int value = 0;

// det over er kun til parameterere



void setup() {
  Serial.begin(9600);                       //Forteller arduinoen at den skal starte
  pinMode(A0, INPUT);              //"aktiverer" en input
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("DC VOLTMETER AV ");                // Skal komme opp at dette er et DC volt-meter
  lcd.setCursor(0, 1);
  lcd.print("-B,T,S,Z-");                     //initalene vårt skal komme opp, for å vise alle gruppe medlemmene (altsa Biraveen,Tommy,Shoaib og Zishan)
  delay(3000);
  lcd.clear();                                //Tømmer LCD-skjermen og plasserer markøren i øvre venstre hjørne.

}
void loop() {
  lcd.print("DC Voltmeter");               
  value = analogRead(A0);                   //leser verdien av en analog pin
  vout = (value * 5) / 1024.0;              // beregninger for V_ut ((((det som går til analog input). her ganges value med 5 fordi pga forsynningspenningen, juster om den er over eller under. deretter deler vi med 1024.0(ADC-verdi). denne er koblet til analogpinnen)))) 
  vin = vout / (R2 / (R1 + R2));            // beregninger for V_inn
 
  
  lcd.setCursor(0, 1);
  lcd.print("Spenning:");               //skriver ut "Volt/Spenning:"
  
  lcd.print(vin);                          // skriver ut hvor mye spenningen er på 
  
  delay(3000);                            // en liten delay på på 3 sec
  lcd.clear();                           //Tømmer LCD-skjermen og plasserer markøren i øvre venstre hjørne.
}
