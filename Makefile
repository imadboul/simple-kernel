
main.img: main.bin stage2.bin
	dd if=/dev/zero of=main.img bs=512 count=2880
	dd if=main.bin of=main.img bs=512 count=1 conv=notrunc
	dd if=stage2.bin of=main.img bs=512 seek=1 conv=notrunc
	truncate -s 1440k main.img

main.bin: bl.asm
	nasm bl.asm -f bin -o main.bin

# Assemble Stage 2
stage2.o: stage2.asm
	nasm -f elf32 stage2.asm -o stage2.o

# Compile the C kernel
kernel.o: kernel.c
	gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -fno-builtin -c kernel.c -o kernel.o

# Link assembly and C into an ELF executable
stage2.elf: stage2.o kernel.o
	ld -m elf_i386 -e start -Ttext 0x8000 -o stage2.elf stage2.o kernel.o

# Convert ELF into a raw binary for the bootloader
stage2.bin: stage2.elf
	objcopy -O binary stage2.elf stage2.bin

run: main.img
	qemu-system-i386 -fda main.img

clean:
	rm -f *.o *.bin *.elf main.img

.PHONY: run clean