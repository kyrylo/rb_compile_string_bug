What to do.

```
rake compile
rake bug
```

If Ruby is compiled with default flags `bug.rb` segfaults.

```
ruby -v
ruby 2.2.2p95 (2015-04-13 revision 50295) [x86_64-linux]
```

Segfaults with: [segfault](/segfault222.txt)

GDB output: [gdb](/gdb222.txt)

If Ruby is compiled with `-O0 -g`, then `bug.rb` doesn't segfault.
