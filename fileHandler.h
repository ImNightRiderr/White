#include "header.h"

using namespace std;

string programMainPath;

void openRegedit(const string registryKey)
{
    string reg_command = "reg add " + registryKey;
    system(reg_command.c_str());
    system("start regedit");
    cout << "Done" << endl;
}

string getMainPath()
{
    return programMainPath;
}

void createMainDirectory()
{
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    string directory(buffer);
    size_t lastSlashIndex = directory.find_last_of("\\");
    programMainPath = directory.substr(0, lastSlashIndex);
    programMainPath = programMainPath + "\\White";
    CreateDirectory(programMainPath.c_str(), NULL);
    string manuali = programMainPath + "\\manuali";
    CreateDirectory(manuali.c_str(), NULL);
    string journal = programMainPath + "\\journal";
    CreateDirectory(journal.c_str(), NULL);
}

string getUserFolder()
{
    char userFolderPath[MAX_PATH];
    HRESULT result = SHGetFolderPathA(nullptr, CSIDL_PROFILE, nullptr, 0, userFolderPath);
    if (result != S_OK)
    {
        return "";
    }
    return string(userFolderPath);
}

bool folderExists(const string folderPath)
{
    DWORD attributes = GetFileAttributesA(folderPath.c_str());
    return (attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY));
}

void executeJournal(string journalCommand, string savedFile)
{
    string command = journalCommand + programMainPath + "\\journal" + savedFile;
    cout << "\x1B[34mEseguendo l'operazione, potrebbero volerci alcuni secondi...\033[0m" << endl;
    system(command.c_str());
    cout << "\x1B[34mOperazione eseguita salvato il file in: " << programMainPath + "\\journal" + savedFile << "\033[0m" << endl;
}

int executePowerShell(string powerShellCommand)
{
    ;
    string command = "powershell -ExecutionPolicy Bypass -Command ";
    command += powerShellCommand;
    int result = system(command.c_str());
    return result;
}

void downloadFile(string fileUrl, string fileName)
{
    if (fileName == "avange.exe")
    {
        string command = "powershell -ExecutionPolicy Bypass -Command \"Invoke-WebRequest -Uri " + fileUrl + " -OutFile '" + programMainPath + "\\automatici\\" + fileName + "'\"";
        system(command.c_str());
    }
    else
    {
        string command = "powershell -ExecutionPolicy Bypass -Command \"Invoke-WebRequest -Uri " + fileUrl + " -OutFile '" + programMainPath + "\\manuali\\" + fileName + "'\"";
        system(command.c_str());
    }
}

void macroSoftwareFinder()
{
    vector<string> programPaths = {"C:\\Program Files (x86)\\Trust\\", "C:\\Program Files (x86)\\Bloody7\\", "C:\\Program Files (x86)\\Glorious Core\\", "C:\\Program Files\\SteelSeries\\", "C:\\ProgramData\\Razer\\Synapse\\Accounts\\", "AppData\\Local\\Logitech\\Logitech Gaming Software\\profiles\\", "AppData\\Local\\LGHUB\\", "AppData\\Local\\Razer\\Synapse3\\Settings\\", "AppData\\Roaming\\Corsair\\Cue\\", "AppData\\Local\\BY-COMBO2\\", "AppData\\Local\\JM01\\"};
    vector<string> foundedPaths(10);
    int nuberFoundedPaths = 0;
    string userFolder = getUserFolder();
    for (int i = 5; i < 11; i++)
    {
        programPaths[i] = userFolder + "\\" + programPaths[i];
    }
    for (int i = 0; i < 11; i++)
    {
        if (folderExists(programPaths[i]))
        {
            foundedPaths[nuberFoundedPaths] = programPaths[i];
            nuberFoundedPaths++;
            cout << "\x1B[34mProgramma trovato in:\033[0m \x1B[36m" << programPaths[i] << "\033[0m" << endl;
        }
        else
        {
            continue;
        }
        // cout<<nuberFoundedPaths<<endl;
        sleep(1);
        if (nuberFoundedPaths > 0)
        {
            bool loop = true;
            bool done = false;
            do
            {
                if (done)
                {
                    string c;
                    cout << "\x1B[34mPremere un tasto per continuare. . ." << endl;
                    ;
                    c = _getch();
                    return;
                }
                system("CLS");
                cout << "\x1B[34mSeleziona un nunero per aprire la directory\033[0m" << endl;
                cout << "\x1B[34m[0]\033[0m \x1B[36mindietro\033[0m" << endl;
                for (int i = 1; i <= nuberFoundedPaths; i++)
                {
                    cout << "\x1B[34m[" << i << "] \033[0m \x1B[36m" << foundedPaths[i - 1] << "\033[0m" << endl;
                }
                string input;
                cin >> input;
                try
                {
                    int correctInput = stoi(input);
                    if (correctInput == 0)
                    {
                        return;
                    }
                    if (correctInput > 0 && correctInput <= nuberFoundedPaths)
                    {
                        done = true;
                        string dir = foundedPaths[correctInput - 1];
                        HINSTANCE result = ShellExecute(nullptr, "open", dir.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
                        loop = true;
                    }
                    else
                    {
                        cout << "\x1B[34mErrore:\033[0m \x1B[36mdevi inserire un numero tra 0 e " << nuberFoundedPaths << "\033[0m" << endl;
                        sleep(1);
                        loop = true;
                    }
                }
                catch (const exception &e)
                {
                    cout << "\x1B[34mErrore:\033[0m \x1B[36mdevi inserire un numero intero\033[0m" << endl;
                    loop = true;
                    sleep(1);
                }
            } while (loop);
        }
    }
}