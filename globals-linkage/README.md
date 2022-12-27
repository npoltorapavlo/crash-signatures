# globals-linkage

`__cxa_finalize/SIGABRT/double free`

> static/const is internal (translation unit), global is external

```shell script
(global)
$ readelf -Ws globals-linkage/libdl5.so |grep ErrCodeMap
   125: 000000000000e420    48 OBJECT  GLOBAL DEFAULT   26 _Z10ErrCodeMapB5cxx11
    84: 000000000000e420    48 OBJECT  GLOBAL DEFAULT   26 _Z10ErrCodeMapB5cxx11
$ readelf -Ws globals-linkage/libdl6.so |grep ErrCodeMap
   133: 000000000000d400    48 OBJECT  GLOBAL DEFAULT   26 _Z10ErrCodeMapB5cxx11
    81: 000000000000d400    48 OBJECT  GLOBAL DEFAULT   26 _Z10ErrCodeMapB5cxx11

(static)
$ readelf -Ws globals-linkage/libdl5.so |grep ErrCodeMap
    13: 000000000000e420    48 OBJECT  LOCAL  DEFAULT   26 _ZL10ErrCodeMap
$ readelf -Ws globals-linkage/libdl6.so |grep ErrCodeMap
    13: 000000000000d400    48 OBJECT  LOCAL  DEFAULT   26 _ZL10ErrCodeMap

(const)
$ readelf -Ws globals-linkage/libdl5.so |grep ErrCodeMap
    13: 000000000000e460    48 OBJECT  LOCAL  DEFAULT   26 _ZL10ErrCodeMap
$ readelf -Ws globals-linkage/libdl6.so |grep ErrCodeMap
    13: 000000000000d440    48 OBJECT  LOCAL  DEFAULT   26 _ZL10ErrCodeMap
```
