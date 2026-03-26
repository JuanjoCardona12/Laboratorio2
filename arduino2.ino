int sumaDiv(int n) {
  int suma = 0;

  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      suma += i;
    }
  }

  return suma;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese numero:");
}

void loop() {
  if (Serial.available()) {

    String input = Serial.readStringUntil('\n');  
    // Lee  todo lo que el usuario escribe 
    //hasta presionar ENTER
    long n = input.toInt();  
    // Convierte el texto leído a número 
    //para poder hacer los cálculos

    long total = 0;

    for (int i = 1; i < n; i++) {
      int b = sumaDiv(i);

      if (b != i && sumaDiv(b) == i) {
        total += i;
      }
    }

    Serial.print("Suma de amigables: ");
    Serial.println(total);

    Serial.println("\nIngrese otro numero:");
  }
}