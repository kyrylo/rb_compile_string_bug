require_relative 'lib/rb_compile_string_bug/rb_compile_string_bug.so'

GC.disable

1_000_000.times { RbCompileStringBug.rb_compile_string }
