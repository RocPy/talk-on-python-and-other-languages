all: clean thing

thing:
	# f2py -c --fcompiler=g95 -m $@ $@.f95
	f2py $@.f95 -m $@ -h $@.pyf 
	f2py -c --fcompiler=g95 $@.pyf $@.f95

clean:
	rm *.pyf *.so

