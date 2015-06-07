#include <ruby.h>
#include "node.h"

static VALUE
mRbCompileStringBug_rb_compile_string(VALUE self)
{
    rb_compile_string("-", rb_str_new2("def foo; end"), 1);
    return self;
}

void Init_rb_compile_string_bug(void)
{
    VALUE rb_cRbCompileStringBug = rb_define_class("RbCompileStringBug", rb_cObject);

    rb_define_singleton_method(rb_cRbCompileStringBug, "rb_compile_string",
			       mRbCompileStringBug_rb_compile_string, 0);
}
