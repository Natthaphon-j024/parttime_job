
int O1 = A7;
int val = 0;
void setup() {
Serial.begin(9600);
}
 
void loop() {
val = analogRead(O1); //อ่านค่าสัญญาณ digital ขา8 ที่ต่อกับ เซ็นเซอร์ตรวจจับวัตถุ IR Infrared
Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
Serial.println(val); // พิมพ์ค่าของตัวแปร val
delay(100);
}
