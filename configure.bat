#!/usr/bin/env bash
chmod +x *.sh
if   [[ "$OS" == "Windows_NT" ]]
then
        echo "detected Microsoft $OS $(uname)"
        . configure-win-mingw.sh > Makefile.mingw
	cp Makefile.mingw Makefile
elif [[ $(uname) == "Linux" ]]
then
        echo "detected GNU/linux $OS"
        uname -a
        lsb_release -a
        . configure.sh > Makefile.lnx
	cp Makefile.lnx Makefile
elif [[ $(uname) == "Darwin" ]]
then
        echo "detected Apple $OS $(uname)"
        . configure-mac.sh > Makefile.mac
else
        echo "unknow OS"
fi
echo "generated Makefile"
ls -lhrt Makefile*
echo "project cnumerics configured"
echo "you can now run:"
echo "make"
echo "to see all generate files type:"
echo "ls -alhrt"
date

