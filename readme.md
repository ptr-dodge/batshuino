# Batshuino
> Run batsh scripts through an Arduino Rubber Ducky!

This Project includes tools that will help you run batsh scripts using an Adruino Pro Micro, on _any system_. This can be useful for HID automation tasks, or goofing around. The interesting idea is that, instead of using a commercially available USB Rubber Ducky, I can buy a cheap arduino and program it to run batsh!

---
Duckyscript is very powerful, but it seldom works on arduinos
With this, you still get an easy, but powerful shell scripting language, that you can directly use with an HID compatible arduino.

## About
> Only works on Windows for the moment

This project uses two of my previous projects, to connect them in a new way.

The way this works is
1. `batsh.py` uses the [batsh api](https://batsh.org/compile) to compile the batsh script to a batch file.
1. `batuino.py` uses a template Arduino script inside the python code to open a cmd prompt, and run all the commands in the batch file. This outputs a `.ino` file that we can upload to our arduino

## Dependencies
-   Arduino (for uploading code)
-   This repo
-   python 3

## How to use
```bash
python batshuino.py -i test.batsh -o test.ino
```

## Todo
-   get shell scripts working