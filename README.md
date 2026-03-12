# ARM Cortex-M4 MCAL — STM32F401RCT6 (Black Pill)

> Bare-metal **Microcontroller Abstraction Layer (MCAL)** written from scratch for the **STM32F401RCT6** on the STM32 Black Pill development board, targeting the **ARM Cortex-M4** core — no HAL, no vendor middleware, pure register-level C.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Target Hardware](#target-hardware)
- [Project Structure](#project-structure)
- [Peripheral Drivers (MCAL)](#peripheral-drivers-mcal)
- [Getting Started](#getting-started)
- [Build System](#build-system)
- [Flashing & Debugging](#flashing--debugging)
- [Coding Standards](#coding-standards)
- [License](#license)

---

## Overview

This repository implements a complete **MCAL (Microcontroller Abstraction Layer)** for the STM32F401RCT6 microcontroller, written entirely in bare-metal C. Every peripheral driver directly accesses hardware registers via memory-mapped I/O — no STM32 HAL, no CMSIS peripheral drivers, no hidden abstractions.

The layer is designed to be clean, layered, and portable — suitable as the foundation for an **AUTOSAR-inspired** embedded software stack or any bare-metal application that demands full hardware control.

---

## Target Hardware

| Property | Details |
|---|---|
| **Board** | STM32 Black Pill |
| **MCU** | STM32F401RCT6 |
| **Core** | ARM Cortex-M4F (with FPU) |
| **Clock** | Up to 84 MHz (HSI/HSE + PLL) |
| **Flash** | 256 KB |
| **SRAM** | 64 KB |
| **Package** | LQFP-64 |
| **Operating Voltage** | 2.0V – 3.6V |

> 📄 [STM32F401RCT6 Datasheet](https://www.st.com/resource/en/datasheet/stm32f401rc.pdf) — [Reference Manual RM0368](https://www.st.com/resource/en/reference_manual/rm0368-stm32f401xbc-and-stm32f401xde-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

---

## Project Structure

```
ARM-Cortex-M4-MCAL-Files/
│
├── MCAL/
│   ├── GPIO/
│   │   ├── GPIO_CONFIG.h      # User configuration (modes, pins, speeds ...)
│   │   ├── GPIO_INTERFACE.h   # Public API — functions & types exposed to upper layers
│   │   ├── GPIO_PRIVATE.h     # Register map, bit masks, internal macros
│   │   └── GPIO_DRIVER.c      # Driver implementation
│   ├── RCC/
│   │   ├── RCC_CONFIG.h
│   │   ├── RCC_INTERFACE.h
│   │   ├── RCC_PRIVATE.h
│   │   └── RCC_DRIVER.c
│   ├── NVIC/
│   │   ├── NVIC_CONFIG.h
│   │   ├── NVIC_INTERFACE.h
│   │   ├── NVIC_PRIVATE.h
│   │   └── NVIC_DRIVER.c
│   ├── EXTI/
│   │   ├── EXTI_CONFIG.h
│   │   ├── EXTI_INTERFACE.h
│   │   ├── EXTI_PRIVATE.h
│   │   └── EXTI_DRIVER.c
│   ├── USART/
│   │   ├── USART_CONFIG.h
│   │   ├── USART_INTERFACE.h
│   │   ├── USART_PRIVATE.h
│   │   └── USART_DRIVER.c
│   ├── SPI/
│   │   ├── SPI_CONFIG.h
│   │   ├── SPI_INTERFACE.h
│   │   ├── SPI_PRIVATE.h
│   │   └── SPI_DRIVER.c
│   ├── I2C/
│   │   ├── I2C_CONFIG.h
│   │   ├── I2C_INTERFACE.h
│   │   ├── I2C_PRIVATE.h
│   │   └── I2C_DRIVER.c
│   ├── TIM/
│   │   ├── TIM_CONFIG.h
│   │   ├── TIM_INTERFACE.h
│   │   ├── TIM_PRIVATE.h
│   │   └── TIM_DRIVER.c
│   ├── ADC/
│   │   ├── ADC_CONFIG.h
│   │   ├── ADC_INTERFACE.h
│   │   ├── ADC_PRIVATE.h
│   │   └── ADC_DRIVER.c
│   └── DMA/
│       ├── DMA_CONFIG.h
│       ├── DMA_INTERFACE.h
│       ├── DMA_PRIVATE.h
│       └── DMA_DRIVER.c
│
├── LIB/
│   ├── STD_TYPES.h        # Standard type definitions (u8, u16, u32 ...)
│   ├── BIT_MATH.h         # Bit manipulation macros
│   └── ERROR_STATE.h      # Error / status return codes
│
├── Startup/
│   ├── startup.c          # Vector table & reset handler
│   └── linker_script.ld   # Memory layout for STM32F401RCT6
│
├── App/
│   └── main.c             # Application entry point
│
└── README.md
```

### File Roles per Peripheral

| File | Role |
|------|------|
| `XXX_CONFIG.h` | User-facing configuration — change modes, pins, clock sources here |
| `XXX_INTERFACE.h` | Public API — all function prototypes and types exposed to upper layers |
| `XXX_PRIVATE.h` | Internal register map, bit positions, and private macros — not included by app code |
| `XXX_DRIVER.c` | Full driver implementation |

---

## Peripheral Drivers (MCAL)

All drivers follow a consistent interface pattern:

```c
void         PERIPHx_vInit    (PERIPHx_Config_t *Config);
void         PERIPHx_vEnable  (void);
void         PERIPHx_vDisable (void);
ErrorState_t PERIPHx_u8Op     (...);
```

### Implemented Peripherals

| Driver | Status | Description |
|--------|--------|-------------|
| **RCC** | ✅ Done | System clock configuration, PLL setup, peripheral clock enable/disable |
| **GPIO** | ✅ Done | Input / Output / AF / Analog modes, speed control, pull-up/pull-down config |
| **NVIC** | ✅ Done | Interrupt enable/disable, priority grouping, pending flags |
| **EXTI** | ✅ Done | External interrupt lines, rising/falling/both edge selection |
| **USART** | ✅ Done | Async TX/RX, baud rate configuration, interrupt-driven transfers |
| **SPI** | ✅ Done | Master/Slave, full-duplex, CPOL/CPHA configuration |
| **I2C** | ✅ Done | Master TX/RX, 7-bit addressing, ACK/NACK handling |
| **TIM** | ✅ Done | Basic timer, PWM generation, input capture, output compare |
| **ADC** | ✅ Done | Single/continuous conversion, channel sequencing, DMA mode |
| **DMA** | ✅ Done | Memory-to-memory, peripheral-to-memory, circular mode |

---

## Getting Started

### Prerequisites

| Tool | Purpose |
|------|---------|
| `arm-none-eabi-gcc` | GNU Arm Embedded Toolchain |
| `st-flash` | Flash via ST-Link (stlink-tools) |
| `OpenOCD` | On-chip debugger server |
| `arm-none-eabi-gdb` | Source-level debugger |

### Clone

```bash
git clone https://github.com/KerolosMaged/ARM-Cortex-M4-MCAL-Files.git
cd ARM-Cortex-M4-MCAL-Files
```

---

## Build System

```bash
arm-none-eabi-gcc \
  -mcpu=cortex-m4        \
  -mthumb                \
  -mfpu=fpv4-sp-d16      \
  -mfloat-abi=hard       \
  -DSTM32F401xC          \
  -Wall -O0 -g           \
  -T Startup/linker_script.ld \
  -o output.elf          \
  Startup/startup.c App/main.c MCAL/**/*.c
```

Generate flashable binary:

```bash
arm-none-eabi-objcopy -O binary output.elf output.bin
```

---

## Flashing & Debugging

### Flash via ST-Link

```bash
st-flash write output.bin 0x08000000
```


### Debug with GDB + OpenOCD

```bash
# Terminal 1 — start OpenOCD
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg

# Terminal 2 — connect GDB
arm-none-eabi-gdb output.elf
(gdb) target remote :3333
(gdb) monitor reset halt
(gdb) load
(gdb) continue
```

---

## Coding Standards

- Written in **C99**
- Register access via **pointer-to-struct** mapped over hardware base addresses
- **No dynamic memory allocation** (`malloc` / `free`)
- Consistent naming convention: `MODULE_ReturnType_FunctionName()`
- Error handling via `ErrorState_t` → `E_OK`, `E_NOK`, `NULL_PTR`
- Bit manipulation via `BIT_MATH.h` macros:

```c
SET_BIT(REG, BIT)
CLR_BIT(REG, BIT)
GET_BIT(REG, BIT)
TOG_BIT(REG, BIT)
```

---

## Author

**Kerolos Maged**
Embedded Systems Engineer — ARM Cortex-M4 Bare-Metal MCAL

---

