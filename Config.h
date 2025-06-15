/*

                ############# White.exe V2.0 #############

                        (c) 2024 - 2025 NightRiderr_
        By using this software, you accept the terms of service and the licence.
            View everything on: https://github.com/ImNightRiderr/

                ##########################################

*/

#pragma once
#include <string>
#include <shlobj.h>

namespace Config {
    const std::string COLOR_BLUE = "\x1B[34m";
    const std::string COLOR_CYAN = "\x1B[36m";
    const std::string COLOR_ERROR = "\x1B[31m";
    const std::string COLOR_RESET = "\033[0m";

    const std::string TITLE = "White.exe - ";
    const std::string AUTHOR = " By: NightRiderr_"; // Non rimuovere questa riga, per usare il programma devi mantenere l'autore (NightRiderr_) come da licenza. Don't remove this line, to use the program you must keep the author (NightRiderr_) as license.
    const std::string VERSION = "Beta 1.9 ";
    const std::string COPYRIGHT = " - Copyright (c) 2025";
    static std::string BASE_PATH;
    static std::string TOOLS_PATH;
    static std::string JOURNAL_PATH;
    const std::string BAM_SCRIPT = R"###(
$ErrorActionPreference = "SilentlyContinue"

function Get-Signature {
    [CmdletBinding()]
    param (
        [string[]]$FilePath
    )

    $Existence = Test-Path -PathType 'Leaf' -Path $FilePath
    $Authenticode = (Get-AuthenticodeSignature -FilePath $FilePath -ErrorAction SilentlyContinue).Status
    $Signature = 'Invalid Signature (UnknownError)'

    if ($Existence) {
        if ($Authenticode -eq 'Valid') {
            $Signature = 'Valid Signature'
        }
        elseif ($Authenticode -eq 'NotSigned') {
            $Signature = 'Invalid Signature (NotSigned)'
        }
        elseif ($Authenticode -eq 'HashMismatch') {
            $Signature = 'Invalid Signature (HashMismatch)'
        }
        elseif ($Authenticode -eq 'NotTrusted') {
            $Signature = 'Invalid Signature (NotTrusted)'
        }
        elseif ($Authenticode -eq 'UnknownError') {
            $Signature = 'Invalid Signature (UnknownError)'
        }
        return $Signature
    } else {
        $Signature = 'File Was Not Found'
        return $Signature
    }
}

Clear-Host

function Test-Admin {
    $currentUser = New-Object Security.Principal.WindowsPrincipal $([Security.Principal.WindowsIdentity]::GetCurrent())
    $currentUser.IsInRole([Security.Principal.WindowsBuiltinRole]::Administrator)
}
if (!(Test-Admin)) {
    Write-Warning 'Please Run This Script as Admin.'
    Start-Sleep 10
    Exit
}

$sw = [Diagnostics.Stopwatch]::StartNew()

if (!(Get-PSDrive -Name HKLM -PSProvider Registry)) {
    Try {
        New-PSDrive -Name HKLM -PSProvider Registry -Root HKEY_LOCAL_MACHINE
    }
    Catch {
        Write-Warning 'Error Mounting HKEY_Local_Machine'
    }
}
$bv = ('bam', 'bam\State')
Try {
    $Users = foreach ($ii in $bv) {
        Get-ChildItem -Path "HKLM:\SYSTEM\CurrentControlSet\Services\$($ii)\UserSettings\" | Select-Object -ExpandProperty PSChildName
    }
}
Catch {
    Write-Warning 'Error Parsing BAM Key. Likely unsupported Windows Version'
    Exit
}
$rpath = @('HKLM:\SYSTEM\CurrentControlSet\Services\bam\', 'HKLM:\SYSTEM\CurrentControlSet\Services\bam\state\')

$UserTime = (Get-ItemProperty -Path 'HKLM:\SYSTEM\CurrentControlSet\Control\TimeZoneInformation').TimeZoneKeyName
$UserBias = (Get-ItemProperty -Path 'HKLM:\SYSTEM\CurrentControlSet\Control\TimeZoneInformation').ActiveTimeBias
$UserDay = (Get-ItemProperty -Path 'HKLM:\SYSTEM\CurrentControlSet\Control\TimeZoneInformation').DaylightBias

$Bam = Foreach ($Sid in $Users) {
    $u++

    foreach ($rp in $rpath) {
        $BamItems = Get-Item -Path "$($rp)UserSettings\$Sid" -ErrorAction SilentlyContinue | Select-Object -ExpandProperty Property
        Write-Host -ForegroundColor Blue 'Extracting ' -NoNewLine
        Write-Host -ForegroundColor Cyan "$($rp)UserSettings\$SID"
        $bi = 0

        Try {
            $objSID = New-Object System.Security.Principal.SecurityIdentifier($Sid)
            $User = $objSID.Translate([System.Security.Principal.NTAccount])
            $User = $User.Value
        }
        Catch {
            $User = ''
        }
        $i = 0
        ForEach ($Item in $BamItems) {
            $i++
            $Key = Get-ItemProperty -Path "$($rp)UserSettings\$Sid" -ErrorAction SilentlyContinue | Select-Object -ExpandProperty $Item

            If ($key.length -eq 24) {
                $Hex = [System.BitConverter]::ToString($key[7..0]) -replace '-', ''
                $TimeLocal = Get-Date ([DateTime]::FromFileTime([Convert]::ToInt64($Hex, 16))) -Format 'yyyy-MM-dd HH:mm:ss'
                $TimeUTC = Get-Date ([DateTime]::FromFileTimeUtc([Convert]::ToInt64($Hex, 16))) -Format 'yyyy-MM-dd HH:mm:ss'
                $Bias = -([convert]::ToInt32([Convert]::ToString($UserBias, 2), 2))
                $Day = -([convert]::ToInt32([Convert]::ToString($UserDay, 2), 2))
                $Biasd = $Bias/60
                $Dayd = $Day/60
                $TImeUser = (Get-Date ([DateTime]::FromFileTimeUtc([Convert]::ToInt64($Hex, 16))).addminutes($Bias) -Format 'yyyy-MM-dd HH:mm:ss')
                $d = if((((split-path -path $item) | ConvertFrom-String -Delimiter '\').P3)-match '\\d{1}')
                {((split-path -path $item).Remove(23)).trimstart('\Device\HarddiskVolume')} else {$d = ''}
                $f = if((((split-path -path $item) | ConvertFrom-String -Delimiter '\').P3)-match '\\d{1}')
                {Split-path -leaf ($item).TrimStart()} else {$item}
                $cp = if((((split-path -path $item) | ConvertFrom-String -Delimiter '\').P3)-match '\\d{1}')
                {($item).Remove(1, 23)} else {$cp = ''}
                $path = if((((split-path -path $item) | ConvertFrom-String -Delimiter '\').P3)-match '\\d{1}')
                {Join-Path -Path 'C:' -ChildPath $cp} else {$path = ''}
                $sig = if((((split-path -path $item) | ConvertFrom-String -Delimiter '\').P3)-match '\\d{1}')
                {Get-Signature -FilePath $path} else {$sig = ''}
                [PSCustomObject]@{
                    'Examiner Time' = $TimeLocal
                    'Last Execution Time (UTC)'= $TimeUTC
                    'Last Execution User Time' = $TimeUser
                    Application = $f
                    Path = $path
                    Signature = $Sig
                    User = $User
                    SID = $Sid
                    Regpath = $rp
                }
            }
        }
    }
}

$Bam | Out-GridView -PassThru -Title "BAM key entries $($Bam.count)  - User TimeZone: ($UserTime) -> ActiveBias: ( $Bias) - DayLightTime: ($Day)"

$sw.stop()
$t = $sw.Elapsed.TotalMinutes
)###";

    struct ToolInfo {
        std::string url;
        std::string filename;
    };
    const ToolInfo PROCESS_HACKER = {
        "https://github.com/winsiderss/systeminformer/releases/download/v3.2.25011.2103/systeminformer-3.2.25011-release-bin.zip",
        "processhacker(systeminformer).zip"
    };
}