SM = nasm
VM = kvm

all:
	$(SM) haemolacria.asm -o haemolacria.bin
	$(VM) -hda haemolacria.bin -monitor stdio

makeonly:
	$(SM) haemolacria.asm -o haemolacria.bin

getsize:
	$(SM) haemolacria.asm -o haemolacria.bin
	wc -c < haemolacria.bin
