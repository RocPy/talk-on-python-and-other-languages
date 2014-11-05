LDFLAGS=`python-config --ldflags` "`pwd`/../spam-module/build/temp.macosx-10.9-x86_64-2.7/spammodule.o" -lcrt1.o -macosx_version_min 10.6
CFLAGS=`python-config --includes` -I"`pwd`/../spam-module"

.PHONY: clean

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

pyembed: pyembed.o
	$(LD) $(LDFLAGS) $< -o pyembed

clean:
	rm pyembed pyembed.o
