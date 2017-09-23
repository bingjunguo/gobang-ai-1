#!/bin/bash
# gitpush.sh
# Time ：2017-8-30 
# Author Weifei

if [ ! -n "$1" ] ;then
		echo "you have not input a commit word!"
			exit 1
else
	echo "the commit you input is $1"
	echo "copy file to client..."
	cd ./src 
	cp * ../test/client/JustDraw/
	echo "ok..."

	cd ..
	git add -A
	git commit -m "$1"
	git push
fi

exit 0
