A couple of pet projects with no rhyme or reason

# **Connect Four**
### *You can play connect four in a terminal*

Pretty simple. 
`gcc -o {pick a name} connect_four.c`
Put the resulting binary whereever you want and run `/path/to/connect_four.`
______
# **PyComp**
### *Automates compiling packages*

dependencies: base-devel, asp

Prompts for package name, retrieves the pkgbuild, then compiles and installs packages using the Arch Build System. It will create a directory called .asp in the same directory as itself for build directories.

Use: run `python pycomp.py` and follow prompts.

**Made on Arch for Arch. May or may not work on Arch based distros (e.g. Manjaro)**
