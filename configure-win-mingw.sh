#/usr/bin/env bash
echo "generating total makefile for $(uname) $OS ..." >/dev/stderr
a=0;t=0;TARGETS=
EEXT=.exe
OEXT=.o
echo 'LDFLAGS =  -L"."  -g'
echo 'LIBS = '
echo 'INCS =  -I"."'
echo 'CXXINCS =  -I"include"'
echo 'CXXFLAGS = $(CXXINCS)   -g'
echo 'CFLAGS = $(INCS) -std=c99  -g'
echo 'RM = rm -f'
echo 'CXX  = x86_64-w64-mingw32-g++ -g -O2'
echo 'CC   = x86_64-w64-mingw32-gcc -g -O2'
echo 'SRC = $(wildcard *.c)'
echo "OBJ = *"$OEXT
echo 'CPPFLAGS = -Iinclude'
echo 'LDFLAGS = -Llib -lm'

for t in $(ls -1 *.c)
do
	TARGET=$(basename ${t%.*})
	echo 'TARGET'$a = $TARGET$EEXT
	TARGETS="$TARGET$EEXT $TARGETS"
	a=$(($a+1)) 
done
	echo 'TARGETS' = $TARGETS
	echo 'all: $(TARGETS)'
a=0
for s in $(ls -1 *.c)
do
	TARGET=$(basename ${s%.*})
	echo '$(TARGET'$a')'$OEXT': '$TARGET'.c'
	echo -e "\t"'$(CC) -c   $< -o '$TARGET$OEXT' $(CPPFLAGS)'
	if [[ $TARGET != "analysis" ]]
	then
		echo '$(TARGET'$a'): '$TARGET$OEXT
		echo -e "\t"'$(CC) -o '$TARGET$EEXT' $< $(LDFLAGS)'
	else
		echo 'analysis:'
	fi
	a=$(($a+1)) 
done
	echo 'echo created all targets' >/dev/stderr
	echo 'install: all'
        echo -e '\tmv $(TARGETS) bin'
	echo '.PHONY: clean'
	echo 'clean:'
	echo -e "\t"'rm -f $(OBJ) $(TARGETS) *.log'
	echo 'distclean: clean'
        echo -e "\trm -f bin/* Makefile"
echo "generating dirs" >/dev/stderr
if ! test -d bin; then mkdir  bin; fi
