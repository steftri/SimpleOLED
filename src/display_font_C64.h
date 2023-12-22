//
//  display_font_C64.h
//  SimpleOLED
//
//  Created by Stefan Trippler on 2021-02-23.
//

#ifndef display_font_C64_h
#define display_font_C64_h


#define COMPLETE_C64_FONT   1

#define WIDTH_OF_C64_CHARS   8




static const uint8_t gau8_CharC64[][WIDTH_OF_C64_CHARS] PROGMEM =
{
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
    B01001111,
    B01001111,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x22, "
    B00000000,
    B00000111,
    B00000111,
    B00000000,
    B00000000,
    B00000111,
    B00000111,
    B00000000
  },
  { // 0x23, #
    B00010100,
    B01111111,
    B01111111,
    B00010100,
    B00010100,
    B01111111,
    B01111111,
    B00010100
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
    B00000000,
    B01100011,
    B00110011,
    B00011000,
    B00001100,
    B01100110,
    B01100011,
    B00000000
  },
  { // 0x26, &
    B00000000,
    B00110010,
    B01111111,
    B01001101,
    B01001101,
    B01110111,
    B01110010,
    B01010000
  },
  { // 0x27, '
    B00000000,
    B00000000,
    B00000000,
    B00000100,
    B00000110,
    B00000011,
    B00000001,
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
    B00000000,
    B01000000,
    B01100000,
    B00110000,
    B00011000,
    B00001100,
    B00000110,
    B00000010
  },
  
  
  { // 0x30, 0
    B00000000,
    B00111110,
    B01111111,
    B01001001,
    B01000101,
    B01111111,
    B00111110,
    B00000000
  },
  { // 0x31, 1
    B00000000,
    B01000000,
    B01000100,
    B01111111,
    B01111111,
    B01000000,
    B01000000,
    B00000000
  },
  { // 0x32, 2
    B00000000,
    B01100010,
    B01110011,
    B01010001,
    B01001001,
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
    B00000000,
    B00011000,
    B00011000,
    B00010100,
    B00010110,
    B01111111,
    B01111111,
    B00010000
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
    B00111110,
    B01111111,
    B01001001,
    B01001001,
    B01111011,
    B00110010,
    B00000000
  },
  { // 0x37, 7
    B00000000,
    B00000011,
    B00000011,
    B01111001,
    B01111101,
    B00000111,
    B00000011,
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
    B00100110,
    B01101111,
    B01001001,
    B01001001,
    B01111111,
    B00111110,
    B00000000
  },
  { // 0x3A, :
    B00000000,
    B00000000,
    B00000000,
    B00100100,
    B00100100,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x3B, ;
    B00000000,
    B00000000,
    B10000000,
    B11100100,
    B01100100,
    B00000000,
    B00000000,
    B00000000
  },
  { // 0x3C, <
    B00000000,
    B00001000,
    B00011100,
    B00110110,
    B01100011,
    B01000001,
    B01000001,
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
    B01000001,
    B01000001,
    B01100011,
    B00110110,
    B00011100,
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
    B00000000,
    B00111110,
    B01111111,
    B01000001,
    B01001101,
    B01001111,
    B00101110,
    B00000000
  },
  { // 0x41, A
    B00000000,
    B01111100,
    B01111110,
    B00001011,
    B00001011,
    B01111110,
    B01111100,
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
    B00111110,
    B01111111,
    B01000001,
    B01000001,
    B01100011,
    B00100010,
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
    B00111010,
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
    B01000001,
    B01111111,
    B00111111,
    B00000001,
    B00000000
  },
  { // 0x4B, K
    B00000000,
    B01111111,
    B01111111,
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
    B00000000,
    B01111111,
    B01111111,
    B00000110,
    B00001100,
    B00000110,
    B01111111,
    B01111111
  },
  { // 0x4E, N
    B00000000,
    B01111111,
    B01111111,
    B00001110,
    B00011100,
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
    B00000000,
    B00011110,
    B00111111,
    B00100001,
    B01100001,
    B01111111,
    B01011110,
    B00000000
  },
  { // 0x52, R
    B00000000,
    B01111111,
    B01111111,
    B00011001,
    B00111001,
    B01101111,
    B01000110,
    B00000000
  },
  { // 0x53, S
    B00000000,
    B00100110,
    B01101111,
    B01001001,
    B01001001,
    B01111011,
    B00110010,
    B00000000,
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
    B00011111,
    B00111111,
    B01100000,
    B01100000,
    B00111111,
    B00011111,
    B00000000
  },
  { // 0x57, W
    B00000000,
    B01111111,
    B01111111,
    B00110000,
    B00011000,
    B00110000,
    B01111111,
    B01111111
  },
  { // 0x58, X
    B00000000,
    B01100011,
    B01110111,
    B00011100,
    B00011100,
    B01110111,
    B01100011,
    B00000000
  },
  { // 0x59, Y
    B00000000,
    B00000111,
    B00001111,
    B01111000,
    B01111000,
    B00001111,
    B00000111,
    B00000000
  },
  { // 0x5A, Z
    B00000000,
    B01100001,
    B01110001,
    B01011001,
    B01001101,
    B01000111,
    B01000011,
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
    B00000000,
    B00000010,
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
    B00000000,
    B00000100,
    B00000110,
    B00000011,
    B00000011,
    B00000110,
    B00000100,
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
    B10000000
  },
  
  
  { // 0x60, `
    B00000000,
    B00000000,
    B00000001,
    B00000011,
    B00000110,
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
    B01111110,
    B01111110,
    B01001000,
    B01001000,
    B01111000,
    B00110000,
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
    B00110000,
    B01111000,
    B01001000,
    B01001000,
    B01111110,
    B01111110,
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
    B00000000,
    B00001000,
    B01111100,
    B01111110,
    B00001010,
    B00001010,
    B00000000
  },
  { // 0x67, g
    B00000000,
    B10011000,
    B10111100,
    B10100100,
    B10100100,
    B11111100,
    B01111100,
    B00000000
  },
  { // 0x68, h
    B00000000,
    B01111110,
    B01111110,
    B00001000,
    B00001000,
    B01111000,
    B01110000,
    B00000000
  },
  { // 0x69, i
    B00000000,
    B00000000,
    B01001000,
    B01111010,
    B01111010,
    B01000000,
    B00000000,
    B00000000
  },
  { // 0x6A, j
    B00000000,
    B00000000,
    B10000000,
    B10000000,
    B10000000,
    B11111010,
    B01111010,
    B00000000
  },
  { // 0x6B, k
    B00000000,
    B01111110,
    B01111110,
    B00010000,
    B00111000,
    B01101000,
    B01000000,
    B00000000
  },
  { // 0x6C, l
    B00000000,
    B00000000,
    B01000010,
    B01111110,
    B01111110,
    B01000000,
    B00000000,
    B00000000
  },
  { // 0x6D, m
    B00000000,
    B01111100,
    B01111100,
    B00011000,
    B00111000,
    B00011100,
    B01111100,
    B01111000
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
    B00100100,
    B00000000
  },
  { // 0x74, t
    B00000000,
    B00000100,
    B00000100,
    B00111110,
    B01111110,
    B01000100,
    B01000100,
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
    B00000000,
    B00011100,
    B01111100,
    B01110000,
    B00111000,
    B01110000,
    B01111100,
    B00011100
  },
  { // 0x78, x
    B00000000,
    B01000100,
    B01101100,
    B00111000,
    B00111000,
    B01101100,
    B01000100,
    B00000000
  },
  { // 0x79, y
    B00000000,
    B10011100,
    B10111100,
    B10100000,
    B11100000,
    B01111100,
    B00111100,
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
    B00000000,
    B00000010,
    B00000011,
    B00000001,
    B00000011,
    B00000010,
    B00000011,
    B00000001
  },
  { // 0x7F, £
    B01000000,
    B01101000,
    B01111100,
    B01011110,
    B01001001,
    B01001001,
    B00100010,
    B00000000
  },
  
#if COMPLETE_C64_FONT == 1
  // More characters:
  
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B11110000,
    B11110000,
    B11110000,
    B11110000,
    B11110000,
    B11110000,
    B11110000,
    B11110000
  },
  {
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001
  },
  {
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000
  },
  {
    B11111111,
    B11111111,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00110011,
    B00110011,
    B11001100,
    B11001100,
    B00110011,
    B00110011,
    B11001100,
    B11001100
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B11111111,
    B11111111
  },
  {
    B00110000,
    B00110000,
    B11000000,
    B11000000,
    B00110000,
    B00110000,
    B11000000,
    B11000000
  },
  {
    B00110011,
    B10011001,
    B11001100,
    B01100110,
    B00110011,
    B10011001,
    B11001100,
    B01100110
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B11111111,
    B11111111
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B11111111,
    B11111111,
    B00011000,
    B00011000,
    B00011000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B11110000,
    B11110000,
    B11110000,
    B11110000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00011111,
    B00011111,
    B00011000,
    B00011000,
    B00011000
  },
  {
    B00011000,
    B00011000,
    B00011000,
    B11111000,
    B11111000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B11000000,
    B11000000,
    B11000000,
    B11000000,
    B11000000,
    B11000000,
    B11000000,
    B11000000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B11111000,
    B11111000,
    B00011000,
    B00011000,
    B00011000
  },
  {
    B00011000,
    B00011000,
    B00011000,
    B00011111,
    B00011111,
    B00011000,
    B00011000,
    B00011000
  },
  {
    B00011000,
    B00011000,
    B00011000,
    B11111000,
    B11111000,
    B00011000,
    B00011000,
    B00011000
  },
  {
    B00011000,
    B00011000,
    B00011000,
    B11111111,
    B11111111,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B11111111,
    B11111111,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B11111111,
    B11111111,
    B11111111,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B11111111,
    B11111111,
    B11111111
  },
  {
    B00000011,
    B00000011,
    B00000011,
    B00000011,
    B00000011,
    B00000011,
    B00000011,
    B00000011
  },
  {
    B00000111,
    B00000111,
    B00000111,
    B00000111,
    B00000111,
    B00000111,
    B00000111,
    B00000111
  },
  {
    B11100000,
    B11100000,
    B11100000,
    B11100000,
    B11100000,
    B11100000,
    B11100000,
    B11100000
  },
  {
    B00000000,
    B01111000,
    B01111000,
    B00110000,
    B00011000,
    B00001100,
    B00000110,
    B00000011
  },
  {
    B11110000,
    B11110000,
    B11110000,
    B11110000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00001111,
    B00001111,
    B00001111,
    B00001111
  },
  {
    B00011000,
    B00011000,
    B00011000,
    B00011111,
    B00011111,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00001111,
    B00001111,
    B00001111,
    B00001111,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00001111,
    B00001111,
    B00001111,
    B00001111,
    B11110000,
    B11110000,
    B11110000,
    B11110000
  },
#endif
  
  {
    B00000000,
    B00001000,
    B00001100,
    B11111110,
    B11111110,
    B00001100,
    B00001000,
    B00000000
  },
  {
    B00000000,
    B00011000,
    B00111100,
    B01111110,
    B00011000,
    B00011000,
    B00011000,
    B00011000
  },
  {
    B00011000,
    B00011000,
    B00011000,
    B11111111,
    B11111111,
    B00011000,
    B00011000,
    B00011000
  },
  {
    B00110011,
    B00110011,
    B11001100,
    B11001100,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B11111111,
    B11111111,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B11001100,
    B11001100,
    B00110011,
    B00110011,
    B11001100,
    B11001100,
    B00110011,
    B00110011
  }
};



#endif /* display_font_C64_h */