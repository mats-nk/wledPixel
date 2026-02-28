# wledPixel
![img](https://raw.githubusercontent.com/widapro/wled-pixel-v2/master/img/wledPixel_logoPicS.jpeg)

MAX7219 LED dot matrix display driven by an ESP32 or ESP8266 MCU.

<a href="https://github.com/widapro/wled-pixel-v2/releases" target="_blank">The latest firmware version can be found in Releases</a>

## Supported key features:
1. **Home Assistant client** [display sensor values]
2. **OpenWeatherMap client** [display: temperature (C/F), humidity, pressure, wind speed, weather icon]
3. **MQTT client** [each display zone support own topic]
4. Display controll through MQTT
5. **Wall NTP clock** [NTP sync clock]
6. **Manual input**
7. **Stock Ticker Mode**: Display real-time stock prices on any zone. Supports multiple symbols, customizable display format, prefix/suffix, and price change arrows (↑↓)
8. Countdown timer
9. Full controll through **web UI**
10. Home Assistant MQTT discovery [When MQTT settings specified, device will be automatically send discovery message to HA]
11. Control display as light in Home Assistant [MQTT setup required]
12. Initial setup through wifi AP and web UI
13. Support 4 independent display zones
14. Support up to 12 display segments at the same time [configured in web UI]
15. Included 3 different fonts
16. Plus symbols font

## Web UI - Settings
![img](https://raw.githubusercontent.com/widapro/wled-pixel-v2/master/img/wledPixel_settingsS.jpeg)

## First boot:
> - Device will boot in wifi access point mode and show "AP Mode" on the display.
> - AP wifi name: **wledPixel-[short MAC address]**
> - AP wifi password: **12345678**
> - Connect to this AP and configure your wifi settings (connect to your wifi network)
> - When the device connects to the WIFI network, the device's IP address will be displayed on the zone0
> - Open the browser and go to the device IP address

## Wall clock
Wall clock mode support next following display options:
* `HH:MM`       - Hours : Minutes [21:43]
* `HH:MM:SS`    - Hours : Minutes : Seconds [21:43:54]
* `HH`          - Hours [21]
* `MM`          - Minutes [43]
* `dd.mm.yyyy`  - Day.Month.Year [21.06.2022]
* `dd.mm`       - Day.Month [21.06]
* `dd.mm aa`    - Day.Month weekday name (e.g., Sun) [21.06 Tue] *in Cyrillic font weekday name will be in Cyrillic
* `aa`          - Weekday name (e.g. Sun) *in Cyrillic font weekday name will be in Cyrillic

### Display Logic
* **If text fits in the zone:**
  - Displays statically.
  - Dots blink (unless disabled).
* **If text does NOT fit in the zone:**
  - Text scrolls completely until it disappears.
  - Screen remains blank for the duration of **Scroll Pause**.
  - Text starts scrolling again.
  - Dots do **NOT** blink to prevent interrupting the scroll cycle.

> **Note:** The **Scroll Effect Out** setting in the Web UI is disabled (greyed out) for Wall Clock mode because the loop animation doesn't use an exit effect.


## Scroll effect list
Default effects:
* `PA_RANDOM`
* `PA_PRINT`
* `PA_SCAN_HORIZ`
* `PA_SCROLL_LEFT`
* `PA_WIPE`
* `PA_SCAN_VERTX`
* `PA_SCROLL_UP_LEFT`
* `PA_SCROLL_UP`
* `PA_FADE`
* `PA_OPENING_CURSOR`
* `PA_GROW_UP`
* `PA_SCROLL_UP_RIGHT`
* `PA_BLINDS`
* `PA_CLOSING`
* `PA_GROW_DOWN`
* `PA_SCAN_VERT`
* `PA_SCROLL_DOWN_LEFT`
* `PA_WIPE_CURSOR`
* `PA_SCAN_HORIZX`
* `PA_DISSOLVE`
* `PA_MESH`
* `PA_OPENING`
* `PA_CLOSING_CURSOR`
* `PA_SCROLL_DOWN_RIGHT`
* `PA_SCROLL_RIGHT`
* `PA_SLICE`
* `PA_SCROLL_DOWN`
* `PA_SPRITE` (Generic)

### Custom effects (Sprites)
* `PACMAN`
* `WAVE`
* `ROLL`
* `LINES`
* `ARROW`
* `SAILBOAT`
* `STEAMBOAT`
* `HEART`
* `INVADER`
* `ROCKET`
* `FBALL`
* `CHEVRON`
* `WALKER`
* `MARIO` (New!)
* `GHOST` (New!)
* `DINO` (New!)

## Demo Video
<a href="https://youtu.be/0IlsjbE2lU0" target="_blank">Watch the effects demo on YouTube</a>

