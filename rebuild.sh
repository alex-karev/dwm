#!/bin/bash
# Rebuilds and Reinstalls dwm
make clean && make && sudo make install && killall dwm