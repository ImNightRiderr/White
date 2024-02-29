#include "fileHandler.h"

using namespace std;

void menu();

void manuali()
{
    system("CLS");
    cout << "\x1B[34mTool Manuali\033[0m" << endl;
    cout << "\x1B[34m[0]\033[0m \x1B[36mIndietro\033[0m" << endl
         << endl;
    cout << "\x1B[34m[1]\033[0m \x1B[36mDownload Process Hacker 2\033[0m" << endl;
    cout << "\x1B[34m[2]\033[0m \x1B[36mDownload LastActivityView\033[0m" << endl;
    cout << "\x1B[34m[3]\033[0m \x1B[36mDownload WinPrefetchView\033[0m" << endl;
    cout << "\x1B[34m[4]\033[0m \x1B[36mDownload Luyten\033[0m" << endl;
    cout << "\x1B[34m[5]\033[0m \x1B[36mDownload Everything\033[0m" << endl;
    cout << "\x1B[34m[6]\033[0m \x1B[36mDownload AlternateStreamView\033[0m" << endl;
    cout << "\x1B[34m[7]\033[0m \x1B[36mDownload PreviousFilesRecovery\033[0m" << endl;
    cout << "\x1B[34m[8]\033[0m \x1B[36mRegScanner\033[0m" << endl;
    cout << "\x1B[34m[9]\033[0m \x1B[36mUSBDeview\033[0m" << endl;
    string input;
    cin >> input;
    try
    {
        int correctInput = stoi(input);
        switch (correctInput)
        {
        case 0:
            menu();
            break;
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
        default:
            cout << "\x1B[34mErrore:\033[0m \x1B[36minserimento errato, seleziona un numero tra 0 e 9.\033[0m" << endl;
            manuali();
        }
    }
    catch (const exception &e)
    {
        cout << "\x1B[34mErrore:\033[0m \x1B[36mdevi inserire un numero intero\033[0m" << endl;
        sleep(1);
        manuali();
        return;
    }
}

void automatici()
{
    system("CLS");
    cout << "\x1B[34mTool Automatici\033[0m" << endl;
    cout << "\x1B[34m[0]\033[0m \x1B[36mIndietro\033[0m" << endl
         << endl;
    cout << "\x1B[34m[1]\033[0m \x1B[36mDownload Avenge\033[0m" << endl;
    cout << "\x1B[34m[2]\033[0m \x1B[36mDownload Echo (Via Browser)\033[0m" << endl;
    cout << "\x1B[34m[3]\033[0m \x1B[36mDownload Paladine (Via Browser)\033[0m" << endl;
    string input;
    cin >> input;
    try
    {
        int correctInput = stoi(input);
        switch (correctInput)
        {
        case 0:
            menu();
            break;
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
        default:
            cout << "\x1B[34mErrore:\033[0m \x1B[36minserimento errato, seleziona un numero tra 0 e 3.\033[0m" << endl;
            automatici();
            break;
        }
    }
    catch (const exception &e)
    {
        cout << "\x1B[34mErrore:\033[0m \x1B[36mdevi inserire un numero intero\033[0m" << endl;
        sleep(1);
        automatici();
        return;
    }
}

void journal()
{
    system("CLS");
    cout << "\x1B[34mJournal Paths\033[0m" << endl;
    cout << "\x1B[34m[0]\033[0m Indietro\033[0m" << endl
         << endl;
    cout << "\x1B[34m[1]\033[0m Security changes\033[0m" << endl;
    cout << "\x1B[34m[2]\033[0m Explorer restart\033[0m" << endl;
    cout << "\x1B[34m[3]\033[0m Deleted files\033[0m" << endl;
    cout << "\x1B[34m[4]\033[0m Renamed files\033[0m" << endl;
    cout << "\x1B[34m[5]\033[0m File streams\033[0m" << endl;
    cout << "\x1B[34m[6]\033[0m Jarcache\033[0m" << endl;
    cout << "\x1B[34m[7]\033[0m Type\033[0m" << endl;
    string input;
    cin >> input;
    try
    {
        int correctInput = stoi(input);
        switch (correctInput)
        {
        case 0:
            menu();
            break;
        case 1:
            executeJournal("fsutil usn readjournal c: csv | findstr /i /C:\"0x00000800\" | findstr /i /C:.exe /i /C:Prefetch >", "\\securityChanges.txt");
            break;
        case 2:
            executeJournal("fsutil usn readJournal c: csv | findstr /i /C:\"0x00000100\" | findstr /i /C:explorer /i /C:.pf >", "\\restartExplorer.txt");
            break;
        case 3:
            executeJournal("fsutil usn readjournal c: csv | findstr /i /C:\"0x80000200\" | findstr /i /C:.exe\\^\" /i /C:.py\\^\" /i /C:.jar\\^\" /i /C:.dll\\^\" /i /C:.com\\^\" /i /C:.pif\\^\" /i /C:.txt\\^\" /i /C:.jpg\\^\" /i /C:.jpeg\\^\" /i /C:.png\\^\" /i /C:.lnk\\^\" /i /C:.mp3\\^\" /i /C:.mp4\\^\" /i /C:.mkv\\^\" /i /C:.avi\\^\" /i /C:.ico\\^\" /i /C:.bat\\^\" /i /C:.cmd\\^\" /i /C:.reg\\^\" /i /C:.zip\\^\" /i /C:.rar\\^\" /i /C: .7z\\^\" /i /C:.ini\\^\" /i /C:.html\\^\" /i /C:.ppt\\^\" /i /C:.docx\\^\" /i /C:.xlsx\\^\" /i /C:.chm\\^\" /i /C:.aspx\\^\" /i /C:.app\\^\" /i /C:? > ", "\\deletedFiles.txt");
            break;
        case 4:
            executeJournal("fsutil usn readjournal c: csv | findstr /i /C:\"0x00002000\" /i /C:\"0x00001000\" | findstr /i /C:.exe\\^\" /i /C:.py\\^\" /i /C:.jar\\^\" /i /C:.dll\\^\" /i /C:.com\\^\" /i /C:.pif\\^\" /i /C:.txt\\^\" /i /C:.jpg\\^\" /i /C:.jpeg\\^\" /i /C:.png\\^\" /i /C:.lnk\\^\" /i /C:.mp3\\^\" /i /C:.mp4\\^\" /i /C:.mkv\\^\" /i /C:.avi\\^\" /i /C:.ico\\^\" /i /C:.bat\\^\" /i /C:.cmd\\^\" /i /C:.reg\\^\" /i /C:.zip\\^\" /i /C:.rar\\^\" /i /C:.7z\\^\" /i /C:.ini\\^\" /i /C:.html\\^\" /i /C:.ppt\\^\" /i /C:.docx\\^\" /i /C:.xlsx\\^\" /i /C:.chm\\^\" /i /C:.aspx\\^\" /i /C:.app\\^\" /i /C:? >", "\\renamedFiles.txt");
            break;
        case 5:
            executeJournal("fsutil usn readJournal c: csv | findstr /I /C:\"0x00200120\" >", "\\fileStreams.txt");
            break;
        case 6:
            executeJournal("fsutil usn readJournal c: csv | findstr /i /C:\"0x00000004\" /i /C:\"0x00000102\" | findstr /i /C:\"jar_cache\" /i /C:\".timestamp\" >", "\\jarCache.txt");
            break;
        case 7:
            executeJournal("fsutil usn readJournal c: csv | findstr /i /C:\"0x00002020\" /i /C:\"0x00000020\" /i /C:\"0x00200000\" | findstr /i /C:\"0x80008000\" /i /C:\"0x00008006\" /i /C:\"0x80200120\" | findstr /i /C:.exe\\^\" /i /C:.py\\^ \" /i /C:.jar\\^\" /i /C:.dll\\^ \" /i /C:.com\\^\" /i /C:.pif\\^\" /i /C:.txt\\^\" /i /C:.jpg\\^\" /i /C:.jpeg\\^\" /i / C :.png\\^\" /i /C:.lnk\\^\" /i /C:.mp3\\^\" /i /C:.mp4\\^\" /i /C :.mkv\\^\" /i /C:.avi\\^\" /i /C:.ico\\^\" /i /C:.bat\\^\" /i /C:.cmd\\^\" /i /C:.reg\\^\" /i /C:.zip\\^\" /i /C:.rar\\^\" /i /C: .7z\\^\" /i /C:.ini\\^\" /i /C:.html\\^\" /i /C:.ppt\\^\" /i /C:.docx\\^\" /i /C:.xlsx\\^\" /i /C:.chm\\^\" /i /C:.aspx\\^\" /i /C:.app\\^\" /i /C:? >", "\\renamedfiles.txt");
            break;
        default:
            cout << "\x1B[34mErrore:\033[0m \x1B[36minserimento errato, seleziona un numero tra 0 e 7.\033[0m" << endl;
            journal();
        }

        menu();
    }
    catch (const exception &e)
    {
        cout << "\x1B[34mErrore:\033[0m \x1B[36mdevi inserire un numero intero\033[0m" << endl;
        sleep(1);
        journal();
        return;
    }
}

void macro()
{
    system("CLS");
    cout << "\x1B[34mMacro Paths\033[0m" << endl;
    cout << "\x1B[36mCercando . . .\033[0m" << endl;
    macroSoftwareFinder();
    menu();
}

void registro()
{
    system("CLS");
    cout << "\x1B[34mRegistry Paths\033[0m" << endl;
    cout << "\x1B[34m[0]\033[0m \x1B[36mIndietro\033[0m" << endl
         << endl;
    cout << "\x1B[34m[1]\033[0m \x1B[36mExecutable Files Ran\033[0m" << endl;
    cout << "\x1B[34m[2]\033[0m \x1B[36mExecuted Programs\033[0m" << endl;
    cout << "\x1B[34m[3]\033[0m \x1B[36mFile Type Associations\033[0m" << endl;
    cout << "\x1B[34m[4]\033[0m \x1B[36mOpen Save DialogBox\033[0m" << endl;
    cout << "\x1B[34m[5]\033[0m \x1B[36mPrefetch Parameters\033[0m" << endl;
    cout << "\x1B[34m[6]\033[0m \x1B[36mMounted Volumes\033[0m" << endl;
    string input;
    cin >> input;
    try
    {
        int correctInput = stoi(input);
        switch (correctInput)
        {
        case 0:
            menu();
            return;
            break;
        case 1:
            openRegedit("HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Applets\\Regedit /v LastKey /t REG_SZ /d HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services\\bam\\State\\UserSettings /f");
            break;
        case 2:
            openRegedit("HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Applets\\Regedit /v LastKey /t REG_SZ /d \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Compatibility Assistant\\Store\" /f");
            break;
        case 3:
            openRegedit("HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Applets\\Regedit /v LastKey /t REG_SZ /d HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts /f");
            break;
        case 4:
            openRegedit("HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Applets\\Regedit /v LastKey /t REG_SZ /d HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU /f");
            break;
        case 5:
            openRegedit("HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Applets\\Regedit /v LastKey /t REG_SZ /d \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\PrefetchParameters\" /f");
            break;
        case 6:
            openRegedit("HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Applets\\Regedit /v LastKey /t REG_SZ /d HKEY_LOCAL_MACHINE\\SYSTEM\\MountedDevices /f");
            break;
        default:
            cout << "\x1B[34mErrore:\033[0m \x1B[36minserimento errato, seleziona un numero tra 0 e 6.\033[0m" << endl;
        }
    }
    catch (const exception &e)
    {
        cout << "\x1B[34mErrore:\033[0m \x1B[36mdevi inserire un numero intero\033[0m" << endl;
        sleep(1);
        registro();
        return;
    }
    menu();
}

void menu()
{
    system("CLS");
    string input;
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
    cin >> input;
    try
    {
        int correctInput = stoi(input);
        switch (correctInput)
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
        case 4:
            macro();
            break;
        case 5:
            registro();
            break; /*
        case 6:
            evtvwr();
            break;
        case 7:
            record();
            break; */
        case 8:
            return;
        default:
            cout << "\x1B[34mErrore:\033[0m \x1B[36minserimento errato, seleziona un numero tra 1 e 8.\033[0m" << endl;
            sleep(1);
            menu();
            break;
        }
    }
    catch (const exception &e)
    {
        cout << "\x1B[34mErrore:\033[0m \x1B[36mdevi inserire un numero intero\033[0m" << endl;
        sleep(1);
        menu();
        return;
    }
}

int main()
{
    if (!elevate())
    {
        cout << "\x1B[34mErrore:\033[0m \x1B[36mImpossibile eseguire come amministratore.\033[0m" << endl;
        system("PAUSE");
        return 1;
    }
    else if (!isElevated())
    {
        return 0;
    }
    system("CLS");
    bool pwok = false;
    do
    {
        string pw = password();
        if (pw == "kzy")
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