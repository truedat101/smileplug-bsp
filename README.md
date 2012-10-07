smileplug-bsp
=============

This is a bunch of initial config.  This will include a set of configs to be applied in the BSP.

Package Manifest
================
* nodejs
* openssl
* make
* gcc

> pacman -S openssl gcc nodejs make

NPM Modules:

    console.io

I've also added for testing:

* iperf
* ntop
* afps-fs (may consider adding this to above list)

Some manual commands to run in the configuration of a new BSP based on arch:

    # This generates the /usr/lib/ufw/user.conf commands used to store the rules
    ufw allow from 10.0.0.0/24
    ufw allow from 10.1.0.0/24
