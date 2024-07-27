#include "plant.h"

class StensMoistureSensor {
public:
  StensMoistureSensor(String sensorName);
  String getJson();
  String getHTML();
  String getRaw();

private:
  Plant* eberhardt_jr;
  String sensorName;
};

StensMoistureSensor::StensMoistureSensor(String sensorName) {
  this->eberhardt_jr = new Plant("Eberhardt Jr.", 32);
  this->sensorName = sensorName;
}

String StensMoistureSensor::getHTML() {
  String pre = eberhardt_jr->getName() + ":<br>Bodenfeuchtigkeit: ";
  float moisture = eberhardt_jr->getHumidity();
  String rest = " %";
  String out = pre + moisture + rest;
  return out;
}

String StensMoistureSensor::getJson() {
  String pre = "{\"sensorName\": \"" + this->sensorName + "\", \"plants\": [";

  String p = "{\"name\": \"" + this->eberhardt_jr->getName() + "\", \"humidity\": \"" + this->eberhardt_jr->getHumidity() + "\"}";

  String end = "]}";
  return pre + p + end;
}

String StensMoistureSensor::getRaw() {
  String pre = this->sensorName + ": \n\t";
  String p = this->eberhardt_jr->getName() + ": " + this->eberhardt_jr->getHumidity() + " %";
  return pre + p;
}