#include "One_LED_LED_LinkIt_One.h"

Internal_LED::Internal_LED()
{
  state = -1;
}

void Internal_LED::init()
{
  state = 0;
  pinMode(ledPin, OUTPUT);
}

void Internal_LED::toggle()
{
  if (state == -1)
  {
    init();
  }
  if (state == 0)
  {
    state = 1;
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    state = 0;
    digitalWrite(ledPin, LOW);
  }
}

void Internal_LED::turnOn()
{
  if (state == -1)
  {
    init();
  }
  state = 1;
  digitalWrite(ledPin, HIGH);
}

void Internal_LED::turnOff()
{
  if (state == -1)
  {
    init();
  }
  state = 0;
  digitalWrite(ledPin, LOW);
}

Internal_LED TL_LED;
