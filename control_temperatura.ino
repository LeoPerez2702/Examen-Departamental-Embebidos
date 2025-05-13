#include <DHT.h>

#define DHTPIN 2          // Pin digital conectado al sensor DHT11
#define DHTTYPE DHT11     // Tipo de sensor

#define FAN_PIN 3         // Pin conectado al ventilador (actuador)

DHT dht(DHTPIN, DHTTYPE); // Inicializa el sensor DHT11

void setup() {
  Serial.begin(9600);     // Inicia comunicación serial
  dht.begin();            // Inicia el sensor
  pinMode(FAN_PIN, OUTPUT); // Declara el pin del ventilador como salida
}

void loop() {
  float temp = dht.readTemperature(); // Lee temperatura en grados Celsius

  if (isnan(temp)) {
    Serial.println("Error leyendo el sensor");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println("°C");

  if (temp > 25.0) {
    digitalWrite(FAN_PIN, HIGH);  // Enciende ventilador
    Serial.println("Ventilador ENCENDIDO");
  } else {
    digitalWrite(FAN_PIN, LOW);   // Apaga ventilador
    Serial.println("Ventilador APAGADO");
  }

  delay(2000); // Espera 2 segundos antes de la siguiente lectura
}