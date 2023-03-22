DIR='week01'
DIRL='week10'
mkdir $DIR
mkdir $DIRL
touch $DIR/file.txt

echo "123 123" > $DIR/file.txt
link $DIR/file.txt $DIRL/_ex2.txt > ex2.txt
echo "linked" >> $DIR/file.txt

INUM=$(ls -i $DIR/file.txt | awk '{print $1}')
find . -inum $INUM >> ex2.txt
find . -inum $INUM -exec rm {} \; >> ex2.txt
