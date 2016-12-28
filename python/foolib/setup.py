from distutils.core import setup, Extension

module1 = Extension('foolib',
                    define_macros = [('MAJOR_VERSION', '1'),
                                     ('MINOR_VERSION', '0')],
                    include_dirs = ['../../cxx/include'],
                    sources = ['foolibmodule.c', '../../cxx/src/foolib_c.cxx'])

setup (name = 'foolib',
       version = '1.0',
       description = 'This is a demo package',
       author = 'Tom Kraljevic',
       author_email = 'tomk@tomk.net',
       url = 'http://example-of-where-to-put-url.org',
       long_description = '''
This is really just a demo package.
''',
       ext_modules = [module1])

