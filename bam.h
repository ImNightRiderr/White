#include "C:\Users\GameFire\Desktop\fileHandler.h"
#include <fstream>
#include <cstdio>

void executeBam()
{
    cout << "\x1B[34mEseguendo il BAM, potrebbero volerci alcuni secondi. . .\033[0m" << endl;
    std::string frase = "$ErrorActionPreference = \"SilentlyContinue\"\n\n"
                        "function Get-Signature {\n"
                        "\t[CmdletBinding()]\n"
                        "\tparam (\n"
                        "\t\t[string[]]$FilePath\n"
                        "\t)\n\n"
                        "\t$Existence = Test-Path -PathType 'Leaf' -Path $FilePath\n"
                        "\t$Authenticode = (Get-AuthenticodeSignature -FilePath $FilePath -ErrorAction SilentlyContinue).Status\n"
                        "\t$Signature = 'Invalid Signature (UnknownError)'\n\n"
                        "\tif ($Existence) {\n"
                        "\t\tif ($Authenticode -eq 'Valid') {\n"
                        "\t\t\t$Signature = 'Valid Signature'\n"
                        "\t\t}\n"
                        "\t\telseif ($Authenticode -eq 'NotSigned') {\n"
                        "\t\t\t$Signature = 'Invalid Signature (NotSigned)'\n"
                        "\t\t}\n"
                        "\t\telseif ($Authenticode -eq 'HashMismatch') {\n"
                        "\t\t\t$Signature = 'Invalid Signature (HashMismatch)'\n"
                        "\t\t}\n"
                        "\t\telseif ($Authenticode -eq 'NotTrusted') {\n"
                        "\t\t\t$Signature = 'Invalid Signature (NotTrusted)'\n"
                        "\t\t}\n"
                        "\t\telseif ($Authenticode -eq 'UnknownError') {\n"
                        "\t\t\t$Signature = 'Invalid Signature (UnknownError)'\n"
                        "\t\t}\n"
                        "\t\treturn $Signature\n"
                        "\t} else {\n"
                        "\t\t$Signature = 'File Was Not Found'\n"
                        "\t\treturn $Signature\n"
                        "\t}\n"
                        "}\n\n"
                        "Clear-Host\n\n"
                        "function Test-Admin {;\n"
                        "\t$currentUser = New-Object Security.Principal.WindowsPrincipal $([Security.Principal.WindowsIdentity]::GetCurrent());\n"
                        "\t$currentUser.IsInRole([Security.Principal.WindowsBuiltinRole]::Administrator);\n"
                        "}\n"
                        "if (!(Test-Admin)) {\n"
                        "\tWrite-Warning 'Please Run This Script as Admin.'\n"
                        "\tStart-Sleep 10\n"
                        "\tExit\n"
                        "}\n\n"
                        "$sw = [Diagnostics.Stopwatch]::StartNew()\n\n"
                        "if (!(Get-PSDrive -Name HKLM -PSProvider Registry)) {\n"
                        "\tTry {\n"
                        "\t\tNew-PSDrive -Name HKLM -PSProvider Registry -Root HKEY_LOCAL_MACHINE\n"
                        "\t}\n"
                        "\tCatch {\n"
                        "\t\tWrite-Warning 'Error Mounting HKEY_Local_Machine'\n"
                        "\t}\n"
                        "}\n"
                        "$bv = ('bam', 'bam\\State')\n"
                        "Try {\n"
                        "\t$Users = foreach ($ii in $bv) {\n"
                        "\t\tGet-ChildItem -Path \"HKLM:\\SYSTEM\\CurrentControlSet\\Services\\$($ii)\\UserSettings\\\" | Select-Object -ExpandProperty PSChildName\n"
                        "\t}\n"
                        "}\n"
                        "Catch {\n"
                        "\tWrite-Warning 'Error Parsing BAM Key. Likely unsupported Windows Version'\n"
                        "\tExit\n"
                        "}\n"
                        "$rpath = @('HKLM:\\SYSTEM\\CurrentControlSet\\Services\\bam\\', 'HKLM:\\SYSTEM\\CurrentControlSet\\Services\\bam\\state\\')\n\n"
                        "$UserTime = (Get-ItemProperty -Path 'HKLM:\\SYSTEM\\CurrentControlSet\\Control\\TimeZoneInformation').TimeZoneKeyName\n"
                        "$UserBias = (Get-ItemProperty -Path 'HKLM:\\SYSTEM\\CurrentControlSet\\Control\\TimeZoneInformation').ActiveTimeBias\n"
                        "$UserDay = (Get-ItemProperty -Path 'HKLM:\\SYSTEM\\CurrentControlSet\\Control\\TimeZoneInformation').DaylightBias\n\n"
                        "$Bam = Foreach ($Sid in $Users) {\n"
                        "\t$u++\n\n"
                        "\tforeach ($rp in $rpath) {\n"
                        "\t\t$BamItems = Get-Item -Path \"$($rp)UserSettings\\$Sid\" -ErrorAction SilentlyContinue | Select-Object -ExpandProperty Property\n"
                        "\t\tWrite-Host -ForegroundColor Blue 'Extracting ' -NoNewLine\n"
                        "\t\tWrite-Host -ForegroundColor Cyan \"$($rp)UserSettings\\$SID\"\n"
                        "\t\t$bi = 0\n\n"
                        "\t\tTry {\n"
                        "\t\t\t$objSID = New-Object System.Security.Principal.SecurityIdentifier($Sid)\n"
                        "\t\t\t$User = $objSID.Translate([System.Security.Principal.NTAccount])\n"
                        "\t\t\t$User = $User.Value\n"
                        "\t\t}\n"
                        "\t\tCatch {\n"
                        "\t\t\t$User = ''\n"
                        "\t\t}\n"
                        "\t\t$i = 0\n"
                        "\t\tForEach ($Item in $BamItems) {\n"
                        "\t\t\t$i++\n"
                        "\t\t\t$Key = Get-ItemProperty -Path \"$($rp)UserSettings\\$Sid\" -ErrorAction SilentlyContinue | Select-Object -ExpandProperty $Item\n\n"
                        "\t\t\tIf ($key.length -eq 24) {\n"
                        "\t\t\t\t$Hex = [System.BitConverter]::ToString($key[7..0]) -replace '-', ''\n"
                        "\t\t\t\t$TimeLocal = Get-Date ([DateTime]::FromFileTime([Convert]::ToInt64($Hex, 16))) -Format 'yyyy-MM-dd HH:mm:ss'\n"
                        "\t\t\t\t$TimeUTC = Get-Date ([DateTime]::FromFileTimeUtc([Convert]::ToInt64($Hex, 16))) -Format 'yyyy-MM-dd HH:mm:ss'\n"
                        "\t\t\t\t$Bias = -([convert]::ToInt32([Convert]::ToString($UserBias, 2), 2))\n"
                        "\t\t\t\t$Day = -([convert]::ToInt32([Convert]::ToString($UserDay, 2), 2))\n"
                        "\t\t\t\t$Biasd = $Bias/60\n"
                        "\t\t\t\t$Dayd = $Day/60\n"
                        "\t\t\t\t$TImeUser = (Get-Date ([DateTime]::FromFileTimeUtc([Convert]::ToInt64($Hex, 16))).addminutes($Bias) -Format 'yyyy-MM-dd HH:mm:ss')\n"
                        "\t\t\t\t$d = if((((split-path -path $item) | ConvertFrom-String -Delimiter '\\\\').P3)-match '\\\\d{1}')\n"
                        "\t\t\t\t{((split-path -path $item).Remove(23)).trimstart('\\Device\\HarddiskVolume')} else {$d = ''}\n"
                        "\t\t\t\t$f = if((((split-path -path $item) | ConvertFrom-String -Delimiter '\\\\').P3)-match '\\\\d{1}')\n"
                        "\t\t\t\t{Split-path -leaf ($item).TrimStart()} else {$item}\n"
                        "\t\t\t\t$cp = if((((split-path -path $item) | ConvertFrom-String -Delimiter '\\\\').P3)-match '\\\\d{1}')\n"
                        "\t\t\t\t{($item).Remove(1, 23)} else {$cp = ''}\n"
                        "\t\t\t\t$path = if((((split-path -path $item) | ConvertFrom-String -Delimiter '\\\\').P3)-match '\\\\d{1}')\n"
                        "\t\t\t\t{Join-Path -Path 'C:' -ChildPath $cp} else {$path = ''}\n"
                        "\t\t\t\t$sig = if((((split-path -path $item) | ConvertFrom-String -Delimiter '\\\\').P3)-match '\\\\d{1}')\n"
                        "\t\t\t\t{Get-Signature -FilePath $path} else {$sig = ''}\n"
                        "\t\t\t\t[PSCustomObject]@{\n"
                        "\t\t\t\t\t'Examiner Time' = $TimeLocal\n"
                        "\t\t\t\t\t'Last Execution Time (UTC)'= $TimeUTC\n"
                        "\t\t\t\t\t'Last Execution User Time' = $TimeUser\n"
                        "\t\t\t\t\tApplication = $f\n"
                        "\t\t\t\t\tPath = $path\n"
                        "\t\t\t\t\tSignature = $Sig\n"
                        "\t\t\t\t\tUser = $User\n"
                        "\t\t\t\t\tSID = $Sid\n"
                        "\t\t\t\t\tRegpath = $rp\n"
                        "\t\t\t\t}\n"
                        "\t\t\t}\n"
                        "\t\t}\n"
                        "\t}\n"
                        "}\n\n"
                        "$Bam | Out-GridView -PassThru -Title \"BAM key entries $($Bam.count)  - User TimeZone: ($UserTime) -> ActiveBias: ( $Bias) - DayLightTime: ($Day)\"\n\n"
                        "$sw.stop()\n"
                        "$t = $sw.Elapsed.TotalMinutes\n";
    // chatgpt mi ha carriato qua senno chi cazzo aveva voglia di sostituire tutti gli spazi le " gli invii
    string path = getMainPath();
    path += "\\script.ps1";
    std::ofstream file(path);
    if (file.is_open())
    {
        file << frase;
        file.close();
    }
    else
    {
        std::cerr << "Impossibile creare il file temporaneo." << std::endl;
        return;
    }
    std::string comando = "powershell -ExecutionPolicy ByPass -File " + path;
    int risultato = system(comando.c_str());
    if (std::remove(path.c_str()) != 0)
    {
        std::string command = "del /F ";
        command += path;
        int result = system(command.c_str());
    }
    sleep(1);
    return;
}