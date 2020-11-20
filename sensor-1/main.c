#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"

int main () {
  struct sensor *ptr_sensor0, *ptr_sensor1;
  
  ptr_sensor0 = sensor_Create();
  ptr_sensor1 = sensor_Create();

  ptr_sensor0->value = 99;
  ptr_sensor1->value = -1;

  printf ("[%s] The Current value from Sesonr is = %d \n", __func__, sensor_getValue(ptr_sensor0));
  printf ("[%s] The Current value from Sesonr is = %d \n", __func__, sensor_getValue(ptr_sensor1));
  
  sensor_Destroy(ptr_sensor0);
  sensor_Destroy(ptr_sensor1);

  return 0;
}
