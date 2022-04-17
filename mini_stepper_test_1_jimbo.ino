struct stepper_pin_config {
    int dir;
    int step;

    stepper_pin_config(int dir_, int step_)
    {
      dir = dir_;
      step = step_;
    }
};

constexpr int num_motors = 16;
stepper_pin_config motors[num_motors] = {
    { 2, 3 },  
    { 4, 5 },
    { 6, 7 },
    { 8, 9 },
    { 10, 11 },
    { 30, 31 },
    { 32, 33 },
    { 34, 35 },
    { 36, 37 },
    { 38, 39 },
    { 40, 41 },
    { 42, 43 },
    { 44, 45 },
    { 46, 47 },
    { 48, 49 },
    { 50, 51 },
};

int num_steps = 450;
int step_delay = 1800;

void setup() 
{
  for (int i = 0; i < num_motors; i++ ) {
    pinMode(motors[i].dir, OUTPUT);  
    pinMode(motors[i].step, OUTPUT);  
  }

}

void loop() 
{
  for (int i = 0; i < num_motors; i++ )
   spin(motors[i], num_steps);
}

void spin(stepper_pin_config& motor_, int num_steps_)
{

    digitalWrite(motor_.dir, HIGH);
  for (int i = 0; i < num_steps_; i++)
  {
    digitalWrite(motor_.step, HIGH);
    delayMicroseconds(step_delay);
    digitalWrite(motor_.step, LOW);
    delayMicroseconds(step_delay);
  }

  digitalWrite(motor_.dir, LOW);
  for (int i = 0; i < num_steps_; i++)
  {
    digitalWrite(motor_.step, HIGH);
    delayMicroseconds(step_delay);
    digitalWrite(motor_.step, LOW);
    delayMicroseconds(step_delay);
  }
}
