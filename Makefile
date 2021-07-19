INSTALL_MANPATH		= /usr/share/man/man1
INSTALL_SCRIPTS_PATH	= /usr/bin

install: install_manpages install_scripts compile_c

install_manpages: manpages
	mkdir -p $(INSTALL_MANPATH)
	install manpages/* $(INSTALL_MANPATH)

install_scripts: scripts
	install scripts/* $(INSTALL_SCRIPTS_PATH)

purge:
	rm -rf *~

compile_c: scripts/c_source
	for i in $(shell ls scripts/c_source) ; \
		do gcc -o $(INSTALL_SCRIPTS_PATH)/$${i%%.c} scripts/c_source/$$i ; \
	done
