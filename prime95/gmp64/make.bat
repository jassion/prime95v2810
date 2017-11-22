@echo off
rem  π”√ddk±‡“Î
set path=D:\WinDDK\7600.16385.1\bin\x86\amd64;%path%
set include=D:\WinDDK\7600.16385.1\inc\crt;C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Include;D:\WinDDK\7600.16385.1\inc\api;
set lib=D:\WinDDK\7600.16385.1\lib\Crt\amd64;D:\WinDDK\7600.16385.1\lib\win7\amd64;

rem call "D:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x64

echo ---==By GoldenSpider 2014-7-1==--

cl   /c /MD gmptest.c
link /subsystem:console gmptest.obj  msvcrt.lib

del *.obj

pause
gmptest.exe
pause
