#!/bin/sh


STARTTIME=$(date +%s)

duration () {
    expr $(date +%s) - $STARTTIME
}


GOT_JACKD=0
GOT_JACKDMP=0

# Try for 10 seconds.
while [ $(duration) -lt 10 ] ; do 
    
    if ! killall -9 jackd ; then
        echo "finished killing jackd"
        GOT_JACKD=1
    else
        GOT_JACKD=0 # maybe it reappared?
    fi
    
    if ! killall -9 jackdmp ; then
        echo "finished killing jackdmp"
        GOT_JACKDMP=1
    else
        GOT_JACKDMP=0 # maybe it reappared?
    fi

    if [ $GOT_JACKD -eq 1 ] ; then
        if [ $GOT_JACKDMP -eq 1 ] ; then
            exit 0
        fi
    fi

#    echo $(duration)
    sleep 0.01
done

exit 1
