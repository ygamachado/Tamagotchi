#include <M5Cardputer.h>
#include <WiFi.h>


// Variáveis de estado do Tamagotchi
int hunger = 0;   // Fome
int happiness = 100; // Felicidade

// Função para alimentar o Tamagotchi
void feed() {
  hunger -= 10;
  if (hunger < 0) hunger = 0;
}

// Função para brincar com o Tamagotchi
void play() {
  happiness += 10;
  if (happiness > 100) happiness = 100;
}
// Função para a animação do panda sorrindo e piscando
void pandaAnimation(unsigned long duration) {
  unsigned long startTime = millis(); // Tempo inicial
  while (millis() - startTime < duration) { // Executa enquanto não passar o tempo determinado
    // Limpar a tela
    M5.Lcd.fillScreen(TFT_BLACK);

    // Desenhar a cabeça do panda
    M5.Lcd.fillCircle(80, 60, 30, TFT_WHITE);

    // Desenhar as orelhas
    M5.Lcd.fillCircle(60, 40, 15, TFT_WHITE);
    M5.Lcd.fillCircle(100, 40, 15, TFT_WHITE);

    // Desenhar os olhos
    M5.Lcd.fillCircle(70, 50, 6, TFT_BLACK);
    M5.Lcd.fillCircle(90, 50, 6, TFT_BLACK);

    // Desenhar a boca sorridente
    M5.Lcd.drawArc(80, 70, 20, 20, 0, 180, TFT_BLACK);

    // Desenhar o nariz
    M5.Lcd.fillCircle(80, 70, 6, TFT_BLACK);

    // Piscar um olho
    M5.Lcd.fillCircle(70, 50, 6, TFT_WHITE);
    delay(200); // Piscar por 0,2 segundos

    // Limpar a tela
    M5.Lcd.fillScreen(TFT_BLACK);
    delay(100); // Aguardar um curto intervalo entre o piscar

    // Desenhar a cabeça do panda
    M5.Lcd.fillCircle(80, 60, 30, TFT_WHITE);

    // Desenhar as orelhas
    M5.Lcd.fillCircle(60, 40, 15, TFT_WHITE);
    M5.Lcd.fillCircle(100, 40, 15, TFT_WHITE);

    // Desenhar os olhos
    M5.Lcd.fillCircle(70, 50, 6, TFT_BLACK);
    M5.Lcd.fillCircle(90, 50, 6, TFT_BLACK);

    // Desenhar a boca sorridente
    M5.Lcd.drawArc(80, 70, 20, 20, 0, 180, TFT_BLACK);

    // Desenhar o nariz
    M5.Lcd.fillCircle(80, 70, 6, TFT_BLACK);

    // Piscar o outro olho
    M5.Lcd.fillCircle(90, 50, 6, TFT_WHITE);
    delay(200); // Piscar por 0,2 segundos

    // Limpar a tela
    M5.Lcd.fillScreen(TFT_BLACK);
    delay(100); // Aguardar um curto intervalo entre o piscar
  }

  // Após a animação, exibe o panda com um olho fechado
  // Limpar a tela
  M5.Lcd.fillScreen(TFT_BLACK);

  // Desenhar a cabeça do panda
  M5.Lcd.fillCircle(80, 60, 30, TFT_WHITE);

  // Desenhar as orelhas
  M5.Lcd.fillCircle(60, 40, 15, TFT_WHITE);
  M5.Lcd.fillCircle(100, 40, 15, TFT_WHITE);

  // Desenhar o olho fechado
  M5.Lcd.drawArc(70, 50, 12, 12, 0, 180, TFT_BLACK);

  // Desenhar o olho aberto
  M5.Lcd.fillCircle(90, 50, 6, TFT_BLACK);

  // Desenhar a boca sorridente
  M5.Lcd.drawArc(80, 70, 20, 20, 0, 180, TFT_BLACK);

  // Desenhar o nariz
  M5.Lcd.fillCircle(80, 70, 6, TFT_BLACK);
}
void drowPanda() {
  // Desenhar a cabeça do panda
  M5.Lcd.fillCircle(30, 15, 15, TFT_WHITE);

  // Desenhar as orelhas
  M5.Lcd.fillCircle(20, 7, 7, TFT_WHITE);
  M5.Lcd.fillCircle(40, 7, 7, TFT_WHITE);

  // Desenhar os olhos
  M5.Lcd.fillCircle(25, 10, 3, TFT_BLACK);
  M5.Lcd.fillCircle(35, 10, 3, TFT_BLACK);

  // Desenhar o nariz
  M5.Lcd.fillCircle(30, 18, 3, TFT_BLACK);

  // Desenhar a boca
  M5.Lcd.drawPixel(28, 22, TFT_BLACK);
  M5.Lcd.drawPixel(29, 22, TFT_BLACK);
  M5.Lcd.drawPixel(30, 22, TFT_BLACK);
  M5.Lcd.drawPixel(31, 22, TFT_BLACK);
  M5.Lcd.drawPixel(32, 22, TFT_BLACK);


  delay(10); // Delay para manter o panda na tela por 10 segundos
}

// Função para alimentar o panda por um determinado período de tempo (em milissegundos)
void feedPanda(unsigned long duration) {
  unsigned long startTime = millis(); // Obtém o tempo inicial
  while (millis() - startTime < duration) { // Executa enquanto não passar o tempo determinado
    // Limpar a tela
    M5.Lcd.fillScreen(TFT_BLACK);

    // Desenhar a cabeça do panda
    M5.Lcd.fillCircle(80, 60, 30, TFT_WHITE);

    // Desenhar as orelhas
    M5.Lcd.fillCircle(60, 40, 15, TFT_WHITE);
    M5.Lcd.fillCircle(100, 40, 15, TFT_WHITE);

    // Desenhar os olhos
    M5.Lcd.fillCircle(70, 50, 6, TFT_BLACK);
    M5.Lcd.fillCircle(90, 50, 6, TFT_BLACK);

    // Desenhar o nariz
    M5.Lcd.fillCircle(80, 70, 6, TFT_BLACK);

    // Desenhar a boca aberta
    M5.Lcd.drawLine(75, 80, 85, 80, TFT_BLACK);
    M5.Lcd.drawLine(75, 80, 75, 85, TFT_BLACK);
    M5.Lcd.drawLine(85, 80, 85, 85, TFT_BLACK);

    delay(250); // Ajuste para controlar a velocidade da animação (250 ms para cada frame)

    // Limpar a tela
    M5.Lcd.fillScreen(TFT_BLACK);

    // Desenhar a cabeça do panda
    M5.Lcd.fillCircle(80, 60, 30, TFT_WHITE);

    // Desenhar as orelhas
    M5.Lcd.fillCircle(60, 40, 15, TFT_WHITE);
    M5.Lcd.fillCircle(100, 40, 15, TFT_WHITE);

    // Desenhar os olhos
    M5.Lcd.fillCircle(70, 50, 6, TFT_BLACK);
    M5.Lcd.fillCircle(90, 50, 6, TFT_BLACK);

    // Desenhar o nariz
    M5.Lcd.fillCircle(80, 70, 6, TFT_BLACK);

    // Desenhar a boca fechada
    M5.Lcd.drawLine(75, 80, 85, 80, TFT_BLACK);
    M5.Lcd.drawLine(75, 80, 75, 80, TFT_BLACK);
    M5.Lcd.drawLine(85, 80, 85, 80, TFT_BLACK);

    delay(250); // Ajuste para controlar a velocidade da animação (250 ms para cada frame)
  }
}
// Função para desenhar a barra de status da bateria
void drawBatteryStatus(int batteryLevel) {
  // Limpar a área da barra de status da bateria
  M5.Lcd.fillRect(120, 0, 40, 10, BLACK);

  // Desenhar contorno da bateria
  M5.Lcd.drawRect(125, 1, 20, 8, WHITE);

  // Desenhar preenchimento da bateria com base no nível da bateria
  int batteryWidth = map(batteryLevel, 0, 100, 0, 18);
  M5.Lcd.fillRect(127, 3, batteryWidth, 4, WHITE);

  // Exibir porcentagem da bateria
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(150, 0);
  M5.Lcd.printf("%d%%", batteryLevel);
}

void runPanda(unsigned long duration) {
  unsigned long startTime = millis(); // Obtém o tempo inicial
  while (millis() - startTime < duration) { // Executa enquanto não passar o tempo determinado
    // Limpar a tela
    M5.Lcd.fillScreen(TFT_BLACK);

    // Desenhar a cabeça do panda
    M5.Lcd.fillCircle(80, 60, 30, TFT_WHITE);

    // Desenhar as orelhas
    M5.Lcd.fillCircle(60, 40, 15, TFT_WHITE);
    M5.Lcd.fillCircle(100, 40, 15, TFT_WHITE);

    // Desenhar os olhos
    M5.Lcd.fillCircle(70, 50, 6, TFT_BLACK);
    M5.Lcd.fillCircle(90, 50, 6, TFT_BLACK);

    // Desenhar o nariz
    M5.Lcd.fillCircle(80, 70, 6, TFT_BLACK);

    // Desenhar a boca
    M5.Lcd.drawLine(75, 80, 85, 80, TFT_BLACK);

    // Desenhar as pernas
    M5.Lcd.drawLine(70, 70, 60, 90, TFT_WHITE);
    M5.Lcd.drawLine(90, 70, 100, 90, TFT_WHITE);

    delay(250); // Ajuste para controlar a velocidade da animação (250 ms para cada frame)

    // Limpar a tela
    M5.Lcd.fillScreen(TFT_BLACK);

    // Desenhar a cabeça do panda
    M5.Lcd.fillCircle(80, 60, 30, TFT_WHITE);

    // Desenhar as orelhas
    M5.Lcd.fillCircle(60, 40, 15, TFT_WHITE);
    M5.Lcd.fillCircle(100, 40, 15, TFT_WHITE);

    // Desenhar os olhos
    M5.Lcd.fillCircle(70, 50, 6, TFT_BLACK);
    M5.Lcd.fillCircle(90, 50, 6, TFT_BLACK);

    // Desenhar o nariz
    M5.Lcd.fillCircle(80, 70, 6, TFT_BLACK);

    // Desenhar a boca
    M5.Lcd.drawLine(75, 80, 85, 80, TFT_BLACK);

    // Desenhar as pernas
    M5.Lcd.drawLine(70, 70, 80, 90, TFT_WHITE);
    M5.Lcd.drawLine(90, 70, 80, 90, TFT_WHITE);

    delay(250); // Ajuste para controlar a velocidade da animação (250 ms para cada frame)
  }
}

void limpar_tela(){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
}
void menu(){
  limpar_tela();
  drowPanda();
  M5.Lcd.setCursor(0, 50);
  M5.Lcd.print("1-Alimentar\n");
  M5.Lcd.print("2-Brincar\n");
  M5.Lcd.print("Ok-Status\n");
  delay(100);
  limpar_tela();
}
void setup() {
  auto cfg = M5.config();
  M5Cardputer.begin(cfg);
  M5Cardputer.begin();
  M5Cardputer.Display.setTextSize(1);
  M5Cardputer.Display.setTextColor(GREEN);

  M5.Lcd.setRotation(1); // 
  M5.Lcd.fillScreen(BLACK); // Limpa a tela
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("initializating...");
  delay(500);
  pandaAnimation(2000);
  limpar_tela();
}

void loop() {
  //menu();
  int batteryLevel = M5.Power.getBatteryLevel();
  // Desenhar a barra de status da bateria com base no nível atual da bateria
  drawBatteryStatus(batteryLevel);

  // Esperar um curto período antes de atualizar novamente (simulação)
  delay(500);
  M5.Lcd.setTextSize(2);

  M5Cardputer.update();
  // Lógica para alimentar o Tamagotchi
  if (M5Cardputer.Keyboard.isKeyPressed('1')) {
    limpar_tela();
    feed();
    M5.Lcd.setCursor(10, 50);
    M5.Lcd.print("Alimentando...");
    delay(500); // Debounce delay
    feedPanda(3000);
    delay(500);
    limpar_tela();
  }
  M5Cardputer.update();
  // Lógica para brincar com o Tamagotchi
  if (M5Cardputer.Keyboard.isKeyPressed('2')) {
    limpar_tela(); 
    play();
    M5.Lcd.setCursor(10, 50);
    M5.Lcd.print("Brincando..."); 
    runPanda(10000);
    delay(100);
    limpar_tela();
  }

  M5Cardputer.update();
  if (M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER)) {
  // Exibição do estado atual do Tamagotchi
    limpar_tela();
    M5.Lcd.setCursor(0, 50);
    drowPanda();
    M5.Lcd.print("Fome: ");
    M5.Lcd.println(hunger);
    M5.Lcd.print("Felicidade: ");
    M5.Lcd.println(happiness);
    M5Cardputer.update();

   delay(1000); // Delay para atualização do estado
    hunger +=1;   // Fome
    happiness -=1; // Felicidade
    limpar_tela();
  }
  drowPanda();
  M5.Lcd.setCursor(0, 50);
  M5.Lcd.print("1-Alimentar\n");
  M5.Lcd.print("2-Brincar\n");
  M5.Lcd.print("Ok-Status\n");
  delay(1000);
}
