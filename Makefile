INSTALL_MANPATH		= /usr/share/man/man1
INSTALL_SCRIPTS_PATH	= /usr/bin


install: install_manpages install_scripts

install_manpages: manpages/*
	mkdir -p $(INSTALL_MANPATH)
	install manpages/* $(INSTALL_MANPATH)

install_scripts: scripts/*
	install scripts/* $(INSTALL_SCRIPTS_PATH)

purge:
	rm -rf *~
