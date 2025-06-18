
/*

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
        By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/

#pragma once
#include <windows.h>

enum class SystemLanguage {
    English,
    Italian
};

inline SystemLanguage GetSystemLanguage() {
    LANGID langID = GetUserDefaultUILanguage();
    return (PRIMARYLANGID(langID) == LANG_ITALIAN)
           ? SystemLanguage::Italian
           : SystemLanguage::English;
}

#define LANG_TEXT(it, en) \
    (GetSystemLanguage() == SystemLanguage::Italian ? (it) : (en))

namespace Language {
    struct Current {
        static inline const char* CHOOSE_OPERATION = LANG_TEXT(
            "Scegli l'operazione:",
            "Choose operation:");
        static inline const char* QUIT = LANG_TEXT(
            "Esci",
            "Quit");
        static inline const char* MANUAL_TOOLS = LANG_TEXT(
            "Tool Manuali",
            "Manual Tools");
        static inline const char* AUTO_TOOLS = LANG_TEXT(
            "Tool Automatici",
            "Automatic Tools");
        static inline const char* JOURNAL_PATHS = LANG_TEXT(
            "Percorsi Journal",
            "Journal Paths");
        static inline const char* MACRO_PATHS = LANG_TEXT(
            "Percorsi Macro",
            "Macro Paths");
        static inline const char* REGISTRY_PATHS = LANG_TEXT(
            "Percorsi Registro",
            "Registry Paths");
        static inline const char* EVENT_VIEWER = LANG_TEXT(
            "Visualizzatore Eventi",
            "Event Viewer");
        static inline const char* RECORD = LANG_TEXT(
            "Controllo: VM, Registrazioni, Condivisione Schermo",
            "Check: VM, Recordings, Screen Sharing");
        static inline const char* BAM = LANG_TEXT(
            "Analisi BAM",
            "BAM Analysis");
        static inline const char* BACK = LANG_TEXT(
            "Indietro",
            "Back");
        static inline const char* WORKING_DIRECTORY = LANG_TEXT(
            "Cartella di lavoro",
            "Working Directory");
        static inline const char* CLEANING = LANG_TEXT(
            "Eliminazione della cartella Principale in corso...",
            "Cleaning main directory...");

        static inline const char* WELCOME_MESSAGE = LANG_TEXT(
            "============================================================\n"
            "                       \x1B[36mWhite.exe\x1B[0m\n"
            "============================================================\n\n"
            "(c) 2024 - 2025 NightRiderr_\n"
            "Utilizzando questo software, accetti i termini di servizio.\n"
            "Per ulteriori dettagli, visita:\n"
            "\x1B]8;;https://github.com/ImNightRiderr/White\x07"
            "\x1B[34mhttps://github.com/ImNightRiderr/White\x1B[0m"
            "\x1B]8;;\x07\n"
            "Se il link non \212 cliccabile, copialo (seleziona e tasto destro) e incollalo nel browser.\n\n"
            "\x1B[31mATTENZIONE:\x1B[0m Se hai pagato per questo software, sei stato truffato!\n"
            "Questo programma \212 completamente gratuito e disponibile sempre su GitHub:\n\n"
            "Per segnalare bug, richiedere supporto o proporre miglioramenti,\n"
            "crea una issue direttamente sul repository.\n\n"
            "\x1B[33mNota:\x1B[0m per funzionare correttamente, il programma richiede i permessi di amministratore.\n"
            "Sono necessari per accedere a tutte le informazioni di sistema durante la condivisione dello schermo.\n\n"
            "Mi scuso per questo messaggio, ma ritengo importante essere trasparente.\n"
            "Per continuare, digita \x1B[36mOK\x1B[0m e premi Invio: ",

            "============================================================\n"
            "                       \x1B[36mWhite.exe\x1B[0m\n"
            "============================================================\n\n"
            "(c) 2024 - 2025 NightRiderr_\n"
            "By using this software, you accept the terms of service.\n"
            "For more details, visit:\n"
            "\x1B]8;;https://github.com/ImNightRiderr/White\x07"
            "\x1B[34mhttps://github.com/ImNightRiderr/White\x1B[0m"
            "\x1B]8;;\x07\n"
            "If the link is not clickable, copy it (select and right click) and paste it in your browser.\n\n"
            "\x1B[31mWARNING:\x1B[0m If you paid for this software, you have been scammed!\n"
            "This program is completely free and always available on GitHub:\n\n"
            "To report bugs, request support or suggest improvements,\n"
            "create an issue directly on the repository.\n\n"
            "\x1B[33mNote:\x1B[0m To work properly, the program requires administrator permissions.\n"
            "These are needed to access all system information during screen sharing.\n\n"
            "I apologize for this message, but I believe in being transparent.\n"
            "To continue, type \x1B[36mOK\x1B[0m and press Enter: ");

        static inline const char* ADMIN_RIGHTS_ERROR = LANG_TEXT(
            "\x1B[31mERRORE: PERMESSI AMMINISTRATORE RIFIUTATI\x1B[0m\n"
            "Il programma richiede i permessi di amministratore per poter:\n"
            " - Visualizzare tutti i processi e le applicazioni in esecuzione\n"
            " - Accedere a informazioni di sistema normalmente protette\n"
            " - Eseguire controlli approfonditi durante lo screenshare\n\n"
            "Per favore, riavvia il programma e concedi i permessi di amministratore.",

            "\x1B[31mERROR: ADMINISTRATOR PERMISSIONS DENIED\x1B[0m\n"
            "The program requires administrator permissions to:\n"
            " - View all running processes and applications\n"
            " - Access normally protected system information\n"
            " - Perform thorough checks during screensharing\n\n"
            "Please restart the program and grant administrator permissions.");

        static inline const char* ELIMINATION_CONFIRM_QST = LANG_TEXT(
            "Vuoi eliminare i tutti file presennti sulla cartella White e la cartella stessa? (y/n):",
            "Do you want to delete all files in the White folder and the folder itself? (y/n):");
        static inline const char* ELIMINATION_COMPLETE = LANG_TEXT(
            "Tutti i file nella cartella 'White' sono stati eliminati.",
            "All files in the 'White' folder have been deleted.");
        static inline const char* OPERATION_CANCELLED = LANG_TEXT(
            "\nOperazione annullata. Il programma non verr\205 avviato.",
            "\nOperation cancelled. The program will not start.");
        static inline const char* PRESS_KEY = LANG_TEXT(
            "Premi un tasto per continuare...",
            "Press any key to continue...");
        static inline const char* INVALID_INPUT = LANG_TEXT(
            "Errore: inserimento errato, seleziona un numero tra ",
            "Error: invalid input, select a number between ");
        static inline const char* MUST_BE_NUMBER = LANG_TEXT(
            "Errore: devi inserire un numero",
            "Error: you must enter a number");
        static inline const char* GOODBYE = LANG_TEXT(
            "Arrivederci. . .",
            "Goodbye. . .");
        static inline const char* AUTO_TOOLS_BROWSER = LANG_TEXT(
            "Tool Automatici (APERTURA VIA BROWSER)",
            "Automatic Tools (BROWSER OPENING)");
        static inline const char* ENTER_CHOICE = LANG_TEXT(
            "Inserisci la tua scelta: ",
            "Enter your choice: ");
        static inline const char* DOWNLOADING = LANG_TEXT(
            "Download in corso...",
            "Downloading...");
        static inline const char* NO_RECORDING_SOFTWARE = LANG_TEXT(
            "Nessun software di registrazione o condivisione trovato",
            "No recording or sharing software found");
        static inline const char* CHECKING_SCREEN_SHARE = LANG_TEXT(
            "Controllo applicazioni di condivisione schermo...",
            "Checking screen sharing applications...");
        static inline const char* FOUND_SOFTWARE = LANG_TEXT(
            "Trovato: ",
            "Found: ");
        static inline const char* WINDOWS_REMOTE_SERVICE = LANG_TEXT(
            "Servizio Desktop Remoto di Windows attivo",
            "Windows Remote Desktop Service active");
        static inline const char* SELECT_PROCESS = LANG_TEXT(
            "Scegli quale processo terminare o tornare indietro",
            "Choose which process to terminate or go back");
        static inline const char* RECORDING_NOTE = LANG_TEXT(
            "Nota: Le registrazioni in corso potrebbero venir corrotte o eliminate.",
            "Note: Active recordings may be corrupted or deleted.");
        static inline const char* TERMINATING_PROCESS = LANG_TEXT(
            "Terminazione processo in corso...",
            "Terminating process...");
        static inline const char* PROCESS_TERMINATED = LANG_TEXT(
            "Processo terminato",
            "Process terminated");
        static inline const char* ERR = LANG_TEXT(
            "Errore:",
            "Error:");
        static inline const char* NO_EVENTS_FOUND = LANG_TEXT(
            "Nessun evento rilevato",
            "No events found");
        static inline const char* REGISTRY_OPENING = LANG_TEXT(
            "Aprendo l'Editor del Registro",
            "Opening Registry Editor");
        static inline const char* OPEN_DIR_CHOICE = LANG_TEXT(
            "Seleziona un numero per aprire la directory",
            "Select a number to open the directory");
        static inline const char* TEMP_FILE_ERROR = LANG_TEXT(
            "Impossibile creare il file temporaneo.",
            "Unable to create temporary file.");
        static inline const char* BAM_SCRIPT_ERROR = LANG_TEXT(
            "Errore nell'esecuzione dello script BAM",
            "Error running BAM script");
        static inline const char* JOURNAL_LOADING = LANG_TEXT(
            "Cercando nel percorso del journal selezionato...",
            "Searching selected journal path...");
        static inline const char* SEARCHING = LANG_TEXT(
            "Cercando . . .",
            "Searching . . .");
        static inline const char* BAM_SEARCHING = LANG_TEXT(
            "Caricando BAM, attendere",
            "Loading BAM, please wait");
        static inline const char* EVENT_VIEWER_LOADING = LANG_TEXT(
            "Analizzando l'Event Viewer, attendi",
            "Analyzing Event Viewer, please wait");
        static inline const char* INVALID_COMMAND_ID = LANG_TEXT(
            "ID comando non valido.",
            "Invalid command ID.");
        static inline const char* AND = LANG_TEXT(
            "e",
            "and");
        static inline const char* DIRECTORY_CREATED = LANG_TEXT(
            "Cartella creata con successo.",
            "Directory created successfully.");
        static inline const char* ERR_CREATE_DIR = LANG_TEXT(
            "Impossibile creare la cartella.",
            "Error creating directory.");
        static inline const char* OPENING_REGEDIT = LANG_TEXT(
            "Apertura dell'Editor del Registro di sistema",
            "Opening Registry Editor");
        static inline const char* VIRTUAL_ENVIRONMENT_DETECTED = LANG_TEXT(
            "Ambiente virtuale rilevato",
            "Detected virtual environment");
        static inline const char* CONTINUE_CHECKING = LANG_TEXT(
            "Continuando il controllo per software di registrazione o condivisone schermo...",
            "Continuing the check for recording software or screensharing...");
        static inline const char* NO_VIRTUAL_ENVIRONMENT_DETECTED = LANG_TEXT(
            "Nessun ambiente virtuale rilevato",
            "No virtual environment detected");
    };
}
