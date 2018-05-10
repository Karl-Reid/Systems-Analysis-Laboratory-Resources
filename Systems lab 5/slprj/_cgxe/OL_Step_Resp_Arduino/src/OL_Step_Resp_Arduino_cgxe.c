/* Include files */

#include "OL_Step_Resp_Arduino_cgxe.h"
#include "m_ePayuoj95JiWdmGoyRgl3F.h"

unsigned int cgxe_OL_Step_Resp_Arduino_method_dispatcher(SimStruct* S, int_T
  method, void* data)
{
  if (ssGetChecksum0(S) == 1549931359 &&
      ssGetChecksum1(S) == 1263036639 &&
      ssGetChecksum2(S) == 698122758 &&
      ssGetChecksum3(S) == 3309159334) {
    method_dispatcher_ePayuoj95JiWdmGoyRgl3F(S, method, data);
    return 1;
  }

  return 0;
}
