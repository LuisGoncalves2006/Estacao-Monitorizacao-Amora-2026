# Estação de Monitorização Ambiental - Amora (2026)

Este repositório contém a documentação e o código para a estação de monitorização ambiental desenvolvida para a Amora, Setúbal.

## Estrutura
- `Estacao_Monitorizacao_Ambiental_IoT_Ciencia_Cidada.pdf`: Artigo científico.
- `estacao_ambiental.ino`: Firmware para ESP32.
- `esquema_ligacoes.png`: Diagrama de montagem.

## Ligações Elétricas
- **SDS011**: RX/TX ligado aos pinos GPIO16/GPIO17 do ESP32.
- **BME680**: SDA/SCL ligado aos pinos GPIO21/GPIO22 do ESP32.

## Licença
Projeto distribuído sob a licença MIT.
