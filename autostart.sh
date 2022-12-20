#!/bin/bash

pkill xbanish
pkill picom

nitrogen --restore
xbanish &
picom &

eww kill
eww daemon
eww open bar0
eww open bar1
