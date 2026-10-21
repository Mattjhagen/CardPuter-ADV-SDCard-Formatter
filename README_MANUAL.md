# SD Formatter for M5Stack Cardputer

**Version:** 1.0.0  
**Platform:** M5Stack Cardputer / Cardputer ADV  
**Format:** FAT32  
**Compatible with:** M5Launcher / EasyLauncher

## Overview

A simple, safe, and user-friendly SD card formatter specifically designed for the M5Stack Cardputer. Format your SD card to FAT32 directly on your device without needing a computer!

## Features

✅ **Direct Formatting** - No PC needed  
✅ **FAT32 File System** - Universal compatibility  
✅ **Large Card Support** - Works with cards up to 128GB+  
✅ **Safety Confirmations** - Double-check before formatting  
✅ **Visual Progress** - See each step as it happens  
✅ **Auto Directory Creation** - Sets up folder structure automatically  
✅ **Multiple Key Support** - F, G, or Enter keys for accessibility  
✅ **Clean UI** - Professional interface with color-coded states

## Installation

### Via M5Launcher Web UI (Recommended)
1. Connect to your Cardputer's WiFi access point
2. Navigate to `http://192.168.4.1`
3. Upload `CardputerSDFormatter-v1.0.0.bin`
4. Flash to app partition (0x10000)

### Via esptool (Advanced)
```bash
esptool.py --chip esp32s3 --port /dev/cu.usbmodem* write_flash 0x10000 CardputerSDFormatter-v1.0.0.bin
```

## How to Use

1. **Launch** the SD Formatter app from M5Launcher
2. **Read** the warning screen carefully
3. **Press** F, G, or Enter to begin
4. **Confirm** by pressing F, G, or Enter again
5. **Wait** 2-5 minutes for formatting to complete
6. **Done!** Your SD card is now formatted with a clean folder structure

### Keyboard Controls
- **F / G / Enter** - Proceed to next step
- **ESC / Q** - Cancel and exit

## What It Creates

After formatting, your SD card will have:

```
/apps/        - Applications & firmware files
/data/        - User data files
/config/      - Configuration files
/screenshots/ - Screen captures
/images/      - Image files
/sounds/      - Audio files
README.txt    - Card information
```

## Formatting Process

The formatter goes through 5 steps:

1. **Unmounting** - Safely disconnects the SD card
2. **Init SPI** - Initializes communication bus
3. **Detecting** - Verifies SD card presence and reads capacity
4. **Formatting** - Creates FAT32 filesystem (2-5 minutes)
5. **Setup** - Creates folder structure and README

## Status Indicators

- 🟦 **Blue Header** - App title and version
- 🟢 **Green** - Ready, success, safe actions
- 🟡 **Yellow** - Processing, warnings
- 🔴 **Red** - Errors, critical warnings

## Safety Features

- ⚠️ **Double Confirmation** - Must confirm twice before formatting
- 🔒 **Clear Warnings** - Prominent warnings about data loss
- 🚫 **ESC Anytime** - Cancel operation at any point
- 💾 **Write Verification** - Tests card after formatting
- 📊 **Progress Display** - Always shows current step

## Troubleshooting

**"SD card not detected"**
- Remove and reinsert the SD card
- Check card is properly seated
- Try a different SD card

**"Format failed"**
- Card may be write-protected
- Card may be damaged
- Try formatting on a PC first

**Freeze or hang**
- Power cycle the device
- Try removing card before launching app
- Insert card after app has started

## Technical Details

- **Filesystem:** FAT32
- **Supported Sizes:** Up to 2TB (tested up to 128GB)
- **Partition:** Single partition
- **Cluster Size:** Automatic (optimized)
- **Flash Address:** 0x10000 (M5Launcher app partition)
- **Firmware Size:** ~860KB

## Compatibility

✅ M5Stack Cardputer  
✅ M5Stack Cardputer ADV  
✅ M5Launcher / EasyLauncher bootloader  
✅ Works with all SD card sizes  
✅ Works with SDHC and SDXC cards

## Changelog

### Version 1.0.0 (2026-10-20)
- Initial release
- FAT32 formatting support
- Multiple key input support (F/G/Enter)
- Auto directory structure creation
- Visual step-by-step progress
- Safety confirmations
- Error handling and recovery

## Credits

**Created by:** Claude (Anthropic) & Matt  
**Built with:** PlatformIO, Arduino Framework  
**Libraries:** M5Cardputer, ESP32 SD Library

## License

Free to use and distribute. No warranty provided.

## Support

For issues, questions, or suggestions, please open an issue on the GitHub repository.

---

**⚠️ WARNING:** Formatting will permanently erase all data on the SD card. This action cannot be undone. Always backup important data before formatting!
