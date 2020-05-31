CFLAGS= -m32 -Wfatal-errors -nostdlib -Wno-builtin-declaration-mismatch
ASFLAGS= --32
LDFLAGS= -melf_i386 -nostdlib -e loader -T link.ld
OBJS=kernel.bin

all: $(OBJS)

kernel.bin: loader.o kernel.o
	@echo "  LD	kernel.bin"
	@$(LD) $(LDFLAGS) $^ -o $@

install: $(OBJS)
	@echo "  CP	kernel.bin"
	@cp ./kernel.bin /boot/mykernel.bin

%.o: %.c
	@echo "  CC	$@"
	@$(CC) $(CFLAGS) -c $^

%.o: %.s
	@echo "  AS	$@"
	@$(AS) $(ASFLAGS) -c $^ -o $@

clean:
	@echo "  RM	*.o kernel.bin"
	@$(RM) *.o kernel.bin
