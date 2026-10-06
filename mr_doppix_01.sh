#!/bin/bash

clear

# Ranglar
RED='\033[1;31m'
GREEN='\033[1;32m'
CYAN='\033[1;36m'
YELLOW='\033[1;33m'
WHITE='\033[1;37m'
RESET='\033[0m'

# Terminal title
printf '\033]0;MR DOPPIX\007'

# ASCII Banner
echo -e "${CYAN}"
cat <<'EOF'
███╗   ███╗██████╗     ██████╗  ██████╗ ██████╗ ██████╗ ██╗██╗  ██╗
████╗ ████║██╔══██╗    ██╔══██╗██╔═══██╗██╔══██╗██╔══██╗██║╚██╗██╔╝
██╔████╔██║██████╔╝    ██║  ██║██║   ██║██████╔╝██████╔╝██║ ╚███╔╝
██║╚██╔╝██║██╔══██╗    ██║  ██║██║   ██║██╔═══╝ ██╔═══╝ ██║ ██╔██╗
██║ ╚═╝ ██║██║  ██║    ██████╔╝╚██████╔╝██║     ██║     ██║██╔╝ ██╗
╚═╝     ╚═╝╚═╝  ╚═╝    ╚═════╝  ╚═════╝ ╚═╝     ╚═╝     ╚═╝╚═╝  ╚═╝
EOF
echo -e "${RESET}"

echo -e "${YELLOW}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "${WHITE}                    SYSTEM INFORMATION${RESET}"
echo -e "${YELLOW}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"

# CPU
CPU=$(grep -m1 "model name" /proc/cpuinfo | cut -d: -f2 | xargs)

# RAM
RAM_TOTAL=$(free -h | awk '/^Mem:/ {print $2}')
RAM_USED=$(free -h | awk '/^Mem:/ {print $3}')
RAM_FREE=$(free -h | awk '/^Mem:/ {print $4}')
RAM_PERCENT=$(free | awk '/^Mem:/ {printf "%.0f", $3/$2*100}')

# Root disk
DISK_TOTAL=$(df -h / | awk 'NR==2 {print $2}')
DISK_USED=$(df -h / | awk 'NR==2 {print $3}')
DISK_FREE=$(df -h / | awk 'NR==2 {print $4}')
DISK_PERCENT=$(df / | awk 'NR==2 {print $5}')

# Uptime
UPTIME=$(uptime -p)

echo
echo -e "${CYAN}  CPU${RESET}"
echo -e "  ├─ ${WHITE}$CPU${RESET}"

echo
echo -e "${CYAN}  RAM${RESET}"
echo -e "  ├─ Total : ${WHITE}$RAM_TOTAL${RESET}"
echo -e "  ├─ Used  : ${RED}$RAM_USED${RESET}"
echo -e "  ├─ Free  : ${GREEN}$RAM_FREE${RESET}"
echo -e "  └─ Usage : ${YELLOW}${RAM_PERCENT}%${RESET}"

echo
echo -e "${CYAN}  DISK / SSD / HDD${RESET}"
echo -e "  ├─ Total : ${WHITE}$DISK_TOTAL${RESET}"
echo -e "  ├─ Used  : ${RED}$DISK_USED${RESET}"
echo -e "  ├─ Free  : ${GREEN}$DISK_FREE${RESET}"
echo -e "  └─ Usage : ${YELLOW}$DISK_PERCENT${RESET}"

echo
echo -e "${CYAN}  SYSTEM${RESET}"
echo -e "  └─ Uptime: ${WHITE}$UPTIME${RESET}"

echo
echo -e "${YELLOW}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "${GREEN}                    MR DOPPIX SYSTEM${RESET}"
echo -e "${YELLOW}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
