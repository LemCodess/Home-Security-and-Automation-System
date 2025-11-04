#include <WiFi.h>
#include <HTTPClient.h>

#define Buzzer 33
#define Sensor 32  // fire
#define PIR_PIN 25
#define LED_PIN 26
#define MOTION_SIGNAL_PIN 27

//whatsapp message send "I allow callmebot to send me messages"
const char* ssid = "AradAriyaana";        // Replace with your WiFi name
const char* password = "Arad2@1234"; // Replace with your WiFi password 

String phoneNumber = "8801820061505"; // Your WhatsApp number
String apiKey = "9816379";             // Your API key from CallMeBot

void setup() {
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);
  pinMode(Sensor, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);


  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi with IP: " + WiFi.localIP().toString());

  sendAlert("Your fire alert system is now active and ready!");
   pinMode(MOTION_SIGNAL_PIN, OUTPUT);
  digitalWrite(MOTION_SIGNAL_PIN, LOW);
}

void loop() {
  bool sensorValue = digitalRead(Sensor);
  if (sensorValue == 0) {
    digitalWrite(Buzzer, HIGH);
    sendAlert("🔥 Warning! Fire Detected!");
    delay(5000); // Delay to prevent message spamming
  } else {
    digitalWrite(Buzzer, LOW);
  }
  static unsigned long lastMotionTime = 0;
bool motionDetected = digitalRead(PIR_PIN);

if (motionDetected) {
  lastMotionTime = millis(); // Save the time motion was detected
}

if (millis() - lastMotionTime < 5000) {
  digitalWrite(LED_PIN, HIGH);
} else {
  digitalWrite(LED_PIN, LOW);
}

if (motionDetected) {
  digitalWrite(MOTION_SIGNAL_PIN, HIGH);
} else {
  digitalWrite(MOTION_SIGNAL_PIN, LOW);
}

}
void sendAlert(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String encodedMessage = urlEncode(message);
    String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + encodedMessage;

    http.begin(url);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.POST("");
    String response = http.getString();

    if (httpResponseCode == 200) {
      Serial.println("✅ WhatsApp message sent successfully!");
    } else {
      Serial.println("❌ Failed to send WhatsApp message. Code: " + String(httpResponseCode));
      Serial.println("Server response: " + response);
    }

    http.end();
  } else {
    Serial.println("WiFi not connected. Cannot send alert.");
  }
}


// Manual URL encoder function (replaces the need for UrlEncode.h)
String urlEncode(String str) {
  String encodedString = "";
  char c;
  char code0;
  char code1;
  char code2;
  for (int i = 0; i < str.length(); i++) {
    c = str.charAt(i);
    if (isalnum(c)) {
      encodedString += c;
    } else {
      code1 = (c & 0xf) + '0';
      if ((c & 0xf) > 9) {
        code1 = (c & 0xf) - 10 + 'A';
      }
      c = (c >> 4) & 0xf;
      code0 = c + '0';
      if (c > 9) {
        code0 = c - 10 + 'A';
      }
      code2 = '\0';
      encodedString += '%';
      encodedString += code0;
      encodedString += code1;
    }
    yield(); // prevent watchdog timer reset
  }
  return encodedString;
}