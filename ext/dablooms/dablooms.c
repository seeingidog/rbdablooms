#include <ruby.h>
#include "dablooms.h"

typedef struct
{
  scaling_bloom_t *filter;
} DabloomStruct;

void Dablooms_mark(DabloomStruct* self)
{
   rb_gc_mark(self->filter);
}

void Dablooms_free(DabloomStruct* self)
{
   free(self);
}

VALUE Dablooms_allocate(VALUE klass)
{
  DabloomStruct *g = malloc(sizeof(DabloomStruct));
  g->filter = Qnil;
  Data_Wrap_Struct(klass, Dablooms_mark, Dablooms_free, g);
}

VALUE initialize(VALUE self, VALUE capacity, VALUE error_rate, VALUE filepath, VALUE id)
{
  DabloomStruct* ds;
  
  rb_iv_set(self, "@capacity", capacity);
  rb_iv_set(self, "@error_rate", error_rate);
  rb_iv_set(self, "@filepath", filepath);
  rb_iv_set(self, "@id", id);

  Data_Get_Struct(self, DabloomStruct, ds);
  //ds->filter = new_scaling_bloom(capacity, error_rate, filepath, id);

  return self;
}

static VALUE db_add(VALUE self, VALUE hash, VALUE id)
{
}

static VALUE db_check(VALUE self, VALUE hash)
{
}

static VALUE db_delete(VALUE self, VALUE hash, VALUE id)
{
}

static VALUE db_flush(VALUE self)
{
}

void Init_dablooms(void)
{
  VALUE klass = rb_define_class("Dablooms", rb_cObject);

  rb_define_method(klass, "initialize", initialize, 4);
  rb_define_method(klass, "add", db_add, 2);
  rb_define_method(klass, "check", db_check, 1);
  rb_define_method(klass, "delete", db_delete, 2);
  rb_define_method(klass, "flush", db_flush, 0);

  rb_define_alloc_func(klass, Dablooms_allocate);
}


