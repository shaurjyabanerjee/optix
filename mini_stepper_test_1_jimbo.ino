struct stepper_pin_config {
    int dir;
    int step;

    // long int step_time = 0;
    bool step_state;

    stepper_pin_config(int dir_, int step_)
    {
      dir = dir_;
      step = step_;
    }

    void init()
    {
      pinMode(dir, OUTPUT);  
      pinMode(step, OUTPUT); 
              digitalWrite(dir, HIGH);
 
    }

    void update(/*int steps_desired*/)
    {
        // divide microsecond counter by 2048, to get
        // aproximately 2.048ms
        long int _micros = micros();
        if ((_micros >> 11) & 1)
          step_state = !step_state;

        if (1) {
            if (step_state) {
                digitalWrite(this->step, HIGH);
            } else {
                digitalWrite(this->step, LOW);

            }
        }
    }
};

constexpr float deg_per_step = 1.6;
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
