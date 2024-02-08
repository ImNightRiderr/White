#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <limits.h>
#include <fstream>
#include <cstdlib>

using namespace std;


void createMainDirectory() {
    string directoryMainPath;
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    string directory(buffer);
    size_t lastSlashIndex = directory.find_last_of("\\");
    directoryMainPath = directory.substr(0, lastSlashIndex) + "\\White";
    CreateDirectory(directoryMainPath.c_str(), NULL);
    string manuali = directoryMainPath + "\\manuali";
    CreateDirectory(manuali.c_str(), NULL);
    string journal = directoryMainPath + "\\journal";
    CreateDirectory(journal.c_str(), NULL);
}

void openBrowser(string urlBrowser) {
    string command = "start " + urlBrowser;
    system(command.c_str());
}

string password()
{
    string password;
    char ch;
    const int ENTER = 3;

    cout << "Inserisci la password: ";

    for (int i = 0; i < ENTER; i++)
    {
        ch = _getch();
        password += ch;
        cout << '*';
    }
    return password;
}

void executeJournal(string journalCommand, string savedFile) {
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    string saveDirectory(buffer);
    string command = journalCommand + saveDirectory + "\\White\\journal" + savedFile;
    cout<<"\x1B[34mEseguendo l'operazione, potrebbero volerci alcuni secondi...\033[0m"<<endl;
	system(command.c_str());
}

bool IsUserAdmin()
{
    BOOL isAdmin = FALSE;
    SID_IDENTIFIER_AUTHORITY ntAuth = SECURITY_NT_AUTHORITY;
    PSID adminGroup;
    if (AllocateAndInitializeSid(&ntAuth, 2, SECURITY_BUILTIN_DOMAIN_RID,
                                 DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminGroup))
    {
        if (!CheckTokenMembership(NULL, adminGroup, &isAdmin))
        {
            isAdmin = FALSE;
        }
        FreeSid(adminGroup);
    }
    return isAdmin == TRUE;
}


void downloadFile(string fileUrl, string fileName)
{
	
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    string saveDirectory(buffer);
    if(fileName == "avange.exe") {
		string command = "powershell -ExecutionPolicy Bypass -Command \"Invoke-WebRequest -Uri " + fileUrl + " -OutFile '" + saveDirectory + "\\White\\automatici\\" + fileName + "'\"";
		system(command.c_str());
	} else {
		string command = "powershell -ExecutionPolicy Bypass -Command \"Invoke-WebRequest -Uri " + fileUrl + " -OutFile '" + saveDirectory + "\\White\\manuali\\" + fileName + "'\"";
		system(command.c_str());
	}
}

