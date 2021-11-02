dd if=/dev/zero of=lofs.img bs=100M count=1
# du -sh lofs.img 
sudo losetup -fP lofs.img
losetup -a
sudo mkfs.ext4 lofs.img
mkdir lofsdisk
sudo mount -o loop lofs.img lofsdisk