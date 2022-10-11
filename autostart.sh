#!/bin/bash

pkill xbanish
pkill picom

nitrogen --restore
xbanish &
picom &
