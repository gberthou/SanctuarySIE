if [ "$1" == "gdb" ]; then
	(cd ../resources/;gdb ../src/Debug/bin/SanctuarySIE)
elif [ "$1" == "valgrind" ]; then
	(cd ../resources/;valgrind ../src/Debug/bin/SanctuarySIE)
else
	(cd ../resources/;../src/Debug/bin/SanctuarySIE)
fi
