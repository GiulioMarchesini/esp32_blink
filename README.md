# ESP32-S3 Blink Example

Questo progetto è un esempio di base per la scheda **ESP32-S3 DevKitC-1** utilizzando PlatformIO e il framework Arduino.
Il codice fa lampeggiare il LED RGB integrato (NeoPixel) ciclando tra i colori Rosso, Verde e Blu.

## Hardware

* **Scheda:** ESP32-S3 DevKitC-1
* **Flash:** 16MB (Quad I/O)
* **PSRAM:** 8MB (Octal SPI / OPI)
* **LED:** RGB integrato (indirizzabile tramite `neopixelWrite`)

## Configurazione PlatformIO

Il file `platformio.ini` è configurato per:

* Utilizzare il **JTAG integrato** via USB per Upload e Debug (`esp-builtin`).
* Abilitare la **USB CDC on Boot** per avere la Serial Monitor via USB nativa.
* Configurare correttamente la memoria per moduli N16R8 (16MB Flash, 8MB PSRAM OPI).

## Setup Driver per Debug (Importante)

Per utilizzare il debug e l'upload tramite la porta USB nativa ("USB"), è necessario configurare correttamente i driver su Windows utilizzando **Zadig**:

1. Collega la scheda tramite la porta USB nativa (non UART).
2. Apri **Zadig**.
3. Vai su **Options** -> **List All Devices**.
4. Seleziona **"USB JTAG/serial debug unit (Interface 2)"**
5. Seleziona il driver **WinUSB (v6.1.7600.16385)**.
    * *Nota:* Versioni più recenti di WinUSB potrebbero dare problemi.
6. Clicca su **Replace Driver** o **Reinstall WCID Driver**.

## Come usare

1. **Build:** Esegui il task `Build` di PlatformIO.
2. **Upload:** Collega la scheda alla porta USB e lancia `Upload`.
3. **Monitor:** Apri il Serial Monitor a 115200 baud per vedere i messaggi di debug.
4. **Debug:** Vai nella sezione "Run and Debug" di VS Code e avvia "PIO Debug".

## Struttura del codice

* `src/main.cpp`: Contiene la logica principale. Utilizza `neopixelWrite()` per controllare il LED RGB senza bisogno di librerie esterne complesse.
* `platformio.ini`: File di configurazione dell'ambiente, partizioni e flag di compilazione.
