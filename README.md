# Semáforo Automatizado para Aplicação Industrial

Este projeto tem como objetivo desenvolver um sistema de semáforo automatizado para aplicação industrial, utilizando um sensor infravermelho (IR) para monitoramento de fluxo e um buzzer para alerta sonoro. O sistema pode ser aplicado em áreas de segurança, controle de passagem em fábricas e monitoramento de movimentação em espaços restritos.

## Funcionalidades

- **Controle de semáforo**: O sistema controla um semáforo com luzes vermelha, amarela e verde.
- **Detecção de objetos**: Um sensor infravermelho (IR) detecta a presença de objetos ou pessoas.
- **Alerta sonoro**: Um buzzer emite um alerta sonoro quando um objeto é detectado.
- **Lógica de operação**:
  - Quando um objeto é detectado, a luz vermelha acende e o buzzer é ativado por 3 segundos.
  - Após 3 segundos, a luz vermelha apaga, a luz amarela acende por 2 segundos.
  - Em seguida, a luz amarela apaga, a luz verde acende por 5 segundos e o buzzer é desativado.

## Componentes Utilizados

- **Arduino**: Microcontrolador para controle do sistema.
- **Sensor IR**: Sensor infravermelho para detecção de objetos.
- **Buzzer**: Dispositivo para emitir alertas sonoros.
- **LEDs**: LEDs vermelho, amarelo e verde para simular o semáforo.
- **Resistores**: Para limitar a corrente dos LEDs.

## Esquema de Montagem

Aqui está um diagrama simplificado de como conectar os componentes ao Arduino:

```
Sensor IR   -> Pino 7
Buzzer      -> Pino 6
LED Vermelho -> Pino 9
LED Amarelo  -> Pino 10
LED Verde    -> Pino 11
```

## Código

O código abaixo controla o semáforo automatizado:

```cpp
const int vermelho = 9;
const int amarelo = 10;
const int verde = 11;
const int sensorIR = 7;
const int buzzer = 6;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensorIR, INPUT);
}

void loop() {
  int estadoSensor = digitalRead(sensorIR);

  if (estadoSensor == LOW) {  // Se detectar um objeto
    digitalWrite(vermelho, HIGH);  
    digitalWrite(buzzer, HIGH);  
    delay(3000);

    digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, HIGH);  
    delay(2000);
    
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, HIGH);  
    digitalWrite(buzzer, LOW);  
    delay(5000);

    digitalWrite(verde, LOW);  
  }
}
```

## Como Usar

1. **Montagem**: Conecte os componentes ao Arduino conforme o esquema de montagem.
2. **Upload do Código**: Carregue o código fornecido no Arduino usando a IDE do Arduino.
3. **Teste**: Aproxime um objeto do sensor IR para verificar o funcionamento do semáforo e do buzzer.

## Contribuição

Contribuições são bem-vindas! Se você quiser melhorar este projeto, siga os passos abaixo:

1. Faça um fork deste repositório.
2. Crie uma branch para sua feature (`git checkout -b feature/nova-feature`).
3. Commit suas mudanças (`git commit -m 'Adiciona nova feature'`).
4. Faça push para a branch (`git push origin feature/nova-feature`).
5. Abra um Pull Request.
