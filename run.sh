#!/usr/bin/env bash
# MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV

set -e

# MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV
GREEN='\033[1;32m'
CYAN='\033[1;36m'
YELLOW='\033[1;33m'
RED='\033[1;31m'
NC='\033[0m'

echo -e "${CYAN}==============================================================================${NC}"
echo -e "${CYAN}  ALKENE CHEMISTRY (1974 VINTAGE SIMULATOR) - ISHGA TUSHIRISH SKRIPTI         ${NC}"
echo -e "${CYAN}==============================================================================${NC}"
echo -e "${YELLOW}  [MR DOPPIX CREATED BY BEHRUZ GOFFAROV | TEL: 70 024 94 14 | TG: @BEHRUZGOFFAROV]${NC}\n"

# MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV
check_and_install_deps() {
    if ! command -v gcc &> /dev/null; then
        echo -e "${YELLOW}[!] GCC kompilyatori topilmadi. O'rnatish tekshirilmoqda...${NC}"
        if command -v apt-get &> /dev/null; then
            echo -e "${CYAN}[*] apt orqali build-essential o'rnatilmoqda...${NC}"
            sudo apt-get update -y && sudo apt-get install -y build-essential gcc
        elif command -v dnf &> /dev/null; then
            echo -e "${CYAN}[*] dnf orqali gcc o'rnatilmoqda...${NC}"
            sudo dnf install -y gcc make
        elif command -v pacman &> /dev/null; then
            echo -e "${CYAN}[*] pacman orqali base-devel o'rnatilmoqda...${NC}"
            sudo pacman -Sy --noconfirm base-devel gcc
        elif command -v apk &> /dev/null; then
            echo -e "${CYAN}[*] apk orqali build-base o'rnatilmoqda...${NC}"
            sudo apk add --no-cache build-base gcc
        else
            echo -e "${RED}[X] Paket menejeri topilmadi. Iltimos GCC o'rnating!${NC}"
            exit 1
        fi
    else
        echo -e "${GREEN}[OK] GCC kompilyatori aniqlandi.${NC}"
    fi
}

# MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV
check_and_install_deps

# MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV
echo -e "${CYAN}[*] O'yin C tilida kompilyatsiya qilinmoqda...${NC}"
gcc -Wall -Wextra -O2 -std=c99 alkene_1974.c -o alkene_1974

if [ -f "./alkene_1974" ]; then
    echo -e "${GREEN}[OK] Kompilyatsiya muvaffaqiyatli yakunlandi! O'yin boshlanmoqda...${NC}\n"
    sleep 1
    ./alkene_1974
else
    echo -e "${RED}[X] Kompilyatsiyada xatolik yuz berdi!${NC}"
    exit 1
fi
