// Optimized Bitmaps.h
#pragma once
#include <Arduino.h>

#if defined(ESP8266)
  #define FLASH_BITMAP PROGMEM
#else
  #define FLASH_BITMAP PROGMEM
#endif

// ─── Arrow
extern const uint8_t arrow1[] FLASH_BITMAP;
constexpr uint8_t ARROW1_FRAMES = 3;
constexpr uint8_t ARROW1_WIDTH  = 10;
constexpr size_t  ARROW1_SIZE   = 30;

extern const uint8_t arrow2[] FLASH_BITMAP;
constexpr uint8_t ARROW2_FRAMES = 3;
constexpr uint8_t ARROW2_WIDTH  = 9;
constexpr size_t  ARROW2_SIZE   = 27;

// ─── Chevron
extern const uint8_t chevron[] FLASH_BITMAP;
constexpr uint8_t CHEVRON_FRAMES = 1;
constexpr uint8_t CHEVRON_WIDTH  = 9;
constexpr size_t  CHEVRON_SIZE   = 9;

// Dino
extern const uint8_t dino[] FLASH_BITMAP;
constexpr uint8_t DINO_FRAMES = 1;
constexpr uint8_t DINO_WIDTH  = 8;
constexpr size_t  DINO_SIZE   = 8;

// Fireball
extern const uint8_t fireball[] FLASH_BITMAP;
constexpr uint8_t FBALL_FRAMES = 2;
constexpr uint8_t FBALL_WIDTH  = 11;
constexpr size_t  FBALL_SIZE   = 22;

// Ghost
extern const uint8_t ghost[] FLASH_BITMAP;
constexpr uint8_t GHOST_FRAMES = 1;
constexpr uint8_t GHOST_WIDTH  = 8;
constexpr size_t  GHOST_SIZE   = 8;

// Heart
extern const uint8_t heart[] FLASH_BITMAP;
constexpr uint8_t HEART_FRAMES = 5;
constexpr uint8_t HEART_WIDTH  = 9;
constexpr size_t  HEART_SIZE   = 45;

// Invader
extern const uint8_t invader[] FLASH_BITMAP;
constexpr uint8_t INVADER_FRAMES = 2;
constexpr uint8_t INVADER_WIDTH  = 10;
constexpr size_t  INVADER_SIZE   = 20;

// Lines
extern const uint8_t lines[] FLASH_BITMAP;
constexpr uint8_t LINES_FRAMES = 1;
constexpr uint8_t LINES_WIDTH  = 24;
constexpr size_t  LINES_SIZE   = 24;

// Mario
extern const uint8_t mario[] FLASH_BITMAP;
constexpr uint8_t MARIO_FRAMES = 1;
constexpr uint8_t MARIO_WIDTH  = 8;
constexpr size_t  MARIO_SIZE   = 8;

// Pacman1
extern const uint8_t pacman1[] FLASH_BITMAP;
constexpr uint8_t PACMAN1_FRAMES = 6;
constexpr uint8_t PACMAN1_WIDTH  = 8;
constexpr size_t  PACMAN1_SIZE   = 48;

// Pacman2
extern const uint8_t pacman2[] FLASH_BITMAP;
constexpr uint8_t PACMAN2_FRAMES = 14;
constexpr uint8_t PACMAN2_WIDTH  = 8;
constexpr size_t  PACMAN2_SIZE   = 112;

// Rocket
extern const uint8_t rocket[] FLASH_BITMAP;
constexpr uint8_t ROCKET_FRAMES = 2;
constexpr uint8_t ROCKET_WIDTH  = 11;
constexpr size_t  ROCKET_SIZE   = 22;

// Roll1
extern const uint8_t roll1[] FLASH_BITMAP;
constexpr uint8_t ROLL1_FRAMES = 4;
constexpr uint8_t ROLL1_WIDTH  = 8;
constexpr size_t  ROLL1_SIZE   = 32;

// Roll2
extern const uint8_t roll2[] FLASH_BITMAP;
constexpr uint8_t ROLL2_FRAMES = 4;
constexpr uint8_t ROLL2_WIDTH  = 8;
constexpr size_t  ROLL2_SIZE   = 32;

// Sailboat
extern const uint8_t sailboat[] FLASH_BITMAP;
constexpr uint8_t SAILBOAT_FRAMES = 1;
constexpr uint8_t SAILBOAT_WIDTH  = 11;
constexpr size_t  SAILBOAT_SIZE   = 11;

// Steamboat
extern const uint8_t steamboat[] FLASH_BITMAP;
constexpr uint8_t STEAMBOAT_FRAMES = 2;
constexpr uint8_t STEAMBOAT_WIDTH  = 11;
constexpr size_t  STEAMBOAT_SIZE   = 22;

// Walker
extern const uint8_t walker[] FLASH_BITMAP;
constexpr uint8_t WALKER_FRAMES = 5;
constexpr uint8_t WALKER_WIDTH  = 7;
constexpr size_t  WALKER_SIZE   = 35;

// Wave
extern const uint8_t wave[] FLASH_BITMAP;
constexpr uint8_t WAVE_FRAMES = 24;
constexpr uint8_t WAVE_WIDTH  = 8;
constexpr size_t  WAVE_SIZE   = 192;
