if [ ! -f num.txt ]; then
    echo 0 > num.txt
fi

if [ "$(tail -1 num.txt)" = "" ]; then
    echo 0 > num.txt
fi

iter=0

while [ $iter -lt 100 ]; do
    if $(ln num.txt num.lock); then
        rm num.lock
        counter=$(tail -1 num.txt)
        echo "$((counter+1))" >> num.txt
        iter=$((iter+1))
    else
        sleep 1
    fi
done
 
tail -1 num.txt
