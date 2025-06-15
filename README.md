# White.exe – Minecraft Screenshare Tool

---
## Documentazione legale 

- **Leggi i [Termini di Servizio](./TERM_OF_SERVICE.md)** prima di usare il software. 
- **Leggi la [Licenza](./LICENSE.md)** relativa al programma.  
- **Consulta la [Privacy Policy](./PRIVACY_POLICY.md)** per i dettagli sulla gestione dei dati.
## L’utilizzo di White.exe implica la piena accettazione di licenza e privacy policy e termini di servizio.

----

**White.exe**, Sviluppato da **NightRiderr_**, è uno strumento open‑source, gratuito e portatile pensato per le sessioni di **screenshare** durante i controlli anti‑cheat su **Minecraft**.  

---

## Caratteristiche principali

### Strumenti manuali
Accesso a una raccolta di utility manuali esterni per analizzare direttamente il sistema.

### Strumenti automatici
Possibilità di scaricare e avviare automaticamente strumenti di scansione esterni progettati per l’analisi anti-cheat. Questi tool possono semplificare il controllo, riducendo i tempi di verifica.

### Controllo dei percorsi Journal (Eventi recenti)
Visualizza i percorsi legati ai file journal, i quali registrano l’attività utente e di sistema. Utile per rilevare operazioni recenti come esecuzioni o pulizie effettuate poco prima dello screenshare.

### Percorsi macro noti
Scansione rapida delle directory comunemente utilizzate da autoclicker o macro. Consente l’accesso diretto alle cartelle sospette per una verifica immediata.

### Registro di sistema (Registry)
Controlla chiavi note del registro di sistema associate a cheat client, esecuzioni di programmi sospetti o altro.

### Visualizzatore eventi di Windows
Avvio rapido dell'Event Viewer di Windows, utile per ispezionare eventi recenti del sistema.

### Rilevamento software di registrazione/condivisione schermo
Individua e segnala i processi attivi legati a programmi di registrazione video o condivisione schermo, come OBS, ShareX, Bandicam o Discord. Può opzionalmente terminare i processi per garantire una sessione di screenshare pulita.

### BAM Analysis
Esegue automaticamente la scansione della Background Activity Moderator (BAM).

---

##  Guida rapida all’uso

1. Installazione  
   – Scarica l’ultima release da [GitHub Releases](https://github.com/ImNightRiderr/White/releases).  
   – Estrai il contenuto in una cartella a tua scelta.

2. Esecuzione  
   – Avvia `White.exe` con **tasti destro → “Esegui come amministratore”**.

---

# Guida alla Compilazione di White (usando MinGW)

## Prerequisiti

1. **MinGW (Minimalist GNU for Windows)**  
   Assicurati che MinGW sia installato e correttamente configurato sul tuo sistema.

2. **Codice Sorgente**  
   Scarica il codice sorgente dalla [pagina delle release su GitHub](https://github.com/ImNightRiderr/White/releases).

---

## Passaggi

### 1. **Scarica il Codice Sorgente**
   - Vai alla [pagina delle release su GitHub](https://github.com/ImNightRiderr/White/releases).
   - Scarica l'archivio `.zip` contenente il codice sorgente.
   - Estrai il contenuto del file `.zip` in una cartella sul tuo computer.

### 2. **Apri il Terminale**
   - Apri il terminale o il prompt dei comandi nella cartella in cui hai estratto il codice sorgente.

### 3. **Seleziona la Lingua**
   - Vai al file `Language.h`.
   - Aprilo e scegli la lingua che preferisci modificando la riga appropriata.

### 4. **Compila il File delle Risorse (`resources.rc`)**
   - Nel terminale, compila il file `resources.rc` in un file oggetto `.res` usando `windres`:
   
     ```bash
     windres resources.rc -O coff -o resources.res
     ```

### 5. **Compila Tutti i File in un Eseguibile**
   - Dopo aver compilato le risorse, usa `g++` per compilare tutti i file sorgente in un eseguibile Windows. Esegui il seguente comando:

     ```bash
     g++ main.cpp Tools.cpp Menu.cpp ScreenShareDetection.cpp SecurityManager.cpp Utils.cpp resources.res -o white.exe -mwindows -static-libgcc -static-libstdc++
     ```

   - Questo comando genererà un eseguibile chiamato `white.exe` nella stessa cartella.

### 6. **ENJOY!**
   - Una volta completata la compilazione, dovresti trovare `white.exe` nella cartella corrente.
   - Esegui l'eseguibile e goditi il programma!

---

Se riscontri problemi durante il processo di compilazione, non esitare a chiedere ulteriori assistenza!


---

***L’utilizzo di White.exe implica la piena accettazione di licenza e privacy policy e termini di servizio.***


# White.exe – Minecraft Screenshare Tool

---

## Legal Notice

- **Read the [Terms of Service](./TERM_OF_SERVICE.md)** before using this software.  
- **Read the [License](./LICENSE.md)** for licensing details.  
- **Read the [Privacy Policy](./PRIVACY_POLICY.md)** to understand how data is handled.

## By using White.exe, you agree to the Terms of Service, License, and Privacy Policy.

---

**White.exe**, developed by **NightRiderr_**, is a free, open-source, portable tool designed specifically for **screenshare sessions** during anti-cheat inspections on **Minecraft**.

---

## Key Features

### Manual Tools
Access to a set of external manual utilities for in-depth system inspection.

### Automatic Tools
Ability to download and launch third-party anti-cheat scanning tools automatically. These tools help speed up inspections and reduce manual checks.

### Journal Path Inspection (Recent Events)
Displays paths related to journal files, which log recent system or user activity. Useful to detect recent executions or cleanups prior to a screenshare.

### Known Macro Paths
Quickly scans directories typically used by macro tools or autoclickers. Allows direct access to suspicious folders for manual inspection.

### Registry Inspection
Scans specific registry keys commonly linked to cheat clients, suspicious executables, or unwanted configurations.

### Windows Event Viewer Access
Launches the Windows Event Viewer for reviewing recent system events, crashes, or suspicious operations.

### Screen Recording / Sharing Software Detection
Detects and optionally terminates screen sharing and recording tools such as OBS, ShareX, Bandicam, and Discord to ensure a clean and transparent session.

### BAM Analysis
Automatically inspects the Background Activity Moderator (BAM) to identify recently run programs, including those no longer active.

---

## Quick Start Guide

1. Installation  
   – Download the latest release from [GitHub Releases](https://github.com/ImNightRiderr/White/releases).  
   – Extract the contents to a folder of your choice.

2. Execution  
   – Right-click on `White.exe` and choose **“Run as administrator”** for full functionality.

---

# Compiling Guide for White (using MinGW)

## Prerequisites

1. **MinGW (Minimalist GNU for Windows)**  
   Make sure MinGW is installed and properly configured on your system.

2. **Source Code**  
   Download the source code from the [GitHub Releases page](https://github.com/ImNightRiderr/White/releases).

---

## Steps

### 1. **Download the Source Code**
   - Go to the [GitHub Releases page](https://github.com/ImNightRiderr/White/releases).
   - Download the `.zip` archive containing the source code.
   - Extract the contents of the `.zip` file to a folder on your computer.

### 2. **Open Terminal**
   - Open a terminal or command prompt in the folder where you extracted the source code.

### 3. **Select the Language**
   - Navigate to the `Language.h` file.
   - Open it and choose the language you prefer by modifying the appropriate line.

### 4. **Compile the Resource File (`resources.rc`)**
   - In the terminal, compile the `resources.rc` file into a `.res` object file using `windres`:
   
     ```bash
     windres resources.rc -O coff -o resources.res
     ```

### 5. **Compile All Files into an Executable**
   - After compiling the resources, use `g++` to compile all source files into a Windows executable. Run the following command:

     ```bash
     g++ main.cpp Tools.cpp Menu.cpp ScreenShareDetection.cpp SecurityManager.cpp Utils.cpp resources.res -o white.exe -mwindows -static-libgcc -static-libstdc++
     ```

   - This command will generate an executable named `white.exe` in the same folder.

### 6. **Enjoy!**
   - Once the compilation is complete, you should find `white.exe` in the current directory.
   - Run the executable and enjoy the program!

---

***By using White.exe, you agree to the Terms of Service, License, and Privacy Policy.***

*© 2024 – 2025 NightRiderr_*

