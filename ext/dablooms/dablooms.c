#include <ruby.h>


static VALUE db_new(VALUE self) {
}

static VALUE db_add(VALUE self) {
}

static VALUE db_check(VALUE self) {
}

static VALUE db_delete(VALUE self) {
}


void Init_dablooms(void) {
  VALUE klass = rb_define_class("Dablooms", rb_cObject);

  rb_define_singleton_method(klass, "new", db_new, 1);
  rb_define_method(klass, "add", db_add, 1);
  rb_define_method(klass, "check", db_check, 1);
  rb_define_method(klass, "delete", db_delete, 1);

}


