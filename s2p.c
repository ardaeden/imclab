#include "m_pd.h"


static t_class *s2p_class;


typedef struct _s2p {
  t_object  x_obj;
  t_atom outList[5];
  t_int index;
  t_outlet *l_out;
} t_s2p;



void s2p_float(t_s2p *x, t_floatarg f)
{
  SETFLOAT(x->outList+x->index, f);
  x->index++;
  if (x->index > 4) {
    x->index = 0;
    outlet_list(x->l_out, 0, 5, x->outList);
  }
}

void *s2p_new(void)
{
  t_s2p *x = (t_s2p *)pd_new(s2p_class);
  x->index = 0;
  x->l_out=outlet_new(&x->x_obj, gensym("list"));
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
