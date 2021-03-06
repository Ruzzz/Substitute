@echo off
:: Pack exe files in 7z archive
:: Dependences: http://www.7-zip.org

:: Initialize
call get_version.bat
set CURRENT_PATH="%~dp0"
set ROOT_PATH=%CURRENT_PATH%..\..
set ARC_NAME=substi_v%VERSION%_win
set ARC_PATH=%ARC_NAME%
set CLEAN_EXE_PATCH=%CURRENT_PATH%clean_rich_signature

:: Prepare files
mkdir %ARC_PATH%
copy /V %ROOT_PATH%\bin\substi.exe %ARC_PATH%\
sipatch -nobackup %ARC_PATH%\substi.exe %CLEAN_EXE_PATCH%

:: Pack
erase *.7z
7za.exe a -t7z %ARC_NAME%.7z %ARC_PATH%\ -mx9
rmdir /S /Q %ARC_PATH%
