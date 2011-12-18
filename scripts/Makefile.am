#
# ACCORDS Makefile.am
#
# Copyright 2011, Mandriva, All rights reserved
#
# Authors:
#   Jean Parpaillon <jparpaillon@mandriva.com>
#
pkgsysconfdir=$(sysconfdir)/$(PACKAGE)
dist_pkgsysconf_DATA=cords_user.xml

scripts=accords

aliases = \
	co-start co-broker co-command co-parser co-resolver co-status co-stop \
	run-azprocci run-broker run-coes run-comons run-conets run-coobas run-coss \
	run-fileserver run-onprocci run-osprocci run-parser run-procci run-publisher \
	accords-config

EXTRA_DIST = accords.in
CLEANFILES = $(scripts) $(aliases)

# Edit for local run (without installation)
localpath = $(PATH_AZPROCCI):$(PATH_BROKER):$(PATH_COES):$(PATH_COMONS):$(PATH_CONETS):$(PATH_COOBAS):$(PATH_COSS):$(PATH_FILESERVER):$(PATH_ONPROCCI):$(PATH_OSPROCCI):$(PATH_PARSER):$(PATH_PROCCI):$(PATH_PUBLISHER):$(builddir)
localedit = sed \
        -e 's|@sitepath[@]|$(localpath)|g' \
        -e 's|@pkgsysconfdir[@]|$(pkgsysconfdir)|g'

# Edit for normal run (installed)
installpath = $(pkglibexecdir)
installedit = sed \
        -e 's|@sitepath[@]|$(installpath)|g' \
        -e 's|@pkgsysconfdir[@]|$(pkgsysconfdir)|g'

all-local: $(scripts)
	chmod 755 accords
	for alias in $(aliases); do \
	  ln -fs accords $$alias; \
	done

install-exec-local: accords.in Makefile
	mkdir -p $(DESTDIR)$(bindir)
	srcdir=''; \
	  test -f ./accords.in || srcdir=$(srcdir)/; \
	  $(installedit) $${srcdir}accords.in >$(DESTDIR)$(bindir)/accords
	chmod 755 $(DESTDIR)$(bindir)/accords
	for alias in aliases; do \
	  ln -fs accords $(DESTDIR)$(bindir)/$$alias; \
	done

uninstall-local:
	for alias in $(aliases); do \
	  rm -f $(DESTDIR)$(bindir)/$$alias; \
	done
	rm -f $(DESTDIR)$(bindir)/accords

accords: accords.in
accords: Makefile
	rm -f $@ $@.tmp
	srcdir=''; \
	  test -f ./$@.in || srcdir=$(srcdir)/; \
	  $(localedit) $${srcdir}$@.in >$@.tmp
	mv $@.tmp $@