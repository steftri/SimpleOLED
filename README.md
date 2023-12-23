# SimpleOLED

Simple text-only library for OLED SSD1306 via i2c


## General

This library allows to display text on an OLED display controlled by the SSD1306. It is possible to use both sizes (128x64 and 128x32).

In contrast to other display drivers, this driver does not hold a buffer for execution of paint operations in memory, so the very limited SRAM on Arduino boards stays available for other needs.

Therefore enhanced paint operations (circles, flood fill, lines etc.) are not possible directly. The library is designed for displaying text.

Three fonts are available:

1. The default font is a very tiny font with 6x8 pixels per character.
2. The Topaz font is a font inspired by Amiga OS 2.x and above. In contrast to the original font, the character mapping complies (with small exceptions) to ISO-8859-1.
3. The C64 font is inspired by the font of the Commodore 64. The character mapping also complies to ASCII, but as the original C64 font, it does not have the special characters needed in some languages. 


## Features

* Basic arduino library file structure
* very low memory footprint
* Three fonts: a 6x8 pixel font, a C64-style font, and an Amiga Topaz style font.


## Development Environment

For library development using Visual Studio Code, the following tools and frameworks are used:

* git 2.40.0 by Junio Hamano 
* Git Extensions 4.0.2 by Henk Mesthuis
* Visual Studio Code 1.77.2 by Microsoft
* PlatformIO IDE 3.1.1 by PlatformIO
* MinGW Installation Manager 0.6.2-beta-20131004-1 by Keith Marshall (mingw32-base 2013072200, mingw32-gcc 6.3.0-1, mingw32-gcc-g++ 6.3.0-1)
* Python 3.10 by the Python Software Foundation
* Java 8 Update 371 by Oracle
* PlantUML 2.17.5 by Arnaud Roques

## Dependencies
The library uses the Arduino wire library.

# Usage
The OLED SSD1306 must be connected via I2C (aka TwoWire, TWI or simply Wire).

| Arduino	| Display |
| ------- | ------- |
| +5V     | VCC     |
| GND     | GND     |
| SDA     | SDA     |
| SCL     | SCL     |

An instance of the class "SimpleOLED" is needed. As first argument, the constructor expects the I2C address of the display (usually 0x3C), followed by the width (128) and the height (32 or 64) in pixels.

```C++
#define DISPLAY_I2C_ADDR 0x3C
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 32

SimpleOLED Display(DISPLAY_I2C_ADDR, DISPLAY_WIDTH, DISPLAY_HEIGHT);
```

## Functions

### begin()
This function must be called to initialise the display and switch it on.

Example:
```C++
Display.begin();
```

### end()
This function switches off the display.

Example:
```C++
Display.end();
```

### clear()
This function clears the whole content of the display and sets the cursor to the top left corner.

Example:
```C++
Display.clear();
```

### setFont(char *Name, bool DoubleHeight)
This function changes the font for the following operations. Possible fonts are "default", "Topaz" and "C64". The font height can be set with the parameter "DoubleHeight" - false means 8 pixels, true means 16 pixels.

After changing the font, the cursor position must be set again (see setCursor).

Example:
```C++
Display.setFont("Topaz", true);
```

### setCursor(uint8_t Column, uint8_t Row)
This function sets the cursor position for the following print operations. The values are in characters, not in pixels.

Example:
```C++
Display.setCursor(8, 1);
```

### print(char *String)
This function writes a string to the display. The only special character is "\n", which performs a carriage return and a line feed.

Example:
```C++
Display.print("Hello World!");
```

### println(char *String)
This function works exactly like the print function, but it adds a carriage return / line feed at the end of the line.

Example:
```C++
Display.println("Hello World!");
```



## Known Anomalies

* When changing from a double height to a single height font (and vice versa), the cursor position is corrupted and the following text is not readable until a line ending or a setCursor call. Workarround: when swithing the font settings, everytime call setCursor afterwards. 


## Changelog


### v1.1.1 (2023-12-23)

* Sourcecode moved to GitHub

### v1.0.0

* Initial release


