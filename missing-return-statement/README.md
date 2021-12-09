# missing-return-statement 

undefined behavior

```shell script
$ ./missing-return-statement 
Illegal instruction: 4

missing-return-statement`std::__1::vector<unsigned char, std::__1::allocator<unsigned char> >::vector:
    0x100003d20 <+0>:  pushq  %rbp
    0x100003d21 <+1>:  movq   %rsp, %rbp
Target 0: (missing-return-statement) stopped.
(lldb) bt
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_INSTRUCTION (code=EXC_I386_INVOP, subcode=0x0)
  * frame #0: 0x0000000100003d1c missing-return-statement`subdomainVisits() + 28
```
