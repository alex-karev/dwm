# My DWM 6.4 config
Forked from: [suckless.org](https://dwm.suckless.org/)

<img src="https://github.com/alex-karev/dwm/raw/main/screenshot.png">

## Table of Contents
1. [Features](#features)
2. [Installation](#installation)
3. [Configuration](#configuration)
4. [Applied patches](#applied-patches)
5. [Custom changes](#custom-changes)

## Features
* Gaps with compositor(picom) integration to disable/enable round corners
* Dwmblocks integration
* Multiple monitors with single tagset
* Tabbar in the bottom in monocle mode
* Shiftview/tag patches applied, movestack patch applied
* Fullscreen support with switching between clients
* Bottomstack layouts
* Current screen indicator in status bar

## Installation
1. Install dependencies:

```
sudo pacman -S wireless_tools acpi top flameshot rofi trayer dunst pamixer libcanberra xorg-xbacklight
```

2. Clone this repo, build and install dwm:

```
git clone https://github.com/alex-karev/dwm.git
cd dwm
make
sudo make install
```

3. Make scripts in ```scripts``` directory executable and copy them to ```~/.local/bin/``` *(or wherever you store your scripts)*:

```
chmod +x scripts/*
cp scripts/* ~/.local/bin/
cp statbar.conf ~/.config/statbar.conf
```

4. *OPTIONAL:* Add ```$HOME/.local/bin``` to path

5. Configure and install ```dwmblocks-async``` or any other dwmblocks implementation:
```
git clone https://github.com/UtkarshVerma/dwmblocks-async.git
cd dwmblocks-async
```

Change dwmblocks' ```config.h``` to something like this:
```
#define CMDLENGTH 45
#define DELIMITER "  "
#define CLICKABLE_BLOCKS

const Block blocks[] = {
        BLOCK("statbar --wireless",   3,    18),
        BLOCK("statbar --battery",   10,    18),
        BLOCK("statbar --cpu",   2,    18),
        BLOCK("statbar --ram",   5,    18),
        BLOCK("statbar --date",   60,    18),
        BLOCK("statbar --time",   5,    18)
};
```

Compile and install dwmblocks:
```
sudo make install
```

6. Add dunst, dwmblocks and dwm to your ```.xinitrc```:

```
/usr/bin/dunst -conf $HOME/.config/dunst/dunstrc &
dwmblocks &
exec dwm-start
```

7. *OPTIONAL:* Copy dunstrc to ```~/.config/dunst/```:
```
mkdir ~/.config/dunst
cp dunstrc ~/.config/dunst/dunstrc
```

8. *OPTIONAL:* For rounded corners support use [this](https://github.com/ibhagwan/picom-ibhagwan-git.git) fork of ```picom```

## Configuration
* Edit ```config.h``` to change keybindings, appearance and default apps. Recompile and reinstall dwm.
* Edit ```~/.config/statbar.conf``` to change the appearance and functionality of the status bar widgets.
* Edit dwmblocks' ```config.h``` to configure the status bar. Recompile and reinstall dwmblocks.
* Edit ```~/.config/dunst/dunstrc``` to change the appearance of dunst (Sound and Brightness change notifications)
* To quickly rebuild and reinstall dwm use ```rebuild.sh```
* To test dwm in nested xsession install ```Xephyr``` and run ```test.sh```

## Applied patches
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
* [Alwayscenter](https://dwm.suckless.org/patches/alwayscenter/)

## Custom changes
* Shifttag - shift window to the next/previous tag
* Focus Fullscreen Pertag -  Make Focus Fullscreen to work as Pertag layout
* Barpadding with Fullgaps - Merge barpadding and fullgaps functionality
* Screen Indicator - Indicator which shows currently focused screen in bar
* Compositor integration - Restart compositor with different arguments depending on gaps
* Cut bar title - Cuts bar title to fit specified width
* Movefullscreen - fullscreen windows can be moved to another monitor
* Improved cursorwarp - works even when there are no windows on another monitor
* Gaming mode - switch compositors for gaming