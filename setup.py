from distutils.core import setup, Extension

spammodul = Extension('spam',
                    define_macros = [('MAJOR_VERSION', '1'),
                                     ('MINOR_VERSION', '0')],
                    include_dirs = ['/usr/local/include'],
                    #libraries = ['cpprest', 'boost_system'],
                    library_dirs = ['/usr/local/lib'],
                    sources = ['spammodule.c'])

setup (name = 'spam',
       version = '1.0',
       description = 'This is a spam package',
       ext_modules = [spammodul])

