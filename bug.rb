require_relative 'lib/rb_compile_string_bug/rb_compile_string_bug.so'

1_000_000.times { RbCompileStringBug.rb_compile_string }
