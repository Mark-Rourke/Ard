#include <LiquidCrystal.h>
#include <DateTime.h>
#include <DateTimeStrings.h>

#define dt_SHORT_DAY_STRINGS
#define dt_SHORT_MONTH_STRINGS

// simple sketch to display a digital clock on an LCD
// see the LiquidCrystal documentation for more info on this

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int backLight = 13; // pin 13 will control the backlight

void setup(){
pinMode(backLight, OUTPUT);
digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.

DateTime.sync(DateTime.makeTime(0, 44, 13, 16, 10, 2010)); // sec, min, hour, date, month, year // Replace this with the most current time
}

void loop(){
if(DateTime.available()) {
unsigned long prevtime = DateTime.now();
while( prevtime == DateTime.now() ) // wait for the second to rollover
;

DateTime.available(); //refresh the Date and time properties
digitalClockDisplay( ); // update digital clock
}
}

void printDigits(byte digits){
// utility function for digital clock display: prints preceding colon and leading 0
lcd.print(":");
if(digits < 10)
lcd.print('0');
lcd.print(digits,DEC);
}



void digitalClockDisplay(){
lcd.clear();
lcd.begin(16,2);
lcd.setCursor(3,0);

//lcd.print(DateTimeStrings.dayStr(DateTime.DayofWeek));
if(DateTime.Day <10)
lcd.print('0');
lcd.print(DateTime.Day,DEC);
lcd.print("/");

//lcd.print(DateTimeStrings.monthStr(DateTime.Month));
if(DateTime.Month <10)
lcd.print('0');
lcd.print(DateTime.Month,DEC);
lcd.print("/");
lcd.print((DateTime.Year,DEC)+2000);

//lcd.print(" ");
if(DateTime.Hour <10)
lcd.setCursor(5,1);
lcd.setCursor(4,1);

// digital clock display of current time
lcd.print(DateTime.Hour,DEC);
printDigits(DateTime.Minute);
printDigits(DateTime.Second);
