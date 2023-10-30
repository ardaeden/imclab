#include "m_pd.h"


static t_class *sss_class;


typedef struct _sss {
  t_object  x_obj;
} t_sss;



void sss_float(t_sss *x)
{
  post("Hello world !!");
}

void *sss_new(void)
{
  t_sss *x = (t_sss *)pd_new(sss_class);
  return (void *)x;
}


void sss_setup(void) {
  /* create a new class */
  sss_class = class_new(gensym("sss"),
                               (t_newmethod)sss_new,
                               0,
                               sizeof(t_sss),
                               CLASS_DEFAULT,
                               0);
  class_addfloat(sss_class, sss_float);
}
