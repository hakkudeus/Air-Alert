# Air Alert
Air Alert is a homemade project made to improve my coding skills and learn more about old Windows (r) OS'es (especially 9x and 3.x) and DOS-like plus their networking capabilities.
This app is aimed at retro-PC fans, just like me.

I am NOT a professional coder, so I may have done basic mistakes and one of motivations to publish the source code was to improve the app with help of others and myself included.

Air Alert - is a live aerial threat tracker for Ukrainian territories, made as standalone Windows (r) app with old-fashioned design and environment. 
However, it does not surpass the official sources; in some cases, lacks some functionality: read the disclaimer.

![](https://cdn.bsky.app/img/feed_fullsize/plain/did:plc:d4dutltyznlhk2m7kv5t62c4/bafkreiht3pv2es3vfq6j2yf6z2xxufl2shnruy26bdcmjgqbeax7z52hry@jpeg)

# Disclaimer
As you may seen from the source code, it uses unofficial (currently) data source and it may be unreliable and as of now it lacks one of features, including:
* threat status for Crimea;
* sub-region threat statuses;
> **Do not** use this app as a main source of information. You may put it as a demonstration piece on your retro-workstation, however consider checking with official/professional sources.
 
Windows Defender might report the installer/app on modern OS'es (Windows 10 & 11) as suspicious due to (as far as i can guess) lack of digital certificates on executables. I have reported this issue to Microsoft, but if the problem persists and you know how to fix, let me know. 

# Build Requirements
Currently, there are two "branches" of development with different code, platform and language.
If you plan to build the app yourself, I would recommend using original environments to do so:
|                |Windows 9x (main branch)       |MS-DOS (secondary)           |
|----------------|-------------------------------|-----------------------------|
|Environment|`Borland Delphi 6.0`            |`Borland Turbo C (4.5)`            |
|Language|`Delphi (Object Pascal)`|`C (for app) and Batch script (for installer)`|
|Dependencies          |`IdBaseComponent, IdComponent, IdTCPConnection, IdTCPClient, IdHTTP, IdTime, Windows, IdException, plus 14 more` | `stdio, string, dos, stdlib, conio, time`           |
|External          |`-`|`mTCP TCP/IP Stack, ANSI.SYS/EXE`|

["Smart Install Maker"](http://www.sminstall.com/) was used to create an installer and ["HelpNDoc"](https://www.helpndoc.com/) to make help files for main branch releases.
Currently planning to switch to NSIS or InstallShield.

# Development Goals
|                |Main Branch (Windows 9x)       | Secondary Branch (MS-DOS)| Third Branch (W3.11)|
|----------------|-------------------------------|-|-|
|Main Functionality|`✅ Done`|`✅ Done`|`⚒ In progress`|
|Installer|`✅ Present (SIM), ⚒ Planned to switch to NSIS` |`⚒ In progress`|`?`|
|Multiple Resolutions  |`By Default`   |`⚒ In progress` |`?`|
|16 Color Support      |`By Default`|`⚒ In progress`|`?`|
|Settings Menu|`-`|`⚒ In progress`|`?`|
|Don't rely on mTCP|`-`|`⚒ To be planned`|`?`|
|Rewrite in C|`⚒ To be planned`|`✅ Already on C`|`?`|

A third branch is being planned to add Windows 3.11 support, however it's in too early stage and may be merged with one of previous ones/use their features or ideas. 
# System Requirements
If you plan to use my pre-built code, check up the requirements:
|                |Main Branch       |
|----------------|-------------------------------|
|OS|`Microsoft Windows 95 or greater`²            |
|Processor¹          |`Intel Pentium III`            |
|RAM¹          |`4 MB`|
|Graphics¹|`VGA-compatible video card (min. 640x480, 16 Color)`³
|Network|`NIC with Internet access through TCP/IP`

² This includes all the OS'es, inluding Windows 98, 2000, ME, XP, Vista, 7, 8, 8.1, 10, 11, all in-betweens after 95 (builds, etc), plus it can run on Linux through Wine.

|                |Secondary Branch       |
|----------------|-------------------------------|
|OS|`MS-DOS 3.10 or greater`            |
|Processor¹   |`Intel 8086`            |
|RAM¹          |`1 MB`|
|Graphics¹|`80x25 Monochrome or VGA-compatible video card (16 Color)`³
|Network|`NIC with Internet access through TCP/IP`
|Hardware|`Clock/calendar chip`⁴|
|Extra|`mTCP Config`⁵

¹ Some of parameters were not fully checked due to lack of real hardware and they were set to minimum OS requirements, so the real values may be even lower, like 486 Processor and etc.

³ CGA video card may work too, if it supports somewhat close to specified resolution and 16 Colors. 

⁴ Most modern motherboards include it by default, however on pre-AT machines or MS-DOS 3.10 (etc) it will require a setup solution to change date/time, if you have the chip.

⁵ An installer will attempt to add own if none found and insert a SET value to autoexec.bat, in case you never/don't use mTCP stack.
# Pre-packaged contents
If you have decided to download a pre-built package by me, you may have noticed it comes in two variants:
- IMA Floppy Image - authentical 1.44M image for retro workstation;
- ZIP Archive - for modern machines to be run out-of-box;
Their contents should be the same, including the app itself, "promo" materials, help files and installers. It does **not** come with source code.

# Outro
You contact me here through:
* the Issues page, 
* E-mail: kotsumehaku@gmail.com 
* Bluesky: https://bsky.app/profile/kotsumehaku.bsky.social

Currently looking for fellas with a real hardware to test on!
