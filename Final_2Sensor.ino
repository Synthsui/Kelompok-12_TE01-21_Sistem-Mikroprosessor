// Pin untuk Sensor PIR
const int pirPin = 8;
// Pin untuk Sensor MQ-7
const int mq7Pin = A0;
// Pin untuk Buzzer
const int buzzerPin = 5;
// Pin untuk LED
const int ledPin = 7;
// Pin untuk Lampu Rumah
const int ledRumah = 6;

// Variabel status deteksi
bool gasDetected = false;
bool motionDetected = false;

int val = 0;
int pirState = LOW;

void setup() {
  // Mengatur pin-mode
  pinMode(pirPin, INPUT);
  pinMode(mq7Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledRumah, OUTPUT);
  // Menghentikan Buzzer dan LED awal
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, LOW);

  // Memulai serial monitor
  Serial.begin(9600);
}

void loop() {
  // Membaca status deteksi PIR
  if (digitalRead(pirPin) == HIGH) {
    motionDetected = true;
  }

  // Membaca nilai dari Sensor MQ-7
  int gasValue = analogRead(mq7Pin);
  Serial.println("Gas value: " + String(gasValue));

  // Memeriksa jika nilai gas melebihi batas ambang
  if (gasValue > 700) {
    gasDetected = true;
  } else {
    gasDetected = false;
  }

  // LED RUMAH
val = digitalRead(pirPin);
  if(val == HIGH)
  {
    digitalWrite(ledRumah, HIGH);
      Serial.println("Motion detected!");
  }
      else
     { Serial.println("motion not Detected! ");
    digitalWrite(ledRumah, LOW); 
    }

  
  // Menyalakan atau mematikan Buzzer dan LED berdasarkan status deteksi
  if (!gasDetected) {
    // Gerakan terdeteksi, mematikan Buzzer dan LED
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, LOW);
  } else if (gasDetected) {
    // Deteksi gas, menyala Buzzer dan LED
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, HIGH);
  }

  // Mengatur status deteksi kembali menjadi false
  motionDetected = false;

  // Delay untuk stabilisasi pembacaan
  delay(100);
}

