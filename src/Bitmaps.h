// Optimized Bitmaps.h
#pragma once

#include <Arduino.h>
#include <MD_MAX72xx.h>

/*
  - No RAM-based globals
  - Width/Frame metadata as macros (zero RAM footprint)
  - All data in flash
*/

#if defined(ESP8266)
  #define FLASH_BITMAP ICACHE_RODATA_ATTR
#else
  #define FLASH_BITMAP
#endif

// ─── Arrow
// ─────────────────────────────────────────────────────────────────────
#define F_ARROW1  1
#define W_ARROW1  8
extern const uint8_t arrow1[] PROGMEM FLASH_BITMAP;

#define F_ARROW2  1
#define W_ARROW2  8
extern const uint8_t arrow2[] PROGMEM FLASH_BITMAP;

// ─── Chevron
// ───────────────────────────────────────────────────────────────────
#define F_CHEVRON 1
#define W_CHEVRON 8
extern const uint8_t chevron[] PROGMEM FLASH_BITMAP;

// ─── Dino
// ──────────────────────────────────────────────────────────────────────
#define F_DINO    1
#define W_DINO    8
extern const uint8_t dino[] PROGMEM FLASH_BITMAP;

// ─── Fireball
// ──────────────────────────────────────────────────────────────────
#define F_FBALL   1
#define W_FBALL   8
extern const uint8_t fireball[] PROGMEM FLASH_BITMAP;

// ─── Ghost
// ─────────────────────────────────────────────────────────────────────
#define F_GHOST   1
#define W_GHOST   8
extern const uint8_t ghost[] PROGMEM FLASH_BITMAP;

// ─── Heart
// ─────────────────────────────────────────────────────────────────────
#define F_HEART   1
#define W_HEART   8
extern const uint8_t heart[] PROGMEM FLASH_BITMAP;

// ─── Invader
// ───────────────────────────────────────────────────────────────────
#define F_INVADER 1
#define W_INVADER 8
extern const uint8_t invader[] PROGMEM FLASH_BITMAP;

// ─── Lines
// ─────────────────────────────────────────────────────────────────────
#define F_LINES   1
#define W_LINES   8
extern const uint8_t lines[] PROGMEM FLASH_BITMAP;

// ─── Mario
// ─────────────────────────────────────────────────────────────────────
#define F_MARIO   1
#define W_MARIO   8
extern const uint8_t mario[] PROGMEM FLASH_BITMAP;

// ─── Pacman
// ──────────────────────────────────────────────────────────────────────
#define F_PMAN1   1
#define W_PMAN1   8
extern const uint8_t pacman1[] PROGMEM FLASH_BITMAP;

#define F_PMAN2   1
#define W_PMAN2   8
extern const uint8_t pacman2[] PROGMEM FLASH_BITMAP;

// ─── Rocket
// ────────────────────────────────────────────────────────────────────
#define F_ROCKET  1
#define W_ROCKET  8
extern const uint8_t rocket[] PROGMEM FLASH_BITMAP;

// ─── Roll
// ──────────────────────────────────────────────────────────────────────
#define F_ROLL1   1
#define W_ROLL1   8
extern const uint8_t roll1[] PROGMEM FLASH_BITMAP;

#define F_ROLL2   1
#define W_ROLL2   8
extern const uint8_t roll2[] PROGMEM FLASH_BITMAP;

// ─── Sailboat
// ──────────────────────────────────────────────────────────────────
#define F_SAILBOAT 1
#define W_SAILBOAT 8
extern const uint8_t sailboat[] PROGMEM FLASH_BITMAP;

// ─── Steamboat
// ─────────────────────────────────────────────────────────────────
#define F_STEAMBOAT 1
#define W_STEAMBOAT 8
extern const uint8_t steamboat[] PROGMEM FLASH_BITMAP;

// ─── Walker
// ────────────────────────────────────────────────────────────────────
#define F_WALKER  1
#define W_WALKER  8
extern const uint8_t walker[] PROGMEM FLASH_BITMAP;

// ─── Wave
// ──────────────────────────────────────────────────────────────────────
#define F_WAVE    1
#define W_WAVE    8
extern const uint8_t wave[] PROGMEM FLASH_BITMAP;
