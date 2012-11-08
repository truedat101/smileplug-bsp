#!/bin/sh
version=0.0.5
# Use /tmp so that we can be sure that this is blown away between reboots
spdir="/tmp/.smileplug"
spvdir="$spdir/$version"
spvupscript="$spvdir/update-smileplug.sh"

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
	if [ ! -d "$spvupscript" ]; then
		echo SMILE Plug version $version installed, attempt update of newer version
		# 
		# Don't EVER CHANGE THIS URL
		#
		curl -o $spvdir/update-smileplug.sh https://raw.github.com/SMILEConsortium/smileplug-bsp/master/spdist/update-smileplug.sh
 		sh $spvupscript	
	else
		echo Nothing to update
		echo If you feel you would like to update, delete $spvupscript 
	fi
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
