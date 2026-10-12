#!/bin/bash
# Demo script: backup helper
NAME="World"
COUNT=0
EMPTY=
readonly PI=3

greet() {
    echo "Hello, $1!"
    return 0
}

function add {
    local a=$1
    local b=$2
    echo $((a + b))
}

greet $NAME
export PATH=$PATH:/usr/local/bin

if [ -f "/etc/passwd" ] && [ $COUNT -eq 0 ]; then
    echo "file exists"
elif [[ -d /tmp || $NAME == "World" ]]; then
    echo "tmp exists"
else
    echo 'nothing'
fi

for i in 1 2 3 4 5; do
    COUNT=$((COUNT + i))
    echo "i = $i"
done

while [ $COUNT -gt 0 ]
do
    COUNT=$((COUNT - 5))
done

until [ $COUNT -ge 3 ]; do
    COUNT=$((COUNT + 1))
done

case "$1" in
    start) echo "starting" ;;
    stop|halt)
        echo "stopping"
        ;;
    *) echo "usage: $0 {start|stop}" ;;
esac

ls -l /tmp | grep ".txt" | sort > out.txt 2>&1
cat < input.txt >> log.txt
FILES=$(ls -a)
TODAY=`date`
(cd /tmp; ls) &
{ echo a; echo b; } > both.txt
[ -z "$NAME" ] || echo "name set"
! grep -q root /etc/passwd
x=5 y=6 env
echo done_msg
exit 0
