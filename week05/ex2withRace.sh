if [ ! -f num.txt ]; then
    echo 0 > num.txt
fi

if [ "$(tail -1 num.txt)" = "" ]; then
    echo 0 > num.txt
fi

iter=1

while [ $iter -lt 100 ]; do
    counter=$(tail -1 num.txt)
    echo "$((counter+1))" >> num.txt
    iter=$((iter+1))
done
 
tail -1 num.txt