# CPP Courses

C++ courses and experiments.


<hr> 

## 📦 - Conan - software package manager for C++

[Conan](https://conan.io/) can install packages juste with a `conanfile.txt`.

### Install conan

Install conan directly with pip ```pip3 instal conan@1.59```.

> Since conan v2 does not have opencv lib, we use the latest v1 version.

### Install your libs

Create a `conanfile.txt`then install yours libs like this :

```
conan install . -s build_type=Debug --build=missing --install-folder=cmake-build-debug
```

source : https://docs.conan.io/1/integrations/ide/clion.html

### create a dependencies graph

```
conan info . --graph=graph.html
```

### Search package

Go to https://conan.io/center/ to find a package.

<hr> 

##  - Mojave issues

If headers are missing like this, please follow instructions

```
fatal error: 'wchar.h' file not found
#include_next <wchar.h>
``` 

source : https://stackoverflow.com/questions/26185978/macos-wchar-h-file-not-found/26185979#26185979

```
code-select --install
sudo xcode-select --switch /Library/Developer/CommandLineTools/
open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_10.14.pkg
```


