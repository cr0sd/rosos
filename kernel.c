#define SPACE "                                                                                                "
void puts(char*s)
{
	static unsigned short*vram=(unsigned short*)0xb8000;
	for(int i=0;s[i];++i)
		vram[i]=0x1f00|s[i];
}

void kernelmain(void*multiboot_structure,unsigned magicnumber)
{
	puts("Hello and welcome to my first operating system, yo!"SPACE);
}
