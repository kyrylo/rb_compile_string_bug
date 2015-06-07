This is a repo to demonstrate a bug filed here:

[https://bugs.ruby-lang.org/issues/11232](https://bugs.ruby-lang.org/issues/11232)

What to do.

```
bundle
rake compile
ruby bug.rb
```

If Ruby is compiled with default flags `bug.rb` segfaults.

```
ruby -v
ruby 2.2.2p95 (2015-04-13 revision 50295) [x86_64-linux]
```

Segfaults with: [segfault](/segfault222.txt)

GDB output: [gdb](/gdb222.txt)

If Ruby is compiled with `-O0 -g`, then `bug.rb` doesn't segfault.

When the GC is disabled, it works as supposed to. To test:

```
ruby nobug.rb
```
