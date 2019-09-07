# Changelog

## v0.2

- Cancel autolaunch/autochainloading of `argon/payload.bin` by holding VOL_DOWN_BUTTON when ArgonNX is booting.
- Minerva training to improve performace.
- Custom background. Just place your custom background inside `argon` directory and name it `background.bmp`. Use of custom background is optional.
- Custom title. Just place your custom title inside argon directory and name it `title.bmp`. Use of custom title is optional.
- By default ArgonNX uses dark background instead of the white one in v0.1.
- Payloads' names now are centered below the logo.
- Partial touch support. To enable touch support create an empty file called `touch` inside `argon` directory.
- Take Screenshots to share your argon configuration! 
- Improve system stability to enhance user experience.

## v0.3

- Now background must be in a vertical position. New background size must be smaller or equal than 720x1280. (Performance reasons)
- Using double buffering for rendering in order to avoid flickering and also improve performance.
- Fully touch support. Thanks to @pixel-stuck
- Now payloads are sorted by name.
- Correctly deallocate argon-nx from memory when launching payloads.
- Improve system stability to enhance user experience.

## v1.0-alpha

- ArgonNX's UI has been rewritten using [LittlevGL]() library. This rewrite has a lot of benefits. Some benefits include:
    - Prettier font
    - Faster rendering
    - Better touch support
    - In general terms improves UX
- Now payloads are listed inside tabviews where each tab contains a group of 4 payloads.
- New tab of tools. By now tools only are related to reboot stuff (reboot to rcm, power off, reboot to ofw)
- Background size back to 1280*720. No more weird image flippings.
- ArgonNX Command Line Interface to simplify the process to create logos and backgrounds.
- Now there is no need to declare a `default.bmp` logo inside the `argon/logos` directory.
- Improve system stability to enhance user experience.

## v1.1-alpha

- Fixing critical bug. Now launches using any payload sender.
- Argon now is composed by 2 payloads (2 stages).
    1. First stage configures hardware
    2. Loads the GUI
- Bootlogo/splash and wait until GUI is loaded.
- Improve system stability to enhance user experience.
