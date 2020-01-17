# Installing and Using Guide
This example works with Python2.7 only. Run:
```
$ python --version
```
Make sure it is "Python 2.7.xxx"

## Prepare
Install CppRest package according to https://github.com/microsoft/cpprestsdk.
*Hints*: Online binary version of the package needs to be installed. After installation, update the include and library paths in "setup.py" to match your system. 

## Build
Run below command:
```
$ python setup.py build
```

## Install
Run:
```
$ sudo python setup.py install
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
>>> record = spam.get()
>>> record
```

## References
[1] Extending Python with C or C++. https://docs.python.org/2/extending/extending.html\
[2] HL7 FHIR Foundation Enabling health interoperability through FHIR http://fhir.org/\
[3] https://fhir-drills.github.io/index.html
