REM this script is not complete
REM Date: 2021-01-16
REM Author: Francesco Lazzarotto mailto:fralaz1971@gmail.com
bash configure
REM to be developed cmd batch configure.bat
REM cmd /c configure.bat
mingw32-make
mingw32-make install
mingw32-make clean
copy plot*.* bin
PAUSE


