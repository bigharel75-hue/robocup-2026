class motor{
  private:
    int pin0;
    int pin1;

  public:
    motor(int p0, int p1) {
      pin0 = p0;
      pin1 = p1;
    }

    void begin() {
      pinMode(pin0, OUTPUT);
      pinMode(pin1, OUTPUT);
    }

    void move(int speed) {
      if (speed > 255) speed = 255;
      if (speed < -255 ) speed = -255;
      if (speed > 0) {
        analogWrite(pin0, speed);
        analogWrite(pin1, LOW);
      }
      else {
        analogWrite(pin1, -speed);
        analogWrite(pin0, LOW);
      }
    }
};
