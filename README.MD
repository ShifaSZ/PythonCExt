# Installing guide
This example works with Python2.7 only. Run:
```
$ python --version
```
Make sure it is "Python 2.7.xxx"

## Build
Run below command:
```
$ python setup.py build
```

## Install
Run:
```
$ python setup.py install
```

## Test
Run Python, import the spam library and test it.
```
$ python
Python 2.7.15+ (default, Oct  7 2019, 17:39:04) 
[GCC 7.4.0] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> import spam
>>> spam.system("ls -l")
```
