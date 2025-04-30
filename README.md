
# 🛡️ Projeto GuardianPro – Plataforma Integrada de Telemedicina com IA

## 📌 Descrição Geral

O **GuardianPro** é uma plataforma de telemedicina integrada que conecta os atendimentos médicos remotos aos serviços hospitalares já existentes. Com o auxílio de **Inteligência Artificial**, o sistema permite que médicos tenham acesso a laudos, exames e histórico clínico dos pacientes em tempo real, otimizando o fluxo hospitalar e promovendo agilidade nos diagnósticos e atendimentos.

---

## 🎯 Objetivos

- Integrar exames, atendimentos e históricos médicos em uma única plataforma.
- Reduzir o tempo entre a realização do exame e a avaliação médica.
- Permitir encaminhamentos diretos ao atendimento presencial sem retrabalho.
- Melhorar a experiência do paciente e a eficiência interna do hospital.
- Utilizar sensores com Arduino para obter sinais vitais e integrá-los ao sistema.

---
## Diagrama do Sistema

![Diagrama do Sistema](./main/diagrama-edgecomputing.drawio.png)

## ⚙️ Especificações Técnicas dos Principais Componentes

### 🖥️ Front-End (Web ou App)
- Login para diferentes tipos de usuários (médicos, pacientes, atendentes)
- Dashboard com sinais vitais em tempo real
- Geração e visualização de PDFs com receitas e laudos médicos

### 🌐 Back-End (Node-RED + Servidor)
- Integração com Arduino via **Serial** 
- Fluxos MQTT e HTTP organizados por tipo de dado
- Armazenamento em banco de dados
- IA para auxiliar na tomada de decisão médica
- Comunicação com front-end via APIs

### 🔧 IoT – Arduino Uno (Simulado no Wokwi)
- Sensor de batimentos cardíacos (simulado)
- Sensor de temperatura (simulado)
- LEDs indicativos (normal/crítico)
- Buzzer para alertas
- Comunicação via **Serial** com Node-RED

---

## 🔍 Observações Finais

O projeto GuardianPro representa um avanço significativo na integração entre dispositivos IoT e sistemas de saúde baseados em nuvem, promovendo eficiência, acessibilidade e precisão no atendimento médico.
"""
