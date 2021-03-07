## Build

### Release/Debugビルドの切り替え

```
$ cmake -DCMAKE_BUILD_TYPE=Release  # -O2 とか -DNDEBUG とかが付く
$ cmake -DCMAKE_BUILD_TYPE=Debug  # -O0 とか -g とかが付く
```


以下が指定できるらしい。具体的にどういうオプションがセットされるかは調べていない。
* empty
* Debug
* Release
* RelWithDebInfo
* MinSizeRel

何も指定しないと何になる??


### for command line
```
cd build
cmake ..
cmake --build .
```

### for Xcode 
```
cd build_xcode
cmake .. -G Xcode
```

### Address Sanitizer Check
```
cd build
cmake .. -DCMAKE_BUILD_TYPE=SanitizeCheck
cmake --buid .
```
