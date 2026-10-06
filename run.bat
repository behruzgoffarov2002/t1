@echo off
REM MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV
title ALKENE CHEMISTRY 1974 - MR DOPPIX

REM MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV
color 0B
cls
echo ==============================================================================
echo   ALKENE CHEMISTRY (1974 VINTAGE SIMULATOR) - WINDOWS ISHGA TUSHIRISH
echo ==============================================================================
echo   [MR DOPPIX CREATED BY BEHRUZ GOFFAROV | TEL: 70 024 94 14 | TG: @BEHRUZGOFFAROV]
echo.

REM MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV
where gcc >nul 2>nul
if %errorlevel% neq 0 (
    echo [!] GCC (MinGW yoki Clang) kompilyatori topilmadi!
    echo [*] Iltimos MinGW (GCC) o'rnating yoki winget orqali o'rnatishni sinab ko'ring:
    echo     winget install LLVM.LLVM yoki winget install msys2
    echo.
    pause
    exit /b 1
)

REM MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV
echo [*] O'yin C tilida kompilyatsiya qilinmoqda...
gcc -Wall -Wextra -O2 -std=c99 alkene_1974.c -o alkene_1974.exe

if exist alkene_1974.exe (
    echo [OK] Kompilyatsiya muvaffaqiyatli bajarildi!
    echo [*] O'yin ishga tushirilmoqda...
    timeout /t 1 /nobreak >nul
    alkene_1974.exe
) else (
    echo [X] Kompilyatsiya jarayonida xatolik yuz berdi!
    pause
    exit /b 1
)
