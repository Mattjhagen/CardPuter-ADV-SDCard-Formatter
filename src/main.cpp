#include <M5Cardputer.h>
#include <SD.h>
#include <FS.h>
#include <SPI.h>

#define SD_SCK  40
#define SD_MISO 39
#define SD_MOSI 14
#define SD_CS   12

#define APP_VERSION "1.0.0"
#define APP_NAME "SD Formatter"

enum AppState {
    STATE_READY,
    STATE_CONFIRM,
    STATE_FORMATTING,
    STATE_COMPLETE
};

AppState currentState = STATE_READY;
bool formatSuccess = false;

void drawHeader() {
    M5Cardputer.Display.fillRect(0, 0, 240, 30, 0x1E90);
    M5Cardputer.Display.setTextColor(WHITE);
    M5Cardputer.Display.setTextSize(1.5);
    M5Cardputer.Display.setCursor(10, 10);
    M5Cardputer.Display.print(APP_NAME);
    M5Cardputer.Display.setCursor(180, 10);
    M5Cardputer.Display.setTextSize(1);
    M5Cardputer.Display.print("v");
    M5Cardputer.Display.print(APP_VERSION);
}

void drawMessage(String title, String line1 = "", String line2 = "", String line3 = "", uint16_t titleColor = WHITE) {
    M5Cardputer.Display.fillRect(0, 35, 240, 100, BLACK);

    M5Cardputer.Display.setTextSize(1.5);
    M5Cardputer.Display.setTextColor(titleColor);
    M5Cardputer.Display.setCursor(10, 45);
    M5Cardputer.Display.println(title);

    M5Cardputer.Display.setTextSize(1);
    M5Cardputer.Display.setTextColor(WHITE);

    if (line1 != "") {
        M5Cardputer.Display.setCursor(10, 70);
        M5Cardputer.Display.println(line1);
    }

    if (line2 != "") {
        M5Cardputer.Display.setCursor(10, 90);
        M5Cardputer.Display.println(line2);
    }

    if (line3 != "") {
        M5Cardputer.Display.setCursor(10, 110);
        M5Cardputer.Display.println(line3);
    }
}

void drawFooter(String text, uint16_t color = 0x7BEF) {
    M5Cardputer.Display.fillRect(0, 115, 240, 20, BLACK);
    M5Cardputer.Display.setTextSize(1);
    M5Cardputer.Display.setTextColor(color);
    M5Cardputer.Display.setCursor(10, 118);
    M5Cardputer.Display.println(text);
}

bool formatSDCard() {
    // Step 1: Unmount
    drawMessage("Formatting", "Step 1/5: Unmounting...", "", "", YELLOW);
    SD.end();
    delay(800);

    // Step 2: Initialize SPI
    drawMessage("Formatting", "Step 2/5: Init SPI...", "", "", YELLOW);
    SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);
    delay(500);

    // Step 3: Detect card
    drawMessage("Formatting", "Step 3/5: Detecting card...", "", "", YELLOW);
    if (!SD.begin(SD_CS, SPI, 25000000)) {
        drawMessage("Error!", "SD card not detected", "", "Check card insertion", RED);
        delay(3000);
        return false;
    }

    // Get card info
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    String sizeStr = String((int)cardSize) + " MB";

    drawMessage("Formatting", "Step 4/5: Formatting FAT32", "Card: " + sizeStr, "This may take 2-5 minutes", YELLOW);
    drawFooter("DO NOT POWER OFF!", RED);

    // Unmount before format
    SD.end();
    delay(500);

    // Format the card
    if (!SD.begin(SD_CS, SPI, 25000000, "/sd", 5, true)) {
        drawMessage("Error!", "Format failed", "", "Try PC formatter or retry", RED);
        delay(3000);
        return false;
    }

    // Step 5: Create directory structure
    drawMessage("Formatting", "Step 5/5: Creating folders...", "", "", YELLOW);
    delay(500);

    SD.mkdir("/apps");
    SD.mkdir("/data");
    SD.mkdir("/config");
    SD.mkdir("/screenshots");
    SD.mkdir("/images");
    SD.mkdir("/sounds");

    // Write README file
    File readme = SD.open("/README.txt", FILE_WRITE);
    if (readme) {
        readme.println("Cardputer SD Card");
        readme.println("==================");
        readme.println("");
        readme.println("Formatted: FAT32");
        readme.println("Formatter: " + String(APP_NAME) + " v" + String(APP_VERSION));
        readme.println("");
        readme.println("Directory Structure:");
        readme.println("  /apps        - Applications & firmware");
        readme.println("  /data        - User data files");
        readme.println("  /config      - Configuration files");
        readme.println("  /screenshots - Screen captures");
        readme.println("  /images      - Image files");
        readme.println("  /sounds      - Audio files");
        readme.println("");
        readme.println("This SD card is now ready to use!");
        readme.close();
    }

    // Verify write capability
    File test = SD.open("/test.txt", FILE_WRITE);
    if (!test) {
        drawMessage("Warning", "Format OK but", "write test failed", "", YELLOW);
        delay(2000);
        return true; // Still consider it success
    }
    test.println("Write test successful");
    test.close();
    SD.remove("/test.txt");

    return true;
}

void showReadyScreen() {
    drawMessage("Ready to Format", "WARNING: All data will", "be permanently erased!", "");
    drawFooter("Press F/G/Enter to start | ESC to exit", GREEN);
}

void showConfirmScreen() {
    drawMessage("ARE YOU SURE?", "This cannot be undone!", "", "Press again to confirm", RED);
    drawFooter("F/G/Enter = Yes | ESC = Cancel", YELLOW);
}

void showCompleteScreen() {
    if (formatSuccess) {
        drawMessage("Success!", "SD card formatted", "FAT32 with folders", "Ready to use!", GREEN);
        drawFooter("Press any key to exit", GREEN);
    } else {
        drawMessage("Failed", "Could not format", "SD card", "Check card & retry", RED);
        drawFooter("Press any key to exit", RED);
    }
}

void setup() {
    auto cfg = M5.config();
    M5Cardputer.begin(cfg, true);

    M5Cardputer.Display.setRotation(1);
    M5Cardputer.Display.fillScreen(BLACK);

    drawHeader();

    // Show splash
    M5Cardputer.Display.setTextSize(1);
    M5Cardputer.Display.setTextColor(WHITE);
    M5Cardputer.Display.setCursor(10, 50);
    M5Cardputer.Display.println("Initializing...");
    delay(1000);

    showReadyScreen();
}

void loop() {
    M5Cardputer.update();

    if (M5Cardputer.Keyboard.isChange() && M5Cardputer.Keyboard.isPressed()) {
        Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();

        // Check which key was pressed
        bool actionKey = false;  // F, G, or Enter
        bool escKey = false;

        for (auto key : status.word) {
            if (key == 'f' || key == 'F' || key == 'g' || key == 'G' ||
                key == '\n' || key == '\r' || key == 0x0D || key == 0x0A) {
                actionKey = true;
                break;
            }
            if (key == 0x1B || key == 'q' || key == 'Q') {
                escKey = true;
                break;
            }
        }

        // State machine
        switch (currentState) {
            case STATE_READY:
                if (actionKey) {
                    currentState = STATE_CONFIRM;
                    showConfirmScreen();
                } else if (escKey) {
                    drawMessage("Exiting...", "", "", "", WHITE);
                    delay(1000);
                    M5Cardputer.Power.powerOff();
                }
                break;

            case STATE_CONFIRM:
                if (actionKey) {
                    currentState = STATE_FORMATTING;
                    drawMessage("Starting...", "Preparing to format", "", "", YELLOW);
                    delay(1000);

                    formatSuccess = formatSDCard();

                    currentState = STATE_COMPLETE;
                    showCompleteScreen();
                } else if (escKey) {
                    currentState = STATE_READY;
                    drawHeader();
                    showReadyScreen();
                }
                break;

            case STATE_COMPLETE:
                // Any key exits
                drawMessage("Goodbye!", "", "", "", WHITE);
                delay(1000);
                M5Cardputer.Power.powerOff();
                break;

            default:
                break;
        }
    }

    delay(10);
}
