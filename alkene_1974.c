/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
  #include <windows.h>
  #include <conio.h>
  #define SLEEP_MS(ms) Sleep(ms)
  #define CLEAR_SCREEN() system("cls")
#else
  #include <unistd.h>
  #include <termios.h>
  #define SLEEP_MS(ms) usleep((ms) * 1000)
  #define CLEAR_SCREEN() printf("\033[H\033[J")
#endif

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
#define COLOR_RESET   "\033[0m"
#define COLOR_BLACK   "\033[0;30m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN    "\033[1;36m"
#define COLOR_WHITE   "\033[1;37m"
#define COLOR_BG_BLUE "\033[44m"
#define COLOR_BG_DARK "\033[40m"
#define COLOR_BOLD    "\033[1m"

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void enable_raw_mode(void) {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void print_header(void) {
    CLEAR_SCREEN();
    printf("%s", COLOR_CYAN);
    printf("  ==============================================================================\n");
    printf("  ||       __      _       __  __  ____  _   _  ______      __   ___  _____ _   || \n");
    printf("  ||      /\\ \\    | |  / /|  |/ / | ___|| \\ | ||  ____|    /_ | / _ \\|__  /| |  || \n");
    printf("  ||     /  \\ \\   | | / / | ' /   | |__ |  \\| || |__        | || (_) | / / | |  || \n");
    printf("  ||    / /\\ \\ \\  | |< <  |  <    |  __|| . ` ||  __|       | | \\__, |/ /  |_|  || \n");
    printf("  ||   / ____ \\ \\ | | \\ \\ | . \\   | |___| |\\  || |____      | |   / // /_   _   || \n");
    printf("  ||  /_/    \\_\\_\\|_|  \\_\\|_|\\_\\  |_____|_| \\_||______|     |_|  /_/|____| (_)  || \n");
    printf("  ||                    VINTAGE CHEMISTRY LAB SIMULATOR (1974)                  || \n");
    printf("  ==============================================================================\n%s", COLOR_RESET);
    printf("%s  [MR DOPPIX CREATED BY BEHRUZ GOFFAROV | TEL: 70 024 94 14 | TG: @BEHRUZGOFFAROV]%s\n\n", COLOR_YELLOW, COLOR_RESET);
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void pause_prompt(void) {
    printf("\n%s  [Bosh sahifaga qaytish uchun ENTER tugmasini bosing...]%s", COLOR_GREEN, COLOR_RESET);
    while (getchar() != '\n');
    getchar();
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void show_reaction_animation(const char* reactant, const char* reagent, const char* catalyst, const char* product) {
    printf("\n%s  [*] Reaksiya idishi qizdirilmoqda va aralashtirilmoqda...%s\n  ", COLOR_YELLOW, COLOR_RESET);
    const char spinner[] = {'|', '/', '-', '\\'};
    for (int i = 0; i < 20; i++) {
        printf("\r  %s[Kimyoviy Reaksiya Jarayoni]%s %c [ %s + %s --(%s)--> ??? ]", 
               COLOR_MAGENTA, COLOR_RESET, spinner[i % 4], reactant, reagent, catalyst);
        fflush(stdout);
        SLEEP_MS(75);
    }
    printf("\r  %s[Reaksiya Muvaffaqiyatli!]%s  %s + %s %s--[%s]-->%s %s%s%s       \n\n",
           COLOR_GREEN, COLOR_RESET, reactant, reagent, COLOR_CYAN, catalyst, COLOR_RESET, COLOR_YELLOW, product, COLOR_RESET);
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void draw_ethene(void) {
    printf("%s", COLOR_CYAN);
    printf("        H       H       \n");
    printf("         \\     /        \n");
    printf("          C = C         %s<-- Eten (Ethylene: C2H4)%s\n%s", COLOR_YELLOW, COLOR_RESET, COLOR_CYAN);
    printf("         /     \\        \n");
    printf("        H       H       \n");
    printf("%s", COLOR_RESET);
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void draw_propene(void) {
    printf("%s", COLOR_CYAN);
    printf("        H       H       \n");
    printf("         \\     /        \n");
    printf("     H3C - C = C        %s<-- Propen (Propylene: C3H6)%s\n%s", COLOR_YELLOW, COLOR_RESET, COLOR_CYAN);
    printf("               \\        \n");
    printf("                H       \n");
    printf("%s", COLOR_RESET);
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void draw_cis_butene(void) {
    printf("%s", COLOR_CYAN);
    printf("      H3C       CH3     \n");
    printf("         \\     /        \n");
    printf("          C = C         %s<-- cis-But-2-en (Z-isomer)%s\n%s", COLOR_YELLOW, COLOR_RESET, COLOR_CYAN);
    printf("         /     \\        \n");
    printf("        H       H       \n");
    printf("%s", COLOR_RESET);
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void draw_trans_butene(void) {
    printf("%s", COLOR_CYAN);
    printf("      H3C       H       \n");
    printf("         \\     /        \n");
    printf("          C = C         %s<-- trans-But-2-en (E-isomer)%s\n%s", COLOR_YELLOW, COLOR_RESET, COLOR_CYAN);
    printf("         /     \\        \n");
    printf("        H       CH3     \n");
    printf("%s", COLOR_RESET);
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void draw_2methylpropene(void) {
    printf("%s", COLOR_CYAN);
    printf("      H3C       H       \n");
    printf("         \\     /        \n");
    printf("          C = C         %s<-- 2-Metilpropen (Izobutilen: C4H8)%s\n%s", COLOR_YELLOW, COLOR_RESET, COLOR_CYAN);
    printf("         /     \\        \n");
    printf("      H3C       H       \n");
    printf("%s", COLOR_RESET);
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void draw_cyclohexene(void) {
    printf("%s", COLOR_CYAN);
    printf("          / \\           \n");
    printf("        /     \\         \n");
    printf("       |       ||       %s<-- Siklogeksen (Cyclohexene: C6H10)%s\n%s", COLOR_YELLOW, COLOR_RESET, COLOR_CYAN);
    printf("        \\     /         \n");
    printf("          \\ /           \n");
    printf("%s", COLOR_RESET);
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void mode_gallery(void) {
    print_header();
    printf("%s  ======================= [ ALKENLAR ASCII GALEREYASI ] =======================%s\n\n", COLOR_MAGENTA, COLOR_RESET);
    
    printf("%s  [1] Eten (Ethylene - C2H4):%s\n", COLOR_WHITE, COLOR_RESET);
    draw_ethene();
    printf("  Sp2 gibridlanish, tekis tuzilish, bog' burchagi: 120 gradus.\n\n");

    printf("%s  [2] Propen (Propene - C3H6):%s\n", COLOR_WHITE, COLOR_RESET);
    draw_propene();
    printf("  Markovnikov birikish reaksiyalariga kirishuvchi asosiy alken.\n\n");

    printf("%s  [3] Geometrik Izomerlar (But-2-en):%s\n", COLOR_WHITE, COLOR_RESET);
    printf("  %s(A) Cis-Izomer:%s\n", COLOR_YELLOW, COLOR_RESET);
    draw_cis_butene();
    printf("  %s(B) Trans-Izomer:%s\n", COLOR_YELLOW, COLOR_RESET);
    draw_trans_butene();

    printf("\n%s  [4] Tarmoqlangan Alken: 2-Metilpropen:%s\n", COLOR_WHITE, COLOR_RESET);
    draw_2methylpropene();

    printf("\n%s  [5] Siklik Alken: Siklogeksen:%s\n", COLOR_WHITE, COLOR_RESET);
    draw_cyclohexene();

    pause_prompt();
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void mode_reaction_lab(void) {
    int choice = 0;
    while (1) {
        print_header();
        printf("%s  ======================= [ VINTAGE 1974 REAKSIYA LABORATORIYASI ] =======================%s\n\n", COLOR_MAGENTA, COLOR_RESET);
        printf("  Laboratoriyada sintez qilmoqchi bo'lgan kimyoviy jarayonni tanlang:\n\n");
        printf("  %s1.%s Gidrogenlanish (Eten + H2 -> Etan) [Katalizator: Ni / Pt]\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s2.%s Galogenlanish (Propen + Br2 -> 1,2-Dibrompropan) [Bromli suv sinovi]\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s3.%s Gidrogalogenlanish (Propen + HBr -> 2-Brompropan) [Markovnikov qoidasi]\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s4.%s Gidratatsiya (Eten + H2O -> Etanol) [Kislotali katalizator H2SO4]\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s5.%s Polimerlanish (n Eten -> Polietilen) [Ziegler-Natta / Radikal polimerlanish]\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s6.%s Oksidlanish - Vagner Reaksiyasi (Eten + [O] + H2O -> Etandiol-1,2) [KMnO4]\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s0.%s Asosiy menyuga qaytish\n\n", COLOR_RED, COLOR_RESET);
        printf("  %sTanlovingiz (0-6): %s", COLOR_GREEN, COLOR_RESET);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        if (choice == 0) break;

        printf("\n");
        switch (choice) {
            case 1:
                draw_ethene();
                show_reaction_animation("CH2=CH2", "H2", "Ni / Pt (150 C)", "CH3-CH3 (Etan)");
                printf("  %sNatija:%s Qo'shbog' uzilib, vodorod atomlari birikadi va to'yingan uglevodorod (Alkan) hosil bo'ladi.\n", COLOR_GREEN, COLOR_RESET);
                break;
            case 2:
                draw_propene();
                show_reaction_animation("CH3-CH=CH2", "Br2 (qo'ng'ir qizil)", "CCl4", "CH3-CHBr-CH2Br (Rangsiz 1,2-dibrompropan)");
                printf("  %sSifat reaksiyasi:%s Bromli suvning qo'ng'ir rangi yo'qoladi (Rangsizlanish - to'yinmaganlik belgisi!).\n", COLOR_GREEN, COLOR_RESET);
                break;
            case 3:
                draw_propene();
                show_reaction_animation("CH3-CH=CH2", "HBr", "Markovnikov qoidasi", "CH3-CH(Br)-CH3 (2-Brompropan)");
                printf("  %sMarkovnikov qoidasi:%s Vodorod ko'proq gidrogenlangan uglerodga, Br esa kamroq gidrogenlangan uglerodga birikadi.\n", COLOR_GREEN, COLOR_RESET);
                break;
            case 4:
                draw_ethene();
                show_reaction_animation("CH2=CH2", "H2O", "H3PO4 / H2SO4 (300 C)", "CH3-CH2-OH (Etanol - Tibbiy spirt)");
                printf("  %sSanoat sintezi:%s Neft gazlaridan etilen orqali sanoat miqyosida etanol ishlab chiqarish usuli.\n", COLOR_GREEN, COLOR_RESET);
                break;
            case 5:
                draw_ethene();
                show_reaction_animation("n CH2=CH2", "Yuqori Bosim / Katalizator", "P > 1000 atm", "(-CH2-CH2-)n (Polietilen Plastmassa)");
                printf("  %sPolimerlanish:%s Minglab monomerlar zanjir bo'lib ulanib, bardoshli plastik material hosil qiladi.\n", COLOR_GREEN, COLOR_RESET);
                break;
            case 6:
                draw_ethene();
                show_reaction_animation("CH2=CH2", "KMnO4 + H2O", "Kuchsiz ishqoriy muhit", "CH2(OH)-CH2(OH) (Etilen glikol / Antifriz)");
                printf("  %sVagner Reaksiyasi:%s Binafsharang kaliy permanganat eritmasi rangsizlanib, qo'ng'ir MnO2 cho'kmasi tushadi.\n", COLOR_GREEN, COLOR_RESET);
                break;
            default:
                printf("  %sNoto'g'ri tanlov!%s\n", COLOR_RED, COLOR_RESET);
                break;
        }
        pause_prompt();
    }
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
typedef struct {
    char question[256];
    char optA[128];
    char optB[128];
    char optC[128];
    char optD[128];
    char correct;
    char explanation[256];
} ChemQuiz;

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void mode_quiz_game(void) {
    ChemQuiz quizzes[] = {
        {
            "Alkenlarning umumiy formulasi qaysi?",
            "A) CnH2n+2", "B) CnH2n", "C) CnH2n-2", "D) CnH2n-6",
            'B',
            "Alkenlar bitta qo'shbog'ga ega bo'lgan to'yinmagan uglevodorodlar bo'lib, umumiy formulasi CnH2n."
        },
        {
            "Propen (CH3-CH=CH2) ga HCl birikkanda asosiy mahsulot qanday bo'ladi?",
            "A) 1-Xlorpropan", "B) 2-Xlorpropan", "C) 1,2-Dixlorpropan", "D) Propan",
            'B',
            "Markovnikov qoidasiga ko'ra vodorod ko'proq vodorodli CH2 ga, galogen esa kamroq vodorodli CH ga birikadi (2-Xlorpropan)."
        },
        {
            "Alkenlarda uglerod atomlari qaysi gibridlanish holatida bo'ladi (qo'shbog'li uglerodlar)?",
            "A) sp3", "B) sp2", "C) sp", "D) sp3d",
            'B',
            "Qo'shbog' hosil qiluvchi uglerodlar sp2 gibridlangan bo'lib, tekis uchburchak burchagi 120 gradusni tashkil qiladi."
        },
        {
            "To'yinmagan uglevodorodlarni aniqlash uchun laboratoriyada qaysi sifat reaksiyasi ishlatiladi?",
            "A) Bromli suvning rangsizlanishi", "B) Kumush ko'zgu reaksiyasi", "C) Lakmus qog'ozi qizarishi", "D) Biuret reaksiyasi",
            'A',
            "Bromli suv (Br2) va KMnO4 eritmasining rangsizlanishi qo'shbog' mavjudligini ko'rsatuvchi klassik sifat reaksiyasidir."
        },
        {
            "Cis va Trans izomeriya alkenlarning qaysi turdagi izomeriyasiga kiradi?",
            "A) Zanjir izomeriyasi", "B) Holat izomeriyasi", "C) Geometrik (fazoviy) izomeriya", "D) Sinflararo izomeriya",
            'C',
            "Qo'shbog' atrofida erkin aylanish bo'lmaganligi sababli o'rinbosarlarning fazoviy joylashuvi cis/trans izomeriyani hosil qiladi."
        },
        {
            "Etenning sanoatda polimerlanishidan nima olinadi?",
            "A) Teflon", "B) Polietilen", "C) Kauchuk", "D) Polistirol",
            'B',
            "n CH2=CH2 monomerlarining polimerlanishi natijasida keng qo'llaniladigan Polietilen plastmassasi olinadi."
        },
        {
            "Alkenlarga suv birikishi (gidratatsiya) qanday modda hosil bo'lishiga olib keladi?",
            "A) Alkin", "B) Spirt (Alkogol)", "C) Kislota", "D) Efir",
            'B',
            "Kislotali muhitda alkenlarga suv birikkanda tegishli bir atomli spirtlar sintez qilinadi (CH2=CH2 + H2O -> C2H5OH)."
        }
    };

    int total = sizeof(quizzes) / sizeof(quizzes[0]);
    int score = 0;

    print_header();
    printf("%s  ======================= [ RETRO 1974 KIMYOVIY QUIZ MUSOBAQASI ] =======================%s\n\n", COLOR_MAGENTA, COLOR_RESET);
    printf("  Jami %d ta savol beriladi. Har bir to'g'ri javob uchun 100 ball!\n", total);
    printf("  Tayyormisiz? O'yin boshlanmoqda...\n\n");
    SLEEP_MS(1200);

    for (int i = 0; i < total; i++) {
        print_header();
        printf("  %sSAVOL %d / %d%s | Joriy Ball: %s%d%s\n", COLOR_CYAN, i + 1, total, COLOR_RESET, COLOR_YELLOW, score, COLOR_RESET);
        printf("  ------------------------------------------------------------------------------\n");
        printf("  %s%s%s\n\n", COLOR_WHITE, quizzes[i].question, COLOR_RESET);
        printf("    %s\n", quizzes[i].optA);
        printf("    %s\n", quizzes[i].optB);
        printf("    %s\n", quizzes[i].optC);
        printf("    %s\n\n", quizzes[i].optD);

        char ans;
        printf("  %sSizning javobingiz (A / B / C / D): %s", COLOR_GREEN, COLOR_RESET);
        if (scanf(" %c", &ans) != 1) continue;
        ans = toupper(ans);

        if (ans == quizzes[i].correct) {
            printf("\n  %s[TO'G'RI JAVOB! +100 BALL]%s\n", COLOR_GREEN, COLOR_RESET);
            score += 100;
        } else {
            printf("\n  %s[NOTO'G'RI! To'g'ri javob: %c]%s\n", COLOR_RED, quizzes[i].correct, COLOR_RESET);
        }
        printf("  %sIzoh: %s%s\n", COLOR_CYAN, quizzes[i].explanation, COLOR_RESET);
        pause_prompt();
    }

    print_header();
    printf("%s  ======================= [ O'YIN YAKUNLANDI ] =======================%s\n\n", COLOR_MAGENTA, COLOR_RESET);
    printf("  Sizning yakuniy natijangiz: %s%d ball / %d ball%s\n\n", COLOR_YELLOW, score, total * 100, COLOR_RESET);
    
    if (score == total * 100) {
        printf("  %sMukammal! Siz Organik Kimyo bo'yicha haqiqiy Professordek bilimga egasiz! ★★★★★%s\n", COLOR_GREEN, COLOR_RESET);
    } else if (score >= (total * 60)) {
        printf("  %sAjoyib natija! Kimyo laboratoriyasida yaxshi mutaxassissiz! ★★★★%s\n", COLOR_CYAN, COLOR_RESET);
    } else {
        printf("  %sYaxshi harakat! Alkenlar bo'limini yana bir bor takrorlashni tavsiya qilamiz! ★★★%s\n", COLOR_YELLOW, COLOR_RESET);
    }

    pause_prompt();
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void mode_molecule_builder(void) {
    print_header();
    printf("%s  ======================= [ INTERAKTIV ALKEN SINTEZATORI / BUILDER ] =======================%s\n\n", COLOR_MAGENTA, COLOR_RESET);
    printf("  Uglerod zanjiri uzunligini kiriting (2 dan 6 gacha):\n");
    int carbons = 2;
    printf("  Uglerodlar soni (n): ");
    if (scanf("%d", &carbons) != 1 || carbons < 2 || carbons > 6) {
        carbons = 2;
    }

    int d_pos = 1;
    if (carbons > 3) {
        printf("  Qo'shbog' qaysi uglerodda joylashsin (1 dan %d gacha): ", carbons / 2);
        if (scanf("%d", &d_pos) != 1 || d_pos < 1 || d_pos > carbons / 2) {
            d_pos = 1;
        }
    }

    printf("\n  %sSintez qilinayotgan molekula ma'lumotlari:%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("  Kimyoviy formula: %sC%dH%d%s\n", COLOR_CYAN, carbons, 2 * carbons, COLOR_RESET);
    
    const char* names[] = {"Eten", "Propen", "Buten", "Penten", "Geksen"};
    printf("  IUPAC Nomi: %s%s-%d%s\n\n", COLOR_GREEN, names[carbons - 2], d_pos, COLOR_RESET);

    printf("  %sStruktura modeli:%s\n  ", COLOR_WHITE, COLOR_RESET);
    for (int i = 1; i <= carbons; i++) {
        if (i == d_pos) {
            printf("%sCH%s = ", COLOR_CYAN, (i == 1 || i == carbons) ? "2" : "");
        } else if (i == d_pos + 1) {
            printf("%sCH%s", COLOR_CYAN, (i == carbons) ? "2" : "");
            if (i < carbons) printf(" - ");
        } else {
            printf("%sCH%s", COLOR_YELLOW, (i == 1 || i == carbons) ? "3" : "2");
            if (i < carbons) printf(" - ");
        }
    }
    printf("%s\n\n", COLOR_RESET);

    printf("  Molekulyar massasi: %s%d g/mol%s (Uglerod: %d x 12 + Vodorod: %d x 1)\n", 
           COLOR_MAGENTA, carbons * 12 + carbons * 2, COLOR_RESET, carbons, carbons * 2);
    printf("  Sigma bog'lar soni: %s%d%s\n", COLOR_GREEN, 3 * carbons - 1, COLOR_RESET);
    printf("  Pi bog'lar soni: %s1%s (Kuchsiz va reaksiyaga oson kirishuvchi bog')\n", COLOR_RED, COLOR_RESET);

    pause_prompt();
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
void mode_about(void) {
    print_header();
    printf("%s  ======================= [ ALKENE 1974 LOYIHASI HAQIDA ] =======================%s\n\n", COLOR_MAGENTA, COLOR_RESET);
    printf("  1974-yilda ilk kompyuter ta'lim tizimlarida (PDP-11, PLATO) organik kimyo\n");
    printf("  o'quvchilariga alkenlar tuzilishi, IUPAC nomenklaturasi va reaksiyalarini\n");
    printf("  o'rgatish uchun yaratilgan klassik interaktiv kimyo simulyatori.\n\n");
    printf("  %sUshbu zamonaviy C tili remeyki quyidagi imkoniyatlarni o'z ichiga oladi:%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("  - Rangli va chiroyli ASCII 2D molekulyar grafikalar\n");
    printf("  - Dinamik animatsiyali kimyoviy reaksiya laboratoriyasi\n");
    printf("  - Markovnikov qoidasi va sifat reaksiyalari vizualizatsiyasi\n");
    printf("  - Interaktiv test musobaqasi va molekula konstruktori\n\n");
    printf("  %sMualliflik ma'lumotlari:%s\n", COLOR_CYAN, COLOR_RESET);
    printf("  MR DOPPIX CREATED BY BEHRUZ GOFFAROV\n");
    printf("  Telefon: +998 70 024 94 14 / 70 024 94 14\n");
    printf("  Telegram: @BEHRUZGOFFAROV\n\n");
    pause_prompt();
}

/* MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV */
int main(void) {
    enable_raw_mode();
    int choice = 0;

    while (1) {
        print_header();
        printf("  %sASOSIY MENYU:%s\n\n", COLOR_CYAN, COLOR_RESET);
        printf("  %s[1]%s Molekulalar Galereyasi (2D ASCII Tuzilmalar)\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s[2]%s Reaksiya Laboratoriyasi (Gidrogenlanish, Galogenlanish, Markovnikov)\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s[3]%s Kimyo Quiz O'yini (Ball to'plash va Test sinovi)\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s[4]%s Interaktiv Alken Konstruktori (Molecule Builder)\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s[5]%s O'yin va Muallif haqida ma'lumot\n", COLOR_YELLOW, COLOR_RESET);
        printf("  %s[0]%s Dasturdan chiqish\n\n", COLOR_RED, COLOR_RESET);
        printf("  %sKerakli bo'limni tanlang (0-5): %s", COLOR_GREEN, COLOR_RESET);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: mode_gallery(); break;
            case 2: mode_reaction_lab(); break;
            case 3: mode_quiz_game(); break;
            case 4: mode_molecule_builder(); break;
            case 5: mode_about(); break;
            case 0:
                print_header();
                printf("  %sDasturdan foydalanganingiz uchun tashakkur! Xayr!%s\n\n", COLOR_GREEN, COLOR_RESET);
                return 0;
            default:
                break;
        }
    }

    return 0;
}
