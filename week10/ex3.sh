touch _ex3.txt
chmod a-x _ex3.txt > ex3.txt
chmod u=rwx _ex3.txt >> ex3.txt
chmod o=rwx _ex3.txt >> ex3.txt
chmod g=u _ex3.txt >> ex3.txt

echo '
touch _ex3.txt
chmod a-x _ex3.txt > ex3.txt
chmod u=rwx _ex3.txt >> ex3.txt
chmod o=rwx _ex3.txt >> ex3.txt
chmod g=u _ex3.txt >> ex3.txt
660 - 110 110 000 - owner(rw-) group(rw-) other(---)
775 - 111 111 101 - owner(rwx) group(rwx) other(r-x)  
777 - 111 111 001 - owner(rwx) group(rwx) other(rwx)' >> ex3.txt