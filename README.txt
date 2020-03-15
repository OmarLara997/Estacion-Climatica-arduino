# Estacion-Climatica-arduino

Descripción:
Este es un proyecto Arduino que conciste en la lectura de datos atmosféricos (temperatura,humedad,presion,altitud), los cuales serán enviados por radio para posteriormente ser recibidos y ser impresos en una pantalla lcd.

Componentes:
- 2 placas Arduino (usé la Uno)
- 2 módulos de radiofrecuencia nRF24
- 1 sensor Bme280
- 1 pantalla LCD de 20x4

Conexiones: (basicas)
Para el Emisor se conectarán el sensor por las conexiones de I2C y un modulo nRF24 por las conexiones de SPI.
Para el Receptor se conectarán el display lcd por las conexiones de I2C y un modulo nRF24 por las conexiones de SPI.

#NOTA: los modulos nRF24 y el sensor se deben alimentar a 3.3V, si se conectan a 5V se dañan. Usa un regulador de voltaje a 3.3V.
