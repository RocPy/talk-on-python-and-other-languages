from distutils.core import setup, Extension

thing_module = Extension('thing', sources=['thingmodule.c'])

setup(name='ThingModule',
      version='1.0',
      description='This is a thingy package',
      ext_modules=[thing_module])
