smileplug-bsp
=============

This is a bunch of initial config.  This will include a set of configs to be applied in the BSP.

Pacman Package Manifest
=======================
* nodejs
* openssl
* make
* gcc
* sysstat (we just use sar)
* python2 (? - TBD)
* python2-distribute
* python2-pyopenssl
* jdk (? TBD)
* git (for testing ... will consider leaving this in)

> pacman -S openssl gcc nodejs make

NPM Modules:
* forever (install in global)
* forever-webui (npm package is busted, use BETA, off HEAD of https://github.com/SMILEConsortium/forever-webui.git) , wget https://nodeload.github.com/FGRibreau/forever-webui/tarball/master , install dependencies, access on port 8085
* sm (XXX TBD, may need this to get a decent cloud9ide install done)

Scripts:
* dhcpd-status.sh -> /root/spdist/dhcpd-pool-0.2/dhcpd-status-arch.sh

General Config
==============
* Standard root password: root // XXX CHANGE ME
* .bashrc in /root is used
* set default root PATH to include ~/root/bin


Open Ports
==========
* 80 (SMILE and JS.js) - We really need to put all of this behind a reverse proxy
* 8009 (Gateone on https)
* 8085 (forever-webui)
* 9080 (plugmin WS/Web UI)
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
* GateOne: https://github.com/liftoff/GateOne, forked on : https://nodeload.github.com/SMILEConsortium/GateOne/tarball/master (need to evaluate this Affereo GPL)
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
