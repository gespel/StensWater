#include "plant.h"

class StensMoistureSensor {
public:
  StensMoistureSensor(String sensorName);
  String getJson();
  String getHTML();
  String getRaw();

private:
  Plant* eberhardt_jr;
  Plant* pfefferminze;
  Plant* brutblatt;
  String sensorName;
};

StensMoistureSensor::StensMoistureSensor(String sensorName) {
  this->eberhardt_jr = new Plant("Eberhardt Jr.", 32);
  this->pfefferminze = new Plant("Marokkanische Minze", 33);
  this->brutblatt = new Plant("Brutblatt", 35);
  this->sensorName = sensorName;
}

String StensMoistureSensor::getHTML() {
  String p = this->eberhardt_jr->getName() + ":<br>Bodenfeutchtigkeit: " + this->eberhardt_jr->getHumidity() + " %<br><br>";
  String p2 = this->pfefferminze->getName() + ":<br>Bodenfeutchtigkeit: " + this->pfefferminze->getHumidity() + " %<br><br>";
  String p3 = this->brutblatt->getName() + ":<br>Bodenfeutchtigkeit: " + this->brutblatt->getHumidity() + " %<br><br>";
  return p + p2 + p3;
}

String StensMoistureSensor::getJson() {
  String pre = "{\"sensorName\": \"" + this->sensorName + "\", \"plants\": [";

  String p = "{\"name\": \"" + this->eberhardt_jr->getName() + "\", \"humidity\": \"" + this->eberhardt_jr->getHumidity() + "\"},";
  String p2 = "{\"name\": \"" + this->pfefferminze->getName() + "\", \"humidity\": \"" + this->pfefferminze->getHumidity() + "\"},";
  String p3 = "{\"name\": \"" + this->brutblatt->getName() + "\", \"humidity\": \"" + this->brutblatt->getHumidity() + "\"}";

  String end = "]}";
  return pre + p + p2 + p3 + end;
}

String StensMoistureSensor::getRaw() {
  String pre = this->sensorName + ": \n\t";
  String p = this->eberhardt_jr->getName() + ": " + this->eberhardt_jr->getHumidity() + " %";
  String p2 = this->pfefferminze->getName() + ": " + this->pfefferminze->getHumidity() + " %";
  String p3 = this->brutblatt->getName() + ": " + this->brutblatt->getHumidity() + " %";
  return pre + p + p2 + p3;
}