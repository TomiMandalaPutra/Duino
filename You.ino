/*PROGRAM SENSOR SUHU LM35 DENGAN TAMPILAN LCD 16X2
 * JANGAN LUPA FOLLOW IG @duiogram
 * JANGAN LUPA KUNJUNGI www.duinoelektronik.blogspot.com
 * DUKUNG KAMI DALAM MEMBERI ILMU PENGETAHUAN DENGAN CARA SUBSCRIBE, COMMENT, DAN LIKE
 * CHANNEL YOUTUBE www.youtube.com/channel/UC_fv2BRFv2zde5ZMQ5uqauA
 * selamat mencoba.....
*/
#include <LiquidCrystal.h> //librari LCD 16x2
LiquidCrystal lcd(5,4,3,2,1,0);//pin ldc ke arduino
/*
 * pin D7 ke pin 0 arduino
 * pin D6 ke pin 1 arduino
 * pin D5 ke pin 2 arduino
 * pin D4 ke pin 3 arduino
 * pin E ke pin 4 arduino
 * pin RS ke pin 5 arduino
*/

const int LM35 = A0;
float pengukuran = 0;
float tegangan = 0;
float suhu = 0;
void setup() 
{
  lcd.begin(16, 2);//set baris dan kolom pada LCD
  lcd.setCursor(0,0);//set baris posisi 0 dan kolom posisi 0
  lcd.print("SENSOR SUHU LM35");//tulisan yang ditampilkan
  lcd.setCursor(0,1);//set baris posisi 1 dan kolom posisi 0
  lcd.print("duino elektronik");//tulisan yang ditampilkan
  delay(2000);//waktu tampil 2 detik
  lcd.clear();
}

void loop() 
{
  //rumus ADC pada sensor LM35
  pengukuran = analogRead(LM35);
  tegangan = (pengukuran*5000)/1023;
  suhu = tegangan/10;//dalam Celsius

  //menampilkan pengukuran
  lcd.setCursor(3,0);
  lcd.print("PENGUKURAN");
  lcd.setCursor(0,1);
  lcd.print("SUHU:");
  lcd.setCursor(5,1);
  lcd.print(suhu,2);//nilai 2 angka dibelakang koma
  lcd.setCursor(10,1);
  lcd.print((char)223);//menampilkan simbol derajat
  lcd.setCursor(11,1);
  lcd.print("C");
  delay(500);
}
