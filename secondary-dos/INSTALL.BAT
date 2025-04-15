@echo off
echo [Air Alert for MS-DOS]
echo Installing...
set /p dir=C:\AIR4DOS
md c:\air4dos
copy air4dos.exe %dir%
copy htget.exe %dir%
