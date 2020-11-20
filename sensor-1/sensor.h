#ifndef SENSOR_H
#define SENSOR_H

#include <stdio.h>
#include <stdlib.h>

/***
    class Sensor
 */

struct sensor {
  int filterFreq;
  int updateFreq;
  int value;
};

int sensor_getFilterFreq(const struct sensor * const this);
void sensor_setFilterFreq (struct sensor * const this, int p_filterFreq);
int sensor_getUpdateFreq(const struct sensor * const this);
int sensor_getValue(const struct sensor * const this);
struct sensor * sensor_Create(void);
void sensor_Destroy(struct sensor * const this);

#endif
