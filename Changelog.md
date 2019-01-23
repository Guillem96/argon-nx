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
