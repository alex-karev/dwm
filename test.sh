#/bin/bash
# Test dwm in nested X11 session
Xephyr -br -ac -noreset -screen 1920x1080 :1 &
sleep 0.5
DISPLAY=:1
dwm
