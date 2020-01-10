from distutils.core import setup, Extension

spammodul = Extension('spam',
                    define_macros = [('MAJOR_VERSION', '1'),
                                     ('MINOR_VERSION', '0')],
                    include_dirs = ['/usr/include'],
                    libraries = ['cpprest', 'boost_system', 'boost_chrono'],
                    library_dirs = ['/usr/lib/x86_64-linux-gnu'],
                    sources = ['spammodule.c', 'http_client.cpp'])

setup (name = 'spam',
       version = '1.0',
       description = 'This is a spam package',
       ext_modules = [spammodul])

