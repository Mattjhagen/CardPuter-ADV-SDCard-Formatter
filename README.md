# SD Formatter for M5Stack Cardputer

[![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)](https://github.com/Mattjhagen/CardPuter-ADV-SDCard-Formatter/releases)
[![Platform](https://img.shields.io/badge/platform-M5Stack%20Cardputer-orange.svg)](https://shop.m5stack.com/products/m5stack-cardputer-kit-w-m5stamps3)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Downloads](https://img.shields.io/github/downloads/Mattjhagen/CardPuter-ADV-SDCard-Formatter/total.svg)](https://github.com/Mattjhagen/CardPuter-ADV-SDCard-Formatter/releases)

> Format SD cards to FAT32 directly on your Cardputer - no computer needed! 🚀

![SD Formatter Banner](https://via.placeholder.com/800x200/1E90FF/FFFFFF?text=SD+Formatter+for+Cardputer)

## 🎯 Overview

A simple, safe, and user-friendly SD card formatter specifically designed for the M5Stack Cardputer. Perfect for beginners and power users alike!

## ✨ Features

- 🎯 **Direct Formatting** - No PC needed
- 💾 **FAT32 File System** - Universal compatibility  
- 📦 **Large Card Support** - Works with cards up to 128GB+
- 🔒 **Safety First** - Double confirmation before formatting
- 📊 **Visual Progress** - See each of 5 steps as they happen
- 📁 **Auto Directory Creation** - Sets up folder structure automatically
- ⌨️ **Multiple Keys** - F, G, or Enter keys for accessibility
- 🎨 **Clean UI** - Professional interface with color-coded states

## 📸 Screenshots

| Ready Screen | Formatting | Success |
|:---:|:---:|:---:|
| ![Ready](https://via.placeholder.com/240x135/000000/00FF00?text=Ready) | ![Formatting](https://via.placeholder.com/240x135/000000/FFFF00?text=Formatting) | ![Success](https://via.placeholder.com/240x135/000000/00FF00?text=Success) |

## 📥 Installation

### Quick Install (M5Launcher Web UI)

1. **Boot** M5Launcher on your Cardputer
2. **Enable** WiFi Access Point
3. **Connect** to the Cardputer's WiFi
4. **Browse** to `http://192.168.4.1`
5. **Upload** `CardputerSDFormatter-v1.0.0.bin`
6. **Flash** it!

### Advanced Install (esptool)

```bash
esptool.py --chip esp32s3 --port /dev/cu.usbmodem* \
  write_flash 0x10000 CardputerSDFormatter-v1.0.0.bin
```

## 🚀 Quick Start

1. Launch the app from M5Launcher
2. Read the warning screen
3. Press **F** (or G, or Enter) to start
4. Press **F** again to confirm
5. Wait 2-5 minutes
6. Done! ✅

### Keyboard Controls

| Key | Action |
|-----|--------|
| `F` / `G` / `Enter` | Proceed / Confirm |
| `ESC` / `Q` | Cancel / Exit |

## 📁 What Gets Created

After formatting, your SD card will have:

```
📁 SD Card Root
├── 📂 apps/        - Applications & firmware files
├── 📂 data/        - User data files
├── 📂 config/      - Configuration files
├── 📂 screenshots/ - Screen captures
├── 📂 images/      - Image files
├── 📂 sounds/      - Audio files
└── 📄 README.txt   - Card information
```

## 🔄 Formatting Process

The formatter goes through 5 clear steps:

1. **Unmounting** - Safely disconnects the SD card
2. **Init SPI** - Initializes communication bus
3. **Detecting** - Verifies SD card presence and size
4. **Formatting FAT32** - Creates filesystem (2-5 minutes)
5. **Creating Folders** - Sets up directory structure

## 🎨 UI Design

- 🟦 **Blue Header** - App title and version
- 🟢 **Green** - Ready, success, safe actions
- 🟡 **Yellow** - Processing, warnings
- 🔴 **Red** - Errors, critical warnings

## 🛠️ Building from Source

### Prerequisites

- [PlatformIO](https://platformio.org/)
- ESP32 toolchain

### Build Steps

```bash
# Clone the repository
git clone https://github.com/Mattjhagen/CardPuter-ADV-SDCard-Formatter.git
cd CardPuter-ADV-SDCard-Formatter

# Build
pio run

# Flash (optional)
pio run -t upload

# Binary will be in: .pio/build/m5stack-cardputer/firmware.bin
```

## 🔧 Troubleshooting

<details>
<summary><b>"SD card not detected"</b></summary>

- Remove and reinsert the SD card
- Check card is properly seated
- Try a different SD card
</details>

<details>
<summary><b>"Format failed"</b></summary>

- Card may be write-protected
- Card may be damaged
- Try formatting on a PC first
</details>

<details>
<summary><b>App freezes</b></summary>

- Power cycle the device
- Try removing card before launching
- Insert card after app starts
</details>

## 📋 Technical Details

| Specification | Details |
|---------------|---------|
| **Filesystem** | FAT32 |
| **Card Size** | Up to 2TB (tested 128GB) |
| **Flash Address** | 0x10000 (M5Launcher app) |
| **Firmware Size** | ~860KB |
| **Format Time** | 2-5 minutes |

## ✅ Compatibility

- ✅ M5Stack Cardputer
- ✅ M5Stack Cardputer ADV
- ✅ M5Launcher / EasyLauncher
- ✅ All SD card sizes
- ✅ SDHC and SDXC cards

## 📖 Documentation

- [README.md](README.md) - Complete user manual
- [QUICKSTART.md](QUICKSTART.md) - Quick start guide
- [STORE_LISTING.md](STORE_LISTING.md) - Store information

## 🤝 Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

## 📜 License

This project is released under the MIT License. See [LICENSE](LICENSE) for details.

## ⚠️ Warning

**Formatting will permanently erase all data on the SD card. This action cannot be undone. Always backup important data before formatting!**

## 🙏 Credits

- **Created by:** Claude (Anthropic) & Matt
- **Built with:** PlatformIO, Arduino Framework
- **Libraries:** M5Cardputer, ESP32 SD Library

## 🌟 Star History

If you find this useful, please consider giving it a star! ⭐

## 📞 Support

- 🐛 **Issues:** [GitHub Issues](https://github.com/Mattjhagen/CardPuter-ADV-SDCard-Formatter/issues)
- 💬 **Discussions:** [GitHub Discussions](https://github.com/Mattjhagen/CardPuter-ADV-SDCard-Formatter/discussions)

---

Made with ❤️ for the Cardputer community
