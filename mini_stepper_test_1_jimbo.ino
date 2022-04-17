struct stepper_pin_config {
    int dir;
    int step;
    int speed_div;

    stepper_pin_config(int dir_, int step_)
    {
      dir = dir_;
      step = step_;
    }

    void init(int speed_)
    {
      pinMode(dir, OUTPUT);  
      pinMode(step, OUTPUT); 
      digitalWrite(dir, HIGH);
      speed_div = speed_;
 
    }

    void update()
    {
      // TODO: put position control logic in here
    
      if ((micros() >> speed_div) & 1)
        digitalWrite(step, HIGH);
      else
        digitalWrite(step, LOW);
            
    }
};

constexpr int num_motors = 15;
stepper_pin_config motors[num_motors] = {

    { 2, 3 },  
    { 4, 5 },
    { 6, 7 },
    { 8, 9 },
    { 10, 11 },

    { 44, 45 },
    { 46, 47 },
    { 48, 49 },
    { 50, 51 },
    { 52, 53 },

    { 22, 23 },
    { 24, 25 },
    { 26, 27 },
    { 28, 29 },
    { 30, 31 },
};

void setup() 
{
  for (int i = 0; i < num_motors; i++ )
    // NOTE: init function sets the speed right now, but it should maybe go to the update() instead
    motors[i].init(15);
}

void loop() 
{
  for (int i = 0; i < num_motors; i++ ) {
    motors[i].update();
  }
}
