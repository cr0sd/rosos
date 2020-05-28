CFLAGS= -m32 -Wfatal-errors -nostdlib -Wno-builtin-declaration-mismatch
ASFLAGS= --32
LDFLAGS= -melf_i386 -nostdlib -e loader -T link.ld
OBJS=kernel.bin

all: $(OBJS)
kernel.bin: loader.o kernel.o
	$(LD) $(LDFLAGS) $^ -o $@
install:
	cp ./kernel.bin /boot/mykernel.bin
clean:
	$(RM) *.o kernel.bin
