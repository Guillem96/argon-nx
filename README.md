
<img src="img/splash.jpg" alt="banner">

![License badge](https://img.shields.io/badge/license-GPLv3-blue.svg)

## What Argon is?

Argon is a noble gas.
"Argon" comes from Greek "Argon", neuter of "argos" meaning *lazy* , *idle* or *inactive*.
Argon recieved this name because its chemical inactivity.

Argon NX is an immutable payload which is injected to your Nintendo Switch via Fusee Gelee exploit.

## Purpose 

The purpose of Argon NX is to stay immutable, so you can always inject it, without caring about other payloads getting updated (Always use ArgonNX for TegraSmash, TegraGUI, TrinkedM0 ...).

## How can it be?

When Argon NX is injected it automatically launches the `payload.bin` loacted at `argon` directory on your SD Card root. 

If `payload.bin` is not present or VOOLUME DOWN button is pressed on payload injection, Argon NX will list all payloads located at `argon/payloads`, and you will be able tp select one of theme to launch it.

## Features

- Autolaunch/autochainload the payload named `payload.bin` inside `argon` directory in your sd card root
- If `argon/payload.bin` is not found or `VOLUME_DOWN_BUTTON` is held during ArgonNX injection, ArgonNX lists all the payloads located at `argon/payloads`, so you can select one of them to launch it.
- Customize payloads' logos. **Logos must be smaller or equal than 200x200**. Example:
```
argon
  ├───logos
  │     default.bmp       # Default logo (logo for all payloads)
  │     fusee-primary.bmp # Logo for fusee-primary.bin payload
  │
  └───payloads
        fusee-primary.bin
        ReiNX.bin         # Will be rendered using default logo
```
- Custom background add a custom background by simply adding `background.bmp` file inside `argon` directory. **Background must be smaller than 1280x720**.
- Custom title add a custom title by simply adding `title.bmp` file inside `argon` directory. **Not an specific size for title**.

## About BMP format

The only format supported is **BMP 32 bit ARGB color**.
Color used for transparency is **#1D1919**.

## GUI

<img src="img/example.jpg" alt="example" width="500">

The sd card files of the image are:
```
argon
├─── payloads
│       fusee-primary.bin
│       ReiNX.bin
│       fusee-gelee.bin
│       hekate.bin
│       SXOS.bin
│       payload1.bin
│       payload3.bin
│       payload4.bin
│
├─── logos
|       fusee-primary.bmp
|       efault.bmp
|       Reinx.bmp
|       hekate.bmp
|       SXOS.bmp
|       fusee-gelee.bmp
├─── background.bmp
└─── title.bmp
```

## Improve performance

ArgonNX uses **minerva dram training** to improve performance.
Use of minerva is optional but recommended, to use minerva just place the compiled `minerva.bso` inside `argon/sys`. The directory `argon/sys` with minerva, is included in `sd-files.zip` in the release section.

## Compatibility

Works with all cfw payloads. 
Not tested with TeamXecuter SXOS payloat but it should work too.

## Roadmap

1. Touch input
2. Kind of config file
3. Change font

## Credits

* __devkitPro__ for the [devkitA64](https://devkitpro.org/) toolchain and libnx support.
* __naehrwert__ and __st4rk__ for the original [hekate](https://github.com/nwert/hekate) project and its hwinit code base.
* __CTCaer__ for the continued [hekate](https://github.com/CTCaer/hekate) and his **minerva** project.
* __SciresM__, __TuxSH__ and __hexkyz__ for the base hwinit code of Argon NX
* __xalgovia__ and __Retrogamer 74__ for the splash and logos. Also thanks them to use ArgonNX in RetroReloaded.

