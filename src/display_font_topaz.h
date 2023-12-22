//
//  display_font_topaz.h
//  SimpleOLED
//
//  Created by Stefan Trippler on 2021-02-23.
//

#ifndef display_font_TOPAZ_h
#define display_font_TOPAZ_h

#define NUMBER_OF_TOPAZ_CHARS 192
#define WIDTH_OF_TOPAZ_CHARS    8


// ISO-8859 character set

static const uint8_t gau8_CharTopaz[NUMBER_OF_TOPAZ_CHARS][WIDTH_OF_TOPAZ_CHARS] PROGMEM = {
  { // 0x20, ' '
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x21, !
    B00000000,
    B00000000,
    B00000000,
    B01011111,
    B01011111,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x22, "
    B00000000,
    B00000011,
    B00000011,
    B00000000,
    B00000011,
    B00000011,
    B00000000,
    B00000000
  },
  { // 0x23, #
    B00010100,
    B01111111,
    B01111111,
    B00010100,
    B01111111,
    B01111111,
    B00010100,
    B00000000
  },
  { // 0x24, $
    B00000000,
    B00100100,
    B00101110,
    B01101011,
    B01101011,
    B00111010,
    B00010010,
    B00000000
  },
  { // 0x25, %
    B01001100,
    B01101010,
    B00110110,
    B00011000,
    B01101100,
    B01010110,
    B00110010,
    B00000000
  },
  { // 0x26, &
    B00110000,
    B01111110,
    B01001111,
    B01011001,
    B01110111,
    B00111010,
    B01101000,
    B01000000
  },
  { // 0x27, '
    B00000000,
    B00000000,
    B00000100,
    B00000111,
    B00000011,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x28, (
    B00000000,
    B00000000,
    B00011100,
    B00111110,
    B01100011,
    B01000001,
    B00000000,
    B00000000
  },
  { // 0x29, )
    B00000000,
    B00000000,
    B01000001,
    B01100011,
    B00111110,
    B00011100,
    B00000000,
    B00000000
  },
  { // 0x2A, *
    B00001000,
    B00101010,
    B00111110,
    B00011100,
    B00011100,
    B00111110,
    B00101010,
    B00001000
  },
  { // 0x2B, +
    B00000000,
    B00001000,
    B00001000,
    B00111110,
    B00111110,
    B00001000,
    B00001000,
    B00000000
  },
  { // 0x2C, ,
    B00000000,
    B00000000,
    B10000000,
    B11100000,
    B01100000,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x2D, -
    B00000000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00000000
  },
  { // 0x2E, .
    B00000000,
    B00000000,
    B00000000,
    B01100000,
    B01100000,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x2F, /
    B01000000,
    B01100000,
    B00110000,
    B00011000,
    B00001100,
    B00000110,
    B00000011,
    B00000001
  },
  
  
  { // 0x30, 0
    B00000000,
    B00111110,
    B01111111,
    B01011001,
    B01001101,
    B01111111,
    B00111110,
    B00000000
  },
  { // 0x31, 1
    B00000000,
    B00000100,
    B00000110,
    B01111111,
    B01111111,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x32, 2
    B00000000,
    B01000010,
    B01100011,
    B01110001,
    B01011001,
    B01001111,
    B01000110,
    B00000000
  },
  { // 0x33, 3
    B00000000,
    B00100010,
    B01100011,
    B01001001,
    B01001001,
    B01111111,
    B00110110,
    B00000000
  },
  { // 0x34, 4
    B00011000,
    B00011100,
    B00010110,
    B00010011,
    B01111111,
    B01111111,
    B00010000,
    B00000000
  },
  { // 0x35, 5
    B00000000,
    B00100111,
    B01100111,
    B01000101,
    B01000101,
    B01111101,
    B00111001,
    B00000000
  },
  { // 0x36, 6
    B00000000,
    B00111100,
    B01111110,
    B01001011,
    B01001001,
    B01111001,
    B00110000,
    B00000000
  },
  { // 0x37, 7
    B00000000,
    B00000001,
    B00000001,
    B01110001,
    B01111001,
    B00001111,
    B00000111,
    B00000000
  },
  { // 0x38, 8
    B00000000,
    B00110110,
    B01111111,
    B01001001,
    B01001001,
    B01111111,
    B00110110,
    B00000000
  },
  { // 0x39, 9
    B00000000,
    B00000110,
    B01001111,
    B01001001,
    B01101001,
    B00111111,
    B00011110,
    B00000000
  },
  { // 0x3A, :
    B00000000,
    B00000000,
    B00000000,
    B01100110,
    B01100110,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x3B, ;
    B00000000,
    B00000000,
    B10000000,
    B11100110,
    B01100110,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x3C, <
    B00000000,
    B00001000,
    B00001000,
    B00010100,
    B00010100,
    B00100010,
    B00100010,
    B00000000
  },
  { // 0x3D, =
    B00000000,
    B00010100,
    B00010100,
    B00010100,
    B00010100,
    B00010100,
    B00010100,
    B00000000
  },
  { // 0x3E, >
    B00000000,
    B00100010,
    B00100010,
    B00010100,
    B00010100,
    B00001000,
    B00001000,
    B00000000
  },
  { // 0x3F, ?
    B00000000,
    B00000010,
    B00000011,
    B01010001,
    B01011001,
    B00001111,
    B00000110,
    B00000000
  },
  
  
  { // 0x40, @
    B00111110,
    B01111111,
    B01000001,
    B01011101,
    B01010101,
    B00011111,
    B00011110,
    B00000000
  },
  { // 0x41, A
    B00000000,
    B01111110,
    B01111111,
    B00001001,
    B00001001,
    B01111111,
    B01111110,
    B00000000
  },
  { // 0x42, B
    B00000000,
    B01111111,
    B01111111,
    B01001001,
    B01001001,
    B01111111,
    B00110110,
    B00000000
  },
  { // 0x43, C
    B00000000,
    B00011100,
    B00111110,
    B01100011,
    B01000001,
    B01000001,
    B01000001,
    B00000000
  },
  { // 0x44, D
    B00000000,
    B01111111,
    B01111111,
    B01000001,
    B01100011,
    B00111110,
    B00011100,
    B00000000
  },
  { // 0x45, E
    B00000000,
    B01111111,
    B01111111,
    B01001001,
    B01001001,
    B01000001,
    B01000001,
    B00000000
  },
  { // 0x46, F
    B00000000,
    B01111111,
    B01111111,
    B00001001,
    B00001001,
    B00000001,
    B00000001,
    B00000000
  },
  { // 0x47, G
    B00000000,
    B00111110,
    B01111111,
    B01000001,
    B01001001,
    B01111011,
    B01111010,
    B00000000
  },
  { // 0x48, H
    B00000000,
    B01111111,
    B01111111,
    B00001000,
    B00001000,
    B01111111,
    B01111111,
    B00000000
  },
  { // 0x49, I
    B00000000,
    B00000000,
    B01000001,
    B01111111,
    B01111111,
    B01000001,
    B00000000,
    B00000000
  },
  { // 0x4A, J
    B00000000,
    B00100000,
    B01100000,
    B01000000,
    B01000000,
    B01111111,
    B00111111,
    B00000000
  },
  { // 0x4B, K
    B01111111,
    B01111111,
    B00001000,
    B00011100,
    B00110110,
    B01100011,
    B01000001,
    B00000000
  },
  { // 0x4C, L
    B00000000,
    B01111111,
    B01111111,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B00000000
  },
  { // 0x4D, M
    B01111111,
    B01111111,
    B00000110,
    B00001100,
    B00000110,
    B01111111,
    B01111111,
    B00000000
  },
  { // 0x4E, N
    B01111111,
    B01111111,
    B00000110,
    B00001100,
    B00011000,
    B01111111,
    B01111111,
    B00000000
  },
  { // 0x4F, O
    B00000000,
    B00111110,
    B01111111,
    B01000001,
    B01000001,
    B01111111,
    B00111110,
    B00000000
  },
  { // 0x50, P
    B00000000,
    B01111111,
    B01111111,
    B00001001,
    B00001001,
    B00001111,
    B00000110,
    B00000000
  },
  { // 0x51, Q
    B00111110,
    B01111111,
    B01000001,
    B01100001,
    B01111111,
    B01111110,
    B01000000,
    B00000000
  },
  { // 0x52, R
    B00000000,
    B01111111,
    B01111111,
    B00001001,
    B00011001,
    B01111111,
    B01100110,
    B00000000
  },
  { // 0x53, S
    B00000000,
    B00100110,
    B01101111,
    B01001101,
    B01011001,
    B01111011,
    B00110010,
    B00000000
  },
  { // 0x54, T
    B00000000,
    B00000001,
    B00000001,
    B01111111,
    B01111111,
    B00000001,
    B00000001,
    B00000000
  },
  { // 0x55, U
    B00000000,
    B00111111,
    B01111111,
    B01000000,
    B01000000,
    B01111111,
    B00111111,
    B00000000
  },
  { // 0x56, V
    B00000000,
    B00001111,
    B00111111,
    B01110000,
    B01110000,
    B00111111,
    B00001111,
    B00000000
  },
  { // 0x57, W
    B01111111,
    B01111111,
    B00110000,
    B00011000,
    B00110000,
    B01111111,
    B01111111,
    B00000000
  },
  { // 0x58, X
    B01000001,
    B01100011,
    B00110110,
    B00011100,
    B00011100,
    B00110110,
    B01100011,
    B01000001
  },
  { // 0x59, Y
    B00000001,
    B00000011,
    B00000110,
    B01111100,
    B01111100,
    B00000110,
    B00000011,
    B00000001
  },
  { // 0x5A, Z
    B01100001,
    B01110001,
    B01011001,
    B01001101,
    B01000111,
    B01000011,
    B01000001,
    B00000000
  },
  { // 0x5B, [
    B00000000,
    B00000000,
    B01111111,
    B01111111,
    B01000001,
    B01000001,
    B00000000,
    B00000000
  },
  { // 0x5C, "\ "
    B00000001,
    B00000011,
    B00000110,
    B00001100,
    B00011000,
    B00110000,
    B01100000,
    B01000000
  },
  { // 0x5D, ]
    B00000000,
    B00000000,
    B01000001,
    B01000001,
    B01111111,
    B01111111,
    B00000000,
    B00000000
  },
  { // 0x5E, ^
    B00001000,
    B00001100,
    B00000110,
    B00000011,
    B00000110,
    B00001100,
    B00001000,
    B00000000
  },
  { // 0x5F, _
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B00000000
  },
  
  
  { // 0x60, `
    B00000000,
    B00000000,
    B00000000,
    B00000011,
    B00000111,
    B00000100,
    B00000000,
    B00000000
  },
  { // 0x61, a
    B00000000,
    B00100000,
    B01110100,
    B01010100,
    B01010100,
    B01111100,
    B01111000,
    B00000000
  },
  { // 0x62, b
    B00000000,
    B01111111,
    B01111111,
    B01000100,
    B01000100,
    B01111100,
    B00111000,
    B00000000
  },
  { // 0x63, c
    B00000000,
    B00111000,
    B01111100,
    B01000100,
    B01000100,
    B01000100,
    B00000000,
    B00000000
  },
  { // 0x64, d
    B00000000,
    B00111000,
    B01111100,
    B01000100,
    B01000100,
    B01111111,
    B01111111,
    B00000000
  },
  { // 0x65, e
    B00000000,
    B00111000,
    B01111100,
    B01010100,
    B01010100,
    B01011100,
    B00011000,
    B00000000
  },
  { // 0x66, f
    B00000000,
    B00000100,
    B01111110,
    B01111111,
    B00000101,
    B00000101,
    B00000000,
    B00000000
  },
  { // 0x67, g
    B00000000,
    B00011000,
    B10111100,
    B10100100,
    B10100100,
    B11111100,
    B01111100,
    B00000000
  },
  { // 0x68, h
    B00000000,
    B01111111,
    B01111111,
    B00000100,
    B00000100,
    B01111100,
    B01111000,
    B00000000
  },
  { // 0x69, i
    B00000000,
    B00000000,
    B00000000,
    B00111101,
    B01111101,
    B01000000,
    B00000000,
    B00000000
  },
  { // 0x6A, j
    B00000000,
    B10000000,
    B10000000,
    B10000000,
    B11111101,
    B01111101,
    B00000000,
    B00000000
  },
  { // 0x6B, k
    B00000000,
    B01111111,
    B01111111,
    B00010000,
    B00111000,
    B01101100,
    B01000100,
    B00000000
  },
  { // 0x6C, l
    B00000000,
    B00000000,
    B00000000,
    B00111111,
    B01111111,
    B01000000,
    B00000000,
    B00000000
  },
  { // 0x6D, m
    B01111100,
    B01111100,
    B00001100,
    B00011000,
    B00001100,
    B01111100,
    B01111000,
    B00000000
  },
  { // 0x6E, n
    B00000000,
    B01111100,
    B01111100,
    B00000100,
    B00000100,
    B01111100,
    B01111000,
    B00000000
  },
  { // 0x6F, o
    B00000000,
    B00111000,
    B01111100,
    B01000100,
    B01000100,
    B01111100,
    B00111000,
    B00000000
  },
  { // 0x70, p
    B00000000,
    B11111100,
    B11111100,
    B00100100,
    B00100100,
    B00111100,
    B00011000,
    B00000000
  },
  { // 0x71, q
    B00000000,
    B00011000,
    B00111100,
    B00100100,
    B00100100,
    B11111100,
    B11111100,
    B00000000
  },
  { // 0x72, r
    B00000000,
    B01111100,
    B01111100,
    B00000100,
    B00000100,
    B00001100,
    B00001000,
    B00000000
  },
  { // 0x73, s
    B00000000,
    B01001000,
    B01011100,
    B01010100,
    B01010100,
    B01110100,
    B00100000,
    B00000000
  },
  { // 0x74, t
    B00000000,
    B00000100,
    B00111111,
    B01111111,
    B01000100,
    B01000100,
    B00000000,
    B00000000
  },
  { // 0x75, u
    B00000000,
    B00111100,
    B01111100,
    B01000000,
    B01000000,
    B01111100,
    B01111100,
    B00000000
  },
  { // 0x76, v
    B00000000,
    B00011100,
    B00111100,
    B01100000,
    B01100000,
    B00111100,
    B00011100,
    B00000000
  },
  { // 0x77, w
    B00111100,
    B01111100,
    B01100000,
    B00110000,
    B01100000,
    B01111100,
    B00111100,
    B00000000
  },
  { // 0x78, x
    B01000100,
    B01101100,
    B00111000,
    B00010000,
    B00111000,
    B01101100,
    B01000100,
    B00000000
  },
  { // 0x79, y
    B00000000,
    B00011100,
    B10111100,
    B11100000,
    B01100000,
    B00111100,
    B00011100,
    B00000000
  },
  { // 0x7A, z
    B00000000,
    B01000100,
    B01100100,
    B01110100,
    B01011100,
    B01001100,
    B01000100,
    B00000000
  },
  { // 0x7B, {
    B00000000,
    B00001000,
    B00001000,
    B00111110,
    B01110111,
    B01000001,
    B01000001,
    B00000000
  },
  { // 0x7C, |
    B00000000,
    B00000000,
    B00000000,
    B01111111,
    B01111111,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x7D, }
    B00000000,
    B01000001,
    B01000001,
    B01110111,
    B00111110,
    B00001000,
    B00001000,
    B00000000
  },
  { // 0x7E, ~
    B00000010,
    B00000001,
    B00000001,
    B00000011,
    B00000010,
    B00000010,
    B00000001,
    B00000000
  },
  { // 0x7F, ÿ
    B00000100,
    B00001101,
    B00011001,
    B01110000,
    B01110000,
    B00011001,
    B00001101,
    B00000100
  },
  
  // 0x80 - 0x9F is not used
  
  { // 0xA0, NBSP
    B01100000,
    B01100000,
    B01000000,
    B01000000,
    B01000000,
    B01100000,
    B01100000,
    B00000000
    },
    { // 0xA1, ¡
    B00000000,
    B00000000,
    B00000000,
    B01111101,
    B01111101,
    B00000000,
    B00000000,
    B00000000
    },
    { // 0xA2, ¢
    B00000000,
    B00001000,
    B00011100,
    B00010100,
    B00111110,
    B00111110,
    B00010100,
    B00000000
    },
    { // 0xA3, £
    B00000000,
    B01001000,
    B01111110,
    B01111111,
    B01001001,
    B01000011,
    B01000010,
    B00000000
    },
    { // 0xA4, €
    B00010100,
    B00111110,
    B01111111,
    B01010101,
    B01010101,
    B01100011,
    B00100010,
    B00000000
    },
    { // 0xA5, ¥
    B00000001,
    B00000011,
    B00010110,
    B01111100,
    B01111100,
    B00010110,
    B00000011,
    B00000001
    },
    { // 0xA6, ¦
    B00000000,
    B00000000,
    B00000000,
    B01110111,
    B01110111,
    B00000000,
    B00000000,
    B00000000
    },
    { // 0xA7, §
    B00000000,
    B00001010,
    B01011111,
    B01010101,
    B01010101,
    B01111101,
    B00101000,
    B00000000
    },
    { // 0xA8, ¨
    B00000000,
    B00000011,
    B00000011,
    B00000000,
    B00000000,
    B00000011,
    B00000011,
    B00000000
    },
    { // 0xA9, ©
    B00111110,
    B01000001,
    B01001001,
    B01011101,
    B01010101,
    B01010101,
    B01000001,
    B00111110
    },
    { // 0xAA, ª
    B00000000,
    B00100100,
    B00101010,
    B00101001,
    B00101001,
    B00101111,
    B00100000,
    B00000000
    },
    { // 0xAB, «
    B00001000,
    B00011100,
    B00110110,
    B00100010,
    B00001000,
    B00011100,
    B00110110,
    B00100010
    },
    { // 0xAC, ¬
    B00000000,
    B00000000,
    B00000001,
    B00000001,
    B00000001,
    B00000011,
    B00000011,
    B00000000
    },
    { // 0xAD, SHY
    B00000000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00000000
    },
    { // 0xAE, ®
    B01111110,
    B10000001,
    B10111101,
    B10010101,
    B10010101,
    B10101001,
    B10000001,
    B01111110
    },
    { // 0xAF, ¯
    B00000000,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000000
    },
  
    { // 0xB0, °
    B00000000,
    B00000010,
    B00000111,
    B00000101,
    B00000101,
    B00000111,
    B00000010,
    B00000000
    },
    { // 0xB1, ±
    B00000000,
    B01000100,
    B01000100,
    B01011111,
    B01011111,
    B01000100,
    B01000100,
    B00000000
    },
    { // 0xB2, ²
    B00000000,
    B00010001,
    B00011001,
    B00011101,
    B00010111,
    B00010010,
    B00000000,
    B00000000
    },
    { // 0xB3, ³
    B00000000,
    B00010001,
    B00010001,
    B00010101,
    B00011111,
    B00001010,
    B00000000,
    B00000000
    },
    { // 0xB4, Ž instead of ´ (not conform to ISO-8859-1)
    B01000010,
    B01100010,
    B01110011,
    B01011011,
    B01001111,
    B01000110,
    B01000010,
    B00000000
    },
    { // 0xB5, µ
    B00000000,
    B11111100,
    B11111100,
    B01000000,
    B01000000,
    B01111100,
    B01111100,
    B01000000
    },
    { // 0xB6, ¶
    B00000000,
    B00000110,
    B00001111,
    B00001111,
    B01111111,
    B00000001,
    B01111111,
    B00000000
    },
    { // 0xB7, ·
    B00000000,
    B00000000,
    B00000000,
    B00001100,
    B00001100,
    B00000000,
    B00000000,
    B00000000
    },
    { // 0xB8, ž instead of ¸ (not conform to ISO-8859-1)
    B00000000,
    B01000100,
    B01100101,
    B01110110,
    B01011110,
    B01001101,
    B01000100,
    B00000000
    },
    { // 0xB9, ¹
    B00000000,
    B00000010,
    B00011111,
    B00011111,
    B00000000,
    B00000000,
    B00000000,
    B00000000
    },
    { // 0xBA, º
    B00000000,
    B00100110,
    B00101001,
    B00101001,
    B00101001,
    B00100110,
    B00000000,
    B00000000
    },
    { // 0xBB, »
    B00100010,
    B00110110,
    B00011100,
    B00001000,
    B00100010,
    B00110110,
    B00011100,
    B00001000
    },
    { // 0xBC, Œ instead of ¼ (not conform to ISO-8859-1)
    B00111110,
    B01111111,
    B01000001,
    B01000001,
    B00111110,
    B01111111,
    B01001001,
    B01001001
    },
    { // 0xBD, œ instead of ½ (not conform to ISO-8859-1)
    B00111000,
    B01111100,
    B01000100,
    B01111100,
    B00111100,
    B01010100,
    B01011100,
    B01011000
    },
    { // 0xBE, Ÿ instead of ¾ (not conform to ISO-8859-1)
    B00000100,
    B00001101,
    B00011001,
    B01110000,
    B01110000,
    B00011001,
    B00001101,
    B00000100
    },
    { // 0xBF, ¿
    B00000000,
    B00110000,
    B01111000,
    B01001101,
    B01000101,
    B01100000,
    B00100000,
    B00000000
  },
  
  
  { // 0xC0, À
    B00000000,
    B01111000,
    B01111101,
    B00010111,
    B00010110,
    B01111100,
    B01111000,
    B00000000
  },
  { // 0xC1, Á
    B00000000,
    B01111000,
    B01111100,
    B00010110,
    B00010111,
    B01111101,
    B01111000,
    B00000000
  },
  { // 0xC2, Â
    B00000000,
    B01111010,
    B01111110,
    B00010101,
    B00010101,
    B01111110,
    B01111010,
    B00000000
  },
  { // 0xC3, Ã
    B00000010,
    B01111001,
    B01111101,
    B00010101,
    B00010110,
    B01111110,
    B01111010,
    B00000001
  },
  { // 0xC4, Ä
    B00000000,
    B01111001,
    B01111101,
    B00010100,
    B00010100,
    B01111101,
    B01111001,
    B00000000
  },
  { // 0xC5, Å
    B00000000,
    B01111000,
    B01111110,
    B00010101,
    B00010101,
    B01111110,
    B01111000,
    B00000000
  },
  { // 0xC6, Æ
    B01100000,
    B01111000,
    B00011110,
    B00010111,
    B01111111,
    B01111111,
    B01001001,
    B01001001
  },
  { // 0xC7, Ç
    B00000000,
    B00001100,
    B00011110,
    B10110011,
    B11100001,
    B01100001,
    B00100001,
    B00000000
  },
  { // 0xC8, È
    B00000000,
    B01111100,
    B01111101,
    B01010111,
    B01010110,
    B01000100,
    B01000100,
    B00000000
  },
  { // 0xC9, É
    B00000000,
    B01111100,
    B01111100,
    B01010110,
    B01010111,
    B01000101,
    B01000100,
    B00000000
  },
  { // 0xCA, Ê
    B00000000,
    B01111110,
    B01111110,
    B01010101,
    B01010101,
    B01000110,
    B01000110,
    B00000000
  },
  { // 0xCB, Ë
    B00000000,
    B01111101,
    B01111101,
    B01010100,
    B01010100,
    B01000101,
    B01000101,
    B00000000
  },
  { // 0xCC, Ì
    B00000000,
    B00000000,
    B01000101,
    B01111111,
    B01111110,
    B01000100,
    B00000000,
    B00000000
  },
  { // 0xCD, Í
    B00000000,
    B00000000,
    B01000100,
    B01111110,
    B01111111,
    B01000101,
    B00000000,
    B00000000
  },
  { // 0xCE, Î
    B00000000,
    B00000010,
    B01000110,
    B01111101,
    B01111101,
    B01000110,
    B00000010,
    B00000000
  },
  { // 0xCF, Ï
    B00000000,
    B00000001,
    B01000101,
    B01111100,
    B01111100,
    B01000101,
    B00000001,
    B00000000
  },
  
  { // 0xD0, Ð
    B00001000,
    B01111111,
    B01111111,
    B01001001,
    B01100011,
    B00111110,
    B00011100,
    B00000000
  },
  { // 0xD1, Ñ
    B01111110,
    B01111111,
    B00001101,
    B00011001,
    B00110010,
    B01111110,
    B01111110,
    B00000001
  },
  { // 0xD2, Ò
    B00000000,
    B00111000,
    B01111101,
    B01000111,
    B01000110,
    B01111100,
    B00111000,
    B00000000
  },
  { // 0xD3, Ó
    B00000000,
    B00111000,
    B01111100,
    B01000110,
    B01000111,
    B01111101,
    B00111000,
    B00000000
  },
  { // 0xD4, Ô
    B00000000,
    B00111010,
    B01111110,
    B01000101,
    B01000101,
    B01111110,
    B00111010,
    B00000000
  },
  { // 0xD5, Õ
    B00000010,
    B00111001,
    B01111101,
    B01000101,
    B01000110,
    B01111110,
    B00111010,
    B00000001
  },
  { // 0xD6, Ö
    B00000001,
    B00111101,
    B01111110,
    B01000010,
    B01000010,
    B01111110,
    B00111101,
    B00000001
  },
  { // 0xD7, ×
    B00100010,
    B00110110,
    B00011100,
    B00001000,
    B00011100,
    B00110110,
    B00100010,
    B00000000
  },
  { // 0xD8, Ø
    B01000000,
    B01111110,
    B01111111,
    B01011001,
    B01001101,
    B01111111,
    B00111111,
    B00000001
  },
  { // 0xD9, Ù
    B00000000,
    B00111100,
    B01111101,
    B01000011,
    B01000010,
    B01111100,
    B00111100,
    B00000000
  },
  { // 0xDA, Ú
    B00000000,
    B00111100,
    B01111100,
    B01000010,
    B01000011,
    B01111101,
    B00111100,
    B00000000
  },
  { // 0xDB, Û
    B00000000,
    B00111100,
    B01111110,
    B01000001,
    B01000001,
    B01111110,
    B00111100,
    B00000000
  },
  { // 0xDC, Ü
    B00000000,
    B00111101,
    B01111101,
    B01000000,
    B01000000,
    B01111101,
    B00111101,
    B00000000
  },
  { // 0xDD, Ý
    B00000100,
    B00001100,
    B00011000,
    B01110000,
    B01110010,
    B00011001,
    B00001101,
    B00000100
  },
  { // 0xDE, Þ
    B01111111,
    B01111111,
    B00010100,
    B00010100,
    B00010100,
    B00011100,
    B00001000,
    B00000000
  },
  { // 0xDF, ß
    B00000000,
    B11111110,
    B11111111,
    B00000001,
    B01001001,
    B01111111,
    B00110110,
    B00000000
  },

  
  { // 0xE0, à
    B00000000,
    B00100000,
    B01110101,
    B01010111,
    B01010110,
    B01111100,
    B01111000,
    B00000000
  },
  { // 0xE1, á
    B00000000,
    B00100000,
    B01110100,
    B01010110,
    B01010111,
    B01111101,
    B01111000,
    B00000000
  },
  { // 0xE2, â
    B00000000,
    B00100010,
    B01110110,
    B01010101,
    B01010101,
    B01111110,
    B01111010,
    B00000000
  },
  { // 0xE3, ã
    B00000010,
    B00100001,
    B01110101,
    B01010101,
    B01010110,
    B01111110,
    B01111010,
    B00000001
  },
  { // 0xE4, ä
    B00000000,
    B00100001,
    B01110101,
    B01010100,
    B01010100,
    B01111101,
    B01111001,
    B00000000
  },
  { // 0xE5, å
    B00000000,
    B00100000,
    B01110110,
    B01010101,
    B01010101,
    B01111110,
    B01111000,
    B00000000
  },
  { // 0xE6, æ
    B00100000,
    B01110100,
    B01010100,
    B01111100,
    B00111100,
    B01010100,
    B01011100,
    B01011000
  },
  { // 0xE7, ç
    B00000000,
    B00111000,
    B01111100,
    B11000100,
    B11000100,
    B01000100,
    B00000000,
    B00000000
  },
  { // 0xE8, è
    B00000000,
    B00111000,
    B01111101,
    B01010111,
    B01010110,
    B01011100,
    B00011000,
    B00000000
  },
  { // 0xE9, é
    B00000000,
    B00111000,
    B01111100,
    B01010110,
    B01010111,
    B01011101,
    B00011000,
    B00000000
  },
  { // 0xEA, ê
    B00000000,
    B00111010,
    B01111110,
    B01010101,
    B01010101,
    B01011110,
    B00011010,
    B00000000
  },
  { // 0xEB, ë
    B00000000,
    B00111001,
    B01111101,
    B01010100,
    B01010100,
    B01011101,
    B00011001,
    B00000000
  },
  { // 0xEC, ì
    B00000000,
    B00000000,
    B00000001,
    B00111011,
    B01111010,
    B01000000,
    B00000000,
    B00000000
  },
  { // 0xED, í
    B00000000,
    B00000000,
    B00000000,
    B00111010,
    B01111011,
    B01000001,
    B00000000,
    B00000000
  },
  { // 0xEE, î
    B00000000,
    B00000010,
    B00000010,
    B00111001,
    B01111001,
    B01000010,
    B00000010,
    B00000000
  },
  { // 0xEF, ï
    B00000000,
    B00000010,
    B00000010,
    B00111000,
    B01111000,
    B01000010,
    B00000010,
    B00000000
  },
  
  { // 0xF0, ð
    B00000010,
    B00110011,
    B01111011,
    B01001110,
    B01001110,
    B01111010,
    B00110000,
    B00000000
  },
  { // 0xF1, ñ
    B00000010,
    B01111001,
    B01111001,
    B00001001,
    B00001010,
    B01111010,
    B01110010,
    B00000001
  },
  { // 0xF2, ò
    B00000000,
    B00110000,
    B01111001,
    B01001011,
    B01001010,
    B01111000,
    B00110000,
    B00000000
  },
  { // 0xF3, ó
    B00000000,
    B00110000,
    B01111000,
    B01001010,
    B01001011,
    B01111001,
    B00110000,
    B00000000
  },
  { // 0xF4, ô
    B00000000,
    B00110010,
    B01111010,
    B01001001,
    B01001001,
    B01111010,
    B00110010,
    B00000000
  },
  { // 0xF5, õ
    B00000010,
    B00110001,
    B01111001,
    B01001001,
    B01001010,
    B01111010,
    B00110010,
    B00000001
  },
  { // 0xF6, ö
    B00000000,
    B00110010,
    B01111010,
    B01001000,
    B01001000,
    B01111010,
    B00110010,
    B00000000
  },
  { // 0xF7, ÷
    B00000000,
    B00001000,
    B00001000,
    B00101010,
    B00101010,
    B00001000,
    B00001000,
    B00000000
  },
  { // 0xF8, ø
    B10111000,
    B01111100,
    B01100100,
    B01010100,
    B01001100,
    B01111100,
    B00111010,
    B00000000
  },
  { // 0xF9, ù
    B00000000,
    B00111000,
    B01111001,
    B01000011,
    B01000010,
    B01111000,
    B01111000,
    B00000000
  },
  { // 0xFA, ú
    B00000000,
    B00111000,
    B01111000,
    B01000010,
    B01000011,
    B01111001,
    B01111000,
    B00000000
  },
  { // 0xFB, û
    B00000000,
    B00111010,
    B01111010,
    B01000001,
    B01000001,
    B01111010,
    B01111010,
    B00000000
  },
  { // 0xFC, ü
    B00000000,
    B00111010,
    B01111010,
    B01000000,
    B01000000,
    B01111010,
    B01111010,
    B00000000
  },
  { // 0xFD, ý
    B00000000,
    B00011000,
    B10111000,
    B11100010,
    B01100011,
    B00111001,
    B00011000,
    B00000000
  },
  { // 0xFE, þ
    B00000000,
    B11111111,
    B11111111,
    B00100100,
    B00100100,
    B00111100,
    B00011000,
    B00000000
  },
  { // 0xFF, ÿ
    B00000000,
    B00011010,
    B10111010,
    B11100000,
    B01100000,
    B00111010,
    B00011010,
    B00000000
  }
  
};



#endif /* display_font_TOPAZ_h */