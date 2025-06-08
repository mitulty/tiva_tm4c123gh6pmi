
# TM4C123GH6PMI Bare-Metal + FreeRTOS Project

This is a low-level embedded project for the **TIVA-C TM4C123GH6PMI** microcontroller. It demonstrates:

- ✅ Custom Cortex-M4 startup code
- ✅ Vector table + NVIC setup
- ✅ GPIO configuration
- ✅ SysTick timer usage
- ✅ Integrated FreeRTOS Kernel

---

## 📁 Project Structure

```
.
├── datasheets_trm/              # Technical reference PDFs
│   ├── spmu298e.pdf             # Tiva™ C Series TM4C123GH6PM TRM
│   ├── spmu367.pdf              # ARM Cortex-M4 Devices Generic User Guide
│   └── tm4c123gh6pm.pdf         # Microcontroller datasheet
│
├── drivers/gpio/               # GPIO driver
│   ├── gpio.c
│   └── gpio.h
│
├── firmware/                   # Main application and utilities
│   ├── cm4_defines.h
│   ├── FreeRTOSConfig.h
│   ├── main.c
│   ├── main.ld                 # Linker script
│   ├── memUtils.c
│   ├── stdint.h
│   └── system_init.c
│
├── firmware/ivt/               # Interrupt vector table
│   ├── int_vector_table.c
│   └── int_vector_table.h
│
├── firmware/nvic/              # NVIC initialization
│   ├── nvic.c
│   └── nvic.h
│
├── firmware/systick/           # SysTick timer config
│   ├── systick.c
│   └── systick.h
│
├── lib/FreeRTOS-Kernel/        # FreeRTOS source (non-OS abstraction)
│   ├── croutine.c
│   ├── event_groups.c
│   ├── include/
│   ├── list.c
│   ├── portable/
│   ├── queue.c
│   ├── stream_buffer.c
│   ├── tasks.c
│   └── timers.c
|
|── startup_code/               # Cortex-M4 startup
|    └── startup.S
|
└── Makefile                    # Build File

```

---

## 🚀 Getting Started

### Requirements

- [arm-none-eabi-gcc](https://developer.arm.com/downloads/-/gnu-rm)
- [CCS Studio](https://www.ti.com/tool/CCSTUDIO)
- TM4C123GH6PMI-based dev board

---

## 📦 Build & Flash

### 🔨 Build

```bash
make PROFILE=release all
```

Program the main.elf or main.bin.

---

## 📚 Documentation

- `tm4c123gh6pm.pdf` – Official MCU datasheet  
- `spmu298e.pdf` – Tiva™ C Series Technical Reference  
- `spmu367.pdf` – Cortex-M4 Devices User Guide

---

## 📬 Contributing

Feel free to fork and contribute! Add new files, fix bugs, or improve the existing implementations.

---

## 📄 License


MIT License

Copyright (c) 2025 Mitul Tyagi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

---

## 👨‍💻 Author

**Mitul Tyagi**  
Embedded Systems Developer  
[GitHub](https://github.com/mitulty) • [LinkedIn](https://www.linkedin.com/in/mitultyagi45/)