# DOOM for arm64 macOS

This is a fork of the original DOOM source code for linux ported to run on macOS for Apple Silicon based Macs.

![Alt text](/ScreenShot.jpg?raw=true "DOOM Running on macOS High Sierra!")

## Requirements

* You'll likely need a copy of xQuartz (http://xquartz.org/) if you're using a newer version of macOS.
* For display game you need xephyr `brew install xephyr`
* For sounds, you need portaudio `brew install portaudio`

# Building the Sound Server

1. Navigate the sndserv folder with `cd sndserv`
2. Create a directory for your build `mkdir linux`
3. In Makefile you need change path to portaudio library , in my case its `/opt/homebrew/Cellar/portaudio/19.7.0/`
4. Compile your `make`
5. Put build files near `.wad` file

# Building the project

1. Navigate the linuxdoom-1.10 folder with `cd linuxdoom-1.10`
2. Create a directory for your build `mkdir linux`
3. Compile your `make`
4. Copy over a file `.wad` file.
5. Run Doom with `./doom.sh`

