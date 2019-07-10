#include <LiquidCrystal.h>
#include <dht.h>
// 引入函数库

#define dhtPin 11 //定义dht11的数据pin为arduino的digitalpin 11
LiquidCrystal lcd(9, 8, 2, 3, 4, 5);  //创建lcd的instance
dht dht11; //创建sensor的instance

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);  //初始化lcd，并指定显示尺寸
}

void loop() {
  // put your main code here, to run repeatedly:
  refreshData();
}

//自定义数据刷新函数
void refreshData(){
  int readData = dht11.read11(dhtPin); //从sensor中读取数据
  float temp = dht11.temperature;
  float humi = dht11.humidity;
  //定义两个float变量用来分别存储温度和湿度数据，dht11只返回int型数据，dht22可返回float型数据
  lcd.setCursor(0, 0); //设置lcd光标至第一行第一位
  lcd.print("Temp.: ");
  lcd.print(temp);
  lcd.print(" C");
  //显示温度数据
  lcd.setCursor(0, 1);  //设置lcd光标至第二行第一位
  lcd.print("Humi.: ");
  lcd.print(humi);
  lcd.print(" %");
  //显示湿度数据
  //1分钟后刷新数据
  delay(60000);
  lcd.clear();
  lcd.print("Refreshing");
  lcd.setCursor(0, 1);
  lcd.print("Data...");
  delay(5000);
  lcd.clear();
}
