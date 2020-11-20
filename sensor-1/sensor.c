#include "sensor.h"

void sensor_Init(struct sensor * const this) {

}

void sensor_Cleanup(struct sensor * const this) {

}

int sensor_getFilterFreq(const struct sensor * const this) {
  return this->filterFreq;
}

void sensor_setFilterFreq (struct sensor * const this, int p_filterFreq) {
  this->filterFreq = p_filterFreq;
}

int sensor_getUpdateFreq(const struct sensor * const this) {
  return this->updateFreq;
}

int sensor_getValue(const struct sensor * const this) {
  return this->value;
}

struct sensor* sensor_Create(void) {
  struct sensor *this = (struct sensor *)malloc(sizeof(struct sensor));
  if (NULL != this)
    sensor_Init(this);
  return this;
}

void sensor_Destroy(struct sensor * const this) {
  if (NULL != this) {
    sensor_Cleanup(this);
    free(this);
  }
}
