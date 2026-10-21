# Quick Start Guide - SD Formatter

## 📥 Installation

**Method 1: M5Launcher Web UI (Easiest)**
1. Boot into M5Launcher on your Cardputer
2. Enable WiFi Access Point mode
3. Connect your phone/computer to Cardputer's WiFi
4. Open browser: `http://192.168.4.1`
5. Upload: `CardputerSDFormatter-v1.0.0.bin`
6. Flash it
7. Reboot

**Method 2: Command Line**
```bash
esptool.py --chip esp32s3 --port /dev/cu.usbmodem* \
  write_flash 0x10000 CardputerSDFormatter-v1.0.0.bin
```

## 🎯 First Time Use

1. **Launch** the app from M5Launcher menu
2. **Read** the warning (all data will be erased!)
3. **Press F** (or G, or Enter)
4. **Confirm** by pressing F again
5. **Wait** 2-5 minutes while it formats
6. **See** "Success!" message
7. **Press any key** to exit

## ⌨️ Controls

| Key | Action |
|-----|--------|
| F / G / Enter | Proceed / Confirm |
| ESC / Q | Cancel / Exit |

## 📁 Folder Structure Created

After formatting, you'll have:
```
📁 SD Card Root
├── 📂 apps/        - Put .bin firmware files here
├── 📂 data/        - Your data files
├── 📂 config/      - Settings & configs
├── 📂 screenshots/ - Screen captures
├── 📂 images/      - Image files
├── 📂 sounds/      - Audio files
└── 📄 README.txt   - Card info
```

## 🎨 Screen Colors

- 🟦 **Blue** = Header/Title
- 🟢 **Green** = Ready/Success
- 🟡 **Yellow** = Working/Warning
- 🔴 **Red** = Error/Critical

## ⏱️ Expected Time

- Small cards (< 32GB): 1-2 minutes
- Medium cards (32-64GB): 2-3 minutes  
- Large cards (64-128GB): 3-5 minutes

## ❗ Important Notes

- ⚠️ **All data will be erased** - backup first!
- 🔌 **Keep powered** during formatting
- 💾 **Don't remove card** while formatting
- ✅ **Works with any size** SD card
- 🔄 **Can be run multiple times** safely

## 🔧 Troubleshooting

**App won't start?**
- Make sure M5Launcher is installed
- Try reflashing the .bin file

**"SD card not detected"?**
- Remove and reinsert the SD card
- Make sure it's fully inserted
- Try a different SD card to test

**Formatting takes too long?**
- 5+ minutes is normal for 128GB cards
- Don't interrupt the process
- Look for "DO NOT POWER OFF" warning

**Format failed?**
- Card might be write-protected
- Card might be damaged
- Try formatting on a PC first, then retry

## 💡 Tips

- ✅ Format new SD cards before first use
- ✅ Keep M5Launcher on your device to access other apps
- ✅ The README.txt on the card shows format details
- ✅ Folder structure is just a suggestion - organize how you like!

## 🤝 Need Help?

If you encounter issues:
1. Try power cycling the device
2. Try a different SD card
3. Check the full README.md for detailed troubleshooting
4. Report issues on GitHub

---

**Ready to format? Launch the app and press F!** 🚀
