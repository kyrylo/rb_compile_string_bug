require 'mkmf'

$CFLAGS << ' -O0 -g'

create_makefile('rb_compile_string_bug')
