# Python Support in Djinni

Python support in Djinni is experimental, but ready to try out.  It can generate code for bridging C++ with Python 2 or 3.

For more information, you can check out our talk from CppCon 2015 (link to slides and video coming soon).

## Generated Code

When bridging to Python, Djinni generates 4 types of output:

* `python` Generated Python classes and proxies for interacting with C++ via [CFFI](https://cffi.readthedocs.org/).
* `cffi` Python code run at build time to create a Python extension out of the C++ code.
* `cwrapper` A C interface implemented in C++ to allowing Python to interact with C++ classes.
* `cpp` The same C++ classes generated for all other Djinni languages.

## Pre-requisites

Djinni generates code which should work with Python 2 or 3.  Python support has only been tested on Mac OS X with the clang compiler.  It's been designed to work on any platform, and the known issues are in the build process rather than the generated code itself.

The Python support generated by Djinni makes use of a few non-default Python extensions, as does the test suite.  You can install them as follows:

For Python 2:

```
  sudo pip install cffi
  sudo pip install enum34
  sudo pip install future
  sudo pip install pytest
```

For Python 3:

```
  sudo pip3 install cffi
  sudo pip3 install future
  sudo pip3 install pytest
```

## Example app

You can run the example app (a command-line version of the same TextSort example used in other languages) from the top-level `djinni/` directory by running `make example_python2` or `make example_python3`.  You can find the code which uses the generated python interfaces in `example/handwritten-src/python`.

## Test Suite

The Python test-suite will run as part of the global test suite if you run `make test`.  You can run it individually from the `test-suite` directory via `make python2` or `make python3`.  Note that because of the known limitations described below, the Python test suite does not use all of the same inputs as the other languages.  As a result, you'll see a separate `pycpp` directory in generated-src.  This contains output of the standard C++ generator, but for the specific input files used by the Python test suite.

## Known limitations

* Proxy caching is not yet implemented.  In addition to some inefficiency, this means that the same object passed across the language boundary twice is not guaranteed to appear as a single object on the other side.
* External types defined in YAML are not yet supported.
* The support library code makes direct reference to <experimental/optional> types rather than respecting the command-line choice of a different optional library.
* Use of non-nullable pointers is not yet supported.

## Contact
If you have feedback, contact `atwyman@dropbo.com` and/or `j4cbo@dropbox.com`.