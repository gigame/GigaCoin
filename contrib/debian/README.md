
Debian
====================
This directory contains files used to package gigacoind/gigacoin-qt
for Debian-based Linux systems. If you compile gigacoind/gigacoin-qt yourself, there are some useful files here.

## gigacoin: URI support ##


gigacoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install gigacoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your gigacoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/gigacoin128.png` to `/usr/share/pixmaps`

gigacoin-qt.protocol (KDE)

