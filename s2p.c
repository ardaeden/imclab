#include "m_pd.h"


static t_class *s2p_class;


typedef struct _s2p {
  t_object  x_obj;
} t_s2p;



void s2p_float(t_s2p *x, t_floatarg f)
{
  post("Hello world !!");
}

void *s2p_new(void)
{
  t_s2p *x = (t_s2p *)pd_new(s2p_class);
  return (void *)x;
}


void s2p_setup(void) {
  /* create a new class */
  s2p_class = class_new(gensym("s2p"),
                               (t_newmethod)s2p_new,
                               0,
                               sizeof(t_s2p),
                               CLASS_DEFAULT,
                               0);
  class_addfloat(s2p_class, s2p_float);
}
