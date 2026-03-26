void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese cantidad:");
}

void loop() {
  if (Serial.available()) {

    String input = Serial.readStringUntil('\n');
    // Lee  todo lo que el usuario 
    //escribe hasta presionar ENTER
    long cantidad = input.toInt(); 
    // Convierte la cadena leída a tipo 
    //numérico para su procesamiento
    long valores[] = {50000,20000,10000,5000,2000,1000,500,200,100,50};

    Serial.println("Resultado:");

    for (int i = 0; i < 10; i++) {
      Serial.print(valores[i]);
      Serial.print(": ");
      Serial.println(cantidad / valores[i]);
      cantidad %= valores[i];
    }

    if (cantidad > 0) {
      Serial.print("Faltante: ");
      Serial.println(cantidad);
    }

    Serial.println("\nIngrese otra cantidad:");
  }
}