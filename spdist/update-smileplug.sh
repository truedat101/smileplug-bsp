#!/bin/sh
version=0.0.2
spdir="$HOME/.smileplug"
spvdir="$spdir/$version"

updateFun() {
	echo Beginning update
	# Nothing to do in this version
	return 0
}

echo Running update-smilplug.sh $version 

if [ -d "$spdir" ]; then
	echo SMILE Plug version dir exists
else
	echo Creating SMILE Plug version dir
	mkdir $spdir
fi

if [ -d "$spvdir" ]; then
	echo SMILE Plug version $version exists, attempt update of newer version
	# 
	# Don't EVER CHANGE THIS URL
	#
	curl https://raw.github.com/SMILEConsortium/smileplug-bsp/master/spdist/update-smileplug.sh | sh
else
	echo SMILE Plug version $verson does not exist, update with current version
	mkdir -p $spvdir
	updateFun
	if [ "$?" ]; then
		echo Update completed
	else
		echo Update completed with errors
		echo If you feel you need to re-run, delete $spvdir
	fi
fi
