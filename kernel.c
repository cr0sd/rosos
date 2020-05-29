#define SPACE "                                                                                                "

// FILE type
typedef struct FILE
{
	unsigned fd;
	unsigned short*offset;
	unsigned int seek;
} FILE;

FILE*stdout=&(FILE){.fd=0,.offset=(unsigned short*)0xb8000,.seek=0};

// puts to FILE
void fputs(FILE*f,char*s)
{
	for(unsigned i=0;s[i];++i)
		*f->offset++=0x1f00|s[i];
}

#define puts(x) fputs(stdout,x)

void fputc(char c,FILE*f)
{
	*f->offset++=0x1f00|c;
}

// print integer
void printif(FILE*f,int d)
{
	char b[32];
	int i=0;

	// Get each digit as character
	while(d>0)
	{
		int m=d%10;
		d/=10;
		b[i++]=m+'0';
	}
	b[i]=0;

	// Print reversed string
	for(i;i>=0;--i)
		fputc(b[i],f);
}

#define printi(x) printif(stdout,x)



// Entry point
void kernelmain(void*multiboot_structure,unsigned magicnumber)
{
	puts("Hello and welcome to my first operating system, yo!"SPACE);
	printi(123);
}
