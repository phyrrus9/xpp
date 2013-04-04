x++ program loader and language.

x++ comes with all of its source code, and a makefile to produce two binaries: xc and ex
file: xc
xc is the compiler (x compiler), and will take a number of args (just run ./xc to see all of them)
	to produce a binary that can be loaded with ex

file: ex
ex is the executioner, hehe, basically, you just ./ex <binary> or if you are a developer you can
	./ex -v <binary>

I also included some tests and examples, which can be compiled and ran with "make test". I included
the game Super Key Seeker 3 (just the binary) for mac. This game does not have the proper format,
it is missing the entry point, if you run it without debug mode it will figure it out for you, but
if you are in debug mode, select the symbol "main", none of the others will work. SKS3 is named
sks3.bx (the b is so it wont be deleted by make clean)

All programs need to have the following function!
int start(int argc, char * * argv)
{
}
You can name argc and argv whatever you want but nothing else can change. This is the entry point
of your program (start can be replaced with main but it will throw an error). Once you do this,
it is simply c/c++ programming!

Enjoy!

~2013 Ethan Laur (phyrrus9) <phyrrus9@gmail.com>
