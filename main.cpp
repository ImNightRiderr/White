#include <C:\Users\GameFire\Desktop\SenzaTitolo1.h>

using namespace std;

void menu();

void manuali() {
    int selectManuale;
    system("CLS");
    cout << "\x1B[34mTool Manuali\033[0m" << endl;
    cout << "\x1B[34m[1]\033[0m Download Process Hacker 2" << endl;
    cout << "\x1B[34m[2]\033[0m Download LastActivityView" << endl;
    cout << "\x1B[34m[3]\033[0m Download WinPrefetchView" << endl;
    cout << "\x1B[34m[4]\033[0m Download Luyten" << endl;
    cout << "\x1B[34m[5]\033[0m Download Everything" << endl;
    cout << "\x1B[34m[6]\033[0m Download AlternateStreamView" << endl;
    cout << "\x1B[34m[7]\033[0m Download PreviousFilesRecovery" << endl;
    cout << "\x1B[34m[8]\033[0m RegScanner" << endl;
    cout << "\x1B[34m[9]\033[0m USBDeview" << endl;
    cin >> selectManuale;

    switch (selectManuale)
    {
    case 1:
        downloadFile("https://github.com/processhacker/processhacker/releases/download/v2.39/processhacker-2.39-setup.exe", "processhacker.exe");
        menu();
        break;
    case 2:
        downloadFile("https://www.nirsoft.net/utils/lastactivityview.zip", "lastactivityview.zip");
        menu();
        break;
    case 3:
        downloadFile("https://www.nirsoft.net/utils/winprefetchview-x64.zip", "winprefetchview-x64.zip");
        menu();
        break;
    case 4:
        downloadFile("https://github.com/deathmarine/Luyten/releases/download/v0.5.4_Rebuilt_with_Latest_depenencies/luyten-0.5.4.exe", "luyten.exe");
        menu();
        break;
    case 5:
        downloadFile("https://www.voidtools.com/Everything-1.4.1.1024.x64.zip", "Everything-x64.zip");
        menu();
        break;
    case 6:
        downloadFile("https://www.nirsoft.net/utils/alternatestreamview-x64.zip", "alternatestreamview-x64.zip");
        menu();
        break;
    case 7:
        downloadFile("https://www.nirsoft.net/utils/previousfilesrecovery-x64.zip", "previousfilesrecovery-x64.zip");
        menu();
        break;
    case 8:
        downloadFile("https://www.nirsoft.net/utils/regscanner-x64.zip", "regscanner-x64.zip");
        menu();
        break;
    case 9:
        downloadFile("https://www.nirsoft.net/utils/usbdeview-x64.zip", "usbdeview-x64.zip");
        menu();
        break;
    }
}

void automatici() {
    int selectAuto;
    system("CLS");
    cout << "\x1B[34mTool Automatici\033[0m" << endl;
    cout << "\x1B[34m[1]\033[0m Download Avenge" << endl;
    cout << "\x1B[34m[2]\033[0m Download Echo (Via Browser)" << endl;
    cout << "\x1B[34m[3]\033[0m Download Paladine (Via Browser)" << endl;
    cin >> selectAuto;

    switch (selectAuto)
    {
    case 1:
        downloadFile("https://dl.avenge.ac", "avange.exe");
        menu();
        break;
    case 2:
        openBrowser("https://dl.echo.ac");
        menu();
        break;
    case 3:
        openBrowser("https://dl.paladin.ac");
        menu();
        break;
    }
}

void journal() {
    system("CLS");
    int selectJournal;
    cout << "\x1B[34mTool Automatici\033[0m" << endl;
    cout << "\x1B[34m[1]\033[0m Download Avenge" << endl;
    cout << "\x1B[34m[2]\033[0m Download Echo (Via Browser)" << endl;
    cout << "\x1B[34m[3]\033[0m Download Paladine (Via Browser)" << endl;
    cin >> selectJournal;
	switch(selectJournal) {
        case 1:
            executeJournal("fsutil usn readjournal c: csv | findstr /i /C:\"0x80000200\" | findstr /i /C:.exe /i /C:.py /i /C:.jar /i /C:.dll /i /C:.com /i /C:.pif /i /C:.txt /i /C:.jpg /i /C:.jpeg /i /C:.png /i /C:.lnk /i /C:.mp3 /i /C:.mp4 /i /C:.mkv /i /C:.avi /i /C:.ico /i /C:.bat /i /C:.cmd /i /C:.reg /i /C:.zip /i /C:.rar /i /C:.7z /i /C:.ini /i /C:.html /i /C:.ppt /i /C:.docx /i /C:.xlsx /i /C:.chm /i /C:.aspx /i /C:.app /i /C:? > ", "\\deletedfiles.txt");
            menu();
            break;
    }
	
    menu();
}

void menu() {
    system("CLS");
    int select;
    cout << "\x1B[34mWhite.exe By: NightRiderr_ | Original Creation: White.bat by: ??\033[0m" << endl
         << endl;
    cout << "\x1B[34mScegli l'operazione:\033[0m" << endl;
    cout << "\x1B[34m[1]\033[0m \x1B[36mTool Manuali\033[0m" << endl;
    cout << "\x1B[34m[2]\033[0m \x1B[36mTool Automatici\033[0m" << endl;
    cout << "\x1B[34m[3]\033[0m \x1B[36mJournal Paths\033[0m" << endl;
    cout << "\x1B[34m[4]\033[0m \x1B[36mMacro Paths\033[0m" << endl;
    cout << "\x1B[34m[5]\033[0m \x1B[36mRegistry Paths\033[0m" << endl;
    cout << "\x1B[34m[6]\033[0m \x1B[36mEvent Viewer\033[0m" << endl;
    cout << "\x1B[34m[7]\033[0m \x1B[36mRecord\033[0m" << endl;
    cout << "\x1B[34m[8]\033[0m \x1B[36mQuit\033[0m" << endl;
    cin >> select;
    switch (select)
    {
    case 1:
        manuali();
        break;
    case 2: 
        automatici(); 
        break;
    case 3: 
		journal(); 
		break;
	/*	
    case 4: 
		macro(); 
		break;
    case 5: 
		registro(); 
		break;
    case 6: 
		evtvwr(); 
		break;
    case 7: 
		record(); 
		break; */
    case 8:  
		break;
    }
}

int main()
{
	
    /*if (!IsUserAdmin())
    {
        cout << "Per eseguire questo programma avvialo come amministratore." << endl;
        system("PAUSE");
        return 0;
    } */
    bool pwok = false;
    do
    {
        string pw = password();
        if (pw == "abc")
        {
            pwok = true;
        }
        else
        {
            pwok = false;
            system("CLS");
        }
    } while (pwok == false);
    createMainDirectory();
	menu();
    return 0;
}
