# My DWM 6.4 config
Forked from: [suckless.org](https://dwm.suckless.org/)

<img src="https://github.com/alex-karev/dwm/raw/main/screenshot.png">

## Features:
* Gaps with compositor(picom) integration to disable/enable round corners
* Dwmblocks integration
* Multiple monitors with single tagset
* Tabbar in the bottom in monocle mode
* Shiftview/tag patches applied, movestack patch applied
* Fullscreen support with switching between clients
* Bottomstack layouts
* Current screen indicator in status bar

## Applied patches:
* [Pertag](https://dwm.suckless.org/patches/pertag/)
* [Tab](https://dwm.suckless.org/patches/tab/)
* [Actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/)
* [Shiftview](https://lists.suckless.org/dev/1104/7590.html)
* [Focus Fullscreen](https://dwm.suckless.org/patches/focusfullscreen/)
* [Layoutscroll](https://dwm.suckless.org/patches/layoutscroll/)
* [Bottomstack](https://dwm.suckless.org/patches/bottomstack/)
* [Movestack](https://dwm.suckless.org/patches/movestack/)
* [Cursorwarp](https://dwm.suckless.org/patches/cursorwarp/)
* [Single tagset](https://dwm.suckless.org/patches/single_tagset/)
* [EWMHtags](https://dwm.suckless.org/patches/ewmhtags/)
* [Fullgaps](https://dwm.suckless.org/patches/fullgaps/)
* [Barpadding](https://dwm.suckless.org/patches/barpadding/)
* [Statuspadding](https://dwm.suckless.org/patches/statuspadding/)
* [Dwmblocks](https://github.com/torrinfail/dwmblocks)

## Custom changes:
* Shifttag - shift window to the next/previous tag
* Focus Fullscreen Pertag -  Make Focus Fullscreen to work as Pertag layout
* Barpadding with Fullgaps - Merge barpadding and fullgaps functionality
* Screen Indicator - Indicator which shows currently focused screen in bar
* Compositor integration - Restart compositor with different arguments depending on gaps
* Cut bar title - Cuts bar title to fit specified width
* Movefullscreen - fullscreen windows can be moved to another monitor