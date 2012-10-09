smileplug-bsp
=============

This is a bunch of initial config.  This will include a set of configs to be applied in the BSP.

Package Manifest
================
* nodejs
* openssl
* make
* gcc
* python2 (? - TBD)
* python2-distribute
* python2-pyopenssl
* jdk (? TBD)

> pacman -S openssl gcc nodejs make

NPM Modules:
* forever (install in global)
* forever-webui (npm package is busted, use BETA, off HEAD of https://github.com/SMILEConsortium/forever-webui.git) , wget https://nodeload.github.com/FGRibreau/forever-webui/tarball/master , install dependencies, access on port 8085
* sm (TBD, may need this to get a decent cloud9ide install done)

Open Ports
==========
* 80 (SMILE and JS.js)
* 8085 (forever-webui)
* 5000 (epochedu) 

Python Modules:
* curl -O http://python-distribute.org/distribute_setup.py
* sudo python distribute_setup.py
* sudo easy_install pip
* sudo pip install virtualenv
* sudo pip install virtualenvwrapper
* tornado
* kerberos

Additional Software:
* GateOne: https://github.com/liftoff/GateOne, forked on : https://nodeload.github.com/SMILEConsortium/GateOne/tarball/master
* virtualenv goenv
* . ./goenv/bin/activate
* pip install tornado
* pip install kerberos


I've also added for testing:

* iperf
* ntop
* afps-fs (may consider adding this to above list)

Some manual commands to run in the configuration of a new BSP based on arch:

    # This generates the /usr/lib/ufw/user.conf commands used to store the rules
    ufw allow from 10.0.0.0/24
    ufw allow from 10.1.0.0/24
