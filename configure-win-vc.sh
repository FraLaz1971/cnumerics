#/usr/bin/env bash
echo "generating total makefile for $(uname) $OS ..." >/dev/stderr
a=0;t=0;TARGETS=
EEXT=.exe
OEXT=.obj
echo 'LDFLAGS ='
echo 'LIBS = '
echo 'INCS = '
echo 'CXXINCS =  '
echo 'CXXFLAGS = '
echo 'CFLAGS = '
echo 'RM = del /F /Q '
echo 'MV = move /Y '
echo 'CP = copy /Y /B '
echo 'CXX  = cl'
echo 'CC   = cl'
echo 'EEXT   = .exe'
echo 'OEXT   = .obj'
echo 'SRC = $(SRC:.c=.obj)'
echo "OBJ = *"$OEXT
echo 'CPPFLAGS = /W4'
echo 'LDFLAGS = '

for t in $(ls -1 *.c)
do
	TARGET=$(basename ${t%.*})
	echo 'TARGET'$a = $TARGET
	TARGETS="$TARGET $TARGETS"
	RMTARGETS="$TARGET$EEXT $RMTARGETS"
	CPTARGETS="$TARGET$EEXT+$CPTARGETS"
	a=$(($a+1)) 
done
	echo 'TARGETS' = $TARGETS
	echo 'RMTARGETS' = $RMTARGETS
	echo 'CPTARGETS' = $CPTARGETS
	echo 'all: $(RMTARGETS)'
a=0
for s in $(ls -1 *.c)
do
	TARGET=$(basename ${s%.*})
	if [[ $TARGET != "analysis" ]]
	then
		echo '$(TARGET'$a')$(EEXT):'
		echo -e "\t"'$(CC) $(TARGET'$a').c  /link  /out:'$TARGET$EEXT' $(LDFLAGS)'
	else
		echo 'analysis:'
	fi
	a=$(($a+1)) 
done
	echo 'echo created all targets' >/dev/stderr
	echo 'install: all'
    echo -e '\t$(CP) *.exe bin'
    echo -e '\t$(CP) *.obj obj'
    echo -e '\t$(RM) $(RMTARGETS)'
    echo -e '\t$(RM) $(OBJ)'
	echo '.PHONY: clean'
	echo 'clean:'
	echo -e "\t"'$(RM) $(OBJ) $(RMTARGETS)'
	echo 'distclean: clean'
    echo -e "\t"'cd bin && $(RM) *$(EEXT) && cd .. $(RM) Makefile*'
    echo "generating dirs" >/dev/stderr
if ! test -d bin; then mkdir  bin; fi
if ! test -d obj; then mkdir  obj; fi
