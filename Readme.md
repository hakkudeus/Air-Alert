# Air Alert
#### **Do not** use this app as a main source of information. This app is made for my personal educational purposes, thus it may or may not add a significant delay while receiving data due to unoptimized code, outdated OS, lack of computing resources, etc; and it may not be addressed (fixed) by me instantly or quick enough, due to personal lack of time. As of now, it uses unofficial API, though in any case you should not 100% rely on this app. You may put it as a demonstration piece on your retro-workstation, however consider always checking official/professional sources.

> **Notice:** The app is currently broken due to some API being updated and some outdated that I currently cannot keep up with. DOS-version might take longer time to update its code.

Air Alert is a homemade project made to improve my coding skills and learn more about old Windows (r) OS'es (especially 9x and 3.x) and DOS-like plus their networking capabilities.
This app is aimed at retro-PC fans, just like me.

I am not a professional coder, so I may have done basic mistakes so one of motivations to publish the source code was to improve the app with help of others and myself included.

**Air Alert** - is a live aerial threat tracker for Ukrainian territories, made as a standalone Windows (r) app with old-fashioned design and environment. 
However, it does not surpass the official sources; in some cases, lacks some functionality: read the disclaimer.

![](https://cdn.bsky.app/img/feed_fullsize/plain/did:plc:d4dutltyznlhk2m7kv5t62c4/bafkreiht3pv2es3vfq6j2yf6z2xxufl2shnruy26bdcmjgqbeax7z52hry@jpeg)

> API Source: https://ubilling.net.ua

# Disclaimer
As you may have seen from the source code, it uses unofficial (currently) data source and it may be unreliable and as of now it lacks one of features, including:
* threat status for Crimea (it's always set to on, as of now);
* sub-regions threat statuses;
> **Do not** use this app as a main source of information. You may put it as a demonstration piece on your retro-workstation, however consider always checking official/professional sources.
 
Windows Defender might report the installer/app on modern OS'es (Windows 10 & 11, or technically any other OS with an antivirus) as suspicious due to (as far as i can guess) lack of digital certificates on executables. I have reported this issue to Microsoft, but if the problem persists and you know how to fix, let me know. 

# Build Requirements
Currently, there are two "branches" of development with different code, platform and language.
If you plan to build the app yourself, I would recommend using original environments to do so:
|                |Windows 9x (main branch)       |MS-DOS (secondary)           |
|----------------|-------------------------------|-----------------------------|
|Environment|`Borland Delphi 6.0`            |`Borland Turbo C (4.5)`            |
|Language|`Delphi (Object Pascal)`|`C (for app) and Batch script (for installer)`|
|Dependencies          |`Basic Components (IdBaseComponent, IdComponent, IdTCPConnection, IdTCPClient, IdHTTP, IdTime, Windows, IdException, plus 14 more)` | `stdio, string, dos, stdlib, conio, time`           |
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
|Fullscreen Mode|`?`|`By Default`|`?`|
|No Connection detector|`✅ Pauses the program`|`⚒ To be planned`|`?`|
|Rewrite in C|`⚒ To be planned`|`✅ Already on C`|`?`|

A third branch is being planned to add Windows 3.11 support, however it's in too early stage and may be merged with one of previous ones/use their features or ideas. 
# Features
## Windows 95+
* Portable app "out-of-box" capabilities (additionally pre-made installer is provided);
* Graphical map with active regions displayed;
* Auto and manual update;
* Date & time display;
* Graphical time icons;
* Status list by regions;
* "Days since" counter;
* Help file and installer (built with external tools);
  
![bafkreibaa4cxif6cpb34rxuszt4jl2qy3yvn3ftxoauqjbktfshkaq5mvm](https://github.com/user-attachments/assets/50809efe-c551-49c1-b9ea-95fd543ce4ce)

## DOS
* Pretty much the same features, except fullscreen only (for obvious reasons);
* 16 Color **(coming soon)** and Monochrome Mode;
* Ability to change graphical characters and their color **(coming soon)**;
* Ability to change between 25 and 50 lines mode **(coming soon, 25 by default)**;

![image](https://github.com/user-attachments/assets/2007d5d4-dec5-4791-8d9b-a4ab6cb60e87)


# System Requirements
If you plan to use my pre-built code, check up the requirements:
|                |Main Branch       |
|----------------|-------------------------------|
|OS|`Microsoft Windows 95 or greater`²            |
|Processor¹          |`Intel Pentium III`            |
|RAM¹          |`4 MB`|
|Graphics¹|`VGA-compatible video card (min. 640x480, 16 Color)`³
|Network|`NIC with Internet access through TCP/IP`

² This includes all the OS'es, including Windows 98, 2000, ME, XP, Vista, 7, 8, 8.1, 10, 11, all in-betweens after 95 (builds, etc), plus it can run on Linux through Wine.

|                |Secondary Branch       |
|----------------|-------------------------------|
|OS|`MS-DOS 3.10 or greater`³           |
|Processor¹   |`Intel 8086`            |
|RAM¹          |`1 MB`|
|Graphics¹|`80x25 Monochrome or VGA-compatible video card (16 Color)`⁴
|Network|`NIC with Internet access through TCP/IP`
|Hardware|`Clock/calendar chip`⁵|
|Extra|`mTCP Stack`⁶

¹ Some of the parameters were not fully checked due to lack of real hardware and they were set to minimum OS requirements, so the real values may be even lower, like 486 Processor and etc.

³ It can run on pretty much all MS-DOS versions, however older than 3.10 were not tested. It can also run on OS'es *with DOS apps support*, which includes Windows 95, 98, 2000, ME and XP. Windows 3.x is out of this list, unfortunately it won't work - it's quite complicated.

⁴ Monochrome adapter will be enough for now, since there are no colors in the app yet. CGA video card may work too, if it supports somewhat close to specified resolution and 16 Colors. 

⁵ Most modern motherboards include it by default, however on pre-AT machines or MS-DOS 3.10 (etc) it will require a setup solution to change date/time, if you have the chip. More info in the next chapter below.

⁶ It is preferable to use mTCP stack as a networking tool here, due to hard-coded dependency of one of it's HTTP request apps. If mTCP was not found, an installer will attempt to add own and insert a SET value to autoexec.bat, in case you never/don't used the tool.
# Notes on MS-DOS
## mTCP dependency
This project is currently tied to one of mTCP networking app's, namely HTGET, which performs HTTP requests. The reason why is mTCP stack required or its parts is due to needing of their config file, which specifies system interrupts and other values for your network card. Currently, I plan to modify the HTGET to be hardcoded onto a copy of mTCP config located at the app directory so it won't conflict with a real mTCP stack (except TSRs possibly) and won't confuse a user with an odd "mTCP" folder and an autoexec.bat string that he never installed.

As of now, I have written a quick guide on how to properly install mTCP (config), it's in Release package's readme and here is the part with explanations:

>This program relies on the HTGET executable that is a part of mTCP stack.

>If you have never used mTCP, it requires its config file to be specified 
in autoexec.bat file of your DOS using a SET command. You do not need to 
store full mTCP package on your hard disk, you only need the previously 
mentioned file and DHCP.EXE tool if you wish to add IP settings 
automatically.

>1) To install a config file, you can copy it from the installation media for
this program to any directory you want and add the next line to autoexec.bat:

>`set MTCPCFG = [DIRECTORY]\config.cfg`

>Name and extension can be anything, it will be read successfully. 

>2) Next step is specifying packet manager interrupt integer (default: 0x60)
in the config file. Then you will need to scroll to the bottom and input
your IP settings manually, or as said before use a DHCP.EXE tool from mTCP
package

***tldr;** you need an mTCP config with NIC packet manager interrupt code and DHCP (or manual IP & gateway address, etc) info into it and set the location of the config in your autoexec.bat file;*

## Date and Time

>It is necessary to have the correct date and optionally the time.

>If you have an incorrect date set on your PC, the program will exit with
an according message. Date is being used in calculation that is displayed 
on the screen and data receiving, thus having wrong date will corrupt it. 
On the other hand, time may be set to any value if it meets the current 
day frame.

>While running the app on pre-AT system and/or for example MS-DOS 3.10,
make sure the date and time is being saved to your clock chip and you have
the corresponding utilities to address the chip.

>Even though you are able to set the date before the real one, the 
calculation will succeed, but the data will be still corrupted. The app 
does not check the date and time using network, it is up to you.

To prevent garbage data, I have added a kill-switch that exits the program if the year is set to less than 2023 (in newer versions, it's set to 24.02.2022).

***tldr;** set your date and (optionally) time correctly or somewhat close to it;*

# Pre-packaged contents
If you have decided to download a pre-built package by me, you may have noticed it comes in two variants (since v. 1.0.1):
- IMA Floppy Image - authentical 1.44M image for retro workstation;
- ZIP Archive - for modern machines, to be run out-of-box;
Their contents should be the same, including the app itself, "promo" materials, help files and installers. Source code does **not** come with it.

Planned: separate IMA into 2 editions: portable & full.

# Outro
You contact me here through:
* the Issues page, 
* E-mail: kotsumehaku@gmail.com 
* Bluesky: https://bsky.app/profile/kotsumehaku.bsky.social

Currently looking for fellas with a real hardware to test on!
