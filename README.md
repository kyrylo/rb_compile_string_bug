What to do.

```
rake compile
rake bug
```

Ruby compiled with default flags segfaults.

```
ruby -v
ruby 2.2.2p95 (2015-04-13 revision 50295) [x86_64-linux]
```

Produces this:

```
~/code/rb_compile_string_bug[master]% rake bug
bug.rb:3: [BUG] Segmentation fault at 0x00072500000027
ruby 2.2.2p95 (2015-04-13 revision 50295) [x86_64-linux]

-- Control frame information -----------------------------------------------
c:0005 p:---- s:0012 e:000011 CFUNC  :rb_compile_string
c:0004 p:0013 s:0009 e:000008 BLOCK  bug.rb:3 [FINISH]
c:0003 p:---- s:0007 e:000006 CFUNC  :times
c:0002 p:0014 s:0004 E:002690 EVAL   bug.rb:3 [FINISH]
c:0001 p:0000 s:0002 E:001060 TOP    [FINISH]

-- Ruby level backtrace information ----------------------------------------
bug.rb:3:in `<main>'
bug.rb:3:in `times'
bug.rb:3:in `block in <main>'
bug.rb:3:in `rb_compile_string'

-- Machine register context ------------------------------------------------
 RIP: 0x00007f1ed69760c0 RBP: 0x00007f1ed9fa23a0 RSP: 0x00007ffc0c39a738
 RAX: 0xffff88062605daf7 RBX: 0x0000000000000031 RCX: 0x0000000000000310
 RDX: 0x0000000000000188 RDI: 0x00007f1ed9fa23a8 RSI: 0x0000072500000027
  R8: 0x0000000000002bf0  R9: 0x0000000000000001 R10: 0x00007f1ed9b4ea10
 R11: 0xcccccccccccccccd R12: 0x0000000000000092 R13: 0x00007f1ed9ffebe8
 R14: 0x0000000000000061 R15: 0x00007f1ed9ffeb30 EFL: 0x0000000000010206

-- C level backtrace information -------------------------------------------
/opt/rubies/ruby-2.2.2/bin/ruby(rb_vm_bugreport+0x4ea) [0x7f1ed7c1971a] vm_dump.c:693
/opt/rubies/ruby-2.2.2/bin/ruby(rb_bug_context+0xcb) [0x7f1ed7c8da2b] error.c:425
/opt/rubies/ruby-2.2.2/bin/ruby(sigsegv+0x3e) [0x7f1ed7b8963e] signal.c:879
/usr/lib/libpthread.so.0 [0x7f1ed766a660]
/usr/lib/libc.so.6(__memcpy_sse2_unaligned+0x20) [0x7f1ed69760c0]
/opt/rubies/ruby-2.2.2/bin/ruby(local_tbl_gen.isra.20+0x70) [0x7f1ed7c95140] /usr/include/bits/string3.h:53
/opt/rubies/ruby-2.2.2/bin/ruby(ruby_yyparse+0xd2f6) [0x7f1ed7cab706] parse.y:3033
/opt/rubies/ruby-2.2.2/bin/ruby(yycompile0+0xe3) [0x7f1ed7caea33] parse.y:5514
/opt/rubies/ruby-2.2.2/bin/ruby(rb_suppress_tracing+0xf4) [0x7f1ed7c20784] vm_trace.c:406
/opt/rubies/ruby-2.2.2/bin/ruby(rb_compile_string+0x20f) [0x7f1ed7c9cf8f] parse.y:5547
/home/kyrylo/code/rb_compile_string_bug/lib/rb_compile_string_bug/rb_compile_string_bug.so(mRbCompileStringBug_rb_compile_string+0x31) [0x7f1ed5e22891] ../../../../ext/rb_compile_string_bug/rb_compile_string_bug.c:7
/opt/rubies/ruby-2.2.2/bin/ruby(vm_call_cfunc+0x127) [0x7f1ed7bfeec7] vm_insnhelper.c:1382
/opt/rubies/ruby-2.2.2/bin/ruby(vm_exec_core+0x123d) [0x7f1ed7c0346d] insns.def:1054
/opt/rubies/ruby-2.2.2/bin/ruby(vm_exec+0x78) [0x7f1ed7c07be8] vm.c:1400
/opt/rubies/ruby-2.2.2/bin/ruby(rb_yield+0x482) [0x7f1ed7c16692] vm.c:813
/opt/rubies/ruby-2.2.2/bin/ruby(int_dotimes+0x3e) [0x7f1ed7b1bbde] numeric.c:3864
/opt/rubies/ruby-2.2.2/bin/ruby(vm_call_cfunc+0x127) [0x7f1ed7bfeec7] vm_insnhelper.c:1382
/opt/rubies/ruby-2.2.2/bin/ruby(vm_call_method+0x11e) [0x7f1ed7c0dc5e] vm_insnhelper.c:1691
/opt/rubies/ruby-2.2.2/bin/ruby(vm_exec_core+0x1187) [0x7f1ed7c033b7] insns.def:1024
/opt/rubies/ruby-2.2.2/bin/ruby(vm_exec+0x78) [0x7f1ed7c07be8] vm.c:1400
/opt/rubies/ruby-2.2.2/bin/ruby(rb_iseq_eval_main+0x203) [0x7f1ed7c16e43] vm.c:1670
/opt/rubies/ruby-2.2.2/bin/ruby(ruby_exec_internal+0xbf) [0x7f1ed7abe24f] eval.c:252
/opt/rubies/ruby-2.2.2/bin/ruby(ruby_run_node+0x2f) [0x7f1ed7ac1def] eval.c:317
/opt/rubies/ruby-2.2.2/bin/ruby(main+0x4b) [0x7f1ed7abdddb] parse.y:8795

-- Other runtime information -----------------------------------------------

* Loaded script: bug.rb

* Loaded features:

    0 enumerator.so
    1 rational.so
    2 complex.so
    3 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/enc/encdb.so
    4 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/enc/trans/transdb.so
    5 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/unicode_normalize.rb
    6 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/rbconfig.rb
    7 thread.rb
    8 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/thread.so
    9 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/compatibility.rb
   10 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/defaults.rb
   11 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/deprecate.rb
   12 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/errors.rb
   13 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/version.rb
   14 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/requirement.rb
   15 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/platform.rb
   16 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/basic_specification.rb
   17 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/stub_specification.rb
   18 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/util/stringio.rb
   19 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/specification.rb
   20 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/exceptions.rb
   21 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/core_ext/kernel_gem.rb
   22 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/monitor.rb
   23 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems/core_ext/kernel_require.rb
   24 /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/rubygems.rb
   25 /home/kyrylo/code/rb_compile_string_bug/lib/rb_compile_string_bug/rb_compile_string_bug.so

* Process memory map:

7f1ed4e76000-7f1ed5c0c000 r--s 00000000 08:08 1443053                    /opt/rubies/ruby-2.2.2/bin/ruby
7f1ed5c0c000-7f1ed5c22000 r-xp 00000000 08:08 792721                     /usr/lib/libgcc_s.so.1
7f1ed5c22000-7f1ed5e21000 ---p 00016000 08:08 792721                     /usr/lib/libgcc_s.so.1
7f1ed5e21000-7f1ed5e22000 rw-p 00015000 08:08 792721                     /usr/lib/libgcc_s.so.1
7f1ed5e22000-7f1ed5e23000 r-xp 00000000 08:09 661055                     /home/kyrylo/code/rb_compile_string_bug/lib/rb_compile_string_bug/rb_compile_string_bug.so
7f1ed5e23000-7f1ed6022000 ---p 00001000 08:09 661055                     /home/kyrylo/code/rb_compile_string_bug/lib/rb_compile_string_bug/rb_compile_string_bug.so
7f1ed6022000-7f1ed6023000 rw-p 00000000 08:09 661055                     /home/kyrylo/code/rb_compile_string_bug/lib/rb_compile_string_bug/rb_compile_string_bug.so
7f1ed6023000-7f1ed6026000 r-xp 00000000 08:08 1447082                    /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/thread.so
7f1ed6026000-7f1ed6226000 ---p 00003000 08:08 1447082                    /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/thread.so
7f1ed6226000-7f1ed6227000 rw-p 00003000 08:08 1447082                    /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/thread.so
7f1ed6227000-7f1ed6229000 r-xp 00000000 08:08 1447127                    /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/enc/trans/transdb.so
7f1ed6229000-7f1ed6429000 ---p 00002000 08:08 1447127                    /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/enc/trans/transdb.so
7f1ed6429000-7f1ed642a000 rw-p 00002000 08:08 1447127                    /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/enc/trans/transdb.so
7f1ed642a000-7f1ed642c000 r-xp 00000000 08:08 1447149                    /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/enc/encdb.so
7f1ed642c000-7f1ed662b000 ---p 00002000 08:08 1447149                    /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/enc/encdb.so
7f1ed662b000-7f1ed662c000 rw-p 00001000 08:08 1447149                    /opt/rubies/ruby-2.2.2/lib/ruby/2.2.0/x86_64-linux/enc/encdb.so
7f1ed662c000-7f1ed68e6000 r--p 00000000 08:08 829882                     /usr/lib/locale/locale-archive
7f1ed68e6000-7f1ed6a7f000 r-xp 00000000 08:08 789700                     /usr/lib/libc-2.21.so
7f1ed6a7f000-7f1ed6c7e000 ---p 00199000 08:08 789700                     /usr/lib/libc-2.21.so
7f1ed6c7e000-7f1ed6c82000 r--p 00198000 08:08 789700                     /usr/lib/libc-2.21.so
7f1ed6c82000-7f1ed6c84000 rw-p 0019c000 08:08 789700                     /usr/lib/libc-2.21.so
7f1ed6c84000-7f1ed6c88000 rw-p 00000000 00:00 0
7f1ed6c88000-7f1ed6d8b000 r-xp 00000000 08:08 789819                     /usr/lib/libm-2.21.so
7f1ed6d8b000-7f1ed6f8a000 ---p 00103000 08:08 789819                     /usr/lib/libm-2.21.so
7f1ed6f8a000-7f1ed6f8b000 r--p 00102000 08:08 789819                     /usr/lib/libm-2.21.so
7f1ed6f8b000-7f1ed6f8c000 rw-p 00103000 08:08 789819                     /usr/lib/libm-2.21.so
7f1ed6f8c000-7f1ed6f94000 r-xp 00000000 08:08 789720                     /usr/lib/libcrypt-2.21.so
7f1ed6f94000-7f1ed7194000 ---p 00008000 08:08 789720                     /usr/lib/libcrypt-2.21.so
7f1ed7194000-7f1ed7195000 r--p 00008000 08:08 789720                     /usr/lib/libcrypt-2.21.so
7f1ed7195000-7f1ed7196000 rw-p 00009000 08:08 789720                     /usr/lib/libcrypt-2.21.so
7f1ed7196000-7f1ed71c4000 rw-p 00000000 00:00 0
7f1ed71c4000-7f1ed71c7000 r-xp 00000000 08:08 789795                     /usr/lib/libdl-2.21.so
7f1ed71c7000-7f1ed73c6000 ---p 00003000 08:08 789795                     /usr/lib/libdl-2.21.so
7f1ed73c6000-7f1ed73c7000 r--p 00002000 08:08 789795                     /usr/lib/libdl-2.21.so
7f1ed73c7000-7f1ed73c8000 rw-p 00003000 08:08 789795                     /usr/lib/libdl-2.21.so
7f1ed73c8000-7f1ed7458000 r-xp 00000000 08:08 793477                     /usr/lib/libgmp.so.10.2.0
7f1ed7458000-7f1ed7658000 ---p 00090000 08:08 793477                     /usr/lib/libgmp.so.10.2.0
7f1ed7658000-7f1ed7659000 r--p 00090000 08:08 793477                     /usr/lib/libgmp.so.10.2.0
7f1ed7659000-7f1ed765a000 rw-p 00091000 08:08 793477                     /usr/lib/libgmp.so.10.2.0
7f1ed765a000-7f1ed7672000 r-xp 00000000 08:08 789772                     /usr/lib/libpthread-2.21.so
7f1ed7672000-7f1ed7871000 ---p 00018000 08:08 789772                     /usr/lib/libpthread-2.21.so
7f1ed7871000-7f1ed7872000 r--p 00017000 08:08 789772                     /usr/lib/libpthread-2.21.so
7f1ed7872000-7f1ed7873000 rw-p 00018000 08:08 789772                     /usr/lib/libpthread-2.21.so
7f1ed7873000-7f1ed7877000 rw-p 00000000 00:00 0
7f1ed7877000-7f1ed7899000 r-xp 00000000 08:08 789815                     /usr/lib/ld-2.21.so
7f1ed78b4000-7f1ed7a98000 r--s 00000000 08:08 789700                     /usr/lib/libc-2.21.so
7f1ed7a98000-7f1ed7a99000 r--p 00021000 08:08 789815                     /usr/lib/ld-2.21.so
7f1ed7a99000-7f1ed7a9a000 rw-p 00022000 08:08 789815                     /usr/lib/ld-2.21.so
7f1ed7a9a000-7f1ed7a9b000 rw-p 00000000 00:00 0
7f1ed7a9b000-7f1ed7d75000 r-xp 00000000 08:08 1443053                    /opt/rubies/ruby-2.2.2/bin/ruby
7f1ed7e2b000-7f1ed7f31000 rw-p 00000000 00:00 0
7f1ed7f4d000-7f1ed7f4e000 rw-p 00000000 00:00 0
7f1ed7f4e000-7f1ed7f71000 r--s 00000000 08:08 789772                     /usr/lib/libpthread-2.21.so
7f1ed7f71000-7f1ed7f72000 ---p 00000000 00:00 0
7f1ed7f72000-7f1ed7f75000 rw-p 00000000 00:00 0                          [stack:26379]
7f1ed7f75000-7f1ed7f7b000 rw-p 002da000 08:08 1443053                    /opt/rubies/ruby-2.2.2/bin/ruby
7f1ed7f7b000-7f1ed7f8c000 rw-p 00000000 00:00 0
7f1ed9b4d000-7f1eda014000 rw-p 00000000 00:00 0                          [heap]
7ffc0bb9d000-7ffc0c39d000 rw-p 00000000 00:00 0
7ffc0c3f0000-7ffc0c3f2000 r--p 00000000 00:00 0                          [vvar]
7ffc0c3f2000-7ffc0c3f4000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]


[NOTE]
You may have encountered a bug in the Ruby interpreter or extension libraries.
Bug reports are welcome.
For details: http://www.ruby-lang.org/bugreport.html

~/code/rb_compile_string_bug[master]%
```
