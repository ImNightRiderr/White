/* 

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
        By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/

#pragma once
#include <string>

// Choose the language to compile: comment out one of the two lines
// #define APP_LANG_ITALIAN
#define APP_LANG_ENGLISH

#ifdef APP_LANG_ITALIAN
namespace Language {
    struct Current {
        static constexpr const char* CHOOSE_OPERATION = "Scegli l'operazione:";
        static constexpr const char* QUIT = "Esci";
        static constexpr const char* MANUAL_TOOLS = "Tool Manuali";
        static constexpr const char* AUTO_TOOLS = "Tool Automatici";
        static constexpr const char* JOURNAL_PATHS = "Percorsi Journal";
        static constexpr const char* MACRO_PATHS = "Percorsi Macro";
        static constexpr const char* REGISTRY_PATHS = "Percorsi Registro";
        static constexpr const char* EVENT_VIEWER = "Visualizzatore Eventi";
        static constexpr const char* RECORD = "Registrazioni";
        static constexpr const char* BAM = "Analisi BAM";
        static constexpr const char* BACK = "Indietro";
        

        // Messaggi generali
        static constexpr const char* WELCOME_MESSAGE =
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
            "Per continuare, digita \x1B[36mOK\x1B[0m e premi Invio: ";

        static constexpr const char* ADMIN_RIGHTS_ERROR =
            "\x1B[31mERRORE: PERMESSI AMMINISTRATORE RIFIUTATI\x1B[0m\n"
            "Il programma richiede i permessi di amministratore per poter:\n"
            " - Visualizzare tutti i processi e le applicazioni in esecuzione\n"
            " - Accedere a informazioni di sistema normalmente protette\n"
            " - Eseguire controlli approfonditi durante lo screenshare\n\n"
            "Per favore, riavvia il programma e concedi i permessi di amministratore.";

        static constexpr const char* ELIMINATION_CONFIRM_QST = "Vuoi eliminare i tutti file presennti sulla cartella \\Download\\White e la cartella stessa? (y/n):";
        static constexpr const char* ELIMINATION_COMPLETE = "Tutti i file nella cartella 'White' sono stati eliminati.";
        static constexpr const char* OPERATION_CANCELLED = "\nOperazione annullata. Il programma non verr\205 avviato.";
        static constexpr const char* PRESS_KEY = "Premi un tasto per continuare...";
        static constexpr const char* INVALID_INPUT = "Errore: inserimento errato, seleziona un numero tra ";
        static constexpr const char* MUST_BE_NUMBER = "Errore: devi inserire un numero";
        static constexpr const char* GOODBYE = "Arrivederci, premi un tasto per continuare. . .";
        static constexpr const char* AUTO_TOOLS_BROWSER = "Tool Automatici (APERTURA VIA BROWSER)";
        static constexpr const char* ENTER_CHOICE = "Inserisci la tua scelta: ";
        static constexpr const char* DOWNLOADING = "Download in corso...";
        static constexpr const char* NO_RECORDING_SOFTWARE = "Nessun software di registrazione o condivisione trovato";
        static constexpr const char* CHECKING_SCREEN_SHARE = "Controllo applicazioni di condivisione schermo...";
        static constexpr const char* FOUND_SOFTWARE = "Trovato: ";
        static constexpr const char* WINDOWS_REMOTE_SERVICE = "Servizio Desktop Remoto di Windows attivo";
        static constexpr const char* SELECT_PROCESS = "Scegli quale processo terminare o tornare indietro";
        static constexpr const char* RECORDING_NOTE = "Nota: Le registrazioni in corso potrebbero venir corrotte o eliminate.";
        static constexpr const char* TERMINATING_PROCESS = "Terminazione processo in corso...";
        static constexpr const char* PROCESS_TERMINATED = "Processo terminato";
        static constexpr const char* ERR = "Errore:";
        static constexpr const char* NO_EVENTS_FOUND = "Nessun evento rilevato";
        static constexpr const char* REGISTRY_OPENING = "Aprendo l'Editor del Registro";
        static constexpr const char* OPEN_DIR_CHOICE = "Seleziona un numero per aprire la directory";
        static constexpr const char* TEMP_FILE_ERROR = "Impossibile creare il file temporaneo.";
        static constexpr const char* BAM_SCRIPT_ERROR = "Errore nell'esecuzione dello script BAM";
        static constexpr const char* JOURNAL_LOADING = "Cercando nel percorso del journal selezionato...";
        static constexpr const char* SEARCHING = "Cercando . . .";
        static constexpr const char* BAM_SEARCHING = "Caricando BAM, attendere";
        static constexpr const char* EVENT_VIEWER_LOADING = "Analizzando l'Event Viewer, attendi";
        static constexpr const char* INVALID_COMMAND_ID = "ID comando non valido.";
        static constexpr const char* AND  = "e";
        static constexpr const char* DIRECTORY_CREATED = "Cartella creata con successo.";
        static constexpr const char* ERR_CREATE_DIR = "Impossibile creare la cartella.";
    };
}
#endif

#ifdef APP_LANG_ENGLISH
namespace Language {
    struct Current {
        static constexpr const char* CHOOSE_OPERATION = "Choose operation:";
        static constexpr const char* QUIT = "Quit";
        static constexpr const char* MANUAL_TOOLS = "Manual Tools";
        static constexpr const char* AUTO_TOOLS = "Automatic Tools";
        static constexpr const char* JOURNAL_PATHS = "Journal Paths";
        static constexpr const char* MACRO_PATHS = "Macro Paths";
        static constexpr const char* REGISTRY_PATHS = "Registry Paths";
        static constexpr const char* EVENT_VIEWER = "Event Viewer";
        static constexpr const char* RECORD = "Recordings";
        static constexpr const char* BAM = "BAM Analysis";
        static constexpr const char* BACK = "Back";
        

        // General messages
        static constexpr const char* WELCOME_MESSAGE =
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
            "To continue, type \x1B[36mOK\x1B[0m and press Enter: ";

        static constexpr const char* ADMIN_RIGHTS_ERROR =
            "\x1B[31mERROR: ADMINISTRATOR PERMISSIONS DENIED\x1B[0m\n"
            "The program requires administrator permissions to:\n"
            " - View all running processes and applications\n"
            " - Access normally protected system information\n"
            " - Perform thorough checks during screensharing\n\n"
            "Please restart the program and grant administrator permissions.";

        static constexpr const char* ELIMINATION_CONFIRM_QST = "Do you want to delete all files in the \\Downloads\\White folder and the folder itself? (y/n):";
        static constexpr const char* ELIMINATION_COMPLETE = "All files in the 'White' folder have been deleted.";
        static constexpr const char* OPERATION_CANCELLED = "\nOperation cancelled. The program will not start.";
        static constexpr const char* PRESS_KEY = "Press any key to continue...";
        static constexpr const char* INVALID_INPUT = "Error: invalid input, select a number between ";
        static constexpr const char* MUST_BE_NUMBER = "Error: you must enter a number";
        static constexpr const char* GOODBYE = "Goodbye, press any key to continue. . .";
        static constexpr const char* AUTO_TOOLS_BROWSER = "Automatic Tools (BROWSER OPENING)";
        static constexpr const char* ENTER_CHOICE = "Enter your choice: ";
        static constexpr const char* DOWNLOADING = "Downloading...";
        static constexpr const char* NO_RECORDING_SOFTWARE = "No recording or sharing software found";
        static constexpr const char* CHECKING_SCREEN_SHARE = "Checking screen sharing applications...";
        static constexpr const char* FOUND_SOFTWARE = "Found: ";
        static constexpr const char* WINDOWS_REMOTE_SERVICE = "Windows Remote Desktop Service active";
        static constexpr const char* SELECT_PROCESS = "Choose which process to terminate or go back";
        static constexpr const char* RECORDING_NOTE = "Note: Active recordings may be corrupted or deleted.";
        static constexpr const char* TERMINATING_PROCESS = "Terminating process...";
        static constexpr const char* PROCESS_TERMINATED = "Process terminated";
        static constexpr const char* ERR = "Error:";
        static constexpr const char* NO_EVENTS_FOUND = "No events found";
        static constexpr const char* REGISTRY_OPENING = "Opening Registry Editor";
        static constexpr const char* OPEN_DIR_CHOICE = "Select a number to open the directory";
        static constexpr const char* TEMP_FILE_ERROR = "Unable to create temporary file.";
        static constexpr const char* BAM_SCRIPT_ERROR = "Error running BAM script";
        static constexpr const char* JOURNAL_LOADING = "Searching selected journal path...";
        static constexpr const char* SEARCHING = "Searching . . .";
        static constexpr const char* BAM_SEARCHING = "Loading BAM, please wait";
        static constexpr const char* EVENT_VIEWER_LOADING = "Analyzing Event Viewer, please wait";
        static constexpr const char* INVALID_COMMAND_ID = "Invalid command ID.";
        static constexpr const char* AND  = "and";
        static constexpr const char* DIRECTORY_CREATED = "Directory created successfully.";
        static constexpr const char* ERR_CREATE_DIR = "Error creating directory.";
    
       
    };
}
#endif
