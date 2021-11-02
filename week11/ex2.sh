sudo chmod 777 lofsdisk
touch lofsdisk/file1
# sudo chmod 777 lofsdisk/file1
touch lofsdisk/file2
# sudo chmod 777 lofsdisk/file2

echo "Ahmadsho" > lofsdisk/file1
echo "Akdodshoev" > lofsdisk/file2

mkdir lofsdisk/bin
sudo cp -r /bin/bash    lofsdisk/bin/bash
sudo cp -r /bin/ls      lofsdisk/bin/ls
sudo cp -r /bin/cat     lofsdisk/bin/cat
sudo cp -r /bin/echo    lofsdisk/bin/echo

sudo mkdir lofsdisk/lib/
sudo mkdir lofsdisk/lib/x86_64-linux-gnu/
sudo mkdir lofsdisk/lib64

# bash
sudo cp -v /lib/x86_64-linux-gnu/libtinfo.so.6  lofsdisk/lib/x86_64-linux-gnu/libtinfo.so.6
sudo cp -v /lib/x86_64-linux-gnu/libdl.so.2     lofsdisk/lib/x86_64-linux-gnu/libdl.so.2
sudo cp -v /lib/x86_64-linux-gnu/libc.so.6      lofsdisk/lib/x86_64-linux-gnu/libc.so.6
sudo cp -v /lib64/ld-linux-x86-64.so.2          lofsdisk//lib64/ld-linux-x86-64.so.2

# ls
sudo cp -v /lib/x86_64-linux-gnu/libselinux.so.1    lofsdisk/lib/x86_64-linux-gnu/libselinux.so.1
sudo cp -v /lib/x86_64-linux-gnu/libc.so.6          lofsdisk/lib/x86_64-linux-gnu/libc.so.6
sudo cp -v /lib/x86_64-linux-gnu/libpcre2-8.so.0    lofsdisk/lib/x86_64-linux-gnu/libpcre2-8.so.0
sudo cp -v /lib/x86_64-linux-gnu/libdl.so.2         lofsdisk/lib/x86_64-linux-gnu/libdl.so.2
sudo cp -v /lib/x86_64-linux-gnu/libpthread.so.0    lofsdisk/lib/x86_64-linux-gnu/libpthread.so.0
sudo cp -v /lib64/ld-linux-x86-64.so.2              lofsdisk/lib64/ld-linux-x86-64.so.2

# cat
sudo cp -v /lib/x86_64-linux-gnu/libc.so.6  lofsdisk/lib/x86_64-linux-gnu/libc.so.6
sudo cp -v /lib64/ld-linux-x86-64.so.2      lofsdisk/lib64/ld-linux-x86-64.so.2

# echo
sudo cp -v /lib/x86_64-linux-gnu/libc.so.6  lofsdisk/lib/x86_64-linux-gnu/libc.so.6
sudo cp -v /lib64/ld-linux-x86-64.so.2      lofsdisk/lib64/ld-linux-x86-64.so.2


gcc ex2.c -o ex2.out 
sudo cp ex2.out lofsdisk/ex2.out

echo "With chroot" > ex2.txt
sudo chroot lofsdisk/ ./ex2.out >> ex2.txt

echo "
Without chroot" >> ex2.txt
./ex2.out >> ex2.txt

sudo chmod 755 lofsdisk