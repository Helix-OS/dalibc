dalibc-port: userland/build
	@cd userland/ports/dalibc; $(MAKE) AS=$(AS) CC=$(CC) LD=$(LD) \
		ARCH=i386 HOST=helix PREFIX=$(PWD)"/userland/build" all install

dalibc-port-clean:
	@cd userland/ports/dalibc; $(MAKE) AS=$(AS) CC=$(CC) LD=$(LD) \
		ARCH=i386 HOST=helix PREFIX=$(PWD)"/userland/build" clean

USER_CLEAN += dalibc-port-clean
