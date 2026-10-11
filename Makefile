# Build the final floppy image
main.img: loads/main.bin loads/stage2.bin
	dd if=/dev/zero of=main.img bs=512 count=2880
	dd if=loads/main.bin of=main.img bs=512 count=1 conv=notrunc
	dd if=loads/stage2.bin of=main.img bs=512 seek=1 conv=notrunc
	truncate -s 1440k main.img


# Assemble the bootloader
loads/main.bin: bl.asm 
	nasm bl.asm -f bin -o loads/main.bin


# Assemble Stage 2
loads/stage2.o: stage2.asm 
	nasm -f elf32 stage2.asm -o loads/stage2.o


# Assemble interrupt stubs
loads/isr.o: isr.asm 
	nasm -f elf32 isr.asm -o loads/isr.o


# Compile the C kernel
loads/kernel.o: kernel.c video.h idt.h 
	gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -fno-builtin -c kernel.c -o loads/kernel.o


# Compile IDT and interrupt handler
loads/idt.o: idt.c idt.h video.h 
	gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -fno-builtin -c idt.c -o loads/idt.o


# Link Stage 2, kernel, IDT, and interrupt stubs
loads/stage2.elf: loads/stage2.o loads/isr.o loads/kernel.o loads/idt.o
	ld -m elf_i386 -e start -Ttext 0x8000 -o loads/stage2.elf loads/stage2.o loads/isr.o loads/kernel.o loads/idt.o


# Convert ELF into a raw binary
loads/stage2.bin: loads/stage2.elf
	objcopy -O binary loads/stage2.elf loads/stage2.bin





# Remove generated files
clean:
	rm -f loads/*.o loads/*.bin loads/*.elf main.img


