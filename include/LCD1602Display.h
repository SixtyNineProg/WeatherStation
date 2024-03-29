/*
  The circuit:
   Display
 ** SCL A5
 ** SDA A4
*/

#include <Wire.h>              // Подключение библиотеки для I2C
#include <LiquidCrystal_I2C.h> // Подключение библиотеки для управления LCD1602

#define STRING(Value) #Value

class Lcd1602Display
{
public:
    Lcd1602Display();
    LiquidCrystal_I2C lcd;

    void init();
    void draw(float bmeHumidity, float bmeTemperature, float bmePressure, int ppm);
};

// адрес дисплея 0x3f или 0x27
// размер дисплея 16x2 (поддерживаются и другие, например 20x4)
// адрес, столбцов, строк
Lcd1602Display::Lcd1602Display() : lcd(0x27, 16, 2)
{
}

void Lcd1602Display::init()
{
    lcd.init();
    lcd.backlight();
}

void Lcd1602Display::draw(float bmeHumidity, float bmeTemperature, float bmePressure, int ppm)
{
    lcd.setCursor(0, 0);
    lcd.print("H:" + String(bmeHumidity));
    lcd.setCursor(0, 1);
    lcd.print("T:" + String(bmeTemperature));
    lcd.setCursor(8, 0);
    lcd.print("P:" + String(bmePressure));
    lcd.setCursor(8, 1);
    lcd.print("PPM:" + String(ppm));
};